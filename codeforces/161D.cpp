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
const int N = 50005;

deque<int> adj[N];
ll memo[N][505];
ll ans = 0;
int k;
void solve(int v, int p) {
	memo[v][0] = 1;
	for (int w : adj[v]) {
		if (p == w) continue;
		solve(w, v);
		for (int i = 0; i < k; i++)
			ans += memo[v][i] * memo[w][k - i - 1];
		for (int i = 0; i < k - 1; i++)
			memo[v][i + 1] += memo[w][i];
	}
}

int main() {
	int v, w, n, i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &v, &w);
		v--; w--;
		adj[v].pb(w);
		adj[w].pb(v);
	}
	solve(0, 0);
	cout << ans << endl;
	return 0;
}
