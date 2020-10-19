/// http://lequydon.ntucoder.net/Problem/Details/5980

/*
  F[1] = X % m
  F[i] = (F[i-1] * 10 ^ (len(x)) + X) % m
  thì kết quả sẽ là F[N]
  
  thay vì lần lượt nối từng số X đúng N lần
  thì mình sẽ nối X - > XX -> XXXX - > XXXXXXXX -> ..
  giảm độ phức tạp về log2(N)
  chú ý xử lý số lớn (<= 1e18)
  a * b, dùng nhân ân độ

*/

// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,ll>
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define fi first
#define se second
#define sz(a) ll(a.size())
#define FU(x,a,b) for(ll x=ll(a);x<=ll(b);x++)
#define FD(x,a,b) for(ll x=ll(a);x>=ll(b);x--)
#define PROB "REMAINDER"

using namespace std;
typedef unsigned long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

ll x, n, m, l;
ll pls[66], p2[66];

void readinp(){
    cin >> x >> n >> m;
}

ll getbit(ll s, ll i){
    return (s >> i) & 1LL;
}

ll mul (ll a, ll b){
    if (b == 0) return 0;
    if (b == 1) return a % m;
    ll t = mul(a, b / 2);
    t = (t + t) % m;
    if (b % 2 == 0) return t;
    else return (t + a) % m;
}

ll add (ll a, ll b){
    return ((a % m) + (b % m)) % m;
}

ll poww (ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return (a % m);
    ll t = poww(a, b / 2LL);
    t = mul(t, t);
    if (b % 2LL == 0) return t;
    else return mul(t, a);
}

ll digits(ll t){
    ll cnt = 0;
    while (t){
        t/=10LL; cnt = cnt + 1LL;
    }
    return cnt;
}


void solve(){
    l = digits(x);
    p2[0] = 1LL;
    FU(i, 1, 63) p2[i] = p2[i-1] * 2LL;

    pls[0] = x % m;
    FU(i, 1, 63){
        pls[i] = add(mul(pls[i-1] , poww(10LL, l * p2[i-1])) ,
                    pls[i-1]);
    }
    ll res = 0LL;
    FU(i, 0, 63) if (getbit(n, i)){
        res = add(mul(res, poww(10LL, l * p2[i])) , pls[i]);
    }
    cout << res;
}

int main(){
    io_faster
    file();
    ll t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}


