#include <iostream>
using namespace std;

int board[16];
int cnt;

void	print_board(int n)
{
	for (int i = 0; i < n; i++)
		cout << board[i] << " ";
	cout << "\n";
}

int		is_attackable(int lev, int n)
{
	int nowy = board[lev];
	int nowx = lev;

	//print_board(n);
	for (int i = 0; i < lev; i++)
	{
		if (board[i] == nowy)
			return (1);
		if ((board[i] + i) == (nowy + nowx))
			return (1);
		if ((board[i] - i) == (nowy - nowx))
			return (1);
	}
	return (0);
}

void	nqueen(int lev, int n)
{

	if (lev == n)
	{
		cnt++;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		board[lev] = i;
		if (is_attackable(lev, n) == 0)
			nqueen(lev + 1, n);
	}
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		board[i] = -1;
	cnt = 0;
	nqueen(0, n);
	cout << cnt;
}
