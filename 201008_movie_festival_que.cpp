// task: https://cses.fi/problemset/task/1664/

/*
    we will optimize the greedy algorithim : 
    try to get the earliets ending movie ( greedy ) 
    call dp[i][j] is the earliest ending time where we start watching at i (time) and watch exacly 2 ^ j movies
    using rmq to store these val(s)
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
#define PROB "1664"

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

const int N = 2e5 + 1, M = 1e6 + 1;
int n, q;
pii a[N];
int f[M + 2][21];

void readinp(){
    cin >> n >> q;
    FU(i, 1, n) cin >> a[i].fi >> a[i].se;
}



void solve(){
    FU(i, 0, 1e6) f[i][0] = 1e6;

    FU(i, 1, n)
        f[a[i].fi][0] = min(f[a[i].fi][0] , a[i].se);

    FD(i, 1e6 - 1, 1)
        f[i][0] = min(f[i+1][0], f[i][0]);

    FU(k, 1, 20) FU(i, 1, 1e6) f[i][k] = f[f[i][k-1]][k-1];

    while (q--){
        int x, y;
        cin >> x >> y;
        int res = 0;
        FD(k, 20, 0){
            if (f[x][k] <= y){
                x = f[x][k];
                res+= (1 << k);
            }
        }
        cout << res; EL;
    }

}

int main(){
    io_faster
//    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}



