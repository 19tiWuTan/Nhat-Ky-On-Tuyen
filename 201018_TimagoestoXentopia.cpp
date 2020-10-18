/*
task : cho đồ thị vô hướng có trọng số, mỗi cạnh có 1 trong 3 màu 0 : trắng, 1 : đỏ, 2 : xanh
yêu cầu đi từ S đến T phải đi qua đúng k1 cạnh đỏ và k2 cạnh xanh với tổng trọng số là nhỏ nhất
1 đỉnh, 1 cạnh có thể đi lại nhiều lần

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
#define PROB "TimagoestoXentopia"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 455;

struct edg{
    int des, w, c;
};
int n, m, k1, k2, s, t;
vector < edg > a[N];
map < int , map < int , ll > > d[N];

void readinp(){
    cin >> n >> m >> k1 >> k2;
    FU(i, 1, m){
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        a[u].push_back({v, w, c});
        a[v].push_back({u, w, c});
    }
    cin >> s >> t;
}

struct ver{
    int u; ll w; int l1, l2;
};

struct cmp{
    bool operator()(ver t1, ver t2){
        return t1.w > t2.w;
    }
};

void solve(){
    FU(i, 1, n) FU(j, 0, k1) FU(k, 0, k2) d[i][j][k] = 1e18;
    d[s][0][0] = 0;
    priority_queue < ver , vector < ver > ,  cmp > Q;
    Q.push({s, 0, 0, 0});
    while (!Q.empty()){
        int u  = Q.top().u;
        ll  w  = Q.top().w;
        int l1 = Q.top().l1;
        int l2 = Q.top().l2;
        Q.pop();
        if (l1 > k1 || l2 > k2) continue;
        for (auto nex : a[u]){
            int v = nex.des;
            ll  z = 1LL * nex.w;
            int c = nex.c;
            if (d[v][l1 + (c == 1)][l2 + (c == 2)] > w + z){
                d[v][l1 + (c == 1)][l2 + (c == 2)]  = w + z;
                Q.push({v, d[v][l1 + (c == 1)][l2 + (c == 2)], l1 + (c == 1), l2 + (c == 2)});
            }
        }
    }
    cout << (d[t][k1][k2] == 1e18 ? -1 : d[t][k1][k2]);
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



