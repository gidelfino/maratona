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

int main() {
	int n, l, i;
	int a[55], b[55];
	scanf("%d %d", &n, &l);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n; i++) scanf("%d", &b[i]);
	if (n == 1) { puts("YES"); return 0; }
	a[n] = l - a[n - 1] + a[0];
	b[n] = l - b[n - 1] + b[0];
	for (i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
		b[i] = b[i + 1] - b[i];
	}
	a[n - 1] = a[n]; b[n - 1] = b[n];
	for (i = 0; i < n; i++) {
		bool yes = true;
		for (int j = 0; j < n; j++) {
			if (a[j] != b[(j + i) % n]) yes = false;
		}
		if (yes) { puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}
