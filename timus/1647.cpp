#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef long double dd;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const dd eps = 10e-9;

inline dd dist(dd x1, dd y1, dd x2, dd y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
inline dd dabs(dd x) { if(x < 0) return -x; return x; }

dd per, area, pxa, pya, pxb, pyb;
dd xa, ya, xb, yb, xc, yc;
dd theta, alpha, beta, AB, AC, BC, dmax;

bool check(dd theta, dd sa, dd sb, dd x, dd y, dd x1, dd y1, dd x2, dd y2) {
	dd sen = sin(theta);
	dd delta = sen * sen * per * per - 4 * sen * area;
	if(delta < 0.0) return false;
	dd da = (sen * per + sqrt(delta)) / (2 * sen);
	dd db = per - da;
	da = dabs(da); db = dabs(db);
	if(da > sa + eps || db > sb + eps) swap(da, db);
	if(da > sa + eps || db > sb + eps) return false;
	dd norma = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	pxa = da * (x1 - x) / norma + x;
	pya = da * (y1 - y) / norma + y; 
	norma = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	pxb = db * (x2 - x) / norma + x;
	pyb = db * (y2 - y) / norma + y; 
	return true;
}

int main() {
	scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &xa, &ya, &xb, &yb, &xc, &yc);
	AB = dist(xa, ya, xb, yb);
	AC = dist(xa, ya, xc, yc);
	BC = dist(xb, yb, xc, yc);
	per = AB + AC + BC; per /= 2.0;
	theta = (AC * AC + BC * BC - AB * AB) / (2.0 * AC * BC); //oposto a AB
	alpha = (AB * AB + AC * AC - BC * BC) / (2.0 * AB * AC); //oposto a BC
	beta  = (AB * AB + BC * BC - AC * AC) / (2.0 * AB * BC); //oposto a AC
	theta = acos(theta); alpha = acos(alpha); beta  = acos(beta );
	area = (xa * yb + ya * xc + xb * yc - xc * yb - yc * xa - xb * ya) / 2.0;
	area = dabs(area);
	//Checa AC e BC
	if(check(theta, AC, BC, xc, yc, xa, ya, xb, yb)) 
		printf("YES\n%.15Lf %.15Lf\n%.15Lf %.15Lf\n", pxa, pya, pxb, pyb);
	//Checa AB e AC 
	else if(check(alpha, AB, AC, xa, ya, xb, yb, xc, yc)) 
		printf("YES\n%.15Lf %.15Lf\n%.15Lf %.15Lf\n", pxa, pya, pxb, pyb);
	//Checa AB e BC
	else if(check(beta, AB, BC, xb, yb, xa, ya, xc, yc))
		printf("YES\n%.15Lf %.15Lf\n%.15Lf %.15Lf\n", pxa, pya, pxb, pyb);
	else puts("NO");
	return 0;
}
