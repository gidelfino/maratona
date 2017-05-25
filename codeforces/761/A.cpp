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

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (!(a + b) || abs(a-b) > 1) puts("NO");
	else puts("YES");
	return 0;
}
