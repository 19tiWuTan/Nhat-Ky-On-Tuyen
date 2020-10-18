/*

    task : cho  N xâu kí tự s[i] phân biệt, gồm Q truy vấn
    mỗi truy vấn cho biết K vị trí x[i] và 1 số L
    yêu cầu đếm xem có bao nhiêu xâu T phân biệt là tiền tố của đúng L xâu : S(x1), S(x2), ... S(xk)

    ứng dụng của sufix array

    -> sort lại n xâu theo thứ tự từ điển tăng dần
    một xâu T là tiền tố của chính xác L xâu khi nó là tiền tố của L xâu liên tiếp sau khi đã sort

    bài toán bây giờ thành : đếm số xâu T là tiền tố của chính xác của L xâu liên tiếp và nó
    khác hoàn toàn với những tiền tố độ dài |T| của những xâu còn lại


    ví dụ  : L = 2
    abcd
    abcea
    abee
    nb
    nit

    LCP (a, b) là longest common prefix của xâu a và b
    xét các xâu từ 1.. 2 : ta tìm được T = abc có |T| = 3 là LCP của(s[1], s[2]) mà nó khác với những xâu còn lại
    (nếu chọn "ab") thì nó sẽ trùng với tiền tố độ dài 2 của s[3] nên "ab" khong thỏa và đơn nhiên "a" cũng không)


    LCP (s[i], s[i+1], .. , s[i+L-1]) = LCP(s[i], s[i+L-1]) do đã xắp xếp các xâu lại theo thú tự từ điển

    Ví dụ 5 xâu này : abc abcdef abcdeg abcdei abcdh

    xét 3 xâu liên tiếp từ 2 đến 4 có LCP(s2, s3, s4) = LCP(s2, s4) = abcde
    Thế thì mình có 5 ứng cử viên để cập nhật vào biến kết quả là : a, ab, abc, abcd, abcde
    Do yêu cầu là xâu T phải là tiền tố của chính xác của L xâu nên mình cần loại những ứng cử viên là tiền tố của những xâu bên ngoài đoạn mình đang xết
    do đã sort lại các xâu nên để xét xem 1 xâu T có vừa là tiền tố của i..i+l-1 và là tiền tố của 1 vài xâu bên ngoài nào hay không
    mình chỉ việc xét lcp(i, i+1, .. i+l-1) với s[i-1] và s[i+l]


    để loại nhanh ứng cử viên thì mình có những nhận xét này :

    nếu abc bị loại thì chác chắn ab và a cũng bị loại

    với ví dụ tren LCP(i, i+1, .. i+l-1) = abcde
    xét xâu s[1] với abcde, mình có LCP(s[1], abcde) = lcp(abc, abcde) = abc, nên các ứng cử viên abc, ab, a lần lượt bị loại
    tương tự với s[5] và abcde, có LCP(s[5], abcde) = lcp(abcdh, abcde) = abcd nên các ứng cử viên a, ab, abc, abcd bị loại
    nên chỉ còn abcde là ứng cử viên sáng giá =))




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
#define PROB "Pokegene"
using namespace std;
typedef long long ll;
typedef double db;

const int N = 2e5 + 2;
const int base = 331;
const ll mod = 1e9 + 7;
int n, q, p[N], id[N];
string s[N];
vector < vector < ll > > has;
bool cmp (int t1, int t2){
    return s[t1] < s[t2];
}

bool cmp_pos(int t1, int t2){
    return id[t1] < id[t2];
}

int LCP(int i, int j){
    int l = 1, r = min((int)s[i].size(), (int)s[j].size());
    int ret = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (has[i][mid] == has[j][mid]) {
            ret = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ret;
}

void solve(){
    cin >> n >> q;
    has.resize(n + 2);
    FU(i, 0, n - 1){
        cin >> s[i];
        p[i] = i;
        int siz = s[i].size();
        has[i].resize(siz + 1);
        has[i][0] = 0;
        FU(j, 1, s[i].size())
            has[i][j] = (has[i][j-1] * base + s[i][j-1] - 'a' + 1) % mod;
    }

    sort(p, p + n, cmp);
    FU(i, 0, n - 1) id[p[i]] = i;

    while (q--){
        int k, l;
        cin >> k >> l;
        vector < int > pos(k);
        FU(i, 0, k - 1){
            cin >> pos[i];
            pos[i]--;
        }
        sort(pos.begin(), pos.end(), cmp_pos);
        int res = 0;
        FU(i, 0, k - l){
            int add = LCP(pos[i], pos[i+l-1]);
            res+= add - min(add, max(i ? LCP(pos[i], pos[i-1]) : 0
                                   , i + l < k ? LCP(pos[i], pos[i+l]) : 0));
        }
        cout << res,EL;
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
    while (t--) solve();
}

