#include "Student.h"
using namespace std;

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
    setAge(_age);

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

Rank Student::getRank() {
        if (getAverScore() >= 8.5 && getAverScore() <= 10) return Excellent;
        else if (getAverScore() >= 7 && getAverScore() <= 8.4) return Good;
        else if (getAverScore() >= 5.5 && getAverScore() <= 6.9) return Average;
        else if (getAverScore() >= 4 && getAverScore() <= 5.4) return BelowAverage;
        else return Weak;
}
