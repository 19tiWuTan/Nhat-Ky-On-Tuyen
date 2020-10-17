///Cho đồ thị vô hướng đơn giản có trọng số n đỉnh m cạnh và số nguyên dương D, có t đỉnh được gọi là đặc biệt, mỗi cạnh nối từ đỉnh u sang đỉnh v có độ dài là w km
///Bạn xuất phát ở thành phố 1 và muốn đi đường đi ngắn nhất đến đỉnh n. Xe bạn có dung tích tối đa là D và ban đầu, 
///bạn có lượng xăng là D, khi đi 1 km bạn sẽ tốn 1 lít xăng. Nếu đang đi mà hết xăng (tức lượng xăng hiện tại về 0) thì bạn sẽ dừng mãi mãi,
///không thể đi được đến n. May thay có t đỉnh đặc biệt, nếu như bạn đang ở một đỉnh đặc biệt thì bạn có thể đổ đầy bình xăng (không kể lượng xăng hiện tại của bạn là bao nhiêu).

///Yêu cầu: Hỏi số km nhỏ nhất mà bạn có thể đi được từ thành phố 1 đến thành phố n là bao nhiêu.

/// floyd : tạo f[i][j] là đường đi ngắn nhất từ i -> j

/// dựng đồ thị mới gồm t + 2 đỉnh : 1, p[1], p[2], .., p[t], n, với các cạnh = (f[i][j] <= d ? f[i][j] : +oo) ( i = p[], j = p[] )
/// floyd để tìm đường đi ngắn nhất trên đồ thị mới này

// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "SlowLeak"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 505;
int n, m, t, p[N]; ll D;

ll ft[N][N], f[N][N];

void readinp(){
    cin >> n >> m >> t >> D;
    FU(i, 2, t + 1) cin >> p[i];
    p[1] = 1, p[t + 2] = n; t+= 2;
    FU(i, 1, n) FU(j, 1, n) f[i][j] = ft[i][j] = (i != j) ? 1e18 : 0;
    FU(i, 1, m){
        int u, v; ll w;
        cin >> u >> v >> w;
        f[u][v] = min(f[u][v], w);
        f[v][u] = f[u][v];
    }
}

void solve(){
    FU(i, 1, n) FU(u, 1, n) FU(v, 1, n)
        if (f[u][i] != 1e18 && f[i][v] != 1e18)
            f[u][v] = min(f[u][v], f[u][i] + f[i][v]);
    FU(i, 1, t) FU(j, i, t){
        int u = p[i], v = p[j];
        if (f[u][v] <= D)
            ft[u][v] = ft[v][u] = f[u][v];
    }

    FU(i, 1, n) FU(u, 1, n) FU(v, 1, n)
        if (ft[u][i] != 1e18 && ft[i][v] != 1e18)
            ft[u][v] = min(ft[u][v], ft[u][i] + ft[i][v]);

    if (ft[1][n] == 1e18){
        cout << "stuck";
    }
    else {
        cout << ft[1][n];
    }

}

int main(){
    io_faster
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".out","w",stdout);
    }
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}

