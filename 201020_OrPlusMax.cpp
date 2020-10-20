/// task : https://atcoder.jp/contests/arc100/tasks/arc100_c
/*

    hint 1 : 2 ^ i > 2 ^ 0 + 2 ^ 1 + ... + 2 ^ (i - 1)
    hint 2 : A[i] + A[j] max (không quan tâm thứ tự i, j) khi A[i] max và A[j] max -> (1 số lớn nhất và 1 số lớn nhì )
    hint 3 : để i or j <= K thì bit(i) và bit(j) đồng thời là bit con của bit(K)
      bit(X) là con của bit(Y) khi tất cả vị trí mà bit(X) có giá trị bàng 1 thì bit(Y) đều có : ví dụ 11001 , 11000 là con của 11101 , 11110 không là con của 11100
    duyệt từng K = 1 .. (1 << N) - 1
    ta chỉ duyệt qua các bit(i) là con của bit(K) để tránh phải duyệt các bit thừa 
    
    hint 4 : 
    i or j <= K
    K <= P 
    => i or j <= P
    
    Dp[K][0] là giá trị A[i] max nhất với bit(i) là con của bit(K)
    Dp[K][1] là giá trị A[i] max nhì với bit(i) là con của bit(K)
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
#define PROB "OrPlusMax"

using namespace std;
typedef long long ll;
typedef double db;


void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 19;
int n, m; ll a[1 << N], dp[1 << N][2];

void readinp(){
    cin >> n; m = (1 << n) - 1;
    FU(i, 0, m) cin >> a[i];
}

int getbit (int s, int i){
    return (s >> i) & 1;
}

void solve(){
    FU(i, 0, m) {
        for (int j = i; j >= 0; j = (j - 1) & i){
            if (a[j] > dp[i][0]){
                dp[i][1] = dp[i][0];
                dp[i][0] = a[j];
            }
            else dp[i][1] = max(dp[i][1], a[j]);
            if (!j) break;
        }
    }

    ll res = 0;
    FU(k, 1, m){
        res = max(res, dp[k][0] + dp[k][1]);
        cout << res,EL;
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


