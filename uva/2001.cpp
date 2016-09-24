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
const int N = 110;

int n, m, seen[N], dg[N];
deque<int> top, adj[N];
map<string, int> mp;
string rev[N];

void initialize() {
	mp.clear(); top.clear();
	for (int i = 0; i < n; i++)
		adj[i].clear();
	memset(seen, 0, sizeof seen);
	memset(dg, 0, sizeof dg);
}

void solve() {
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
		if (dg[i] == 0) pq.push(-i);
	while(!pq.empty()) {
		int v = -pq.top();
		top.pb(v);
		pq.pop();
		for (int w : adj[v]) {
			dg[w]--;
			if (dg[w] == 0) pq.push(-w);
		}
	}
}

int main() {
	int c = 1;
	while (scanf("%d", &n) != EOF) {
		int i;
		char name[60], a[60], b[60];
		
		initialize();

		for (i = 0; i < n; i++) {
			scanf("%s", name);
			mp[string(name)] = i;
			rev[i] = string(name);
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%s %s", a, b);
			int ia = mp[string(a)];
			int ib = mp[string(b)];
			adj[ia].pb(ib); dg[ib]++;
		}

		solve();

		printf("Case #%d: Dilbert should drink beverages in this order: ", c++);
		for (i = 0; i < top.size(); i++) {
			printf("%s", rev[top[i]].c_str());
			if (i == n - 1) printf(".\n\n");
			else printf(" ");
		}

	}
	return 0;
}
