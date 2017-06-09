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
	int k, r;
	scanf("%d %d", &k, &r);
	if (k % 10 == 0) { puts("1"); return 0; }
	int n = 0, v = 0;
	while (true) {
		v += k; n++;
		if (v % 10 == r) break;
		if (v % 10 == 0) break;
	}
	printf("%d\n", n);
	return 0;
}
