#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Form
{
private:

public:
	struct word {
		string origin_word;
		string upper;
		string lower;
		int count[26] = {0};
	};
	word myWord;
	string FileName;
	void SetInputWord(string inputWord) { myWord.origin_word = inputWord; } // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName) { FileName = fileName; } // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
