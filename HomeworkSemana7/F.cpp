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

    void build(vector <node> &v, int n, int l, int r, bool paridade){
        if(l==r){
            tree[n].value = v[l].value;

            return;
        }

        ll mid = (l+r)/2;
        build(v, 2*n, l, mid, !paridade);
        build(v, 2*n + 1, mid+1, r, !paridade);

        if(paridade) tree[n].value = (tree[2*n].value|tree[2*n + 1].value);
        else tree[n].value = (tree[2*n].value^tree[2*n + 1].value);
        return;
    }

    void updateAux(ll n, ll l, ll r, ll p, ll val, bool paridade){
        if(l==r){
            tree[n].value = val;

            return;
        }

        ll mid = (l+r)/2;
        if(p <= mid) updateAux(2*n, l, mid, p, val, !paridade);
        else updateAux(2*n+1, mid+1, r, p, val, !paridade);

        if(paridade) tree[n].value = (tree[2*n].value|tree[2*n + 1].value);
        else tree[n].value = (tree[2*n].value^tree[2*n + 1].value);
        return;
    }

    public:

    segTree(vector <node> &v, bool paridade){
        size = v.size()-1;
        tree.assign(4*(size), {0});

        build(v, 1, 1, size, paridade);
    }
    ~segTree(){

    }

    void update(ll pos, ll v, bool paridade){
        //cout << "\nval: " << v << "\n";
        updateAux(1, 1, size, pos, v, paridade);
        return;
    }

    ll query(){
        return tree[1].value;
    }

    void printTree(){
        for(auto i:tree) cout << i.value << " ";
        cout << endl;

        return;
    }

    
};

int main(){
    int n, m;
    cin >> n >> m;

    vector <node> v(pow(2, n)+1);
    for(int i=1; i<=pow(2, n); i++) cin >> v[i].value;

    segTree tree(v, n%2);

    while(m--){
        int p, b;
        cin >> p >> b;

        //tree.printTree();
        tree.update(p, b, n%2);
        cout << tree.query() << "\n";
    }

    return 0;
}