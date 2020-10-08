// task : https://codeforces.com/problemset/problem/1406/D
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
#define PROB "C"

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
int n, q;
ll a[N], c[N];

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i];
}

ll res(ll s){
    ll ret = a[1] + s;
    if (ret < 0) return ret / 2LL;
    else return (ret + 1LL) / 2LL;
}

void solve(){
    ll s = 0;
    FU(i, 2, n){
        c[i] = a[i] - a[i - 1];
        s+= max(0LL, c[i]);
    }
    cout << res(s);
    EL;
    cin >> q;
    while (q--){
        int l, r; ll x;
        cin >> l >> r >> x;
        if (l == 1)
            a[1]+= x;
        else{
            s-= max(0LL, c[l]);
            c[l]+= x;
            s+= max(0LL, c[l]);
        }

        if (r != n){
            s-= max(0LL, c[r + 1]);
            c[r+1]-= x;
            s+= max(0LL, c[r + 1]);
        }
        cout << res(s); EL;

    }
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



