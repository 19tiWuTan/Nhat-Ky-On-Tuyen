/// task : tìm cách xóa 1 đoạn liên tiếp duy nhất sao cho những phần tử còn lại có trung bình cộng là lớn nhất
/// chặt nhị phân số thực X
/// khi chặt X để xét xem X có phải là kết quả hay không, lấy a[i]-=X ( với mọi i)
/// pre[i] = sum(a[1] + a[2] + .. a[i])
/// suf[i] = sum(a[n] + a[n-1] + .. + a[i])

/// X thỏa khi tồn tại (i , j) : 1 <= i <= j <= n và pre[i] + suf[j] >= 0
/// mx_pre[i] = max(pre[1], pre[2], .. pre[i])
/// mx_suf[i] = max(suf[n], suf[n-1], .. suf[i])

/// bài toán quy về tìm vị trí i : mx_pre[i] + mx_suf[i+1] >= 0

/// a + b >= 0
/// -> a >= 0 || b >= 0
/// qua một vài nhận xét ta thấy đoạn tối ưu nhất còn lại sẽ là 1 đoạn pre hoặc suf của dãy ban đầu

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
#define PROB "StopCounting"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 1e6 + 2;
int n, a[N];

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i];
}

void solve(){
    long double s = 0.00;
    long double res = 0.00;
    FU(i, 1, n) res = max(res, (s+= (1.00 * a[i])) / (1.00 * i));
    s = 0.00;
    FD(i, n, 1) res = max(res, (s+= 1.00 * a[i]) / (1.00 * (n - i + 1)));
    cout << setprecision(10) << fixed << res;EL;
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
