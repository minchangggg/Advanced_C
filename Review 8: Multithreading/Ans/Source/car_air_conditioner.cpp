/*
* File: car_air_conditioner.cpp
* Author: Ton Nu Minh Trang
* Date: 03/03/2024
* Description: This file contains all the functions/methods to control car air conditioner
*/

#include "../Header/car_air_conditioner.h"
using namespace std;

void DeviceFunction::userMenu() {
    thread thread_setTempOutside(setTempOutside);
    thread thread_getTempOutside(getTempOutside);

    thread thread_setTempInside(setTempInside);
    thread thread_getTempInside(getTempInside);

    thread thread_getWindInside(getWindInside);

    thread thread_controlTempInside(controlTempInside);
    thread thread_controlWindInside(controlWindInside);
}

void DeviceFunction::setTempOutside() {
    while (1) {
        this_thread::sleep_for(chrono::seconds(15));

        unique_lock<mutex> lock(mtx_temp_outside);
        deviceValue.temp_outside = getTempRandom();
        cv_temp_outside.notify_one();
    }
}

void DeviceFunction::getTempOutside() {
    while (1) {
        unique_lock<mutex> lock(mtx_temp_outside);
        cv_temp_outside.wait(lock);
        
        cout << "---------------TEMPERATURE OUTSIDE----------------" << endl;
        cout << "Nhiet do ngoai troi bay gio la: " << deviceValue.temp_outside << endl;
    }
}

void DeviceFunction::setTempInside() {
    while (1) {
        this_thread::sleep_for(chrono::seconds(15));
        
        unique_lock<mutex> lock(mtx_temp_inside);

        mtx_temp_outside.lock();
        deviceValue.temp_inside = deviceValue.temp_outside - 4; // nhiệt độ trong xe luôn thấp hơn ngòai trời 4 độ
        mtx_temp_outside.unlock();

        cv_temp_inside.notify_one();
    }
}

void DeviceFunction::getTempInside() {
    while (1) {
        unique_lock<mutex> lock (mtx_temp_outside);
        cv_temp_outside.wait(lock);

        cout << "---------------TEMPERATURE INSIDE----------------" << endl;
        cout << "Nhiet do trong xe bay gio la: " << deviceValue.temp_inside << endl;
    }
}

void DeviceFunction::getWindInside() {
    while (1) {
        unique_lock<mutex> lock (mtx_wind_insdide);
        cv_wind_insdide.wait(lock);

        if (deviceValue.wind_inside != 0) {
            cout << "---------------WIND LEVEL INSIDE----------------" << endl;
            cout << "Muc gio trong xe bay gio la: " << deviceValue.wind_inside << endl;
        }
        else {
            cout << "Fan off" << endl;
        }
    }  
}

void DeviceFunction::controlTempInside(HandControl handControl) {
    switch (handControl) {
    case INCREASE:
    {
        unique_lock <mutex> lock(mtx_temp_inside);
        if (deviceValue.wind_inside < 30)  // nhiệt độ cao nhất là 30
        {
            deviceValue.temp_inside ++; 
            cv_temp_inside.notify_one();
        }
        else deviceValue.wind_inside = 30;
        break;
    }
    case DECREASE:
    {
        unique_lock <mutex> lock(mtx_temp_inside);
        if (deviceValue.wind_inside > 18)  // nhiệt độ thấp nhất là 18
        {
            deviceValue.temp_inside --; 
            cv_temp_inside.notify_one();
        }
        else deviceValue.wind_inside = 18;
        break;
    }     
    default:
        break;
    }
}

void DeviceFunction::controlWindInside(HandControl handControl) {
    switch (handControl) {
    case INCREASE:
    {
        unique_lock <mutex> lock(mtx_wind_insdide);
        if (deviceValue.wind_inside < 5)  // mức gió lớn nhất là 5
        {   
            deviceValue.wind_inside ++; 
            cv_wind_insdide.notify_one();
        }
        else deviceValue.wind_inside = 5;
        break;
    }
    case DECREASE:
    {
        unique_lock <mutex> lock(mtx_wind_insdide); 
        if (deviceValue.wind_inside > 0) { // mức gió thấp nhất là 1, 0 là off
            deviceValue.wind_inside --;
            cv_wind_insdide.notify_one();
        }
        else deviceValue.wind_inside = 0;
        break;
    }      
    default:
        break;
    }
}
