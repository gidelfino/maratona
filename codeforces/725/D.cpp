#include <bits/stdc++.h>
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
//#include <set>
//#include <queue>
//#include <iostream>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

struct Team {
	ll t, w;
	Team() {}
	Team(ll t, ll w) : t(t), w(w) {}
	bool operator<(Team x) const{
		ll d = x.w - x.t;
		if (d == w - t) {
			return x.t < t;
		}
		return d < w - t;
	}
};

multiset<pii> st;
priority_queue<Team> pq;
ll T, W, t, w;
int n;


int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld %lld", &t, &w);
		if (!i) T = t, W = w;
		else st.insert(pii(t, w));
	}
	ll ans = n + 1;
	while (T >= 0 && ans > 1) {
		for (auto it = st.lower_bound(pii(T + 1, 0)); it != st.end(); ) {
			pq.push(Team(it->fst, it->snd));
			auto it2 = it; ++it;
			st.erase(it2);
		}
		ans = min(ans, (ll)pq.size() + 1);
		if (!pq.empty()) {
			Team x = pq.top(); pq.pop();
			T -= (x.w - x.t + 1);
		}
	}

	cout << ans << endl;	

	return 0;
}
