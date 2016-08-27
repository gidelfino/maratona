#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
    
int n;
int f[32];
pii memo[32][32];

pii solve (int i, int ult) {
    printf("State(%d,%d)\n", i, ult);
    if (i == n-1) return make_pair(0,(f[i]-f[ult])*20);
    pii &m = memo[i][ult];
    if (m.first != -1) return m;
    
    pii ans = make_pair(INT_MAX, f[i]-f[ult]*20);
    for (int k = i + 1; k < n; k++) {
       pii s = solve(k, i + 1);
       printf("State(%d,%d) solve(%d, %d) = (%d,%d)\n", i, ult, k, i + 1, s.first, s.second);           
       if (max(s.first + (f[k]-f[i])*4 + 10, s.second + (f[k]-f[i])*4 + 10) < max(ans.first, ans.second)){
          ans.first = s.first + (f[k]-f[i])*4 + 10;
          ans.second = max(ans.second, s.second + (f[k]-f[i])*4 + 10); 
       }
       printf("ans.first=%d\n", ans.first);
    }
    return m = ans;     
}

int main () {
    while (true) {
        scanf("%d", &n);
        if (n == 0) return 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                memo[i][j].first = -1;


        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            printf("uhasuhsahuashuashuhuashusahusahuhuas\n");        
            pii r = solve(i, 0);
            printf("%d %d - ret = (%d,%d)\n", i, 0, r.first, r.second);            
            ans = min(ans, max(r.first, r.second));             
        }
        printf("%d\n", ans);    
    }
    return 0;
}
