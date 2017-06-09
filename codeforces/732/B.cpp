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

int a[505];

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (i = 1; i < n; i++) {
		if (a[i] + a[i-1] < k) {
			ans += k - (a[i] + a[i-1]);
			a[i] += k - (a[i] + a[i-1]);
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}
