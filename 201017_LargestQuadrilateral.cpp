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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll> point;
#define x first
#define y second
const int N = 4096;
point a[N + 1], st[N + 1], hull[N + 1];
ll ftop[N + 1][N + 1], fbot[N + 1][N + 1];
int n, m;

ll stri(point a, point b, point c){
    ll tmp1 = a.x * (c.y - b.y);
    ll tmp2 = b.x * (a.y - c.y);
    ll tmp3 = c.x * (b.y - a.y);
    return (tmp1 + tmp2 + tmp3);
}

ll S(point a, point b, point c){
    return abs(stri(a, b, c));
}

bool directop(point a, point b, point c){
    return (stri(a, b, c) >= 0);
}

bool direcbot(point a, point b, point c){
    return (stri(a, b, c) < 0);
}

void convexhull(){
    sort(a + 1, a + n + 1);
    int top = 1;
    st[top] = a[1];
    for(int i = 2; i <= n; ++i){
        while(top >= 2 && !(directop(st[top - 1], st[top], a[i]))) --top;
        st[++top] = a[i];
    }
    m = 0;
    for(int i = 1; i <= top; ++i){
        hull[m] = st[i];
        ++m;
    }
    top = 1;
    st[top] = a[1];
    for(int i = 2; i <= n; ++i){
        while(top >= 2 && !(direcbot(st[top - 1], st[top], a[i]))) --top;
        st[++top] = a[i];
    }
    for(int i = top - 1; i > 1; --i){
        hull[m] = st[i];
        ++m;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> a[i].x >> a[i].y;
        }
        convexhull();
        ll ans = 0;
        if(m == 3){
            for(int i = 1; i <= n; ++i){
                if(a[i] != hull[0] && a[i] != hull[1] && a[i] != hull[2]){
                    ll tmp = S(hull[0], hull[1], a[i])
                                + S(hull[0], hull[2], a[i]);
                    tmp = max(tmp, S(hull[1], hull[2], a[i])
                                + S(hull[1], hull[0], a[i]));
                    tmp = max(tmp, S(hull[2], hull[1], a[i])
                                + S(hull[2], hull[0], a[i]));
                    ans = max(ans, tmp);
                }
            }
        }
        if(m >= 4){
            for(int i = 0; i < m; ++i){
                int L = i;
                for(int j = (i + 1) % m; j != i % m; j = (j + 1) % m){
                    int nextL = (L + 1) % m;
                    if(S(hull[i], hull[j], hull[L]) < S(hull[i], hull[j], hull[nextL])) L = nextL;
                    ftop[i][j] = ftop[j][i] = S(hull[i], hull[j], hull[L]);
                }
            }
            for(int i = 0; i < m; ++i){
                int L = i;
                for(int j = (i - 1 + m) % m; j != i % m; j = (j - 1 + m) % m){
                    int nextL = (L - 1 + m) % m;
                    if(S(hull[i], hull[j], hull[L]) < S(hull[i], hull[j], hull[nextL])) L= nextL;
                    fbot[i][j] = fbot[j][i] = S(hull[i], hull[j], hull[L]);
                }
            }
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < m; ++j){
                    ans = max(ans, fbot[i][j] + ftop[i][j]);
                }
            }
        }
        cout << ans / 2;
        if(ans % 2) cout << ".5";
        cout << "\n";
    }
    return 0;
}
