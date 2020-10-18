// task cho N cặp (A[i], B[i]), chọn ra K số sao cho sum(A[i]) / sum(B[i]) là lớn nhất ( trong đó sum(A[i]) = tổng K số a[i] mình chọn
  
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
#define PROB "DIAMOND"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 50005;
int n, k; int a[N], b[N];
ll sa, sb, resa, resb;

void readinp(){
    cin >> n >> k;
    FU(i, 1, n) cin >>  a[i] >> b[i];
}

bool check (ld m){
    vector < pair < ld, int > > d;
    FU(i, 1, n){
        ld c = 1.00 * a[i] - 1.00 * b[i] * m;
        d.push_back({c,i});
    }
    ld s =  0.00;
    sa = 0, sb = 0;
    sort(d.begin(), d.end(), greater < pair < ld, int > > ());
    FU(i, 0, k - 1){
        int p = d[i].se;
        sa+= 1LL * a[p], sb+= 1LL * b[p];
        s+= d[i].fi;
    }
    if (s >= 0.00) return true;
    else return false;
}

void solve(){
    ld l = 0, r = 1e11;
    while (l <= r){
        ld mid = (l + r) / 2.00;
        if (check(mid)){
            l = mid + ld(1e-5);
            resa = sa, resb = sb;
        }
        else r = mid - ld(1e-5);
    }
    ll uc = __gcd(resa, resb);
    cout << resa/uc << " " << resb/uc;
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



