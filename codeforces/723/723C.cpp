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
const int N = 2009;

int n, m, p[N];
deque<int> pos[N], can;

int main() {
	int i;
	scanf("%d %d", &n, &m);
	int x = n / m;
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		if (p[i] > m) can.pb(i);
		else { 
			if (pos[p[i]].size() == x) can.pb(i);
			else pos[p[i]].pb(i);
		}
	}
	
	int ch = 0;
	for (i = 1; i <= m; i++) {
		while (pos[i].size() < x) {
			p[can.front()] = i;
			pos[i].pb(can.front());
			can.pop_front();
			ch++;
		}
	}

	printf("%d %d\n", x, ch);
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	putchar('\n');

	return 0;
}
