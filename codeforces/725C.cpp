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
const int N = 109;

char s[N], m[2][N];

int main() {
	int i, j;
	scanf("%s", s);
	int n = strlen(s);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (s[i] != s[j]) continue;
			if (j == i + 1) { puts("Impossible"); return 0; }
			int up, dw;
			if ((j - i) % 2) {
				int x = (j - i - 1) / 2;
				for (int k = 0; k <= x; k++)
					m[0][12 - x + k] = s[i + k];
				for (int k = 0; k < x; k++)
					m[1][12 - k] = s[i + x + 1 + k];
				up = 12 - x - 1;
				dw = 12 - x;
			}
			else {
				int x = (j - i) / 2 - 1;
				for (int k = 0; k <= x; k++)
					m[0][12 - x + k] = s[i + k];
				for (int k = 0; k <= x; k++)
					m[1][12 - k] = s[i + x + 1 + k];
				up = 12 - x - 1;
				dw = 12 - x - 1;
			}
			int ch = 0;
			for (i--; i >= 0; i--) {
				if (up < 0) ch = 1, up = 0;
				m[ch][up] = s[i];
				if (ch) up++; else up--;
			}
			ch = 1;
			for (j++; j < n; j++) {
				if (dw < 0) ch = 0, dw = 0;
				m[ch][dw] = s[j];
				if (ch) dw--; else dw++;
			}
			printf("%s\n%s\n", m[0], m[1]);
			return 0;
		}
	}
	return 0;
}
