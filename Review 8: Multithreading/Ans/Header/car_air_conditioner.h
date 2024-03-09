/*
* File: car_air_conditioner.h
* Author: Ton Nu Minh Trang
* Date: 03/03/2024
* Description: This file is a Car Air Conditioner header file that program is used for controlling car air conditioner
*/

#ifndef _CAR_AIR_CONDITIONER
#define _CAR_AIR_CONDITIONER

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <shared_mutex> 
#include <chrono>
#include <future>

// hiển thị nhiệt độ trong xe
// hiển thị nhiệt độ ngoài xe

// hiển thị bảng điều chỉnh nhiệt độ trong xe
// hiển thị bảng điều chỉnh mức gió trong xe

using namespace std;

mutex mtx_temp_outside, mtx_temp_inside, mtx_wind_insdide, mtx_key_input;

condition_variable cv_temp_outside, cv_temp_inside, cv_wind_insdide;

typedef struct {
    DeviceMode deviceMode;

    int temp_outside;
    int temp_inside;
    int wind_inside;

    HandControl wind_inside;
    HandControl temp_setting;

} DeviceValue;

DeviceValue deviceValue = {ON, 20, 20, 1, ON, ON};

// Chế độ điều hòa 
typedef enum {
    ON,
    OFF
} DeviceMode;

// Chế độ Bằng tay
typedef enum {
    INCREASE,
    DECREASE
} HandControl;

// random từ 20 đến 40 độ
inline int getTempRandom() { 
    srand(time(NULL));  
    return rand() % 21 + 3;
}

typedef struct {
    // Task 1: Luồng giao diện ng dùng (Màn hình hiển thị)
    void userMenu();

    // Task 2: Luồng sensor nhiệt độ bên ngoài xe
    void setTempOutside(); // thiết lập temp outside
    void getTempOutside(); // hiển thị temp lên màn hình

    // Task 3: Luồng sensor nhiệt độ bên trong xe
    void setTempInside(); // thiết lập temp inside
    void getTempInside(); // hiển thị temp lên màn hình

    void getWindInside(); // hiển thị mức gió lên màn hình

    // Task 4: Luồng điều khiển điều hòa nhiệt độ
    void controlTempInside(HandControl handControl);

    // Task 5: Luồng điều khiển quạt gió (5 level; 0 là tắt quạt gió)
    void controlWindInside(HandControl handControl);
    
} DeviceFunction;

#endif
