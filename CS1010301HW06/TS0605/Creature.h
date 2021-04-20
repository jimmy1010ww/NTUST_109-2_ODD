#ifndef Creature_H
#define Creature_H

#include <iostream>
#include <vector>
#include <string>
#include "Diary.h"

using namespace std;

class Creature
{
public:
    struct Body_Part {
        string body_part; //身體部位
        int value;        //身體部位的數量
    };

    string name;          //生物名字
    string start_day;
    vector <Body_Part> myPart;
    vector <Diary> mylog;
    int changeIndex;  //共用更改index

    Creature(string name);
    Creature(string name, Creature in);

    void operator=(int in);
    void operator+=(int in);
    void operator-=(int in);

    void PrintStatus(); //Prints the value of each body part of the organism.
    void PrintLog();    //Prints the log information of the creature on a Diary basis since it was collected.
    Creature& operator[](string i);
};
#endif
