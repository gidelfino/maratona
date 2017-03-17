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
const int N = 55;

int n, m;
int memo[N][2][2][2];
char key[N][N];

int solve(int i, bool spc, bool low, bool dig) {
	if (i == n) return ((spc && low && dig) ? 0 : 10000);
	int &mem = memo[i][spc][low][dig];
	if (mem != -1) return mem;
	int ans = INT_MAX;
	for (int k = 0; k < m; k++) {
		char c = key[i][k];
		int val = min(k, m - k);
		if (c >= 'a' && c <= 'z') ans = min(ans, val + solve(i + 1, spc, 1, dig));
		if (c == '#' || c == '*' || c == '&') ans = min(ans, val + solve(i + 1, 1, low, dig));
		if (c >= '0' && c <= '9') ans = min(ans, val + solve(i + 1, spc, low, 1));
	}
	return mem = ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%s", key[i]);
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}

