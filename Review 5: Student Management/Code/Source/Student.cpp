/*
* File: Student.cpp
* Author: Ton Nu Minh Trang
* Date: 5/02/2024
* Description: This file contains all of the functions/methods storing students information
*/

#include "../Header/employee.h"
using namespace std;

/*
* Class: Person
* Function: setName
* Description: This function is used for setting name of student
* Input:   _name (name of student)
* Output:  return: None
*/
void Person::setName(string _name) {
    name = _name;
}

/*
* Class: Person
* Function: getName
* Description: This function is used for getting name of student
* Input:   None
* Output:  return: name (name of student)
*/
string Person::getName() const {
    return name;
}

/*
* Class: Person
* Function: setAge
* Description: This function is used for setting age of student
* Input:   _age (age of student)
* Output:  return: None
*/
void Person::setAge(short int _age) {
    age = _age;
}

/*
* Class: Person
* Function: getAge
* Description: This function is used for getting age of student
* Input:   None
* Output:  return: age (age of student)
*/
short int Person::getAge() {
    return age;
}

/*
* Class: Person
* Function: setGender
* Description: This function is used for setting gender of student
* Input:   _gender (gender of student)
* Output:  return: None
*/
void Person::setGender(Gender _gender) {
    gender = _gender;
}

/*
* Class: Person
* Function: getGender
* Description: This function is used for getting gender of student
* Input:   None
* Output:  return: gender (gender of student)
*/
Gender Person::getGender() {
    return gender;
}

/*
* Class: Person
* Function: setID
* Description: This function is used for setting ID of student
* Input:   _ID (ID of student)
* Output:  return: None
*/
void Person::setID(short int _ID) {
    ID = _ID;
}

/*
* Class: Person
* Function: getID
* Description: This function is used for getting ID of student
* Input:   None
* Output:  return: ID (ID of student)
*/
short int Person::getID() {
    return ID;
}

/*
* Class: Student
* Function: setMath
* Description: This function is used for setting Math score of student
* Input:   _Math_score (Math score of student)
* Output:  return: None
*/
void Student::setMath(float _Math_score) {
    Math_score = _Math_score;
}

/*
* Class: Student
* Function: getMath
* Description: This function is used for getting Math score of student
* Input:   None
* Output:  return: Math_score (Math score of student)
*/
float Student::getMath() const {
    return Math_score;
}

/*
* Class: Student
* Function: setPhysic
* Description: This function is used for setting Physics score of student
* Input:   _Physic_score (Physics score of student)
* Output:  return: None
*/
void Student::setPhysic(float _Physic_score) {
    Physic_score = _Physic_score;
}

/*
* Class: Student
* Function: getPhysic
* Description: This function is used for getting Physics score of student
* Input:   None
* Output:  return: Physic_score (Physics score of student)
*/
float Student::getPhysic() const {
    return Physic_score;
}

/*
* Class: Student
* Function: setChemical
* Description: This function is used for setting Chemical score of student
* Input:   _Chemical_score (Chemical score of student)
* Output:  return: None
*/
void Student::setChemical(float _Chemical_score) {
    Chemical_score = _Chemical_score;
}

/*
* Class: Student
* Function: getChemical
* Description: This function is used for getting Chemical score of student
* Input:   None
* Output:  return: Chemical_score (Chemical score of student)
*/
float Student::getChemical() const {
    return Chemical_score;
}

/*
* Class: Student
* Function: getAverScore
* Description: This function is used for getting Average score of student
* Input:   None
* Output:  return: Average_score (Average score of student)
*/
float Student::getAverScore() const {
    Average_score = (Math_score + Physic_score + Chemical_score) / 3;
    return Average_score;
}

/*
* Class: Student
* Function: setData
* Description: This function is used for setting data of student
* Input:   None
* Output:  return: None
*/
void Student::setData() {
    cout << "\t\t\tEnter Name: ";
    cin.ignore();
    string _name; cin >> _name;
    setName(_name);

    cout << "\t\t\tEnter Age: ";
    short int _age; cin >> _age;
    setAge(_age);

    short int num = 0;
    do {
        cout << "\t\t\tEnter 1 for male and 2 for female" << endl;
        cout << "\t\t\tEnter Gender: ";
        cin >> num;
    } while (num != 1 && num != 2);

    Gender _gender;
    if (num == 1) _gender = Male;
    else _gender = Female;
    setGender(_gender);

    cout << "\t\t\tEnter ID: ";
    short int _ID; cin >> _ID;
    setAge(_ID);

    cout << "\t\t\tEnter Student Score: " << endl;

    cout << "\t\t\tEnter Math Score: ";
    float _Math_score; cin >> _Math_score;
    setMath(_Math_score);

    cout << "\t\t\tEnter Physic Score : ";
    float _Physic_score; cin >> _Physic_score;
    setMath(_Physic_score);

    cout << "\t\t\tEnter Chemical Score: ";
    float _Chemical_score; cin >> _Chemical_score;
    setMath(_Chemical_score);
}

/*
* Class: Student
* Function: getData
* Description: This function is used for getting data of student
* Input:   None
* Output:  return: None
*/
void Student::getData() {
    cout << "ID: " << getID() << endl;

    cout << "Name: " << getName() << endl;

    cout << "Age: " << getAge() << endl;

    cout << "Gender: ";
    if (getGender() == Male) { cout << "Male" << endl; }
    else cout << "Female" << endl;

    cout << "Maths\t | \tPhysics | \tChemistry" << endl;
    cout << getMath() << "\t\t" << getPhysic() << "\t\t" << getChemical() << endl;

    cout << "Average_score: " << getAverScore() << endl;

    cout << "Rank: " << getRank() << endl;
    switch(getRank()) {
        case Excellent:
            cout << "Excellent" << endl;
            break;
        case Good:
            cout << "Good" << endl;
            break;
        case Average:
            cout << "Average" << endl;
            break;
        case BelowAverage:
            cout << "BelowAverage" << endl;
            break;
        case Weak: 
            cout << "Weak" << endl;
            break;
        default:
            break;
    }
}

/*
* Class: Student
* Function: getRank
* Description: This function is used for getting rank of student
* Input:   None
* Output:  return: rank (rank of student)
*/
Rank Student::getRank() {
        if (getAverScore() >= 8.5 && getAverScore() <= 10) return Excellent;
        else if (getAverScore() >= 7 && getAverScore() <= 8.4) return Good;
        else if (getAverScore() >= 5.5 && getAverScore() <= 6.9) return Average;
        else if (getAverScore() >= 4 && getAverScore() <= 5.4) return BelowAverage;
        else return Weak;
}
