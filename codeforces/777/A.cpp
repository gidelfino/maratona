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
	ll n, nn;
	int x;
	cin >> nn >> x;
	n = nn;
	n = n - n / 3;
	int r = n % 4;
	int bg0 = (r == 3) ? 1 : r;

	n = nn;
	n = n - (n - 2) / 3 - (n > 1);
	r = n % 4;
	int bg1 = (r % 2 == 0) ? 1 : ((r == 1) ? 0 : 2);

	n = nn;
	n = n - (n - 1) / 3 - 1;
	r = n % 4;
	int bg2 = (r == 3) ? 1 : 2 - r;
	if (x == bg0) puts("0");
	else if (x == bg1) puts("1");
	else if (x == bg2) puts("2");
	return 0;
}
