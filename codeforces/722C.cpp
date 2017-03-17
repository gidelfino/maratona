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
const int N = 100009;

int n, p[N];
ll v[N], acc[N];

struct No {
	int x, y, ind;
	No() {}
	No(int x, int y, int ind) : x(x), y(y), ind(ind) {}
	bool operator <(No no) const{
		if (no.x == x) {
			if (no.y == y) 
				return no.ind < ind;
			return no.y > y;
		}
		return no.x > x;
	}

};

ll ACC(int x) {
	if (x) return acc[x - 1];
	return 0ll;
}

int main() {
	int i, j, val;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		cin >> v[i];
		if (i) acc[i] = acc[i-1] + v[i];
		else acc[i] = v[i];
	}
	set<No> st;
	set<pii> sm;
	st.insert(No(0, n - 1, 0));
	sm.insert(pii(acc[n - 1], 0));
	int c = 1;
	for (i = 0; i < n; i++) {
		scanf("%d", &val); val--;
		auto it = st.lower_bound(No(val, val, 0));
		if (it == st.end() || it->x > val) it--;
		int x = it->x, y = it->y, ind = it->ind;
		st.erase(it);
		auto it2 = sm.find(pii(acc[y] - ACC(x), ind));
		sm.erase(it2);
		
		if (val - 1 >= x) { 
			st.insert(No(x, val - 1, c));
			sm.insert(pii(acc[val - 1] - ACC(x), c));
			c++;
		}
		if (y >= val + 1) {
			st.insert(No(val + 1, y, c));
			sm.insert(pii(acc[y] - ACC(val + 1), c));
			c++;
		}
		if (sm.empty()) puts("0");
		else {
			auto it3 = sm.end(); it3--;
			cout << it3->fst << endl;
		}
	}
	return 0;			
}
