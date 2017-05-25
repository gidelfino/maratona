#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1005;
//Bit Solution

int n;
int ans[N], go[N];

void query(int sz) {
	printf("%d\n", sz);
	for (int i = 1; i <= n; i++)
		if (go[i]) printf("%d ", i);
	printf("\n");
	fflush(stdout);
}

int main() {
	int i, bit;
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
		ans[i] = INT_MAX;
	bit = 1;
	while (42) {
		if (bit > n) break;
		for (int k = 0; k < 2; k++) {
			int sz = 0;
			for (i = 1; i <= n; i++) 
				if ((k && i&bit) || (!k && !(i&bit))) 
					go[i] = 1, sz++;
			
			query(sz);
			int mn;
			for (i = 1; i <= n; i++) {
				scanf("%d", &mn);
				if (go[i]) go[i] = 0;
				else ans[i] = min(ans[i], mn);
			}
		}
		bit *= 2;
	}
	printf("-1\n");
	for (i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
