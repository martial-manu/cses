// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;
 
 
template<typename... T>
void debug(T&... args){
  cout << "\n==================\n";
  ((cout<< args<<", "), ...);
  cout << "\n==================\n";
}
template<typename T>
void debug(vector<T>& a){
  cout << "\n==============\n";
  for(auto& e:a)cout << e << ' ';
  cout << "\n==============\n";
}
 
template<typename... T>
void put(T&... args) { ((cout << args << " "), ...);}

void solve(){
   int crt = 0;

   int n ; cin>> n;
   vector<pair<int,int> >a(n);
   for(int i =0 ;i<n ; i++)cin >> a[i].second >> a[i].first ;

   sort(a.begin() , a.end());
   int ans = 0;
   for(int i =0 ; i<n ; i++){
     if(a[i].second >= crt){
        ans++; crt = a[i].first;
     }
     else{
         ;
     }
   }
   cout<< ans << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
