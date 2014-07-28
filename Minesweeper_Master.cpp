#include"Minesweeper_Master.h"

#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define CLR(x) memset((x), 0, sizeof(x))
#define SQR(a) ((a)*(a))
#define DEBUG 1
typedef long long LL;
typedef long double LD;
//typedef pair<int, int> P;
//typedef vector<int> VI;
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
template<typename T> void mini(T&a4, T b4) {
	a4 = min(a4, b4);
}
template<typename T> void maxi(T&a4, T b4) {
	a4 = max(a4, b4);
}

void Minesweeper_Master() {
	int R, C, M;

	cin >> R >> C >> M;

	bool board[50][50] = { { false } };
	int K = max(R, C);
	int N = min(R, C);
	int Empty = R * C - M;
	bool need_transpose = (N == C);

	int current_empty = 0;

	if (Empty == 1) {//always possible case1
		FOR(i,1,R)
		{
			FOR(j,1,C)
			{
				if (i == 1 && j == 1)
					cout << 'c';
				else
					cout << '*';
			}
			cout << endl;
		}
		return;
	}

	else if (N == 1) {//always possible case2
		int mines = 0;
		if (R == 1) {
			FOR(i,1,C)
			{
				if (mines < M) {
					cout << "*";
					mines++;
				} else if (i == C)
					cout << "c";
				else
					cout << ".";
			}
			cout << endl;
		} else
			FOR(i,1,R)
			{
				if (mines < M) {
					cout << "*" << endl;
					mines++;
				} else if (i == R)
					cout << "c" << endl;
				else
					cout << "." << endl;
			}
		return;
	}

	else if ((N == 2 && M % 2 == 1) || Empty == 2 || Empty == 3 || Empty == 5
			|| Empty == 7) {//impossible case
		cout << "Impossible" << endl;
		return;
	}

	else if (Empty >= 2 * N) {
		if (M % N != N - 1) {
			FOR(j,0,K-1)
				FOR(i,0,N-1)
				{
					if (current_empty < Empty) {
						board[i][j] = true;
						current_empty++;
					}
				}
		} else {
			if (Empty == 2 * N + 1) {
				FOR(j,0,K-1)
					FOR(i,0,N-2)
					{
						if (current_empty < Empty) {
							board[i][j] = true;
							current_empty++;
						}
					}

			} else {
				FOR(j,0,K-1)
					FOR(i,0,N-1)
					{
						if (current_empty < Empty
								&& (j != floor((double) Empty / N) - 1
										|| i != N - 1)) {
							board[i][j] = true;
							current_empty++;
						}
					}
			}
		}
	} else {
		if (Empty % 2 == 0) {
			FOR(j,0,1)
				FOR(i,0,int(Empty/2)-1)
				{
					if (current_empty < Empty) {
						board[i][j] = true;
						current_empty++;
					}
				}
		} else {
			FOR(j,0,K-1)
				FOR(i,0,ceil((double)Empty/3)-1)
				{
					if (current_empty < Empty) {
						board[i][j] = true;
						current_empty++;
					}
				}
		}

	}

	if (need_transpose) {
		bool tmp[50][50];
		FOR(j,0,K-1)
			FOR(i,0,N-1)
				tmp[i][j] = board[i][j];
		FOR(j,0,K-1)
			FOR(i,0,N-1)
				board[j][i] = tmp[i][j];
	}

	bool first_zero = true;

	FOR(i,0,R-1)
	{
		FOR(j,0,C-1)
		{
			if (board[i][j])
				if (first_zero) {
					cout << 'c';
					first_zero = false;
				} else
					cout << '.';
			else
				cout << '*';
		}
		cout << endl;
	}

}
