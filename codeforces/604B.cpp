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
	int n, k, i, j, ans;
	int a[100005];
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	i = 0; j = n-1, ans = 0;
	while(i <= j) {
		if((j+1)/2 + 1 <= k) ans = max(ans, a[j]), j--;
		else { ans = max(ans, a[i] + a[j]); i++; j--; }
		k--;
	}
	printf("%d\n", ans);
	return 0;
}
