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
const int N = 300;
int acc[N];
deque<pii> adj[N];

int solve(int v, int n, int c) {
	int seen[N], d;
	priority_queue<pii> pq;
	memset(seen, 0, sizeof seen);
	pq.push(pii(0, v));
	int ret = INT_MAX;
	while (!pq.empty()) {
		v = pq.top().snd;
		d = -pq.top().fst;
		pq.pop();
		if (seen[v]) continue;
		if (v < c) { ret = min(ret, d + acc[v]); continue; }
		seen[v] = 1;
		for (pii w : adj[v]) {
			if (!seen[w.fst]) pq.push(pii(-(d + w.snd), w.fst));
		}
	}
	return ret;
}

int main() {
	while (42) {
		int n, m, c, k, i, u, v, p;
		scanf("%d %d %d %d", &n, &m, &c, &k);
		if (n + m + c + k == 0) return 0;

		for (i = 0; i < n; i++) adj[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &p);
			if (u == v + 1) acc[v] = p;
			else if (v == u + 1) acc[u] = p;
			adj[u].pb(pii(v, p));
			adj[v].pb(pii(u, p));
		}
		acc[c - 1] = 0;
		for (i = c - 2; i >= 0; i--)
			acc[i] += acc[i + 1];
		int ans = solve(k, n, c);
		cout << ans << endl;
	}
	return 0;
}
