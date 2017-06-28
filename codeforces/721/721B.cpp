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
	int n, k;
	vector<string> v[105];
	char s[105];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		v[strlen(s)].pb(string(s));
	}
	scanf("%s", s);
	int sz = strlen(s);
	int ans = 0;
	for (int i = 1; i < sz; i++) {
		ans += v[i].size();
	}
	int mn = ans + 1;
	int mx = ans + v[sz].size();
	printf("%d %d\n", mn + (mn - 1) / k * 5, mx + (mx - 1) / k * 5);

	return 0;
}
