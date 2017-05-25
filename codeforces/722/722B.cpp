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

bool is(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return true;
	return false;
}

int main() {
	int n, i, j, p[110];
	char line[110], *word;
	int flag = 1;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	getchar();
	for (i = 0; i < n; i++) {
		fgets(line, 200, stdin);
		int sz = strlen(line);
		int cont = 0;
		for (j = 0; j < sz - 1; j++) {
			if (is(line[j])) cont++;
		}
		if (cont != p[i]) flag = 0;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}
