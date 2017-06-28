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
	int n; char c;
	scanf("%d", &n);
	int b = 0, k = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		if (c == 'B') b++;
		else { 
			if (b > 0) {
				k++;
				ans.pb(b); 
				b = 0;
			}
		}
	}
	if (c == 'B') k++, ans.pb(b);
	printf("%d\n", k);
	for (int v : ans) printf("%d ", v);
	putchar('\n');
	return 0;
}
