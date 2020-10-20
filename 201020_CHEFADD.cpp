/// task : https://www.codechef.com/problems/CHEFADD
/*
  dp(i, j, k, c) = số cách xáo trộn các bit trong A hoặc B để tạo được bit thứ i trong C, đã sử dụng j bit 1 trong A, k bit 1 trong B, và c = 1 nếu ở vị trí i - 1 
  có nhớ , và c = 0 là không có nhớ ( 1 + 1 = 0 , nhớ 1 )
*/

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
#define PROB "ChefandStrangeAddition"
using namespace std;
typedef long long ll;
typedef double db;

int vis[31][31][31][2];
ll f[31][31][31][2];
int A, B, C, n, m, N;

void readinp(){
    cin >> A >> B >> C;
}

int getbit (int s, int i){
    return (s >> (i - 1)) & 1;
}

ll dp (int i, int j, int k, int c){ 
    if (i == N + 1) {
        int ret = (j == n && k == m && c == 0); 
        if (j == n && k == m && c == 0) return 1;
        else return 0;
    }
    if (j > n || k > m) return 0;
    if (vis[i][j][k][c]) return f[i][j][k][c];
    vis[i][j][k][c] = 1;
    int bit = getbit(C, i);
    ll ret = 0LL;
    if (c == 0){
        if (bit == 0) ret = dp(i + 1, j, k, 0) + dp(i + 1, j + 1, k + 1, 1);
        if (bit == 1) ret = dp(i + 1, j + 1, k, 0) + dp(i + 1, j, k + 1, 0);
    }
    if (c == 1){
        if (bit == 0) ret = dp(i + 1, j + 1, k, 1) + dp(i + 1, j, k + 1, 1);
        if (bit == 1) ret = dp(i + 1, j, k, 0) + dp(i + 1, j + 1, k + 1, 1);
    }
    f[i][j][k][c] = ret; 
    return ret;
}

void solve(){
    n = __builtin_popcount(A);
    m = __builtin_popcount(B);
    N = int(log2(C) + 1);
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f)); 
    cout << dp(1, 0, 0, 0), EL;
}

int main(){
    io_faster
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".out","w",stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}
