/*
* File: Student.h
* Author: Ton Nu Minh Trang
* Date: 5/02/2024
* Description: This file is a Student header file that program is used for storing student information
*/

#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum Gender {
    Male,
    Female
} Gender;

typedef enum Rank {
    Excellent,
    Good,
    Average,
    BelowAverage,
    Weak
} Rank;

/*
* Class: Person
* Description: This class contains basic properties and methods of a Person object
*/
class Person {
private:
    string name;
    short int age;
    Gender gender;
    short int ID;
public:
    Person() {
        this->name = "";
        this->age = 0;
        this->gender = Male;
        this->ID = 0;
    }

    ~Person() {}

    void setName(string _name);
    string getName() const;

    void setAge(short int _age);
    short int getAge();

    void setGender(Gender _gender);
    Gender getGender();

    void setID(short int _ID);
    short int getID();
};

/*
* Class: Student
* Description: This class contains basic properties and methods of a Student object
*/
class Student : public Person {
private:
    float Math_score;
    float Physic_score;
    float Chemical_score;
    float Average_score;
    Rank rank;

public:
    Student() : Person() {
        this->Math_score = 0;
        this->Physic_score = 0;
        this->Chemical_score = 0;
        this->Average_score = 0;
        this->rank = Excellent;
    }

    ~Student() {}

    void setData();
    void getData();

    void setMath(float _Math_score);
    float getMath() const;

    void setPhysic(float _Physic_score);
    float getPhysic() const;

    void setChemical(float _Chemical_score);
    float getChemical() const;

    float getAverScore() const;

    Rank getRank(); 
};

#endif
