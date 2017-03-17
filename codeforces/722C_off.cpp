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

int n, pr[N], nx[N], p[N];
ll v[N], acc[N];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		if (i) acc[i] = acc[i - 1] + v[i];
		else acc[i] = v[i];
	}
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (i = 0; i < n; i++)
		pr[i] = -2, nx[i] = n + 2;

	ll mx = 0;
	vector<ll> ans;
	for (i = n - 1; i >= 0; i--) {
		int j = p[i] - 1;
		int beg, end;
		ans.pb(mx);
		if (nx[j] == j + 1) end = nx[j + 1];
		else end = j;
		if (pr[j] == j - 1) beg = pr[j - 1];
		else beg = j;
		mx = max(mx, acc[end] - (beg?acc[beg - 1]:0ll));
		if (beg - 1 >= 0) nx[beg - 1] = beg;
		if (end + 1 < n) pr[end + 1] = end;
		nx[beg] = end; pr[end] = beg;
	}
	reverse(ans.begin(), ans.end());
	for (ll x : ans) cout << x << endl;
	return 0;
}
