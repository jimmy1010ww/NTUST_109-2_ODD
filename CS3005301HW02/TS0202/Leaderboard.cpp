#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

//#define DEBUG
#define FILE_NAME "scores.txt"

using namespace std;

//function prototype
void getHighScores(string input_name[], int input_scores[]);

int main() {
	//init var
	string name[3];
	int scores[3];

	getHighScores(name, scores);
	
	//顯示結果
	for (size_t i = 0; i < 3; i++)
	{
		cout << name[i] << endl;
		cout << scores[i] << endl;
	}
}	

void getHighScores(string input_name[], int input_scores[]) {
	
	vector<string> player_name;
	vector<long> player_scores;
	
	string name_tmp;
	int sccore_tmp;

	ifstream file_in;
	file_in.open(FILE_NAME);

	//讀取檔案
	while (!file_in.eof())
	{

		file_in >> name_tmp;
		player_name.push_back(name_tmp);
		file_in >> sccore_tmp;
		player_scores.push_back(sccore_tmp);
	}


#ifdef DEBUG
	cout << "===== Before Sort =====" << endl;
	for (size_t i = 0; i < player_name.size() - 1; i++)
	{
		cout << player_name[i] << endl;
		cout << player_scores[i] << endl;
	}
	cout << "=======================" << endl;
#endif // DEBUG

	//sort
	for (size_t i = 0; i < player_scores.size() - 1; i++)
	{
		for (size_t j = i; j < player_scores.size(); j++)
		{
			if (player_scores[i] < player_scores[j])
			{
				name_tmp = player_name[i];
				player_name[i] = player_name[j];
				player_name[j] = name_tmp;

				sccore_tmp = player_scores[i];
				player_scores[i] = player_scores[j];
				player_scores[j] = sccore_tmp;
			}
		}
	}

#ifdef DEBUG
	cout << "===== After Sort ======" << endl;
	for (size_t i = 0; i < player_name.size() - 1; i++)
	{
		cout << player_name[i] << endl;
		cout << player_scores[i] << endl;
	}
	cout << "=======================" << endl;
#endif // DEBUG

	//儲存陣列
	for (size_t i = 0; i < 3; i++)
	{
		input_name[i] = player_name[i];
		input_scores[i] = player_scores[i];
#ifdef DEBUG
		cout << "input_name[" << i << "]: " << input_name[i] << endl;
		cout << "input_scores[" << i << "]: " << input_scores[i] << endl;
#endif // DEBUG

	}
}

