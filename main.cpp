#include "July 4th week 2014/Minesweeper_Master.h"
//#include "June 2nd week 2013/Pogo.h"

#include<iostream>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
using namespace std;

int main() {
	int T;
	cin >> T;

	FOR(i,1,T)
	{
		cout << "Case #" << i << ": " << endl;
		Minesweeper_Master();
	}
}
