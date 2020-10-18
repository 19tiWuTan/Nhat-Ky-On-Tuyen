/*
  Có n người tham gia cuộc thi, nguyên tắc xếp hạng là ai cao điểm hơn thì rank của người đó sẽ có giá trị thấp hơn, 
  bằng điểm thì rank bằng nhau, rank=1 tức là người đó đang ở vị trí dẫn đầu.


Ví dụ: n=6 và điểm số của mỗi người thi là 5,3,4,3,4,5 thì sẽ tương ứng rank là 1,5,3,5,3,1.

Ban đầu tất cả điểm số của mỗi người là 0. 
Có w ngày thi, mỗi ngày thì sẽ có một số người được tăng điểm số lên 1, sau mỗi ngày thì bảng xếp hạng về rank sẽ có thể thay đổi.

Yêu cầu: Hỏi rank trung bình của mỗi người là bao nhiêu.
input : 
3 2
2 1 2
2 1 3

output : 
1.0000000000
1.5000000000
2.5000000000

  
  
  
  xét người p, những ngày xuất hiện d1 < d2 < ... < dk ( Những ngày dược cộng điểm ) 
  
  thì p sẽ có điểm = 0 từ ngày 0 -> d1 - 1
  có điểm = 1 từ ngày d1 -> d2 - 1
  and so on...
  
  dể tính trung bình rank ta cần tính tổng rank của từng thí sinh qua từng ngày
  
  thứ hạng của 1 thí sinh trong 1 ngày sẽ bằng số lượng thí sinh có điểm cao hơn nó trong ngày đó + 1
  thì tổng thứ hạng của 1 thí sinh trong W ngày sẽ bằng tổng số lượng thí sinh có điểm cao hơn nó qua từng ngày + W
  
  tạo một vector a[point] chứa {L, R, p} với ý nghĩa : thí sinh có số hiệu p sẽ có point điểm trong các ngày [L,R]
  
  để đếm trong các ngày [L,R] có bao nhiêu thí sinh có số điểm nhiều hơn p, ta sẽ duyệt các point theo thứ tự giảm dần,
  với mỗi point, duyệt tất cả {L, R, p} : a[point] 
  
  
  
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
#define PROB "AverageRank"
using namespace std;
typedef long long ll;
typedef double db;


template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}


const int N = 3e5 + 2;
struct data{
    int l, r, id;
};
int n, w; ll st[N * 4], lazy[N * 4], sum[N];
vector < vector < int > > que, d;
vector < vector < data > > a;

void readinp(){
    read(n), read(w);
    a.resize(w + 1);
    que.resize(w + 1);
    d.resize(n + 1);
    FU(i, 1, n) d[i].push_back(0);
    FU(i, 1, w){
        int k;
        read(k);
        que[i].resize(k + 1);
        FU(j, 1, k){
            read(que[i][j]);
            d[que[i][j]].push_back(i);
        }
    }
    FU(i, 1, n) d[i].push_back(w + 1);
}

void down (int id, int l, int r){
    int mid = (l + r) / 2;
    ll t = lazy[id];

    st[id * 2]+= t * (mid - l + 1);
    st[id * 2 + 1]+= t * (r - mid);

    lazy[id * 2]+= t;
    lazy[id * 2 + 1]+= t;

    lazy[id] = 0;
}

void upd (int id, int l, int r, int u, int v, int g){
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        st[id]+= 1LL* (r - l + 1);
        lazy[id]+= 1LL * g;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v, g);
    upd(id * 2 + 1, mid + 1, r, u, v, g);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v){
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    down(id, l, r);
    int mid = (l + r) / 2;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return t1 + t2;
}

void solve(){

    FU(i, 1, n) FU(j, 0, sz(d[i]) - 2)
        a[j].push_back({d[i][j], d[i][j+1] - 1, i});


    FD(i, w, 0) if (!a[i].empty()){
        for (auto j : a[i]){
            int l = j.l, r = j.r;
            sum[j.id]+= get(1, 0, w, l, r) + r - l + 1;
        }
        for (auto j : a[i])
            upd(1, 0, w, j.l, j.r, 1);
    }
    FU(i, 1, n){
        double s = 1.00 * (sum[i] - 1); /// do cộng thừa ngày thứ 0
        cout << setprecision(10) << fixed << s / w;EL;
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

