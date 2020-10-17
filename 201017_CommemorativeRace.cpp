/// task : cho đồ thị DAG, tìm 1 cạnh (u -> v) sao cho tất cả đường đi dài nhất đều đi qua cạnh này và đường đi dài nhất đi qua u nhưng không đi qua (u -> v) là  nhỏ nhất

/// xây dựng g[2][N]
/// trong đó g[0][u] là đường đi dài nhất xuât phát từ u, g[1][u] là đường đi dài nhì xuất phát từ u
/// sử dụng topo để xây dựng mảng g này

/// ta sẽ xác định xem cạnh nào mà tất cả các đường đi dài nhất chắc chắn đi qua cạnh này
/// sử dụng BFS, bắt đầu từ những đỉnh có có g[0][u] là lớn nhất
/// ta sẽ xác định từng lớp trong bfs
/// cạnh (u -> v) là cạnh duy nhất ( tất cả các đường đi dài nhất đều đi qua cạnh này) khi từ lớp pre(u) đến lớp cur(u) chỉ có 1 cạnh và từ cur(u) đến nex(u) cũng chỉ có 1 cạnh
/// khi cạnh (u -> v) là duy nhất, do tất cả đường đi dài nhất đều đi qua cạnh này
/// nên đường đi dài nhất còn lại sau khi xóa cạnh này = max(g[0][i]) - g[1][u] ( i = 1.. n)
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
#define PROB "CommemorativeRace"

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

template <typename T>
inline void write(T x){
    if (x < 0)
        putchar('-'); x = -x;
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

void file(){
#ifndef ONLINE_JUDGE
	freopen(PROB".inp","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

const int N = 1e5 + 2;
int n, m, f[N], g[2][N], deg[N];
vector < int > a[N], b[N];
bool vis[N];

void readinp(){
    cin >> n >> m;
    FU(i, 1, m){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        b[v].push_back(u);
        a[u].push_back(v);
    }
}


void solve(){
    FU(i, 1, n) g[0][i] = g[1][i] = -1e9;
    queue < int > Q;
    FU(i, 1, n) if (!deg[i]){
        Q.push(i); g[0][i] = 0;
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto v : b[u]){
            deg[v]--;
            if (deg[v] == 0) Q.push(v);
            if (g[0][v] < g[0][u] + 1){
                g[1][v] = g[0][v];
                g[0][v] = g[0][u] + 1;
            }
            else g[1][v] = max(g[1][v], g[0][u] + 1);
            g[1][v] = max(g[1][v], g[1][u] + 1);
        }
    }
    FU(i, 1, n) deg[i] = 0;

    int longest = 0;
    FU(i, 1, n) longest = max(longest, g[0][i]);

    FU(i, 1, n) vis[i] = false;
    FU(i, 1, n) if (g[0][i] == longest) vis[i] = true, Q.push(i);
    int res = N;
    while (!Q.empty()){
        int u = Q.front();
        int m = sz(Q);
        FU(i, 1, m){
            int v = Q.front();
            Q.pop();
            for (auto j : a[v]) if (!vis[j]){
                if (g[0][j] + 1 == g[0][v])
                    Q.push(j), vis[j] = true;
            }
        }
        if (m == 1 && sz(Q) == 1)
            res = min(res, longest - g[0][u] + max(0, g[1][u]));
    }
    cout << (res == N ? longest : res);

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



