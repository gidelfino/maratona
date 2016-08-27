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

int i, j, k, K, n, tot;
int a[105], b[105];
bool ok;			

int main() {
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]), tot += b[i];
	if(tot%2) { puts("no quotation"); return 0; }
	for(K = 100; K > 1; K--) {
		for(i = 0; i < n; i++) a[i] = b[i];
		k = K; ok = true; i = 0; j = n - 1;
		while(i <= j && ok && k) {
			a[i] -= k; a[j] -= k;
			if(a[i] < 0 || a[j] < 0) ok = false;
			if(!a[i]) i++;
			if(!a[j]) j--;
			k--;
		}
		if(ok && !k) { printf("%d\n", K); return 0; }
	}
	if(tot == 2) puts("1");
	else puts("no quotation");
	return 0;
}
