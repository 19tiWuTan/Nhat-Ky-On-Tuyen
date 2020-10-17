/*
  task : Với dãy X gồm N phần tử, ta sẽ xác định dãy Y gồm  N * (N - 1) / 2 phần tử, bằng các giá trị : |X[i] - X[j]| ( i < j )
  sau đó xắp xếp lại dãy Y tăng dần
  yêu cầu : cho dãy Y, gồm N * ( N - 1 ) / 2 phần tử, hãy tìm tất cả các dãy X thỏa mãn
  
  bài toán này sẽ được giải bằng phương pháp quay lui
  dễ dàng thấy được
  các phần tử của X sẽ tăng dần nghiêm ngặt
  X[1] = 0
  X[N] = Y[N * (N - 1) / 2] = dmax
  
  dãy X bây giờ có dạng : 0  x x ... x dmax ( x là những giá trị mình sẽ điền vào )
  sau khi quay lui được 1 giá trị x mới, ta sẽ loại bỏ 1 phần tử |x - cur[i]| ra khỏi multiset Y hiện tại
  đặt curmax = giá trị của phần tử max nhất trong dãy Y hiện tại
  mỗi lần quay lui ta thử lần lượt thêm giá trị curmax hoặc dmax - curmax 
  hãy hình dung nó như thế này : 
  0 x . . . . y dmax
  x sẽ = dmax - curmax
  y sẽ = curmax - 0
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
#define PROB "TheSpectrum"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 63;
int n;
multiset < int , greater < int > > d, remain;

void readinp(){
    cin >> n;
    FU(i, 1, n * (n-1) / 2) {
        int x; cin >> x;
        d.insert(x);
    }
}

bool in[1001];
map < vector < int > , int > vis;
vector < int > curarr;
set < vector < int > > res;

void bt(int i){
    vector < int > arr = curarr;
    sort(arr.begin(), arr.end());
    if (vis[arr]) return;
    vis[arr] = 1;
    int mxd = *remain.begin();
    for (auto k : {*remain.begin(), curarr[1] - *remain.begin()}){
        if (k < 0 || k > 999 || in[k]) continue;
        bool flag = true;
        vector < int > del;
        for (auto j : curarr){
            int dis = abs(k - j);
            if (remain.find(dis) == remain.end()){
                flag = false;
                break;
            }
            del.push_back(dis);
            remain.erase(remain.find(dis));
        }
        if (flag){
            curarr.push_back(k);
            in[k] = true;
            if (i == n){
                arr.push_back(k);
                sort(arr.begin(), arr.end());
                res.insert(arr);
            }
            else bt(i + 1);
            curarr.pop_back();
            in[k] = false;
        }
        for (auto j : del) remain.insert(j);
    }
}

void solve(){
    FU(i, 0, 1e3) in[i] = false;
    in[0] = in[*d.begin()] = true;
    curarr.push_back(0); curarr.push_back(*d.begin());
    d.erase(d.begin());
    remain = d;
    bt(3);
    cout << sz(res);EL;
    for (auto arr : res){
        for (auto i : arr) cout << i << ' ';EL;
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
