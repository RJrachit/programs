#include <bits/stdc++.h>
using namespace std;

#define M 998244353
#define inf 1e18
#define pb push_back
#define ff first
#define ss second
#define int long long int
#define ld long double
#define pi pair<li, li>
#define ins insert
#define vc vector
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(), x.end()
#define fr(i, a, n) for (int i = a; i < n; i++)
#define frr(i, a, n) for (int i = n - 1; i >= a; i--)
#define file_in freopen("a.txt", "r", stdin);
void testcase()
{
    int s; cin>>s;
    int n; cin>>n;

    int ans=0;
    if(s%2==1)
        ans+=1;
    s-=1;
    if(n%2==1)
        n-=1;
    ans += s/n;
    if(s%n!=0)
        ans++;
    cout<<ans<<"\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
        testcase();
    return 0;
}
