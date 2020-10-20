/// task : https://codeforces.com/problemset/problem/1420/C2

/*
  quản lý cây IT với mỗi nút thứ id quản lý đoạn L..R ta cần lưu 4 giá trị : 
  scc : tổng dãy con lớn nhất chọn được trong đoạn L..R với phần tử đầu mang dấu + và phần tử cuối mang dấu +
  stt : tổng dãy con lớn nhất chọn được trong đoạn L..R với phần tử đầu mang dấu - và phần tử cuối mang dấu -
  stc : tổng dãy con lớn nhất chọn được trong đoạn L..R với phần tử đầu mang dấu - và phần tử cuối mang dấu +
  sct : tổng dãy con lớn nhất chọn được trong đoạn L..R với phần tử đầu mang dấu + và phần tử cuối mang dấu -
  
  xây dựng hàm merge để ghép node id * 2, với id * 2 + 1 theo đúng thứ tự + - + - + - .. của đề bài



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
#define PROB "1420C2"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 3e5 + 2;
struct node{
    ll scc; /// + - ... - +
    ll stt; /// - + ... + -
    ll stc; /// - + ... - +
    ll sct; /// + - ... + -

}; node st[N * 4];
int n, a[N], q;

void readinp(){
    cin >> n >> q;
    FU(i, 1, n) cin >> a[i];
}

node mergee (node l, node r){
    node ret = {0, 0, 0, 0};
    ret.scc = max({l.scc, r.scc, l.scc + r.stc, l.sct + r.scc});
    ret.stt = max({l.stt, r.stt, l.stt + r.sct, l.stc + r.stt});
    ret.stc = max({l.stc, r.stc, l.stt + r.scc, l.stc + r.stc});
    ret.sct = max({l.sct, r.sct, l.sct + r.sct, l.scc + r.stt});
    return ret;
}

void upd (int id, int l, int r, int p, int v){
    if (l == r && r == p){
        st[id] = {v, -v, 0, 0};
        return;
    }
    int mid = (l + r) / 2;
    if (p >= mid + 1) upd(id * 2 + 1, mid + 1, r, p, v);
    else upd(id * 2, l, mid, p, v);
    st[id] = mergee(st[id * 2], st[id * 2 + 1]);
}

void solve(){
    FU(i, 1, n * 4) st[i] = {0, 0, 0, 0};
    FU(i, 1, n) upd(1, 1, n, i, a[i]);
    cout << max({st[1].scc, st[1].sct}), EL;
    FU(i, 1, q){
        int l, r;
        cin >> l >> r;
        swap(a[l], a[r]);
        upd(1, 1, n, l, a[l]);
        upd(1, 1, n, r, a[r]);
        cout << max({st[1].scc, st[1].sct}), EL;
    }
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
