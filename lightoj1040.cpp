#include <bits/stdc++.h>
using namespace std;

#define   f(i,n) 					for(ll i=0;i<(n);i++)
#define   ff(i,n) 					for(ll i=1;i<=(n);i++)
#define   m0(X) 					memset((X), 0, sizeof((X)))
#define   m1(X) 					memset((X), -1, sizeof((X)))
#define   pb(x) 					push_back(x)
#define   F     					first
#define   S  						second
#define   MP 						make_pair
#define   inf						(1LL << 60LL)
#define	  debug1(x)                	cerr << #x << "= " << x << endl;
#define   debug2(x, y)             	cerr << #x << "= " << x << " | " << #y << "= " << y << endl;
#define   debug3(x, y, z)          	cerr << #x << "= " << x << " | " << #y << "= " << y << " | " << #z << "= " << z << endl;
#define   debug4(a, b, c, d)       	cerr << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "= " << c << " | " << #d << "= " << d << endl;
#define   debug5(a, b, c, d, x)     cerr << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "= " << c << " | " << #d << "= " << d << " | "<< #x << "= " << x << endl;
#define   debug6(a, b, c, d, x, y)  cerr << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "= " << c << " | " << #d << "= " << d << " | "<< #x << "= " << x << " | "<< #y<<"= "<<y<<endl;

typedef long long ll;

ll rd(ll &x){return scanf("%lld",&x);}
ll rd(ll &x,ll &y){return scanf("%lld%lld",&x,&y);}
ll rd(ll &x,ll &y,ll &z){return scanf("%lld%lld%lld",&x,&y,&z);}
ll rd(ll &x,ll &y,ll &z,ll &s){return scanf("%lld%lld%lld%lld",&x,&y,&z,&s);}

struct edge {
	ll u, v, w;
	edge(){}
	edge(ll uu, ll vv, ll ww){
		u=uu, v=vv, w=ww;
	}
	bool operator<(const edge& p) const{
		return w < p.w;
    }
};

const ll N=110;
ll n, par[N], pk[55][55];

vector <edge> e;
//vector <pair<ll,ll> > g[N];
//vector <ll> eTaken;

ll find (ll x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}

ll kruskal(){
    sort(e.begin(),e.end());
	f(i,n+1) par[i]=i;
	ll c=0, sum=0, sz=e.size();
	f(i,sz){
		ll u=find(e[i].u);
		ll v=find(e[i].v);
		if(u!=v){
			par[u]=v;
			ll w=e[i].w;
			sum+=w;
//			eTaken.pb(i);
	//		g[e[i].u].pb(MP(e[i].v,w));
		//	g[e[i].v].pb(MP(e[i].u,w));
			c++;
			if(c==n-1) break;
		}
	}
	return (c==n-1)?sum:inf;
}

int main()
{
    ll tc, w;
    rd(tc);
    ff(cs,tc){
        rd(n);
        e.clear(); m0(pk);
   //     m0(visit);
        ll sum=0;
        f(i,n){
            f(j,n){
                rd(w);
                pk[i][j]=w;
                sum+=w;
                if(w<1) continue;
                e.pb(edge(i,j,w));
            }
        }
        ll a=kruskal();
        ll cnt=0;
        f(i,n){
            if(par[i]==i) cnt++;
        }
        if(a==inf || cnt>1) printf("Case %lld: -1\n",cs);
        else printf("Case %lld: %lld\n",cs,sum-a);
    }


	return 0;
}
















