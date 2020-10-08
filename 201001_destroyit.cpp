/// task : https://codeforces.com/contest/1176/problem/F
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
#define PROB "Destroyit"

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

int n;
ll f[2][10], g[4][2];

void solve(){
    cin >> n;
    FU(j, 0, 10) f[0][j] = -1e18;
    f[0][0] = 0LL;
    FU(i, 1, n){
        vector < int > a[4];
        vector < pii > use;
        int sl;
        cin >> sl;
        FU(j, 1, sl){
            int c, d;
            cin >> c >> d;
            a[c].push_back(d);
        }
        FU(j, 1, 3){
            sort(a[j].begin(), a[j].end(), greater < int > ());
            FU(c, 0, min((j == 1 ? 3 : 1), sz(a[j])) - 1)
               use.push_back({j, a[j][c]});
        }
        sort(use.begin(), use.end());
        FU(j, 1, 3) FU(k, 0, 1) g[j][k] = -1e18;
        FU(j, 0, 9) f[i % 2][j] = -1e18;
        g[0][0] = 0LL;
        do{
            int left = 3;
            int cnt = 0;
            ll doublee = 0;
            ll s = 0;
            for (auto c : use){
                if (left - c.fi < 0) break;
                left-= c.fi; cnt++;
                doublee = max(doublee, 1LL * c.se);
                s+= 1LL * c.se;
                g[cnt][0] = max(g[cnt][0], s);
                g[cnt][1] = max(g[cnt][1], s + doublee);
            }
        }
        while (next_permutation(use.begin(), use.end()));
        FU(j, 0, 9) FU(k, 0, 3){
            int p = i % 2;
            if (j + k >= 10)
                f[p][(j + k) % 10] = max(f[p][(j + k) % 10],
                                         f[!p][j] + g[k][1]);
            else
                f[p][(j + k) % 10] = max(f[p][(j + k) % 10],
                                         f[!p][j] + g[k][0]);
        }
    }
    ll res = 0;
    FU(i, 0, 9) res = max(res, f[n % 2][i]);
    cout << res;

}

int main(){
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        solve();
    }
}
