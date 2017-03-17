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

ll n, k;
vector<ll> pr;

int main() {	
	cin >> n >> k;
	if (n == 1 && k > 1) { puts("-1"); return 0; } 
	for (ll v = 1; v * v <= n; v++) 
		if (n % v == 0) 
			pr.pb(v);
	if (pr.size() >= k) {
		cout << pr[k - 1] << endl;
		return 0; 
	}
	ll sz = pr.size();
	reverse(pr.begin(), pr.end());
	for (ll v : pr) {
		if (v * v == n) continue;
		sz++;
		if (sz == k) { cout << n / v << endl; return 0; } 
	}
	puts("-1");
	return 0;
}
