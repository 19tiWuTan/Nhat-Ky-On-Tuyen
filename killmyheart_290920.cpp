// task : https://codeforces.com/contest/1396/problem/C
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
#define PROB "killmyheart"

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

const int N = 1e6 + 1;
int n; ll a[N], r1, r2, r3, d;
ll dp[N][2];
void readinp(){
    cin >> n >> r1 >> r2 >> r3 >> d;
    FU(i, 1, n) cin >> a[i];
}

void solve(){
    dp[0][1] = 0;
    dp[0][0] = -d;
    FU(i, 1, n){
        dp[i][1] = min(dp[i-1][0] + d + min(r2, (a[i] + 1) * r1),
                       dp[i-1][1] + d + min(r2, (a[i] + 1) * r1) + d + r1 + d);
        dp[i][0] = min(dp[i-1][0] + d + a[i] * r1 + r3,
                       dp[i-1][1] + d + min(r2, (a[i] + 1) * r1) + d + r1 + d + r1);
    }
    cout << min(dp[n][0], dp[n-1][1] + d + a[n] * r1 + r3 + d + r1);
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



