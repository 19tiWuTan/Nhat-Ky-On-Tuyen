///task : https://codeforces.com/problemset/problem/1245/F

#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int mod=1e9+7;
const int N=1e6;


pii origin;
void operator-=(pii &A, pii B) {
    A.X -= B.X;
    A.Y -= B.Y;
}
bool ccw(pii O, pii A, pii B) {
    A -= O, B -= O;
    return A.X * B.Y > A.Y * B.X;
}
bool cmp(pii A, pii B) { return ccw(origin, A, B); }

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t);
        t=(t*t);
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}
ll dp[2][2][2][2];
ll dpnew[2][2][2][2];
int l,r;
void solve()
{
    cin>>l>>r;
    memset(dp,0,sizeof(dp));
    dp[1][1][1][1]=1;
    for (int i=29;i>=0;i--)
    {
        memset(dpnew,0,sizeof(dpnew));
        int L=(l>>i)&1,R=(r>>i)&1;
        for (int al=0;al<=1;al++)
        for (int ar=0;ar<=1;ar++)
        for (int bl=0;bl<=1;bl++)
        for (int br=0;br<=1;br++)
        for (int a=0;a<=1;a++)
        for (int b=0;b<=1;b++)
        {
            if (a&&b) continue;
            if (al&&L>a) continue;
            if (bl&&L>b) continue;
            if (ar&&R<a) continue;
            if (br&&R<b) continue;
            dpnew[al&&L==a][ar&&R==a][bl&&L==b][br&&R==b]+=dp[al][ar][bl][br];
        }
        memcpy(dp,dpnew,sizeof(dp));
    }
    ll ans=0;
    for (int i=0;i<=1;i++)
    for (int j=0;j<=1;j++)
    for (int u=0;u<=1;u++)
    for (int v=0;v<=1;v++) ans+=dp[i][j][u][v];
    cout<<ans<<"\n";
}
int main()
{
   // freopen("cf.inp","r",stdin);
  //  freopen("cf.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while (T--) solve();
}
