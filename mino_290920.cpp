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
#define PROB "A"

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

const int N = 101;
string a, b, c;
int n, m, l, f[N];
string dp[N][N][N];

void readinp(){
    cin >> a >> b >> c;
    n = sz(a);
    m = sz(b);
    l = sz(c);
}

void initf(){
    int j = 0;

    FU(i, 1, l - 1){
        while (j && c[i] != c[j]) j = f[j-1];
        if (c[i] == c[j]) f[i] = ++j;
    }

}

void upd(string &t1, string t2){
    if (sz(t1) < sz(t2)) t1 = t2;
}

void solve(){
    initf();
    FU(i, 0, n) FU(j, 0, m) FU(k, 0, l) dp[i][j][k] = "";
    a = ' ' + a;
    b = ' ' + b;
    FU(i, 1, n) FU(j, 1, m) FU(k, 0, l - 1){
        if (a[i] == b[j]){
            int p = k;
            while (p && a[i] != c[p]) p = f[p-1];
            if (a[i] == c[p]) p++;
            upd(dp[i][j][p], dp[i-1][j-1][k] + a[i]);
        }
        upd(dp[i][j][k], dp[i-1][j][k]);
        upd(dp[i][j][k], dp[i][j-1][k]);
    }
    string res = "";
    int ans = 0;
    FU(i, 0, l - 1){
        if (sz(dp[n][m][i]) > ans){
            ans = sz(dp[n][m][i]);
            res = dp[n][m][i];
        }
    }
    if (ans) cout << res;
    else cout << 0;
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
