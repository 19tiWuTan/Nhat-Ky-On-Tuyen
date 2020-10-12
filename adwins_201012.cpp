/// task : dem cap hinh chu nhat co chung it nha 1 o
// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "adwins"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 2e5 + 1;
struct rect{
    int xa, ya, xb, yb;
};

struct point{
    int x, y, t;
};
point p[N * 2], q[N * 2];

pii linex[N * 2], liney[N * 2];

rect a[N];
int n, fenx[N * 2], feny[N * 2], fenp[N * 2], fenq[N * 2];
void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i].xa >> a[i].ya >> a[i].xb >> a[i].yb;
}

void upd(int fen[], int p, int v){
    for (int i = p; i <= n * 2; i += i&-i)
        fen[i]+= v;
}

int get (int fen[], int p){
    int ret = 0;
    for (int i = p; i > 0; i-= i&-i)
        ret+= fen[i];
    return ret;
}

void upd_(int p, int v){
    for (int i = p; i > 0; i-= i&-i)
        fenq[i]+= v;
}

int get_(int p){
    int ret = 0;
    for (int i = p; i <= n * 2; i+= i&-i)
        ret+= fenq[i];
    return ret;
}


void compress(){
    int cntx = 0, cnty = 0;
    int i = 1;
    while (i <= n * 2){
        int j = i; cntx++;
        while (i < n * 2 && linex[i+1].fi == linex[j].fi)
            linex[++i].fi = cntx;
        linex[j].fi = cntx;
        i++;
    }

    i = 1;
    while (i <= n * 2){
        int j = i; cnty++;
        while (i < n * 2 && liney[i+1].fi == liney[j].fi)
            liney[++i].fi = cnty;
        liney[j].fi = cnty;
        i++;
    }
    FU(i, 1, n * 2)
        p[i].y = liney[i].fi,
        q[i].y = liney[i].fi;
}



ll solve(pii line[], int fen[]){
    ll ret = 0;
    for (int i = 1; i <= 2 * n; i++){
        if (line[i].se == 1) ret = ret + 1LL * get(fen, line[i].fi - 1);
        if (line[i].se == 2) upd(fen, line[i].fi, 1);
    }
    return ret;
}

ll cal(){
    ll ret = 0LL;
    FU(i, 1, n * 2){
        if (p[i].t == 1) ret+= get(fenp, p[i].y - 1);
        if (p[i].t == 2) upd(fenp, p[i].y, 1);
    }
    FU(i, 1, n * 2){
        if (q[i].t == 1) ret+= get_(q[i].y + 1);
        if (q[i].t == 2) upd_(q[i].y, 1);
    }
    return ret;
}

bool cmpy(point t1, point t2){ return t1.y < t2.y; }
bool cmpx(point t1, point t2){
    if (t1.x != t2.x) return t1.x < t2.x;
    return t1.t < t2.t;
}

bool check(int i, int j){
    rect t1 = a[i],
         t2 = a[j];
    if (t1.xa > t2.xa) swap(t1, t2);
    if (t2.xa > t1.xb) return 0;

    if (t1.ya > t2.ya) swap(t1, t2);
    if (t2.ya > t1.yb) return 0;

    return 1;
}

void solve(){

    FU(i, 1, n * 2) fenx[i] = feny[i] = fenp[i] = 0;
    FU(i, 1, n) linex[i * 2 - 1] = {a[i].xa, 1},
                liney[i * 2 - 1] = {a[i].ya, 1},
                linex[i * 2] = {a[i].xb, 2},
                liney[i * 2] = {a[i].yb, 2},
                p[i * 2 - 1] = {a[i].xa, a[i].ya, 1},
                p[i * 2] = {a[i].xb, a[i].yb, 2},
                q[i * 2 - 1] = {a[i].xa, a[i].yb, 1},
                q[i * 2] = {a[i].xb, a[i].ya, 2};
    sort(linex + 1, linex + 1 + 2 * n);
    sort(liney + 1, liney + 1 + 2 * n);
    sort(p + 1, p + 1 + 2 * n, cmpy);
    sort(q + 1, q + 1 + 2 * n, cmpy);
    compress();
    sort(p + 1, p + 1 + 2 * n, cmpx);
    sort(q + 1, q + 1 + 2 * n, cmpx);

    ll t = solve(linex, fenx) + solve(liney, feny) - cal();
    ll m = 1LL * n;
    m = m * (m - 1) / 2LL;
    cout << m - t;EL;
}

int main(){
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}


