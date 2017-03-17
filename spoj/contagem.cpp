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

int n;
ll ans;
char word[70];

void add(int i) {
	ans += (1ll << (n-i));
}

void solve(int v, int i) {
	if (v == 1) { add(i); return; }
	if (i == n) return;
	if (v == 0 && word[i] == 'a')
		solve(0, i + 1);
	else if (v == 0 && word[i] == 'b')
		solve(0, i + 1), solve(1, i + 1);
}

int main() {
	int c = 1;
	while (scanf("%s", word) != EOF) {
		ans = 0;
		n = strlen(word);
		solve(0, 0);
		printf("Palavra %d\n", c++);
		cout << ans << endl << endl;
	}
	return 0;
}
