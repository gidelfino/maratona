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
	char s[55];
	scanf("%s", s);
	int n = strlen(s);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		bool equal = true;
		for (int j = 0; j < n && equal; j++) {
			if (s[(j + i) % n] != s[j]) equal = false;
		}
		if (!equal) ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}
