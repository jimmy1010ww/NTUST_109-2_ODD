#ifndef Diary_H
#define Diary_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Diary
{
public:
    static string day;
    static vector<string> day_record;

    string day_stamp;
    string body_part;
    int original_value;
    int changed_value;
    int copy = 0;
    static void NewDay(string day);
};
#endif
