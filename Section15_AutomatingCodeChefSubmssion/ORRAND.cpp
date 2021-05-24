#include<bits/stdc++.h>
#define ll long long int 
#define ld long double
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define pb push_bact
#define mp mate_pair
#define resest(a, b) memset(a, b, sizeof(a))
#define vi vector<ll>
#define pii pair<ll,ll>
#define fi first
#define se second
#define mod         (1000000000+7)
#define ERASE(x)    x.erase(unique(x.begin(),x.end()),x.end()) //removes repeated element;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
bool prime(ll n) 
{   
        if (n <= 1)  return false; 
        if (n <= 3)  return true; 
        if (n%2 == 0 || n%3 == 0) return false; 
        for (ll i=5; i*i<=n; i=i+6) 
            if (n%i == 0 || n%(i+2) == 0) 
               return false; 
        return true; 
}
 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) return a; 
    return gcd(b, a % b);  
}
 
void online ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
#endif
}

int count_digits(int n)
{
    string num = to_string(n);
     return num.size();
}

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];
 
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    return subset[n][sum];
}

bool isvow(char s)
{
  if(s == 'a' || s=='e' || s=='i' || s=='o' || s=='u')
    return true;
  else
    return false;
}

bool isKthBitSet(int n, int k)
{
    if (n & (1 << k))
        return true;
    else
        return false;
}

int main ()
{
  online ();
  fast_io;
  int t;
  cin >> t;
  while(t--)
  {
  int n,q;
  cin >> n >> q;
  int arr[n];
  int fn[32];
  memset(fn,0,sizeof(fn));
  int ans=0;
  rep(i,n)
  {
    cin >> arr[i];
    rep(j,32)
    {
      if(isKthBitSet(arr[i],j))
        fn[j]++;
    }
    ans = ans | arr[i];
  }
  cout << ans << "\n";
  while(q--)
  {
    int x,v;
    cin >> x>>v;
    rep(i,32)
    {
      if(isKthBitSet(arr[x-1],i))
        fn[i]--;
      if(isKthBitSet(v,i))
        fn[i]++;
    }
    arr[x-1]=v;
    int ans1=0;
    rep(i,32)
    {
      if(fn[i]>0) ans1+=pow(2,i);
    }
    cout << ans1 << "\n";
  }
  }
  return 0;
}