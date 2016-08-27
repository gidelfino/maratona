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
const int N = 100005;

ll sm[N], f[N];
ll dp[N];
vector<pii> st;

ll xcont(int j, int k) {
	//aqui é com relacao aos trabalhadores apenas
	ll a = sm[j] - sm[k];
	ll b = sm[j+1] - sm[k+1];
	return (ll) (ceil((double) a/b));
}

int main() {
	int i, j, n, m;
	ll x;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%lld", &x);
		if(i) sm[i] = sm[i-1];
		sm[i] += x;
	}
	for(j = 0; j < m; j++) scanf("%lld", &f[j]);
	st.pb(pii(-100000000000000, 1));
	for(i = 2; i <= n - 1; i++) {
		while(xcont(st.back().snd, i) <= st.back().fst) {
			//printf("Tirei %d\n", st.back().snd);
			st.pop_back();
		}
	//	printf("Reta (%d) %d.x - %d\n", i, sm[i+1], sm[i]);
	//	printf("Ponto de encontro (%d,%d) %lld\n", st.back().snd, i, xcont(st.back().snd, i));
		st.pb(pii(xcont(st.back().snd, i), i));
	}
	//puts("=============================");
	for(j = 1; j < m; j++) {
		int l = 0, r = st.size() - 1;
		ll x = f[j-1] / f[j];
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(x <= st[m].fst) r = m - 1;
			else l = m;
		}
		i = st[l].snd;
	//	printf("Carro %d Found Reta %d\n", j, i);
		dp[j] = sm[i+1] * f[j-1] - sm[i] * f[j];
		dp[j] = max(dp[j], sm[1]);
	//	printf("DP[%d] = %lld\n", j, dp[j]);
		dp[j] += dp[j-1];
	}
	printf("%lld\n", dp[m-1] + sm[n]*f[m-1]);
	return 0;
}
