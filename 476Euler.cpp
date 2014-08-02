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

double Problem_476(int n) {

	double r1, r2, r3;

	double area_sum = 0;
	int count = 0;

	double sina_, sinb_;
	double a, b, c, s;
	FORD(ci,n-1,1)
		FORD(bi,ci,1)
			FORD(ai,bi,1)
			{
				a = ai, b = bi, c = ci;

				if (ai + bi <= ci || ai + bi > n)
					continue;

				s = (a + b + c) / 2;
				r1 = sqrt((s - a) * (s - b) * (s - c) / s);

				sina_ = sqrt((1 - (b * b + c * c - a * a) / (2 * b * c)) / 2);
				sinb_ = sqrt((1 - (a * a + c * c - b * b) / (2 * a * c)) / 2);

				r2 = r1 * (1 - sina_) / (1 + sina_);

				r3 = max(r1 * (1 - sinb_) / (1 + sinb_),
						r2 * (1 - sina_) / (1 + sina_));

				area_sum += M_PI * (r1 * r1 + r2 * r2 + r3 * r3);
				count++;

			}

	return area_sum / count;


}

