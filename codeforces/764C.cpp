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
const int N = 100005;

int n, u, v, tot;
int cnt[N], cl[N];
vector<int> adj[N];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (i = 0; i < n; i++)
		scanf("%d", &cl[i]);

	for (i = 0; i < n; i++)
		for (int ng : adj[i])
			if (cl[i] != cl[ng]) {
				cnt[i]++; cnt[ng]++;
				tot++;
			}
	for (i = 0; i < n; i++)
		if (cnt[i] == tot) {
			printf("YES\n%d\n", i + 1);
			return 0;
	
		}
	printf("NO\n");
	return 0;
}
