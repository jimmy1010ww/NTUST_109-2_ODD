#ifndef NumberGame_H
#define NumberGame_H 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NumberGame
{
public:
	int A;
	vector <int> s;
	vector <int> valid;
	string input;
	string FileInName;
	void SetInput(int in) { A = in; }
	void ProcessInput() { input = to_string(A); }
	void SetFileName(string in) { FileInName = in;}
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};

#endif