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
const int N = 100009;

map<ll, set<pii> > mp;
vector<ll> pt;
int n, k,a[N];
ll acc[N];

ll labs(ll x) { if (x > 0) return x; return -x; }

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		acc[i] += (i?acc[i-1]:0) + (ll) a[i];
		if (mp.count(acc[i])) mp[acc[i]].insert(pii(i, 0));
		else {
			int sz = mp[acc[i]].size();
			mp[acc[i]].insert(pii(i, sz));
		}
	}
	ll exp = 1;
	while (exp <= (ll)10e14) {
		pt.pb(exp);
		exp *= (ll)k;
		if (k == 1 || k == -1) break;
	}
	if (k == -1) pt.pb(-1);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll bf = i?acc[i-1]:0;
		for (ll x : pt) {
			if (!mp.count(bf + x)) continue;
			auto it = mp[bf + x].lower_bound(pii(i, 0));
			if (it == mp[bf + x].end()) continue;
			ans += (ll)mp[bf + x].size() - (ll)(*it).snd;
		}
	}	
	cout << ans << endl;
	return 0;
}
