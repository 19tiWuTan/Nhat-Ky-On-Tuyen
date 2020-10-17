/// task : cho tọa độ N điểm trên tọa độ Oxy, tìm 4 điểm phân biệt sao cho có diện tích lớn nhất

// trước hêt ta sẽ tìm bao lồi
// quy bài toán về tim 2 tam giác liền nhau, mỗi tam giác có diện tích lớn nhất để ghép lại ra 1 tự giác có diện tích lớn nhất

// gọi m là số lượng đỉnh trên bao lồi

// m <= 2 => area = 0

// trường hợp đặc biệt m = 3 
// vãn không mất tính tổng quát, mình sẽ lấy diện tích tam giác của 3 đỉnh trên bao lồi, 
// trừ đi diện tích của 1 tam giác bên trong bao lồi sao cho tam giác đó có 2 đỉnh nằm trên bao lồi


// với m > 3
// gọi f1[i][j] sẽ là diện tích của tam giác có diện tích lớn nhất có đáy là a[i] và a[j], đỉnh còn lại nằm trên đường thẳng nối (a[i], a[j])
// gọi f2[i][j] sẽ là diện tích của tam giác có diện tích lớn nhất có đáy là a[i] và a[j], đỉnh còn lại nằm dưới đường thẳng nối (a[i], a[j])

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
#define PROB "LargestQuadrilateral"

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
int n; pll b[N], a[N];
pll st[N * 2], sd[N]; int topt, topd, in[N];
ll f[2][N][N];
vector < pll > hull;

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i].fi >> a[i].se;
}

ll Stri(pll t1, pll t2, pll t3){
    ll s1 = t1.fi * (t3.se - t2.se);
    ll s2 = t2.fi * (t1.se - t3.se);
    ll s3 = t3.fi * (t2.se - t1.se);
    return (s1 + s2 + s3);
}

bool check (int c, pll t1, pll t2, pll t3){
    ll s = Stri(t1, t2, t3);
    if (c == 1) return (s >= 0);
    if (c == 0) return (s < 0);
}

void convexhull(){
    topt = topd = 0;
    FU(i, 1, n){
        while (topt >= 2 && !check(1, st[topt-1], st[topt], a[i]))
            topt--;
        while (topd >= 2 && !check(0, sd[topd-1], sd[topd], a[i]))
            topd--;
        st[++topt] = sd[++topd] = a[i];
    }
    FD(i, topd - 1, 2)
        st[++topt] = sd[i];
    hull.clear();
    FU(i, 1, topt) hull.push_back(st[i]);
}

ll S(pll t1, pll t2, pll t3){
    return abs(Stri(t1, t2, t3));
}

int nxt(int i, int add, int m){
    int ret = (i + add) % m;
    return (ret ? ret : m);
}

void solve(){
    FU(i, 1, n) in[i] = 0;
    sort(a + 1, a + 1 + n);

    convexhull();
    int m = sz(hull);
    ll res = 0;
    if (m <= 2) res = 0LL;
    else if (m == 3){
        FU(i, 1, n) if(a[i] != hull[0] && a[i] != hull[1] && a[i] != hull[2]){
            ll tmp = -1;
            tmp = max(tmp, S(hull[0], hull[1], a[i]) + S(hull[0], hull[2], a[i]));
            tmp = max(tmp, S(hull[1], hull[2], a[i]) + S(hull[1], hull[0], a[i]));
            tmp = max(tmp, S(hull[2], hull[1], a[i]) + S(hull[2], hull[0], a[i]));
            res = max(res, tmp);
        }
    }
    else{
        FU(i, 0, m - 1) FU(j, 0, m - 1) FU(k, 0, 1) f[k][i][j] = 0;

        FU(i, 0, m - 1){
            int L = i;
            for(int j = (i + 1) % m; j != i % m; j = (j + 1) % m){
                int nextL = (L + 1) % m;
                if(S(hull[i], hull[j], hull[L]) < S(hull[i], hull[j], hull[nextL])) L = nextL;
                f[0][i][j] = f[0][j][i] = S(hull[i], hull[j], hull[L]);
            }
        }

        FU(i, 0, m - 1){
            int L = i;
            for(int j = (i - 1 + m) % m; j != i % m; j = (j - 1 + m) % m){
            int nextL = (L - 1 + m) % m;
            if(S(hull[i], hull[j], hull[L]) < S(hull[i], hull[j], hull[nextL])) L = nextL;
                f[1][i][j] = f[1][j][i] = S(hull[i], hull[j], hull[L]);
            }
        }
        FU(i, 0, m - 1)
        FU(j, 0, m - 1)
            res = max(res, f[0][i][j] + f[1][i][j]);

    }
    if (res < 0) cout << 0;
    else cout << res / 2LL << (res % 2LL ? ".5" : ""); EL;
}

int main(){
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}
