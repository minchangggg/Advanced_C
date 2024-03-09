/*
* File: car_air_conditioner
* Author: Ton Nu Minh Trang
* Date: 03/03/2024
* Description: This file is a Car Air Conditioner header file that program is used for control air conditioner
*/

#ifndef _CAR_AIR_CONDITIONER
#define _CAR_AIR_CONDITIONER

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <future>
#include <random>

using namespace std;

mutex mtx_temp_outside, mtx_temp_inside, mtx_wind_insdide, mtx_data_inside, mtx_key_input;
DeviceValue deviceValue;

// Thông số giá trị điều hòa
typedef struct {
    float temp_outside = 0;
    float temp_inside = 0;
    float temp_setting = 0;

    int sensor_wind = 0;
    int wind_setting = 0;
} DeviceValue;

// Chế độ điều hòa 
typedef enum {
    ON,
    OFF
} DeviceMode;

// Chế độ Bằng tay
typedef enum {
    ON,
    INCREASE,
    DECREASE,
    OFF
} HandControl;

// Các chế độ điều khiển của thiết bị 
typedef struct {
    float autoControl; // Chế độ Tự động
    HandControl handControl; // Chế độ Bằng tay
} DeviceControl;

inline float getTempRandom() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> dis(20.0, 40.0);
    return dis(gen);
}

typedef struct {
    // Task 1: Luồng giao diện ng dùng (Màn hình hiển thị)
    void userMenu();

    // Task 2: Luồng sensor nhiệt độ bên ngoài xe
    void setTempOutside();
    float getTempOutside();

    // Task 3: Luồng sensor nhiệt độ bên trong xe
    void setTempInside();
    float getTempInside();

    // Task 4: Luồng điều khiển điều hòa nhiệt độ
    void controlTempInside();

    // Task 5: Luồng điều khiển quạt gió (5 level; 0 là tắt quạt gió)
    void controlWindInside();
    
} DeviceFunction;

#endif
