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

int v[100005];

int main() {
	int n;
	scanf("%d", &n);
	n++;
	for (int i = 2; i <= n; i++) {
		if (v[i]) continue;
		for (int j = i; j <= n; j += i)
			v[j] = (j == i) ? 1 : 2;
	}
	printf("%d\n", (n <= 3) ? 1 : 2);
	for (int i = 2; i <= n; i++)
		printf("%d ", v[i]);
	putchar('\n');
	return 0;
}
