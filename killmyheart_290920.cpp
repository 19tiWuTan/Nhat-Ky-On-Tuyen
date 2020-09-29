// task : https://codeforces.com/contest/1396/problem/C
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

const long long mod=1e9+7;
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
long long dp[N+5][2];
long long n,r1,r2,r3,d;
long long a[N+5];
int solve()
{
    cin>>n>>r1>>r2>>r3>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=-d;
    dp[0][1]=mod;
    for (int i=1;i<=n;i++)
    {
        dp[i][1]=min(dp[i-1][0]+d+min(r2,(a[i]+1)*r1),dp[i-1][1]+d+min(r2,(a[i]+1)*r1)+d+r1+d);
        dp[i][0]=min(dp[i-1][0]+d+a[i]*r1+r3,dp[i-1][1]+d+min(r2,(a[i]+1)*r1)+d+r1+d+r1);
    }

//    for (int i=1;i<=n;i++) cout<<dp[i][0]<<' '<<dp[i][1]<<"\n";
    cout<<min(dp[n][0],dp[n-1][1]+d+a[n]*r1+r3+d+r1);
}
int main()
{
  //  freopen("cf.inp","r",stdin);
  //  freopen("cf.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
