#include <iostream>
#include <algorithm>
#include <string>

//#define NDEBUG
#define LINE_LEN 9

using namespace std;

typedef struct {
    int status[LINE_LEN][LINE_LEN];
    int suduku[LINE_LEN][LINE_LEN];
}Suduku;

int CheckRow(Suduku mysuduku);
int CheckCol(Suduku mysuduku);
int CheckSingle(Suduku mysuduku);
int CheckSuduku(Suduku mysuduku);
int PreCheck(Suduku mysuduku);

int main() {
    string input;
    Suduku mysuduku;
    char n;
    while (getline(cin, input))
    {

        for (int i = 0; i < LINE_LEN; i++)
        {
            int n = 0;
            for (int j = 0; j < LINE_LEN; j++)
            {
                mysuduku.suduku[i][j] = input[n] - '0';
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
                cout << mysuduku.suduku[i][j] << " ";
            }
            cout << endl;
        }
        cout << "===================" << endl;
#endif

        if (PreCheck(mysuduku) == 1 && CheckSuduku(mysuduku) == 1)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;

        }

    }
}

int PreCheck(Suduku mysuduku)
{
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        for (size_t j = 0; j < LINE_LEN; j++)
        {
            if (mysuduku.suduku[i][j] > 9 || mysuduku.suduku[i][j] < 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int CheckSuduku(Suduku mysuduku)
{
    Suduku sort_suduku = mysuduku;
    //assert(mysuduku.suduku[0][0] >= 0 && mysuduku.suduku[0][0] <= LINE_LEN);
    //sort
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        sort(sort_suduku.suduku[i], sort_suduku.suduku[i] + LINE_LEN);
    }

#ifndef NDEBUG
    cout << endl;
    cout << "SORT DATA" << endl;
    cout << "===================" << endl;
    for (int i = 0; i < LINE_LEN; i++)
    {
        for (int j = 0; j < LINE_LEN; j++)
        {
            cout << sort_suduku.suduku[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===================" << endl;
#endif

    if (!CheckRow(sort_suduku) || !CheckCol(sort_suduku) || !CheckSingle(mysuduku))
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

int CheckRow(Suduku mysuduku)
{
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        for (size_t j = 0; j < LINE_LEN - 1; j++) {
            if (mysuduku.suduku[i][j] == mysuduku.suduku[i][j + (size_t)1]) {
                return 0;
            }
        }
    }
    return 1;

}

int CheckCol(Suduku mysuduku)
{
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        for (size_t j = 0; j < LINE_LEN - 1; j++) {
            if (mysuduku.suduku[j][i] != mysuduku.suduku[j + (size_t)1][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int CheckSingle(Suduku mysuduku)
{
    int check_table[LINE_LEN][2] = { {1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7} };
    for (size_t i = 0; i < LINE_LEN; i++)
    {
        int tmp_check[LINE_LEN] = { 0 };
        tmp_check[0] = mysuduku.suduku[check_table[i][0] - (size_t)1][check_table[i][1] - (size_t)1];
        tmp_check[1] = mysuduku.suduku[check_table[i][0]][check_table[i][1] - (size_t)1];
        tmp_check[2] = mysuduku.suduku[check_table[i][0] + (size_t)1][check_table[i][1] - (size_t)1];

        tmp_check[3] = mysuduku.suduku[check_table[i][0] - (size_t)1][check_table[i][1]];
        tmp_check[4] = mysuduku.suduku[check_table[i][0]][check_table[i][1]];
        tmp_check[5] = mysuduku.suduku[check_table[i][0] + (size_t)1][check_table[i][1]];

        tmp_check[6] = mysuduku.suduku[check_table[i][0] - (size_t)1][check_table[i][1] + (size_t)1];
        tmp_check[7] = mysuduku.suduku[check_table[i][0]][check_table[i][1] + (size_t)1];
        tmp_check[8] = mysuduku.suduku[check_table[i][0] + (size_t)1][check_table[i][1] + (size_t)1];

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

