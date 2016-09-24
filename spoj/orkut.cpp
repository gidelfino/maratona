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
const int N = 35;

int n;
int seen[N], pos[N];
deque<int> top, adj[N];
map<string, int> mp;
string rev[N];

void initialize() {
	top.clear();
	mp.clear();
	for (int i = 0; i < n; i++)
		adj[i].clear();
	memset(seen, 0, sizeof seen);
	memset(pos, 0, sizeof pos);
}

bool dfs(int v) {
	seen[v] = 1;
	for (int w : adj[v]) 
		if (!seen[w] && !dfs(w)) return 0;
		else if (seen[w] && !pos[w]) return 0;
	pos[v] = 1;
	top.pb(v);
	return 1;
}

int main() {
	int c = 1;
	while (true) {
		int i, m;
		char name[20];

		scanf("%d", &n);
		if (n == 0) return 0;
		
		initialize();

		for (i = 0; i < n; i++) {
			scanf("%s", name);
			mp[string(name)] = i;
			rev[i] = string(name);
		}
		
		for (i = 0; i < n; i++) {
			scanf("%s %d", name, &m);
			int v = mp[string(name)];
			for (int j = 0; j < m; j++) {
				scanf("%s", name);
				adj[v].pb(mp[string(name)]);
			}
		}
		
		for (i = 0; i < n; i++)
			if (!seen[i] && !dfs(i))
				break;	
		printf("Teste %d\n", c++);
		if (i < n) { puts("impossivel\n"); continue; }
		for (int w : top) printf("%s ", rev[w].c_str());
		printf("\n\n");
	}
	return 0;
}
