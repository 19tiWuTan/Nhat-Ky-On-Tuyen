/*
ví dụ :
4 2 
1 2 3 4
2 3 4 1
ví dụ xét dòng 3 : 
ở cột 1 có thể điền giá trị 3, 4
ở cột 2 có thể điền giá trị 1, 4
ở cột 3 có thể diền giá trị 1, 2
ở cột 4 có thể điền giá trị 2, 3
ta có đồ thị 2 phía với các cạnh trên : 
  cột X   |   giá trị Y
    1            1
    2            2 
    3            3
    4            4 
  trên 1 dòng không có 2 giá trị nào bằng nhau, nên mình cần chọn được nhiều cạnh nhất từ đồ thị 2 phía trên sao cho không có cạnh nào
  có chung đầu mút (vì như thế dòng mình đang xét sẽ có 2 giá trị giống nhau)
  nên ta sẽ tìm cặp ghép cực đại từ đồ thị 2 phía đã dựng
  khi tìm dược 1 cặp ghép cực đại, x[i] = j có nghĩa là cột i sẽ có giá trị là j, ta lần lượt gắn giá trị này vào hàng đang xét 
  và đánh dấu lại giá trị j đã xuất hiện trong cột i để tiếp tục xử lý dòng tiếp theo
  cứ như thế đến hết dòng thứ n 
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
#define PROB "Superdoku"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 1e2 + 2;
int n, a[N][N], k, dc[N][N], dd[N][N];
int vis[N], x[N], y[N], c[N][N];

void readinp(){
    cin >> n >> k;
    FU(i, 1, k) FU(j, 1, n) cin >> a[i][j];
}

bool check (){
    FU(i, 1, k) FU(j, 1, n)
        if (dd[a[i][j]][i])
            return false;
        else if (dc[a[i][j]][j])
            return false;
        else dd[a[i][j]][i] = dc[a[i][j]][j] = 1;
    return true;
}

bool findd(int j){
    if (vis[j]) return false;
    vis[j] = 1;
    FU(val, 1, n) if (c[j][val]) {
        if (!y[val]){
            x[j] = val;
            y[val] = j;
            return true;
        }
        if (findd(y[val])){
            x[j] = val;
            y[val] = j;
            return true;
        }
    }

    return false;
}

void solve(){
    if (!check()){
        cout << "no";
        return;
    }

    FU(i, k + 1, n){
        memset(c, 0, sizeof(c));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        FU(j, 1, n) FU(val, 1, n)
            if (!dc[val][j])
                c[j][val] = 1;
        FU(j, 1, n){
            memset(vis, 0, sizeof(vis));
            findd(j);
        }
        FU(j, 1, n){
            a[i][j] = x[j];
            dc[a[i][j]][j] = 1;
        }
    }
    cout << "yes";EL;
    FU(i, 1, n) FU(j, 1, n)
        cout << a[i][j] << (j == n ? '\n' : ' ');



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

