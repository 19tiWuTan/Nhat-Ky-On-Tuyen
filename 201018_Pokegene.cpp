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

#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 311;
const double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[6] = {0, 0, 1, -1, 1, -1};
const int dy[6] = {1, -1, 0, 0, 1, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 5e3 + 10;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > h(n);
    vector<string> s(n);
    vector<int> p(n), id(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int sz = (int)s[i].size();
        h[i].resize(sz + 1);
        for (int j = 1; j <= sz; j++) {
            h[i][j] = (1LL * h[i][j - 1] * Base + (int)s[i][j - 1]) % MOD;
        }
        p[i] = i;
    }
    auto LCP = [&](int i, int j) {
        int L = 1, R = min((int)s[i].size(), (int)s[j].size());
        int res = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (h[i][mid] == h[j][mid]) {
                res = mid;
                L = mid + 1;
            }
            else R = mid - 1;
        }
        return res;
    };
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    for (int i = 0; i < n; i++) id[p[i]] = i;
    while (q--) {
        int k, L;
        cin >> k >> L;
        vector<int> x(k);
        for (int i = 0; i < k; i++) {
            cin >> x[i];
            x[i]--;
        }
        sort(x.begin(), x.end(), [&](int i, int j) {
            return id[i] < id[j];
        });
        int res = 0;
        for (int i = 0; i < k - L + 1; i++) {
            int cost = LCP(x[i], x[i + L - 1]);
            int cL = 0, cR = 0;
            if (i > 0) cL = LCP(x[i - 1], x[i]);
            if (i + L < k) cR = LCP(x[i], x[i + L]);
            res += cost - min(cost, max(cL, cR));
        }
        cout << res << '\n';
    }
}

void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
