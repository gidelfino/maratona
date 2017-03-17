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

vector<ll> usb, ps;
ll a, b, c;
int m;

int main() {
	int i, j;
	char type[10];
	int v;
	scanf("%d %d %d %d", &a, &b, &c, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %s", &v, type);
		if (!strcmp(type, "USB")) usb.pb((ll)v);
		else ps.pb((ll)v);

	}
	sort(usb.begin(), usb.end());
	sort(ps.begin(), ps.end());
	ll nt = 0, np = 0;
	for (i = 0; i < usb.size() && a; i++)
	{ 	nt++; np += usb[i]; a--; }
	for (j = 0; j < ps.size() && b; j++)
	{	nt++; np += ps[j]; b--; }
	vector<ll> rt;
	for (; i < usb.size(); i++) rt.pb(usb[i]);
	for (; j < ps.size(); j++) rt.pb(ps[j]);
	sort(rt.begin(), rt.end());
	i = 0;
	while (c && i < rt.size()) {
		nt++; np += rt[i]; i++; c--;
	}
	cout << nt << " " << np << endl;
	return 0;
}
