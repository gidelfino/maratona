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
const int N = 200009;

deque<pii> ed, took;
deque<int> comp, both, cp[N];
int n, m, s, t, ds, dt;
int seen[N], id[N], sz[N], eds[N], edt[N], vs[N], vt[N];

int find(int v) {
	if (v == id[v]) return v;
	return id[v] = find(id[v]);
}

void join(int a, int b) {
	int u = find(a), v = find(b);
	if (u == v) return;
	took.pb(pii(a, b));
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v]; id[v] = u;
}

int main() {
	int i, u, v, edge = 0;
	scanf("%d %d", &n, &m);
	for (i =  0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		ed.pb(pii(u, v));
	}
	scanf("%d %d %d %d", &s, &t, &ds, &dt);
	s--; t--;
	for (i = 0; i < n; i++)
		id[i] = i, sz[i] = 0;
	for (i = 0; i < m; i++) {
		if (ed[i].fst == s) eds[ed[i].snd] = 1;
		if (ed[i].snd == s) eds[ed[i].fst] = 1;
		if (ed[i].fst == t) edt[ed[i].snd] = 1;
		if (ed[i].snd == t) edt[ed[i].fst] = 1;
		if (ed[i].fst == s || ed[i].fst == t || ed[i].snd == s || ed[i].snd == t) continue; 
		join(ed[i].fst, ed[i].snd);
	}
	ed.clear();
	for (i = 0; i < n; i++) {
		v = find(i);
		if (i == s || i == t) continue;
		cp[v].pb(i);
		if (seen[v]) continue;
		seen[v] = 1;
		comp.pb(v);
	}
	for (int c : comp) {
		int ns = 0, nt = 0;
		for (int w : cp[c]) {
			if (eds[w]) { ns++; vs[c] = w; }
			if (edt[w]) { nt++; vt[c] = w; }
		}
		cp[c].clear();
		if (!ns && !nt) { puts("No"); return 0; }
		if (!ns) { dt--; join(vt[c], t); }
		if (!nt) { ds--; join(vs[c], s); }
		if (ds < 0 || dt < 0) { puts("No"); return 0; }
		if (ns && nt) both.pb(c);	
	}
	edge = eds[t] + edt[s];
	if ((both.empty() && !edge) || (both.empty() && (!ds || !dt))) { puts("No"); return 0; }
	else if (both.empty() && edge) { ds--; dt--; join(s, t); }	
	else { 
		ds--; join(vs[both[0]], s);
		dt--; join(vt[both[0]], t);
		if (ds < 0 || dt < 0) { puts("No"); return 0; }
		both.pop_front();

		for (int c : both) {
			if (ds > dt) { ds--; join(vs[c], s);	}
			else { dt--; join(vt[c], t); }
			if (ds < 0 || dt < 0) { puts("No"); return 0; }
		}
	}
	puts("Yes");
	for (pii e : took) printf("%d %d\n", e.fst + 1, e.snd + 1);
	return 0;
}
