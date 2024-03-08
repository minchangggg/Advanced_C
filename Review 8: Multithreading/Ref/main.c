#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>

#define INCREASE_TEMP 1
#define DECREASE_TEMP 2
#define INCREASE_WIND 3
#define DECREASE_WIND 4
#define TURN_ON_AIR  5
#define TURN_OFF_AIR 6

using namespace std;

typedef enum {
    INCREASE,
    DECREASE,
    OFF
} Air_condition_status;

typedef enum {
    AIR_MODE_ON,
    AIR_MODE_OFF
} Air_mode;

mutex mtx_sensor_outside, mtx_sensor_inside, mtx_cout, mtx_sensor_wind, mtx_key_input;
double sensor_outside;
double sensor_inside = 16;
int sensor_wind;
double temp_display = 20;
int wind_display;

Air_condition_status air_status = OFF;
Air_mode air_mode = AIR_MODE_OFF;

double generateRandomTemperature() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> dis(20.0, 40.0);
    return dis(gen);
}

double getTemperatureInside() {
    if (air_status == INCREASE) return sensor_inside + 1 ;
    else if (air_status == DECREASE) return sensor_inside - 1;
    return sensor_inside ;
}

/*
    ---------SENSOR_OUTSIDE---------------
    Temperature:
*/
void display_sensor_outside() {
    sensor_outside = generateRandomTemperature();
    while (1) {
        this_thread::sleep_for(chrono::seconds(3));
        mtx_cout.lock();
        cout << "---------------SENSOR_OUTSIDE----------------" << endl;
        cout << "temperature: " << sensor_outside << endl;
        mtx_cout.unlock();

        mtx_sensor_outside.lock();
        sensor_outside = generateRandomTemperature();
        mtx_sensor_outside.unlock();

    }
}

/*
    ---------SENSOR_INSIDE---------------
    Temperature:
*/
void display_sensor_inside() {

    while (1) {
        this_thread::sleep_for(chrono::seconds(3));

        mtx_cout.lock();
        cout << "---------------SENSOR_INSIDE----------------" << endl;
        cout << "temperature: " << sensor_inside << endl;
        mtx_cout.unlock();

        mtx_sensor_inside.lock();
        sensor_inside = getTemperatureInside();

        mtx_sensor_inside.unlock();
    }
}


/*
    ---------AIR_CONDITIONER---------------
    Temperature: Increase/ Decrease/ Off
*/
void display_air_condition() {
    while (1) {
        this_thread::sleep_for(chrono::seconds(3));
        mtx_cout.lock();
        cout << "---------------AIR_CONDITION----------------" << endl;
        if (air_status == DECREASE) cout << "Temperature: Decrease" << endl;
        else if (air_status == INCREASE) cout << "Temperature: Increase" << endl;
        else cout << "Temperature: Off" << endl;

        mtx_cout.unlock();
    }
}

/*
    ---------DISPLAY------------
    temperature: 20
    level wind: 2
    air mode: on/off

*/
void display() {
    while (1) {
        this_thread::sleep_for(chrono::seconds(3));
        mtx_cout.lock();
        mtx_key_input.lock();
        cout << "---------------DISPLAY----------------" << endl;
        cout << "temperature: " << temp_display << endl;
        cout << "level wind: " << wind_display << endl;
      
        if ( air_mode == AIR_MODE_OFF) cout << "air mode: OFF" << endl;  
        else if( air_mode == AIR_MODE_ON) cout << "air mode: ON" << endl;

        mtx_key_input.unlock();
        mtx_cout.unlock();
    }
}


/*
    ---------FAN------------------------
    Level wind: 2
*/
void display_fan() {
    while (1) {
        this_thread::sleep_for(chrono::seconds(3));

        mtx_cout.lock();
        cout << "---------------FAN----------------" << endl;
        cout << "Level wind: " << sensor_wind << endl;
        mtx_cout.unlock();

        mtx_key_input.lock();

        if (sensor_wind < wind_display) sensor_wind++;
        else if (sensor_wind > wind_display) sensor_wind--;

        mtx_key_input.unlock();
    }
}


/*
---------BUTTON------------
    1. Increase temp
    2. Decrease temp
    3. Increase wind
    4. Decrease wind
    5. Turn on air mode
    6. Turn off air mode

*/
void inputKey() {
    int choice;
    
    while (1) {
        
        if (cin.peek() == '\n') {
        }
        cin >> choice;
        
        mtx_key_input.lock();
        switch (choice) {
        case INCREASE_TEMP:
            temp_display++;
            break;
        case DECREASE_TEMP:
            temp_display--;
            break;
        case INCREASE_WIND:
            wind_display++;
            break;
        case DECREASE_WIND:
            wind_display--;
            break;
        case TURN_ON_AIR:
            air_mode = AIR_MODE_ON;
            break;
        case TURN_OFF_AIR:
            air_mode = AIR_MODE_OFF;
            break;
        default:
            break;
        }
        mtx_key_input.unlock();
    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    thread thread_input_key(inputKey);
    thread thread_sensor_outside(display_sensor_outside);
    thread thread_sensor_inside(display_sensor_inside);
    thread thread_fan(display_fan);
    thread thread_air_condition(display_air_condition);
    thread thread_display(display);

    cout << "-------------BUTTON------------------" << endl;
    cout << "1. Increase temperature " << endl;
    cout << "2. Decrease temperature " << endl;
    cout << "3. Increase wind level " << endl;
    cout << "4. Decrease wind level " << endl;
    cout << "5. Turn on air mode " << endl;
    cout << "6. Turn off air mode " << endl;
    
    while (1) {
        mtx_key_input.lock();
        mtx_sensor_outside.lock();
        mtx_sensor_inside.lock();
        if (air_mode == AIR_MODE_ON) {
            if (temp_display * 2  - (sensor_inside + sensor_outside) > 1) {
                sensor_inside = (sensor_inside + sensor_outside)/2;
                air_status = INCREASE;
            }
            else if (temp_display * 2  - (sensor_inside + sensor_outside) < -1) {
                sensor_inside = (sensor_inside + sensor_outside)/2;
                air_status = DECREASE;
            }
            else air_status = OFF;
        }
        else if (air_mode == AIR_MODE_OFF) {
            if (temp_display - sensor_inside  > 1) air_status = INCREASE;
            else if (temp_display - sensor_inside  < -1) air_status = DECREASE;
            else air_status = OFF;
        }
      
        mtx_key_input.unlock();
        mtx_sensor_outside.unlock();
        mtx_sensor_inside.unlock();   
    }
    
    thread_input_key.join();
    thread_display.join();
    thread_air_condition.join();
    thread_fan.join();
    thread_sensor_inside.join();
    thread_sensor_outside.join();

    return 0;
}
