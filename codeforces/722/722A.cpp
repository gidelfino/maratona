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
	int tp, h, m, hc, mc, m1, m2, h1, h2;
	scanf("%d", &tp);
	scanf("%d:%d", &h, &m);
	hc = h; mc = m;
	m2 = mc % 10; mc /= 10; m1 = mc % 10;
	h2 = hc % 10; hc /= 10; h1 = hc % 10;
	if (m < 0 || m > 59)
		m1 = 0;
	if (tp == 12 && h == 0) h2 = 1;
	else if (tp == 12 && h > 12) { 
		if (h2 == 0) h1 = 1;
		else h1 = 0;
	}
	else if (tp == 24 && h > 23) h1 = 0;
	printf("%d%d:%d%d\n", h1, h2, m1, m2);
	return 0;
}
