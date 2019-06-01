#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;

	vector<string> board(0);

	for (int j = 0; j < m; j++)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	int count = 0;

	for (int j = 0; j < m - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			//**
			// *
			if (board[j][i] == '.' && board[j][i + 1] == '.' && board[j + 1][i + 1] == '.') count++;
			//**
			//*
			if (board[j][i] == '.' && board[j][i + 1] == '.' && board[j + 1][i] == '.') count++;
			//*
			//**
			if (board[j][i] == '.' && board[j + 1][i] == '.' && board[j + 1][i + 1] == '.') count++;
			// *
			//**
			if (board[j][i + 1] == '.' && board[j + 1][i] == '.' && board[j + 1][i + 1] == '.') count++;
		}
	}

	cout << count << endl;

	//system("pause");
	return 0;
}