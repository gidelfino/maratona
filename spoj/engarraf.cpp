#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 110;

deque<pii> adj[N];

ll solve(int v, int end) {
	int seen[N];
	ll d;
	memset(seen, 0, sizeof seen);
	priority_queue<pii> pq;
	pq.push(pii(-0, v));
	while (!pq.empty()) {
		v = pq.top().snd;
		d = -pq.top().fst;
		pq.pop();
		if (seen[v]) continue;
		seen[v] = 1;
		if (v == end) return d;
		for (pii w : adj[v])
			if (!seen[w.fst]) 
				pq.push(pii(-(w.snd + d), w.fst));
	}
	return -1;
}

int main() {
	int n, m, i, v, u, t, s, d;
	while (42) {
		scanf("%d %d", &n, &m);
		if (n + m == 0) return 0;
		for (i = 0; i < n; i++) adj[i].clear();
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &t);
			u--; v--;
			adj[u].pb(pii(v, t));
		}

		scanf("%d %d", &s, &d);
		s--; d--;
		ll ans = solve(s, d);
		cout << ans << endl;
	}
	return 0;
}
