#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>

#define NDEBUG
#define LINE_LEN 9

using namespace std;

typedef struct {
    int status[LINE_LEN][LINE_LEN];
    int suduko[LINE_LEN][LINE_LEN];
}Suduku;

int CheckRow(Suduku mySuduko);
int CheckCol(Suduku mySuduko);
int CheckSingle(Suduku mySuduko);
int CheckSuduku(Suduku mySuduko);


int main() {
    string input;
    Suduku mySuduko;

    while (getline(cin, input))
    {
        for (int i = 0; i < LINE_LEN; i++)
        {
            int n = 0;
            for (int j = 0; j < LINE_LEN; j++)
            {
                mySuduko.suduko[i][j] = input[n] - '0';
                n += 2;
            }
            if (i < LINE_LEN-1)
            {
                getline(cin, input);
            }
        }

#ifndef NDEBUG
        cout << endl;
        cout << "GET PARSE DATA" << endl;
        cout << "===================" << endl;
        for (int i = 0; i < LINE_LEN; i++)
        {
            for (int j = 0; j < LINE_LEN; j++)
            {
                cout << mySuduko.suduko[i][j] << " ";
            }
            cout << endl;
        }
        cout << "===================" << endl;
#endif

        if (CheckSuduku(mySuduko) == 1)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;

        }
    }

}


int CheckSuduku(Suduku mySuduko)
{
    Suduku sort_suduko = mySuduko;
    assert(mySuduko.suduko[0][0] >= 0 && mySuduko.suduko[0][0] <= LINE_LEN);
    //sort
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        sort(sort_suduko.suduko[i], sort_suduko.suduko[i] + LINE_LEN);
    }

#ifndef NDEBUG
    cout << endl;
    cout << "SORT DATA" << endl;
    cout << "===================" << endl;
    for (int i = 0; i < LINE_LEN; i++)
    {
        for (int j = 0; j < LINE_LEN; j++)
        {
            cout << sort_suduko.suduko[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===================" << endl;
#endif

    if (CheckRow(sort_suduko) && CheckCol(sort_suduko) && CheckSingle(mySuduko))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int CheckRow(Suduku mySuduko)
{
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        for (size_t j = 0; j < LINE_LEN - 1; j++) {
            if (mySuduko.suduko[i][j] == mySuduko.suduko[i][j + (size_t)1]) {
                return 0;
            }
        }
    }
    return 1;

}

int CheckCol(Suduku mySuduko)
{
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        for (size_t j = 0; j < LINE_LEN - 1; j++) {
            if (mySuduko.suduko[j][i] != mySuduko.suduko[j + (size_t)1][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int CheckSingle(Suduku mySuduko)
{
    int check_table[LINE_LEN][2] = { {1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7} };
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        int tmp_check[LINE_LEN] = { 0 };
        tmp_check[0] = mySuduko.suduko[check_table[i][0] - (size_t)1][check_table[i][1] - (size_t)1];
        tmp_check[1] = mySuduko.suduko[check_table[i][0]]            [check_table[i][1] - (size_t)1];
        tmp_check[2] = mySuduko.suduko[check_table[i][0] + (size_t)1][check_table[i][1] - (size_t)1];

        tmp_check[3] = mySuduko.suduko[check_table[i][0] - (size_t)1][check_table[i][1]];
        tmp_check[4] = mySuduko.suduko[check_table[i][0]]            [check_table[i][1]];
        tmp_check[5] = mySuduko.suduko[check_table[i][0] + (size_t)1][check_table[i][1]];

        tmp_check[6] = mySuduko.suduko[check_table[i][0] - (size_t)1][check_table[i][1] + (size_t)1];
        tmp_check[7] = mySuduko.suduko[check_table[i][0]]            [check_table[i][1] + (size_t)1];
        tmp_check[8] = mySuduko.suduko[check_table[i][0] + (size_t)1][check_table[i][1] + (size_t)1];

        sort(tmp_check, tmp_check + LINE_LEN);

#ifndef NDEBUG
        for (size_t j = 0; j < LINE_LEN; j++) {
            cout << tmp_check[j] << " ";
        }
        cout << endl;
#endif
        for (size_t j = 0; j < LINE_LEN - 1; j++) {
            if (tmp_check[j] == tmp_check[j + (size_t)1]) {
                return 0;
            }
        }
    }
    return 1;
}

