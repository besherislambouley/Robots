        /*
	 * we use binary search on answer , assume x is the value we want to check , lets use the weak robots in ascending order , now from the toys that the weak robot could remove we choose the largest x one of them looking at size , after finishing the weak robots we try to remove the rest toys using the small robots greedly 
	 * */
	#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
        #include <bits/stdc++.h>
        using namespace std;
        #define sqr 400
        #define mid (l+r)/2
        #define pb push_back
        #define ppb pop_back
        #define fi first
        #define se second
        #define lb lower_bound
        #define ub upper_bound
        #define ins insert
        #define era erase
        #define C continue
        #define mem(dp,i) memset(dp,i,sizeof(dp))
        #define mset multiset
        typedef long long ll;
        typedef short int si;
        typedef long double ld;
        typedef pair<int,int> pi;
        typedef pair<ll,ll> pll;
        typedef vector<int> vi;
        typedef vector<ll> vll;
        typedef vector<pi> vpi;
        typedef vector<pll> vpll;
        const ll mod=1e9+7;
        const ll inf= 4e18;
        const ld pai=acos(-1);
        #include "robots.h"
        int szw,szl,n;
        priority_queue<int> pq;
        int wl[100009],sl[100009];
        pi r[1000009];
        int check ( int x ) {
                int j = 0 ;
                while ( pq .size() ){
                        pq.pop () ;
                }
                for ( int i = 0 ;i < szw ;i ++ ) {
                        while ( j < n && r[j].fi<wl[i] ) {
                                pq.push ( r[j].se ) ;
                                j ++ ;
                        }
                        for ( int num = 0 ; num < x ; num ++ ){
                                if ( ! pq.size() ) break ;
                                pq .pop ();
                        }
                }
                for ( int i = j ; i < n ; i ++ ) {
                        pq.push( r[i].se ) ;
                }
                for ( int i = szl-1 ; i >= 0 ;i -- ){
                        for ( int num = 0 ; num < x ; num ++ ){
                                if ( pq.size() && pq.top () < sl[i] ) pq.pop() ;
                                else break ;
                        }
                }
                return pq.empty() ;
        }
        int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
                szw=A , szl = B , n = T ;
                for ( int i =0 ;i < n ;i ++ ) {
                        r[i]= { W[i] , S[i] } ;
                }
                for ( int i =0 ;i < szw ;i ++ ){
                        wl[i] = X[i];
                }
                for ( int i =0 ;i < szl ;i ++ ){
                        sl[i] = Y[i];
                }
                sort ( wl , wl+szw ) , sort ( sl , sl+szl ) , sort ( r , r+n ) ;
          		for (int i=0; i<T; i++) {
            		if ((!szw || r[i].first >= wl[szw-1]) && (!szl || r[i].second >= sl[szl-1])) {
           		     	return -1;
        		    }
     		   }
                int l = 0 , r = n  ;
                while ( r - l > 1 ) {
                        if ( check ( mid ) ) r = mid;
                        else l = mid;
                }
                return r ;
        }
