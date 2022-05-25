#include <bits/stdc++.h>

using namespace std;

const long long inf = 0x3f3f3f;
typedef long long ll;
typedef pair <ll, int> ii;

class segTree{
    int size;
    vector <ii> tree;

    void build(vector <ll> &v, int n, int l, int r){
        if(l==r){
            tree[n].first = v[l];
            tree[n].second = l;
            return;
        }

        ll mid = (l+r)/2;
        build(v, 2*n, l, mid);
        build(v, 2*n + 1, mid+1, r);

        tree[n] = max(tree[2*n], tree[2*n + 1]);
        return;
    }

    void updateAux(ll n, ll l, ll r, ll p, ll val){
        if(l==r){
            tree[n].first = val;
            return;
        }

        ll mid = (l+r)/2;
        if(p <= mid) updateAux(2*n, l, mid, p, val);
        else updateAux(2*n+1, mid+1, r, p, val);

        tree[n] = max(tree[2*n], tree[2*n + 1]);
    }

    public:

    segTree(){
        size = 1e5+5;
        vector <ll> v(size+1, -inf);
        tree.assign(4*(size), {1, 1});

        build(v, 1, 1, size);
    }
    ~segTree(){

    }

    void update(ll pos, ll v){
        updateAux(1, 1, size, pos, v);
        return;
    }

    ii query(){
        return tree[1];
    }

    void printTree(){
        for(auto i=1; i<4*5; i++) cout << tree[i].first << " " << tree[i].second << " ";
        cout << endl;

        return;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long lucro = 0;
    cin >> n;

    map <string, int> leg;
    segTree seg;
    vector <int> initV;
    vector <bool> alive;
    int contador = 0;

    string cmd;

    while(n--){
        cin >> cmd;
        if(cmd == "BUY"){
            string name;
            int value;

            cin >> name >> value;

            initV.push_back(value);
            leg[name] = contador;
            seg.update(contador+1, 0);
            alive.push_back(1);

            contador++;
        }

        else if(cmd == "UPDATE"){
            string name;
            int value;

            cin >> name >> value;
            
            int pos = leg[name];
            if(alive[pos]) seg.update(pos+1, value - initV[pos]);
        }

        else if(cmd == "SELL"){
            ii chosen = seg.query();
            lucro += chosen.first;
            seg.update(chosen.second, -inf);
            alive[chosen.second-1] = 0;
        }
    }

    cout << lucro << "\n";

    return 0;
}