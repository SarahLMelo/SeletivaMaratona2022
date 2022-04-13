#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct node{
    double value = 0;
};

class segTree{
    int size;
    vector <node> tree;

    void build(vector <node> &v, int n, int l, int r){
        if(l==r){
            tree[n].value = v[l].value;

            return;
        }

        ll mid = (l+r)/2;
        build(v, 2*n, l, mid);
        build(v, 2*n + 1, mid+1, r);

        tree[n].value = (tree[2*n].value+tree[2*n + 1].value);
        return;
    }

    void updateAux(ll n, ll l, ll r, ll p, double val){
        if(l==r){
            tree[n].value = val;

            return;
        }

        ll mid = (l+r)/2;
        if(p <= mid) updateAux(2*n, l, mid, p, val);
        else updateAux(2*n+1, mid+1, r, p, val);

        tree[n].value = (tree[2*n].value+tree[2*n + 1].value);
        return;
    }

    double queryAux(ll n, ll l, ll r, ll lInter, ll rInter){
        if(lInter <= l && rInter >= r){
            return tree[n].value;
        }

        if(lInter > r || rInter < l) return 0;

        ll mid = (l+r)/2;
        double left = queryAux(2*n, l, mid, lInter, rInter);
        double right = queryAux(2*n + 1, mid+1, r, lInter, rInter);

        return (left+right);
    }

    public:

    segTree(vector <node> &v){
        size = v.size()-1;
        tree.assign(4*(size), {0});

        build(v, 1, 1, size);
    }
    ~segTree(){

    }

    void update(ll pos, double v){
        //cout << "\nval: " << v << "\n";
        updateAux(1, 1, size, pos, v);
        return;
    }

    double query(ll l, ll r){
        return (queryAux(1, 1, size, l, r)/(r-l+1));
    }

    void printTree(){
        for(auto i:tree) cout << i.value << " ";
        cout << endl;

        return;
    }

    
};

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << fixed;
    cout << setprecision(6);

    vector <node> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i].value;

    segTree tree(v);
    //tree.printTree();
    //cout << endl;
    int q;
    cin >> q;

    while(q--){
        int t;
        cin >> t;

        if(t==1){
            int i;
            double v;

            cin >> i >> v;
            //cout << "\n" << i << " " << v << endl;
            tree.update(i, v);
            //tree.printTree();
            //cout << endl;
        }

        else{
            int l, r;
            cin >> l >> r;

            cout << tree.query(l, r) << "\n";

        }
    }

    return 0;
}