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

int n, t;
int v[55], vn[55];

int main() {
	int i; char x;
	scanf("%d %d", &n, &t);
	for (i = 0; i < n; i++) {
		scanf(" %c", &x);
		v[i] = (x == 'G');
		vn[i] = v[i];
	}
	while (t--) {
		for (i = 0; i < n - 1; i++) {
			if (!v[i] && v[i+1]) { 
				vn[i] = v[i+1];
				vn[i+1] = v[i];
				i++;
			}
			else 
				vn[i] = v[i], vn[i+1] = v[i+1];
		}
		for (i = 0; i < n; i++)
			v[i] = vn[i];
	}
	for (i = 0; i < n; i++)
		printf("%c", (v[i]?'G':'B'));
	putchar('\n');
	return 0;
}
