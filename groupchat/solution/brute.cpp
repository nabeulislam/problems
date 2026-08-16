#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solution(){
    int n, q; cin >> n >> q;
    vector<int> msg, last(n);
    ordered_set ost;

    for (int i = 1; i <= q; i++){
        int type; cin >> type;
        if (type == 1) msg.push_back(i);
        else if (type == 2){
            int f; cin >> f; f--;
            if (last[f]) ost.erase(last[f]);
            ost.insert(i);
            last[f] = i;
        }
        else {
            int s; cin >> s; s--;
            cout << ost.size() - ost.order_of_key(msg[s]) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();

    return 0;
}