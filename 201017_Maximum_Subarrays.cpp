// task : tìm K đoạn liên tiếp không giao nhau từ dãy gồm N phần tử, sao cho tổng các phần tử trong K đoạn này là lớn nhất :
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
#define PROB "MaximumSubarrays"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 5005;
int n, k; ll a[N], s[N], f[N][N];
bool vis[N][N];
void readinp(){
    cin >> n >> k;
    FU(i, 1, n) cin >> a[i];
}

ll dp(int i, int j){
    if (i < j) return -1e18;
    if (i == 0){
        if (j == 0) return 0;
        return -1e18;
    }
    if (vis[i][j]) return f[i][j];
    vis[i][j] = true;
    ll ret = -1e18;
    if (i - 1 >= j) ret = dp(i - 1, j);
    FD(d, i, 1) ret = max(ret, s[i] - s[d-1] + dp(d-1, j-1));
    return (f[i][j] = ret);
}

void solve(){
        s[0] = 0;
    FU(i, 1, n) s[i] = s[i-1] + a[i];
//    cout << dp(n, k);
/*

    cải tiến thuật toán :
    gọi f[i][j] sẽ là giá trị tổng lớn nhất của j đoạn,
    với đoạn thứ j kết thúc ở phần tử a[i]
    thì f[i][j] = max{f[i-1][j], (gắn a[i] vào đoạn trước đó)
                      f[d][j-1]} + a[i] (tạo đoạn mới từ d + 1.. i)
    nhận thấy f[d][j-1] tuyến tính, nên ta có thể dùng biến : mx = max(f[d][j-1]) với d = j..i-1
    để cập nhật vào f[i][j]
*/

    FU(i, 0, n) FU(j, 0, k) f[i][j] = -1e18;
    f[0][0] = 0;
    FU(j, 1, k){
        ll mx = -1e18;
        FU(i, j, n){
            mx = max(mx, f[i-1][j-1]);
            f[i][j] = max(f[i-1][j], mx) + a[i];
        }
    }
    ll res = -1e18;
    FU(i, k, n)  res = max(res, f[i][k]);
    cout << res;
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
