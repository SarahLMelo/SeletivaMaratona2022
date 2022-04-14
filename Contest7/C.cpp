#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node{
    string s = "";
    set <char> dist;

};

class segTree{
    vector <node> tree;
    ll size;

    void build(string &s, ll n, ll l, ll r){
        if( l == r){
            tree[n].s = s[l-1];
            tree[n].dist.insert(s[l-1]);

            return;
        }

        int mid = (l+r)/2;
        build(s, 2*n, l, mid);
        build(s, 2*n+1, mid+1, r);

        tree[n].s = tree[2*n].s + tree[2*n+1].s;

        tree[n].dist = tree[2*n+1].dist;
        tree[n].dist.insert(tree[n].dist.begin(), tree[n].dist.end());
        return;
    }

    void updateAux(ll n, ll l, ll r, ll pos, char c){
        if(l==r){
            tree[n].s = c;
            
        }
    }

    public:
        segTree(string &s){
            size = s.size();
            tree.resize(4*size);

            build(s, 1, 1, size);
        }

        ~segTree(){

        }

        void update(int pos, char c){

        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}