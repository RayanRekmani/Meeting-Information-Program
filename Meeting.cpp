// -----------------------------------------------------
// Assignment 4
// Question: 2
// File name: Meeting.cpp
// Written by: Rayan Rekmani 40283058
// -----------------------------------------------------

#include "Meeting.h"
#include <iostream>

using namespace std;

//this file implements the Meeting member functions

Meeting::Meeting(){
    setName("COMP218");
    setDate("2022-02-12");
    setMode(0);
    setCapacity(100);
}

Meeting::Meeting(string name){
    setName(name);
    setDate("2022-02-22");
    setMode(1);
    setCapacity(1);
}

Meeting::Meeting(string n, string d, int m, int c){
    setName(n);
    setDate(d);
    setMode(m);
    setCapacity(c);
}

string Meeting::getName(){
    return name;
}

string Meeting::getDate(){
    return date;
}

int Meeting::getMode(){
    return mode;
}

int Meeting::getCapacity(){
    return capacity;
}

void Meeting::setName(string n){
    name=n;
}

void Meeting::setDate(string d){
    date=d;
}

void Meeting::setMode(int m){
    mode=m;
}

void Meeting::setCapacity(int c){
    capacity=c;
}

bool Meeting::isOnline(int m){
    if (m==1)
        return true;
    else
        return false;
}

void Meeting::changeOnline(int number){
    cout << "Would you like to change the meeting "<<number<<" online? ";
    string answer;
    cin >> answer;
    if (answer=="yes")
        setMode(1);
}

bool Meeting::equals(Meeting* m){
    if(getName()==m->getName() &&
       getDate()==m->getDate() &&
       getMode()==m->getMode() &&
       getCapacity()==m->getCapacity())
        return true;
    else
        return false;
}

void Meeting::postpone(string newDate){
    setDate(newDate);
}

void Meeting::printInfo(){
    //creating variables for the output as there's a different in plurality and status of meeting. Definining these difference through if functions
    string student, status;
    if (getCapacity()>1)
        student = " students ";
    else
        student = " student ";
    if (getMode()==1)
        status = "online";
    else
        status = "in person";
    cout << getName()<<" on "<<getDate()<<" with capacity: "<<getCapacity()<<student<<status<<".\n";
}
