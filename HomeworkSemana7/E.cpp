#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct node{
    ll value = 0;
};

class segTree{
    int size;
    vector <node> tree;

    void updateAux(ll n, ll l, ll r, ll p, ll val){
        if(l==r){
            tree[n].value = val + tree[n].value;

            return;
        }

        ll mid = (l+r)/2;
        if(p <= mid) updateAux(2*n, l, mid, p, val);
        else updateAux(2*n+1, mid+1, r, p, val);

        tree[n].value = (tree[2*n].value+tree[2*n + 1].value);
        return;
    }

    ll queryAux(ll n, ll l, ll r, ll lInter, ll rInter){
        if(lInter <= l && rInter >= r){
            return tree[n].value;
        }

        if(lInter > r || rInter < l) return 0;

        ll mid = (l+r)/2;
        ll left = queryAux(2*n, l, mid, lInter, rInter);
        ll right = queryAux(2*n + 1, mid+1, r, lInter, rInter);

        return (left+right);
    }

    public:

    segTree(int n){
        size = n;
        tree.assign(4*(size), {0});
    }
    ~segTree(){

    }

    void update(ll pos, ll v){
        //cout << "\nval: " << v << "\n";
        updateAux(1, 1, size, pos, v);
        return;
    }

    ll query(ll l, ll r){
        return (queryAux(1, 1, size, l, r));
    }

    void printTree(){
        for(auto i:tree) cout << i.value << " ";
        cout << endl;

        return;
    }

    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    segTree tree(n);

    while(q--){
        string cmd;
        cin >> cmd;

        if(cmd == "add"){
            int p, f;
            cin >> p >> f;
            tree.update(p, f);
        }
        else{
            int a, b;
            cin >> a >> b;

            cout << tree.query(a, b) << "\n";
        }

    }

    return 0;
}