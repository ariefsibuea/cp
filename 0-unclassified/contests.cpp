#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main()
{
	int x, k, i;
	bool a[4010];
	memset(a, 0, sizeof(a));
	sf("%d %d", &x, &k);
	while(k--) {
		int kode, tmp;
		sf("%d %d", &kode, &tmp); a[tmp]++;
		if(kode == 1) { sf("%d", &tmp); a[tmp]++; }
	}
	int bol = 0, minim = 0, maxim = 0;
	FOR(i,1,x-1) {
		if(a[i]) {
			minim += bol/2;
			if(bol%2) minim++;
			bol = 0;
		} else { bol++; maxim++; }
	}
	if(!a[x]) minim += bol/2;
	if(bol%2) minim++;
	
	pf("%d %d", minim, maxim); nl;
	
	return 0;
}