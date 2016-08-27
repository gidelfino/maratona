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
	double n, r, pi = acos(-1.0);
	scanf("%lf %lf", &n, &r); n /= 2.0;
	double ang = 2.0 * ((pi/2.0) - asin(n / r));
	double base = 2.0 * sqrt(r * r - n * n);
	double p = ((r * r) /2.0) * ang;
	if(r <= n) printf("%.3f\n", pi * r * r);
	else if(r >= sqrt(2 * n * n)) printf("%.3f\n", 2 * n * 2 * n);
	else printf("%.3f\n", pi * r * r - 4 * p + 2 * (base * n));
	return 0;
}
