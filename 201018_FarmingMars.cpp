/// task : cho N số thực, và M truy vấn dạng l..r , yêu cầu xác định xem đoạn l..r có đẹp hay không
/// một đoạn gồm n phần tử gọi là đẹp nếu tồn tại ít nhất 1 số xuất hiện nhiều hơn hoặc bằng n div 2 + 1 lần

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
#define PROB "FarmingMars"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 1e4 + 2;

int n, m;
int a[N], res[N], st[N * 4], cnt[N], s[N]; pair < db, int > b[N];
struct query{
    int l, r, id;
}; query que[N];


void readinp(){
    cin >> n >> m;
    FU(i, 1, n) cin >> b[i].fi, b[i].se = i;
    FU(i, 1, m) cin >> que[i].l >> que[i].r, que[i].id = i;
}

void compress(){
    sort(b + 1, b + 1 + n);
    int cnt = 0;
    FU(i, 1, n){
        cnt++;
        a[b[i].se] = cnt;
        while (i < n && b[i+1].fi == b[i].fi)
            a[b[++i].se] = cnt;
    }
}

bool cmp (query t1, query t2){
    int S = sqrt(n);
    if (t1.l / S != t2.l / S)
        return t1.l / S < t2.l / S;
    return t1.r < t2.r;
}

void upd (int id, int l, int r, int p, int v){
    if (l == r && r == p){
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (p >= mid + 1) upd(id * 2 + 1, mid + 1, r, p, v);
    else upd(id * 2, l, mid, p, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void add(int x){
    cnt[x]++;
    upd(1, 1, n, x, cnt[x]);
}

void del(int x){
    cnt[x]--;
    upd(1, 1, n, x, cnt[x]);
}

void solve(){
    compress();
    sort (que + 1, que + 1 + m, cmp);
    int L = 1, R = 1;
    FU(i, 1, m){
        int l = que[i].l, r = que[i].r;
        while (l > L)  del(a[L++]);
        while (l < L) add(a[--L]);
        while (r >= R) add(a[R++]);
        while (r + 1 < R) del(a[--R]);

        int sl = (que[i].r - que[i].l + 1);
        res[que[i].id] = (st[1] >= sl / 2 + 1);
    }
    FU(i, 1, m) cout << (res[i] ? "usable" : "unusable"),EL;

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



