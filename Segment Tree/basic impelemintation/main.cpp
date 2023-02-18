/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#include <cmath>
#define Fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define clr(x) memset(x, -1 , sizeof(x));
#define Fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define lcm(x,y) x/__gcd(x,y)*y
const ll MOD = 1e9 + 7;
const ll sz = 1e5 + 2;
const ll OO = 1e17;
ll tree[1000000+9];
using namespace std;

struct segtree{
   ll sz;
   vector < ll > tree;
   segtree(ll n){
      sz = 1;

      while(n > sz) sz *= 2;

      tree.assign(2*sz,0LL);


   }
   void build(vector < ll > &orgarr , ll x , ll lx, ll rx){
      if(rx-lx == 1){
         if(lx < orgarr.size()){
            tree[x] = orgarr[lx];
         }
         return;
      }
      ll m = (rx+ lx)/2;

      build(orgarr, 2*x +1, lx , m); build(orgarr, 2*x+2, m,rx);
      tree[x] = tree[2*x+1] + tree[2*x +2];
      
   }
   void build( vector <ll> &orgarr){

            build(orgarr, 0,0,sz);

   }
   void set(ll i , ll v , ll x, ll lx , ll rx ){

           if(rx - lx  == 1){
            tree[x] = v;
             return;
           }

           ll m =(lx + rx) /2;

        if(i < m ) set(i,v,2*x + 1, lx , m);
        else set(i,v,2*x + 2, m , rx);

        tree[x] = tree[2*x + 1] + tree[2*x + 2];


   }
   void set(ll i ,ll v){

        set(i , v , 0 , 0, sz );
   }

   

   ll sum(ll l , ll r , ll x , ll lx , ll rx){
        if( rx <= l || lx >= r) return 0;
        if(lx >= l && rx <= r) return tree[x];

           ll m = (lx + rx) /2;
        ll ch1 = sum(l , r, 2*x +1, lx , m);
        ll ch2 = sum(l , r, 2*x +2, m , rx);

         return  ch1 + ch2;


   }
   ll sum(ll l , ll r){
          return sum( l ,  r , 0, 0, sz);
   }


};
int main()/**<  */
{
ll n , m ;

  cin >> n >> m;
  segtree st(n);ll v;
  vector < ll > orgarr(n);
  for(ll i = 0 ; i < n ; i++){
  cin >> orgarr[i];

  }


  st.build(orgarr);

  while(m--){
  ll op;
  cin >> op;
    if(op == 1){
       ll i; cin >> i >> v;
        st.set(i,v);

    }else {
        ll l , r;
        cin >> l  >> r;
         cout << st.sum(l,r) << "\n";

    }
  }
}
