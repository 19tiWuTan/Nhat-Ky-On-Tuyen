/// task : https://atcoder.jp/contests/agc047/tasks/agc047_b

/*
  hint 1 : abcdghi có thể đưa về aghi
  hitn 2 : trie
  
  từ hint 1 ta có thể thấy rằng xâu S có thể đưa về xâu T nếu và chỉ nếu : 
    -đặt L = |T| , thì xâu S và T có chung tiền tố độ dài L - 1, kí tự đầu tiên của xâu T sẽ xuất hiện ở đâu đó [1, |S| - (L - 1)| trong xâu S
   
  để tiện xử lý trên cây trie ta reverse tất cả N xâu 
  thế thì với mỗi xâu S[i], ta cần đếm xem có bao nhiêu xâu có chung tiền tố độ dài |S[i] - 1| và có chứa kí tự cuối cùng của xâu S[i]
  ở mỗi node trong cây trie, ta cần biết ở dưới node có bao nhiêu xâu chứa kí tự c ( c = 'a' ... 'z' )

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
#define PROB "FirstSecond"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 200002;
int n, in[26]; string s[N];
struct node{
    bool ed; ll cnt[26];
    struct node *index[26];
};

node *root;

struct node *new_node(){
    node *temp = (struct node*) malloc(sizeof(struct node));
    FU(i, 0, 25)
        temp->cnt[i] = 0,
        temp->index[i] = NULL;
    temp->ed = false;
    return temp;
};

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> s[i];
}


void solve(){
    root = new_node();

    ll res = 0;
    FU(i, 1, n){
        reverse(s[i].begin(), s[i].end());
        FU(c, 0, 25) in[c] = 0;
        for (auto j : s[i]) in[j - 'a']++;
        node *cur = root;
        for (auto j : s[i]){
            FU(c, 0, 25) if (in[c]) cur->cnt[c]++;
            in[j - 'a']--;
            if (cur->index[j - 'a'] == NULL) cur->index[j - 'a'] = new_node();
            cur = cur->index[j - 'a'];
        }
    }

    FU(i, 1, n){
        node *cur = root;
        FU(j, 0, sz(s[i]) - 2) cur = cur->index[s[i][j] - 'a'];
        int l = sz(s[i]) - 1;
        res+= cur->cnt[s[i][l] - 'a'] - 1;
    }
    cout << res;
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


