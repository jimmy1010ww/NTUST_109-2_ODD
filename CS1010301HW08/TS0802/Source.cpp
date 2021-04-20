#include <iostream>
#include <vector>

using namespace std;

void clean_matrix(vector <vector<int>>&,int,int);

int main() {

	int m1, n1,m2,n2;
	cin >> m1 >> n1 >> m2 >> n2;
	vector <vector<int>> matrix_1(m1, vector<int>(n1));
	vector <vector<int>> matrix_2(m2, vector<int>(n2));
	vector <vector<int>> ans;
	clean_matrix(matrix_1, m1, n1);
	clean_matrix(matrix_2, m2, n2);

	for (size_t i = 0; i < m1; i++)
	{
		for (size_t j = 0; j < n1; j++)
		{
			cin >> matrix_1[i][j];
		}
	}
	for (size_t i = 0; i < m2; i++)
	{
		for (size_t j = 0; j < n2; j++)
		{
			cin >> matrix_2[i][j];
		}
	}
	//3*2 2*3
	if (n1 == m2)
	{
		ans.resize(m1, vector<int>(n2));
		for (size_t i = 0; i < m1; i++)
		{
			for (size_t j = 0; j < n2; j++)
			{
				for (size_t k = 0; k < n1; k++)
				{
					ans[i][j] += matrix_1[i][k] * matrix_2[k][j];
				}
			}
		}

		for (size_t i = 0; i < m1; i++)
		{
			for (size_t j = 0; j < n2 - 1; j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << ans[i][n2 - 1] << endl;
		}

	}
	else
	{
		cout << "Matrix multiplication failed." << endl;
	}
}

void clean_matrix(vector <vector<int>>& in,int m,int n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			in[i][j] = 0;
		}
	}
}