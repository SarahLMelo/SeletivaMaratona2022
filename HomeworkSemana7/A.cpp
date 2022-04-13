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

    void build(vector <node> &v, int n, int l, int r){
        if(l==r){
            if(v[l].value>0) tree[n].value = 1;
            else if(v[l].value<0) tree[n].value = -1;
            else tree[n].value = 0;

            return;
        }

        ll mid = (l+r)/2;
        build(v, 2*n, l, mid);
        build(v, 2*n + 1, mid+1, r);

        tree[n].value = tree[2*n].value*tree[2*n + 1].value;
        return;
    }

    void updateAux(ll n, ll l, ll r, ll p, ll val){
        if(l==r){
            if(val>0) tree[n].value = 1;
            else if(val<0) tree[n].value = -1;
            else tree[n].value = 0;

            return;
        }

        ll mid = (l+r)/2;
        if(p <= mid) updateAux(2*n, l, mid, p, val);
        else updateAux(2*n+1, mid+1, r, p, val);

        tree[n].value = tree[2*n].value * tree[2*n + 1].value;
    }

    int queryAux(ll n, ll l, ll r, ll lInter, ll rInter){
        if(lInter <= l && rInter >= r){
            //if(tree[n].value > 0) return 1;
            //else if(tree[n].value < 0) return -1;
            return tree[n].value;
        }

        if(lInter > r || rInter < l) return 1;

        ll mid = (l+r)/2;
        ll left = queryAux(2*n, l, mid, lInter, rInter);
        ll right = queryAux(2*n + 1, mid+1, r, lInter, rInter);

        return left*right;
    }

    public:

    segTree(vector <node> &v){
        size = v.size()-1;
        tree.assign(4*(size), {1});

        build(v, 1, 1, size);
    }
    ~segTree(){

    }

    void update(ll pos, ll v){
        updateAux(1, 1, size, pos, v);
        return;
    }

    int query(ll l, ll r){
        return queryAux(1, 1, size, l, r);
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

    int N, K;
    while(cin >> N >> K){
        vector <node> v(N+1);
        for(int i=1; i<=N; i++){
            cin >> v[i].value;
        }

        segTree tree(v);

        while(K--){
            char query;
            cin >> query;

            //if(K == 5) tree.printTree();

            if(query == 'P'){
                int ans, I, J;
                cin >> I >> J;

                ans = tree.query(I, J);
                //cout << "\nAns: " << ans << "\n";
                if(ans>0) cout << "+";
                else if(ans<0) cout << "-";
                else cout << "0";
            }
            else{
                int I, V;
                cin >> I >> V;

                tree.update(I, V);
            }
        }

        cout << endl;
    }

    return 0;
}