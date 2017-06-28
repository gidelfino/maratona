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

int main(){
	int n, v[200005];
	int mn = 2000000000;
	set<int> ls;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		mn = min(mn, v[i]);
	}
	for (int i = 0; i < n; i++) {
		if (mn == v[i]) ls.insert(i), ls.insert(i + n);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = ls.lower_bound(i);
		ans = max(ans, (ll) n * mn + (*it) - i);
	}
	printf("%lld\n", ans);
	return 0;
}
