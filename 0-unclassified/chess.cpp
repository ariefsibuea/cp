#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char a[105][105];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%s", a[i]);
	FORS(i, n) FORS(j, m)
		if(a[i][j] == '.') {
			if(i%2 == j%2) a[i][j] = 'W';
			else a[i][j] = 'B';
		}
	FORS(i, n) pf("%s\n", a[i]);
	return 0;
}
