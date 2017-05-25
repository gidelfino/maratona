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
	ull n;
	char c;
	scanf("%lld%c", &n, &c);
	ull f, k, ans = 0;
	if (n % 2) {
		if (!((n - 1) % 4)) f = (n - 1) / 2, k = (n - 1) / 4;
		else if(!((n - 3) % 4)) f = (n - 2) / 2, k = (n - 3) / 4;
	}
	else {
		if (!((n - 2) % 4)) f = n / 2, k = (n - 2) / 4;
		else if (!((n - 4) % 4)) f = (n - 2) / 2, k = (n - 4) / 4;
		ans++;
	}
	ans += f * 6 + 4 * k;
	if (c >= 'd') ans += 'f' - c + 1;
	else ans += 3 + c - 'a' + 1;

	printf("%lld\n", ans);

	return 0;
}
