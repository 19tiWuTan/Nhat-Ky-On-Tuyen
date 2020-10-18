/*
  task : đếm số cặp (1 <= L < R <= N) sao cho tích(A[i]) = tổng(A[i]) với i = L..R
  
  
  nhận thấy tích càng to càng khó tìm thêm số để cộng vào sum để pro = sum
  để 'kiềm hãm' giá trị pro và tăng sum thì chỉ có cách nhân thêm số 1, trong khi đó sum tăng thêm 1
  nhưng nếu chạy từng số 1 để tăng vào biến sum thì có thể quá thời gian, do vậy ta hãy thử nhảy 1 lần 1 đoạn gồm toàn số 1 
  nex[i] = 0, i không nằm trong đoạn toàn số 1
  nex[i] != 0 sẽ là vị trí cuối cùng trong đoạn toàn số 1 mà i thuộc mà tại đó a[nex[i]] = 1
  tuy là 2 for nhưng for thứ j chỉ chạy tối đa 48 lần :) (1e9 x 2e5 xấp xỉ
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
#define PROB "SumandProduct"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 2e5 + 5;
int n, a1 = 0, nex[N];
ll a[N], sum = 0;

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i], sum+= a[i], a1+= (a[i] == 1);
}

void solve(){

    FD(i, n, 1) {
        if (a[i] == 1 && a[i+1] == 1) nex[i] = nex[i + 1];
        else if (a[i] == 1 && a[i+1] != 1) nex[i] = i;
        else nex[i] = 0;
    }

    ll cnt = 0;
    FU(i, 1, n){
        ll p = a[i], s = a[i];
        FU(j, i + 1, n){
            if (a[j] == 1){
                int r = nex[j];
                if (!r) continue;
                if (p > s && p <= s + r - j + 1) cnt++;
                s+= r - j + 1;
                j = nex[j];
            }
            else{
                p*= a[j], s+= a[j];
                if (p == s) cnt++;
                if (p <= 0) break;
                if (p >= 1e18) break;
                if (p > sum) break;
                if (p - s > a1) break;
            }
        }
    }

    cout << cnt;
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



