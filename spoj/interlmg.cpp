#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, double> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1005;

struct Edge {
	int u, v;
	double d;
	Edge() {}
	Edge(int u, int v, double d) : u(u), v(v), d(d) {}
	bool operator <(const Edge x) {
		if (x.d == d) return u < x.u;
		return d < x.d;
	}
};

deque<Edge> ed;
int n, sz[N], id[N];
pii ct[N];

double dist(pii a, pii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void initialize() {
	for (int i = 0; i < n; i++)
		id[i] = i, sz[i] = 0;
	ed.clear();
}

int find(int v) {
	if (v == id[v]) return v;
	return id[v] = find(id[v]);
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b]; id[b] = a;
}

int main() {
	while (42) {
		int i, j;
		scanf("%d", &n);
		if (n == 0) return 0;

		initialize();
		for (i = 0; i < n; i++) {
			double a, b;
			scanf("%lf %lf", &a, &b);
			ct[i] = pii(a, b);
		}

		for (i = 0; i < n; i++) 
			for (j = i + 1; j < n; j++) 
				ed.pb(Edge(i, j, dist(ct[i], ct[j])));

		sort(ed.begin(), ed.end());	
		double ans = 0.0;
		for (Edge e : ed) {
			if (find(e.u) == find(e.v)) continue;
			ans = e.d;
			join(e.u, e.v);
		}
		printf("%.4f\n", sqrt(ans));
	}
	return 0;
}
