// task : https://codeforces.com/problemset/problem/1227/E
// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "Forest"

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

vector < vector < int > > forest, sum, a, ans;
int n, m;

void readinp(){
    cin >> n >> m;
    FU(i, 0, n){
        if (i == 0){
            vector < int > temp;
            FU(j, 0, m + 1) temp.pb(0);
            forest.pb(temp); sum.pb(temp), a.pb(temp), ans.pb(temp);
            continue;
        }

        vector < int > temp ;
        string s;
        cin >> s;
        temp.pb(0);
        FU(j, 0, m - 1)
            temp.pb(s[j] == 'X');
        temp.pb(0);
        forest.pb(temp); sum.pb(temp), a.pb(temp), ans.pb(temp);
        if (i == n){
            forest.pb(temp); sum.pb(temp), a.pb(temp), ans.pb(temp);
        }
    }
}

int get (int xa, int ya, int xb, int yb){
    return sum[xb][yb] - sum[xa-1][yb] - sum[xb][ya-1] + sum[xa-1][ya-1];
}

void upd (int xa, int ya, int xb, int yb, int v){
    a[xa][ya]+=v;
    a[xb+1][yb+1]+=v;
    a[xa][yb+1]-=v;
    a[xb+1][ya]-=v;
}

int sq(int x) {
    return x * x;
}



bool check(int k){
    FU(i, 0, n + 1) FU(j, 0, m + 1) a[i][j] = 0;
    FU(i, k + 1, n - k) {
        FU(j, k + 1, m - k){
            if (get(i - k, j - k, i + k, j + k) == sq(2 * k + 1)){
                upd(i - k, j - k, i + k, j + k, 1);
            }

        }
    }
    FU(i, 1, n) FU(j, 1, m) a[i][j]+= a[i][j-1];
    FU(i, 1, n) FU(j, 1, m) a[i][j]+= a[i-1][j];
    FU(i, 1, n) FU(j, 1, m)
        if (forest[i][j] == 1 && a[i][j] == 0)
            return false;
    return true;
}

void solve(){
    FU(i, 1, n) FU(j, 1, m)
        sum[i][j]+= sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    int l = 1, r = min(n, m) / 2;
    int res = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    FU(i, 1, n) FU(j, 1, m) ans[i][j] = 0;
    cout << res; EL;
    FU(i, res + 1, n - res) {
        FU(j, res + 1, m - res){
            if (get(i - res, j - res, i + res, j + res) == sq(2 * res + 1)){
                ans[i][j] = 1;
            }

        }
    }
    FU(i, 1, n) {
        FU(j, 1, m) cout << (ans[i][j] ? 'X' : '.');
        EL;
    }
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

