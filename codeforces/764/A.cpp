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
	int n, m, z, i;
	scanf("%d %d %d", &n, &m, &z);
	int ans = 0;
	for (i = n; i <= z; i+=n)
		if (i % m == 0) ans++;
	printf("%d\n", ans);
	return 0;
}
