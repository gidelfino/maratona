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
	int n, i;
	char s[300];
	scanf("%d %s", &n, s);
	int in = 0, nin = 0, sz = 0, st = 0, mx = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == '_') { 
			if (st) {
				if (!in) mx = max(mx, sz);
				sz = 0; st = 0;
			}
		}
		else if (s[i] == '(') { 
			mx = max(mx, sz);
			in = 1; sz = 0; st = 0;
		}
		else if (s[i] == ')') { 
			in = 0; sz = 0; st = 0;
		}
		else { 
			st = 1, sz++;
			if (in && !i) nin++;
			else if (in && (s[i-1] == '_' || s[i-1] == '(')) nin++;
		}
	}
	mx = max(mx, sz);
	printf("%d %d\n", mx, nin);



	return 0;
}
