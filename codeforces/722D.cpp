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

int main() {
	int i, n;
	ll v;
	set<ll> st;
	priority_queue<ll> pq;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> v;
		st.insert(v);
		pq.push(v);
	}

	while (42) {
		v = pq.top(); pq.pop();
		ll x = v;
		while (v) {
			v /= 2;
			if (!st.count(v)) break;
		}
		if (!v) break;
		st.erase(st.find(x));
		st.insert(v);
		pq.push(v);
	}
	for (ll x : st) cout << x << " ";
	putchar('\n');
	return 0;
}
