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

ll max(ll a, ll b) { return (a > b) ? a : b; }
ll maxx(ll a, ll b, ll c) { return max(max(a, b), c); } 

int main() {
	ll b, d, s, x[3], xx[3];
	cin >> x[0] >> x[1] >> x[2];
	ll n = maxx(x[0], x[1], x[2]);
	ll ans = LLONG_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int k; 
			for (k = 0; k < 3; k++) xx[k] = x[k];
			for (k = i; k < 3; k++) xx[k]--;
			for (k = 0; k <= j; k++) xx[k]--;
			ll mx = maxx(xx[0], xx[1], xx[2]);
			ans = min(ans, 3 * mx - xx[0] - xx[1] - xx[2]);
		}
	}
	cout << ans << endl;
	return 0;
}
