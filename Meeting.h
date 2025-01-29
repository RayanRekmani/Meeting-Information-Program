// -----------------------------------------------------
// Assignment 4
// Question: 2
// File name: Meeting.h
// Written by: Rayan Rekmani 40283058
// -----------------------------------------------------

#include <iostream>

using namespace std;

//specification file giving the specification of a Meeting abstract data type
class Meeting {
public:
    //constructors
    Meeting(); //default constructor, which will set three attributes name, date, mode and capacity to “COMP218”, 2022-02-12, 0 and 100
    Meeting(string n); //a name constructor which sets the attribute name to the passed value and the other three attributes date, mode and capacity will be the default one, which are 2022-02-22, 1 and 1
    Meeting(string n, string d, int m, int c); //a third constructor which sets all the attributes to the passed values
    //functions
    string getName(); //returns the name of the meeting
    string getDate(); //returns the date of the meeting
    int getMode(); //returns the mode of the meeting
    int getCapacity(); //returns the capacity of the meeting
    void setName(string n); //sets the name attribute to n
    void setDate(string d); //sets the date attribute to d
    void setMode(int m); //sets the mode attribute to m
    void setCapacity(int c); //sets the capacity attribute to c
    bool isOnline(int m); //returns true if the mode is online, otherwise false
    void changeOnline(int number); //ask the user to change the in person meeting online. Number to indicate which meeting to be changed
    bool equals(Meeting* m); //returns true if the name, date and mode of the calling objects are the same as the name, date and mode of the passed object m, otherwise false.
    void postpone(string newDate); //change date attribute to newDate accordingly
    void printInfo(); //display on the console the item name, date, price and quantity
private:
    string name;
    string date;
    int mode;
    int capacity;
};
