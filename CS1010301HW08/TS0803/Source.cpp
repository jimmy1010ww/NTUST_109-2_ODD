#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

//#define DEBUG
#define COMMAND_COUNT 2

//define TYPE BYTES
#define INT 4
#define SHORT 2
#define CHAR 1

using namespace std;

//Global var
string command_list[COMMAND_COUNT] = { "Set","Get" };

void Set(int pos, string type,vector<int>& buffer)
{

	if (type == "int")
	{
		int dest = pos + INT - 1;
		if (dest >= buffer.size())
		{
			cout << "Violation Access." << endl;
			dest = buffer.size() - 1;
		}
		
		unsigned int value;
		cin >> value;
		for (size_t i = pos; i <= dest; i++)
		{

			buffer[i] = value % 256;
			value /= 256;
			//cout << "buffer :" << buffer[i] << endl;
			//cout << "value :" << value << endl;
		}

	}
	else if (type == "short")
	{
		int dest = pos + SHORT - 1;
		if (dest >= buffer.size())
		{
			cout << "Violation Access." << endl;
			dest = buffer.size() - 1;
		}
		
		short value;
		cin >> value;
		for (size_t i = pos; i <= dest; i++)
		{
			buffer[i] = value % 256;
			value /= 256;
			//cout << "buffer :" << buffer[i] << endl;
			//cout << "value :" << value << endl;
		
		}
	}
	else if (type == "char")
	{
		int value;
		cin >> value;

		buffer[pos] = value;
	}
	else if (type == "String")
	{
		string value;
		getline(cin, value);

		value[ value.size()] = '\0';

		int dest_size = pos + value.size() - 1;
		if (dest_size >= buffer.size())
		{
			cout << "Violation Access." << endl;
			dest_size = buffer.size() - 1;
		}
		
		for (size_t i = pos; i <= dest_size; i++)
		{
			buffer[i] = (char)value[i];
		}

	}


#ifdef DEBUG
	cout << pos << "|" << type << "|" << value << endl;
#endif
}

void Get(int pos, string type, vector<int>& buffer)
{
	if (type == "int")
	{
		int dest = pos + INT - 1;
		if (dest >= buffer.size())
		{
			cout << "Violation Access." << endl;
		}
		else
		{
			unsigned int tmp = 0;
			for (size_t i = pos; i <= dest; i++)
			{
				if (i == dest)
				{
					tmp += buffer[i];
				}
				else
				{
					tmp += buffer[i] * 256;
				}
			}
			cout << tmp << endl;
		}
	}
	else if (type == "short")
	{
		int dest = pos + SHORT - 1;
		if (dest >= buffer.size())
		{
			cout << "Violation Access." << endl;
		}
		else
		{
			unsigned int tmp = 0;
			for (size_t i = pos; i <= dest; i++)
			{
				if (i == dest)
				{
					tmp += buffer[i];
				}
				else
				{
					tmp += buffer[i] * 256;
				}
			}
			cout << tmp << endl;
		}
	}
	else if (type == "char")
	{
		int c;
		c = buffer[pos];
		cout << c << endl;
	}
	else if (type == "String")
	{
		string str = "";
		for (size_t i = pos; i < buffer.size(); i++)
		{
			if (buffer[i] != 0)
			{
				str += buffer[i];
			}
		}
		cout << str << endl;
	}
#ifdef DEBUG
	cout << pos << "|" << type << endl;
#endif
}

int main() 
{
	/*
	int size, command_num;
	cin >> size >> command_num;
	cout << size << "|" << command_num << "|";
	string line = "";
	for (size_t i = 0; i < command_num; i++)
	{
		getline(cin, line);
		cout << line << "|";
	}
	*/
	
	int size, command_num, pos;
	string command, type, value;
	cin >> size >> command_num;
	
	int buffer_size = size;
	vector <int>buffer(buffer_size);

	for (size_t i = 0; i < command_num; i++)
	{
		bool break_flag = false;
		cin >> command;
		for (size_t j = 0; j < COMMAND_COUNT; j++)
		{
			if (command == command_list[j])
			{
				char c;	//remove white space
				switch (j)
				{
				case 0:
					cin >> pos >> type;
					c = getchar();
	
					if (pos < 0 || pos >= size)
					{
						cout << "Violation Access." << endl;
					}
					else
					{
						Set(pos, type, buffer);
						break_flag = true;
					}
					break;
				case 1:
					cin >> pos >> type;
					c = getchar();

					if (pos < 0 || pos >= size)
					{
						cout << "Violation Access." << endl;
					}
					else
					{
						Get(pos, type, buffer);
						break_flag = true;
					}
					break;
				default:
					break;
				}

				if (break_flag)
				{
					break;
				}
			}
		}

	}
	
}