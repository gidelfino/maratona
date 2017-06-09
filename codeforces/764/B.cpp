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
	int n, i, j, a[200005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0, j = n - 1; i < j; i++, j--) {
		if (i % 2 == 0) swap(a[i], a[j]);
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}
