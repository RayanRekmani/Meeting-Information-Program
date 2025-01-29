// -----------------------------------------------------
// Assignment 4
// Question: 2
// File name: A4Q2.cpp
// Written by: Rayan Rekmani 40283058
// -----------------------------------------------------

#include "Meeting.h"
#include <iostream>
#include <iomanip> //for setw

using namespace std;

int main() {
    cout    <<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl
            <<setw(44)<<"Welcome to Meeting Information Program" <<endl
            <<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl<<endl;
    //variables for user input to plug into the constructors
    string m2name, m3name, m3date;
    int m3mode, m3capacity;
    cout << "Please enter the name of meeting 2: ";
    cin >> m2name;
    cout << "Please enter the name, date, mode and capacity of meeting 3: ";
    cin >> m3name >> m3date >> m3mode >> m3capacity;
    Meeting meeting1; //using the default constructor
    Meeting meeting2(m2name);
    Meeting meeting3(m3name, m3date, m3mode, m3capacity);
    //creating an aray to carry by reference the above created Meetings
    Meeting* meetings[] = {&meeting1, &meeting2, &meeting3};
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Meeting "<<i+1<<" is ";
        meetings[i] -> printInfo();
    }
    cout << endl;
    //If the meeting is in-person, ask the user whether they want to change it online
    for (int i = 0; i < 3; i++)
    {
        if (!meetings[i] ->isOnline(meetings[i]->getMode()))
            meetings[i] -> changeOnline(i+1);
    }
    //Create an integer array to save the capacity of 3 objects
    int capacityArray[]={meetings[0]->getCapacity(), meetings[1]->getCapacity(), meetings[2]->getCapacity()};
    int totalCapacity = 0;
    for (int i = 0; i < 3; i++)
    {
        totalCapacity+=capacityArray[i];
    }
    cout << "\nThe total capacity of " << size(capacityArray) << " meetings is: " <<totalCapacity<<endl;
    //Change the capacity of the second object meeting2 which equals to the sum of meeting1 and meeting 3
    meetings[1]->setCapacity(capacityArray[0]+capacityArray[2]);
    //we now replace the value in the capacity array to match the new value
    capacityArray[1]=meetings[1]->getCapacity();
    //and recalculate the new total capacity
    totalCapacity = 0;
    for (int i = 0; i < 3; i++)
    {
        totalCapacity+=capacityArray[i];
    }
    cout    << "\nNow, the capacity of meeting2 is changed..."<<endl
            << "The total capacity of " << size(capacityArray) << " meetings is: " <<totalCapacity<<endl;
    //Ask the user to postpone the meeting1
    cout << "\nWould you like to postpone the meeting1? ";
    string answer;
    cin >> answer;
    if (answer=="yes"){
        string newDate;
        cout << "Please enter the new date: ";
        cin >> newDate;
        meetings[0]->postpone(newDate);
    }
    cout << endl;
    if (meetings[0]-> equals(meetings[1]))
        cout << "Meeting 1 & 2 are equal."<<endl;
    else
        cout << "Meeting 1 & 2 are not equal."<<endl;
    if (meetings[0]-> equals(meetings[2]))
        cout << "Meeting 1 & 3 are equal."<<endl;
    else
        cout << "Meeting 1 & 3 are not equal."<<endl;
    if (meetings[1]-> equals(meetings[2]))
        cout << "Meeting 2 & 3 are equal."<<endl;
    else
        cout << "Meeting 2 & 3 are not equal."<<endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Meeting "<<i+1<<" is ";
        meetings[i]->printInfo();
    }
    cout << endl;
    cout << "Thank you for using this program!"<<endl;
    return 0;
}
