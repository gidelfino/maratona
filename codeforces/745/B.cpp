#include <cstdio>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int i1, j1, i2, j2;
int nk[505], mk[505];

int main() {
	int n, m, i, j;
	i2 = j2 = -1;
	i1 = j1 = 10000;
	char pz[505][505];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			scanf(" %c", &pz[i][j]);
			if (pz[i][j] == 'X') {
				i1 = min(i1, i);
				j1 = min(j1, j);
				i2 = max(i2, i);
				j2 = max(j2, j);
			}
		}
	bool YES = true;
	for (i = i1; i <= i2; i++)
		for (j = j1; j <= j2; j++)
			if (pz[i][j] == '.') YES = false;

	if (YES) puts("YES");
	else puts("NO");
	
	return 0;
}
