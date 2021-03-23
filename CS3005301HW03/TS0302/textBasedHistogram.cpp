#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Global_Var.h"

using namespace std;

void read_file(vector<int> &);
void grade_count(vector<int>, int count_grade[][GRADES_NUM]);
void debug_print(int mode, vector<int>, int count_grade[][GRADES_NUM]);
void grade_print(int count_grade[][GRADES_NUM]);
void grade_output(int count_grade[][GRADES_NUM]);

int main() {
	//init var
	vector<int> num_input;
	int count_grade[2][GRADES_NUM];

	//open file
	read_file(num_input);
	
	//sort data
	sort(num_input.begin(), num_input.end());

#ifdef DEBUG
	debug_print(1, num_input, count_grade);	//print num_input
#endif // DEBUG
	grade_count(num_input, count_grade);

#ifdef DEBUG
	debug_print(2, num_input, count_grade);	//print num_input
#endif // DEBUG
	 
	grade_print(count_grade);
	grade_output(count_grade);
}

void read_file(vector<int>& num_input)
{
	fstream FILE_IN;
	FILE_IN.open(FILE_INPUT_NAME, ios::in);
	int input_tmp;

	while (!FILE_IN.eof())
	{
		FILE_IN >> input_tmp;
		num_input.push_back(input_tmp);
	}

}

void debug_print(int mode, vector<int> num_input, int count_grade[][GRADES_NUM])
{
	cout << "==================" << endl;
	cout << "Debug mode : " << mode << endl;
	switch (mode)
	{
	case 1:
		cout << "num_input.size : " << num_input.size() << endl;
		cout << "num_input : ";
		for (size_t i = 0; i < num_input.size(); i++)
		{
			cout << num_input[i] << " ";
		}
		cout << endl;
		break;

	case 2:
		cout << "count_grade[0] : ";
		for (size_t i = 0; i < GRADES_NUM; i++)
		{
			cout << count_grade[0][i];
		}
		cout << endl;
		cout << "count_grade[1] : ";
		for (size_t i = 0; i < GRADES_NUM; i++)
		{
			cout << count_grade[1][i];
		}
		cout << endl;
		break;

	default:
		break;
	}

	cout << "==================" << endl;

}

void grade_count(vector<int> num_input, int count_grade[][GRADES_NUM]) 
{
	for (int i = 0; i < GRADES_NUM; i++)
	{
		count_grade[0][i] = i;
		count_grade[1][i] = count(num_input.begin(), num_input.end(), i);
	}
}

void grade_print(int count_grade[][GRADES_NUM])
{
	for(size_t i = 0 ; i < GRADES_NUM ; i++){
		cout << count_grade[1][i] <<" grade(s) of " << count_grade[0][i] << endl;
	}
}

void grade_output(int count_grade[][GRADES_NUM]) {
	fstream FILE_OUTPUT;
	FILE_OUTPUT.open(FILE_OUTPUT_NAME, ios::out);
	for (size_t i = 0; i < GRADES_NUM; i++) {
		FILE_OUTPUT << count_grade[1][i] << " grade(s) of " << count_grade[0][i] << endl;
	}
}