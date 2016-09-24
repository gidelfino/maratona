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
const int N = 105;

int seen[N], d[N];
vector<int> g[N];
pair<string, string> p[110];

void bfs(int o) {
	deque<pii> dq;
	dq.pb(pii(o, 0));
	while (!dq.empty()) {
		pii x = dq.front(); dq.pop_front();
		if (seen[x.fst]) continue;
		d[x.fst] = x.snd; seen[x.fst] = 1;
		for (int w : g[x.fst])
			if (!seen[w]) dq.pb(pii(w, x.snd + 1));
	}
}

bool cmp(int i, int j) {
	if (p[i].fst == p[j].fst) return p[i].snd < p[j].snd;
	return p[i].fst < p[j].fst;
}

int main() {
	int c = 0;
	while (42) {
		map<string, int> mp;
		string nm[N];
		char *name, str[1005];	
		int i, j, a, k, n = 0, id[N];

		scanf("%d", &a);
		getchar();
		if (a == 0) return 0;
		for (i = 0; i < N; i++) g[i].clear();
		for (k = 0; k < a; k++) {
			fgets(str, 1000, stdin);
			int sz = strlen(str);
			str[sz-2] = '\0';
			name = strtok(str, ",");
			vector<int> line;
			while (name != NULL) {
				sz = strlen(name);
				string s = string(name);
				if (name[0] == ' ') s = string(name + 1);
				if (mp.count(s)) line.pb(mp[s]);
				else line.pb(n), mp[s] = n++;
				nm[mp[s]] = s;
				name = strtok(NULL, ",");
			}
			for (i = 0; i < line.size(); i++)
				for (j = i + 1; j < line.size(); j++) {
					g[line[i]].pb(line[j]);
					g[line[j]].pb(line[i]);
				}
		}
		for (k = 0; k < n; k++) {
			id[k] = k; i = 0;
			while(nm[k][i] != ' ') i++;
			p[k].fst = nm[k].substr(i + 1);
			p[k].snd = nm[k].substr(0, i);
		}
		sort(id, id + n, cmp);

		int erdos = -1;
		if (mp.count(string("P. Erdos"))) erdos = mp[string("P. Erdos")];
		memset(seen, 0, sizeof seen);
		memset(d, -1, sizeof d);
		if (erdos != -1) bfs(erdos);
		printf("Teste %d\n", ++c);
		for (k = 0; k < n; k++) {
			i = id[k];
			if (nm[i] == string("P. Erdos")) continue;
			cout << nm[i] << ": ";
			if (d[i] == -1) printf("infinito\n");
			else printf("%d\n", d[i]);
		}
		putchar('\n');
	}
	return 0;
}
