//Indeed Hardship comes with ease [94:6]
//Man will not get anything unless he works hard  [53:39]
//ᴇᴀᴄʜ ᴘᴇʀꜱᴏɴ ᴡɪʟʟ ᴏɴʟʏ ʜᴀᴠᴇ ᴡʜᴀᴛ ᴛʜᴇʏ ᴇɴᴅᴇᴀᴠᴏᴜʀᴇᴅ ᴛᴏᴡᴀʀᴅꜱ [53:39]
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
const int maxn= 500005;
ll arr[maxn];
ll tree[4*maxn];
ll lazy[4*maxn];
void push(ll node,ll start,ll end)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node]*(end-start+1);
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]+=tree[2*node]+tree[2*node+1];
}
void update(ll node, ll start, ll end, ll l, ll r, ll val)
{
    push(node,start,end);
    if(start>r||end<l)
    {
        return;
    }
    if(start>=l && end<=r)
    {
        tree[node]+=val*(end-start+1);
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    ll mid=(start+end)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node] = tree[2*node]+tree[2*node+1];
}
ll query(ll node, ll start, ll end, ll l, ll r)
{
    push(node,start,end);
    if(start>=l && end<=r)
    {
        return tree[node];
    }
    if(start>r || end<l)
    {
        return 0;
    }
    ll mid=(start+end)/2;
    ll p1= query(2*node,start,mid,l,r);
    ll p2= query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,Q;
    cin >> n>> Q;
    ll q = Q;
    ll msg=0;
    vector<ll>last(n+1,0); 
    build(1,0,q-1);
    while(Q--)
    {
        ll t;
        cin >> t;
        if(t==1)
        {
            msg++;
        }
        else if(t==2)
        {
            ll f;
            cin >> f;
            if(last[f]>0)
            {
                update(1,0,q-1,last[f]-1,last[f]-1,-1);
            }
            last[f]=msg;
            update(1,0,q-1,last[f]-1,last[f]-1,1);
        }
        else
        {
            ll s;
            cin >> s;
            cout << query(1,0,q-1,s-1,msg-1) << "\n";
        
        }
    }
 
 
    return 0;
}   