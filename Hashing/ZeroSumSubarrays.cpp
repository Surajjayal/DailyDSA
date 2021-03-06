//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define str string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

ll bizan(ll a[],ll n){
  unordered_map<ll,ll> mp;

  ll count = 0;

  fr(i,n){
    if(a[i] == 0)
      count++;
    auto it = mp.find(a[i]);
    if(it == mp.end())
      mp[a[i]] = 0;
    else{

      count+=mp[a[i]]+1;
      mp[a[i]]++;
    }
  }

  return count;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n];

    fr(i,n)
      cin>>a[i];

    fr1(i,1,n,1)
      a[i]+=a[i-1];

    cout<<bizan(a,n)<<endl;
  }
  return 0;
}
