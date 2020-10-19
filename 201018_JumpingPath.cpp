/*
    cho 1 cái cây N đỉnh , mỗi đỉnh 1 giá trị
    đếm số dãy con tăng dài nhất trên 1 cái cây : x[ui] <= x[u[i+1]] <= ... x[u[i+k-1]] sao cho u[i] là cha của u[i+1] và u[i+1] là cha của u[i+1] and so on
   
*/

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
#define PROB "JumpingPath"

using namespace std;
typedef long long ll;
typedef double db;

template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

const int mod = 11092019;
const int N = 1e6 + 2;
int n, x[N]; pii f[N], st[N * 4], res;
vector < vector < int > > a;
vector < pii > store[N];

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

void readinp(){
    read(n);
    a.resize(n + 1);
    FU(i, 1, n) read(x[i]);
    FU(i, 2, n){
        int p; read(p);
        a[p].push_back(i);
    }
}

int add(int a, int b){
    a+= b; return (a >= mod ? a - mod : a);
}

int mul (int a, int b){
    return (ll(a) * b) % mod;
}

pii mergee(pii tl, pii tr){
    pii ret;
    if (tl.fi == tr.fi) ret = {tl.fi, add(tl.se, tr.se)};
    else ret = max(tl, tr);
    return ret;
}

void upd (int id, int l, int r, int p, pii g){
    if (l == r && r == p){
        st[id] = g;
        return;
    }
    int mid = (l + r) / 2;
    if (p >= mid + 1) upd(id * 2 + 1, mid + 1, r, p, g);
    else upd(id * 2, l, mid, p, g);
    st[id] = mergee(st[id * 2], st[id * 2 + 1]);
}

pii get (int id, int l, int r, int u, int v){
    if (r < u || v < l) return {0, 0};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    pii tl = get(id * 2, l, mid, u, v);
    pii tr = get(id * 2 + 1, mid + 1, r, u, v);
    return mergee(tl, tr);
}

void dfs(int u, int p){
    f[u] = get(1, 0, 1e6, 0, x[u]);
    f[u].fi++; if (!f[u].se) f[u].se++;
    res = mergee(res, f[u]);
    store[x[u]].push_back(f[u]);
    upd(1, 0, 1e6, x[u], f[u]);
    for (auto v : a[u]) if (v != p)
        dfs(v, u);
    store[x[u]].pop_back();
    pii g = {0, 0};
    if (store[x[u]].size()) g = store[x[u]].back();
    upd(1, 0, 1e6, x[u], g);
}

void solve(){
    dfs(1, 1);
    cout << res.fi << ' ' << res.se;
}

int main(){
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}



