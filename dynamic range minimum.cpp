// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9+7;
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
 
 
 
int f(int a , int b){
  return min(a,b);
}
 
struct Segtree{
vector<int>lazy,tree , arr;
int n ;int tar;
Segtree(vector<int>& a){
   n = a.size();  tar= 1e18;
  lazy.resize(4*n+4); tree.resize(4*n+4); arr.resize(n+1);
  for(int i= 1; i<=n ;i++)arr[i] =a[i-1];
  build(1,1,n);
}
 
void build(int node , int st , int en ){
   if(st==en){
     tree[node] = arr[st];return;
   }
   int mid = (st+en)/2;
   // pehle left vala bna
   build(2*node ,st, mid);
   // right vala bna le 
   build(2*node +1 , mid+1 , en);
 
   tree[node] = f(tree[2*node] , tree[2*node+1]);
}
 
int update(int node , int st , int en , int l , int r , int val){
    if(st>r || en<l){
      return tree[node]; // this node has got out of range
    }
    // partial overlap or extended overlap
    if(st == l && st==en){
      tree[node] = val;
      return val;
    }
    int mid = (st+ en)/2;
 
    int q1 = update(2*node , st, mid , l , r, val);
    int q2 = update(2*node +1 ,mid+1 , en , l , r , val);
    tree[node] = min(q1,q2);
    return tree[node];
}
 
int get(int node , int st , int en , int  l , int r){
  // itna aage aa hi gya to pehle lazy ko check krleta 
 
 
  if(st>r || en<l){
    // no overlap
    return tar;
  }
 
 
  // if(lazy[node]!=0){
  //   if(st == en)lazy[node] = 0;
  //   else{
  //     int sz = (en-st+1);
  //     tree[2*node] += lazy[node]*((sz+1)/2);
  //     tree[2*node+1] += lazy[node]*(sz/2);
  //     lazy[2*node+1] += lazy[node]; lazy[2*node]+=lazy[node];
  //     lazy[node] = 0;
  //   }
  // }
  
  
 
  if(st>=l and en<=r){
    // full overlap
    return tree[node];
  }
 
  int mid = (st+en)/2;
  int  ans = f(get(2*node , st , mid , l ,r) , get(2*node+1 , mid+1 , en , l , r));
  return ans ;
}
};
 
void solve(){
  int n,q; cin >> n >> q;
  vector<int>a(n); for(auto& e:a)cin >> e;
  Segtree S(a);
  // debug(S.tree);
  while(q--){
    int sw, p , q;
    cin >> sw >> p >> q;
    if(sw == 1){
      
       S.update(1,1,n,p,p,q);
    }
    else{
       cout << S.get(1,1,n,p,q) << '\n';
    }
  }
}
 
signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
