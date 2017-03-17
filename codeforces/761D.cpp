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
const int N = 100005;

int n, p[N], inv[N];
ll l, r;
ll a[N], b[N];

int main() {
	int i;
	cin >> n >> l >> r;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]), p[i]--;
	for (i = 0; i < n; i++)
		inv[p[i]] = i;
	b[inv[0]] = l;
	ll bef = b[inv[0]] - a[inv[0]];
	for (i = 1; i < n; i++) {
		int j = inv[i];
		b[j] = a[j] + bef + 1;
		if (b[j] < l) b[j] = l;
		if (b[j] > r) { printf("-1\n"); return 0; }
		bef = b[j] - a[j];
	}
	
	for (i = 0; i < n; i++)
		cout << b[i] << " ";
	putchar('\n');
	return 0;
}
