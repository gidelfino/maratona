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
	char s1[15], s2[15], s[15];
	int n;
	scanf("%s %s %d", s1, s2, &n);
	printf("%s %s\n", s1, s2);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		if (!strcmp(s, s1)) scanf("%s", s1);
		else scanf("%s", s2);
		printf("%s %s\n", s1, s2);
	}
	return 0;
}
