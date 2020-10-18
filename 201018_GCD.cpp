/*
  task : cho dãy N số nguyên A và M số nguyen B
  tìm cách loại bỏ ít nhất phần tử từ dãy A hoặc dãy B sao cho không tồn tại cặp (i, j) (1 <= i <= N, 1 <= j <= M) sao cho gcd(a[i], b[j]) > 1
  
  với những cặp A[i], B[j] nào có gcd > 1, thì ta dựng cạnh (i, j) 
  -> đồ thị hai phía
  -> kiến thức : tập phủ đỉnh trong đồ thị hai phía
  kết quả sẽ  = n + m - maxmatching();
  
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
#define PROB "GCD"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 805;
int n, m; bool vis[N], c[N][N];
int x[N], y[N], a[N], b[N];

void readinp(){
    cin >> n >> m;
    FU(i, 1, n) cin >> a[i];
    FU(i, 1, m) cin >> b[i];
}

bool findd(int i){
    if (vis[i]) return false;
    vis[i] = true;
    FU(j, 1, m) if (c[i][j]){
        if (!y[j]){
            x[i] = j;
            y[j] = i;
            return true;
        }
        if (findd(y[j])){
            x[i] = j;
            y[j] = i;
            return true;
        }
    }

    return false;
}

void solve(){
    FU(i, 1, n) FU(j, 1, m) c[i][j] = false;
    FU(i, 1, n) FU(j, 1, m) if (__gcd(a[i], b[j]) > 1)
        c[i][j] = true;
    int res = 0;
    FU(i, 1, n) {
        memset(vis, 0, sizeof(vis));
        if (findd(i)) res++;
    }
    cout << n + m - res;
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



