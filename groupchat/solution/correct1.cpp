#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
less<T> can be changed to:
1. less_equal<T>
2. greater<T>

ordered_set functions:
1. *(os.find_by_order(x)) -> return the value at position x (0 base)
2. os.order_of_key(x) -> return the number of elements less than x
*/

typedef long long ll;
#define int ll
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()

const int MOD=1000000007;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

#define fios(); ios_base::sync_with_stdio(0);cin.tie(0);
#define fraction(x); cout.unsetf(ios::floatfield); cout.precision(x); cout.setf(ios::fixed,ios::floatfield);
#define file(); freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

const int N=5e5+9;
int a[N];

struct ST{
    #define lc (n<<1)
    #define rc ((n<<1)+1)
    int t[4*N],lazy[4*N];
    ST(){
        memset(t,0,sizeof t);
        memset(lazy,0,sizeof lazy);
    }
    inline void push(int n,int b,int e){ //change this
        if(lazy[n]==0) return;
        t[n]=t[n]+lazy[n]*(e-b+1);
        if(b!=e){
            lazy[lc]=lazy[lc]+lazy[n];
            lazy[rc]=lazy[rc]+lazy[n];
        }
        lazy[n]=0;
    }
    inline int combine(int a,int b){ //change this
        return a+b;
    }
    inline void pull(int n){ //change this
        t[n]=t[lc]+t[rc];
    }
    void build(int n,int b,int e){
        lazy[n]=0; //change this
        if (b==e) {
            t[n]=a[b];
            return;
        }
        int mid=(b+e)>>1;
        build(lc,b,mid);
        build(rc,mid+1,e);
        pull(n);
    }
    void upd(int n,int b,int e,int i,int j,int v){
        push(n,b,e);
        if(j<b||e<i) return;
        if(i<=b&&e<=j){
            lazy[n]+=v; //set lazy
            push(n,b,e);
            return;
        }
        int mid=(b+e)>>1;
        upd(lc,b,mid,i,j,v);
        upd(rc,mid+1,e,i,j,v);
        pull(n);
    }
    int query(int n,int b,int e,int i,int j){
        push(n,b,e);
        if(i>e||b>j) return 0; //return null
        if(i<=b&&e<=j) return t[n];
        int mid=(b+e)>>1;
        return combine(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
    }
}t;

void solve(){
    int n,q;
    cin>>n>>q;
    int cur=0; //num of messages
    vector<int> read(n+1,0); //last read message
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            cur++;
        }
        else if(type==2){
            int f;
            cin>>f;
            int l=read[f]+1;
            int r=cur;
            if(l<=r) t.upd(1,1,N-1,l,r,1);
            read[f]=cur;
        }
        else{
            int s;
            cin>>s;
            cout<<t.query(1,1,N-1,s,s)<<endl;
        }
    }
    return;
}

int32_t main(){
    fios();
    //file();

    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;tc++){
        //cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0; 
}