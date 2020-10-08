/// task : https://codeforces.com/contest/1408/problem/E
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
#define PROB "AvoidRainbowCycles"

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

template <typename T>
inline void write(T x){
    if (x < 0)
        putchar('-'); x = -x;
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

void file(){
#ifndef ONLINE_JUDGE
	freopen(PROB".inp","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

const int N = 1e5 + 1;
int n, m;
ll a[N], b[N];
int par[N * 2];
vector < int > S[N];
struct data{
    int u, v; ll w;

    bool operator < ( data a )
    {
        return w > a.w;
    }
};
vector < data > edg;

void readinp(){
    cin >> m >> n;
    FU(i, 1, m) cin >> a[i];
    FU(i, 1, n) cin >> b[i];
    FU(i, 1, m){
        int s;
        cin >> s;
        FU(j, 1, s){
            int x;
            cin >> x;
            S[i].push_back(x);
        }
    }
}
;
int root (int x){
    return (par[x] < 0 ? x : par[x] = root(par[x]));
}

bool unionn(int x, int y){
    if ((x = root(x)) == (y = root(y)))
        return false;
    if (-par[x] < -par[y]) swap(x, y);
    par[x]+= par[y];
    par[y] = x;
    return true;
}

void solve(){
    FU(i, 1, n + m) par[i] = -1;
    ll sum = 0;
    FU(j, 1, m){
        for (auto i : S[j]){
            int u = i;
            int v = j + n;
            ll  w = a[j] + b[i];
            sum+= w;
            edg.push_back({u, v, w});
        }
    }
    sort(edg.begin(), edg.end());
    ll res = 0;
    for (auto e : edg){
        int u = e.u;
        int v = e.v;
        ll  w = e.w;
        if (unionn(u, v)){
            res+= w;
        }
    }
    cout << sum - res;
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



