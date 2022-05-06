#include <bits/stdc++.h>

using namespace std;

long long in[(long long)(4 * 1e5 + 5)];
long long out[(long long)(4 * 1e5 + 5)];
long long legenda[(long long)(4 * 1e5 + 5)];
long long cores[(long long)(4 * 1e5 + 5)];
vector <vector <long long>> g;

struct node{
    long long differentColors;
};

class segTree{
    long long size;
    vector <node> tree;
    vector <bool> dirty;

    void build(long long n, long long l, long long r){
        if(l==r){
            tree[n].differentColors = 1;
            tree[n].differentColors <<= cores[legenda[l]];

            return;
        }

        long long mid = (l+r)/2;
        build(2*n, l, mid);
        build(2*n + 1, mid+1, r);

        tree[n].differentColors = tree[2*n].differentColors|tree[2*n + 1].differentColors;
        return;
    }

    void apply(long long n, long long l, long long r){ //Passa a mudança para os filhos
      if(l == r || dirty[n] == 0) return;

      tree[2*n] = tree[n];
      dirty[2*n] = 1;

      tree[2*n + 1] = tree[n];
      dirty[2*n + 1] = 1;

      dirty[n] = 0;
    }

    void updateAux(long long n, long long l, long long r, long long x, long long y, long long colour){
        apply(n, l, r);
        if(l >= x && r <= y){
            long long temp = 1;
            temp <<= colour;
            tree[n].differentColors = temp;
            dirty[n] = 1;

            apply(n, l, r);

            return;
        }

        if(l > y || r < x) return;

        long long mid = (l+r)/2;
        updateAux(2*n, l, mid, x, y, colour);
        updateAux(2*n+1, mid+1, r, x, y, colour);

        tree[n].differentColors = tree[2*n].differentColors|tree[2*n + 1].differentColors;

        return;
    }

    long long queryAux(long long n, long long l, long long r, long long x, long long y){
        apply(n, l, r);
        if(l >= x && r <= y){
            //if(tree[n].value > 0) return 1;
            //else if(tree[n].value < 0) return -1;
            return tree[n].differentColors;
        }

        if(l > y || r < x) return 0;

        long long mid = (l+r)/2;
        long long left = queryAux(2*n, l, mid, x, y);
        long long right = queryAux(2*n + 1, mid+1, r, x, y);

        return left|right;
    }

    public:

    segTree(long long n){
        tree.assign(4*n, {0});
        dirty.assign(4*n, {0});
        size = n-1;

        build(1, 0, size);
    }
    ~segTree(){

    }

    void update(long long pos, long long colour){
        updateAux(1, 0, size, in[pos], out[pos]-1, colour);

        return;
    }

    long long query(long long pos){
        return queryAux(1, 0, size, in[pos], out[pos]-1);
    }

    void printTree(){
        for(auto i:tree) cout << i.differentColors << " ";
        cout << endl;

        return;
    }

    
};

class eulerTour{
  long long t;
  long long n;
  segTree *tree;

  void dfs(long long i, long long parent){
    in[i] = t++;
    legenda[in[i]] = i;

    for(auto x:g[i]){
      if(x == parent) continue;

      dfs(x, i);
    }

    out[i] = t;
  }

  public:
  eulerTour(long long n){
    t = 0;
    dfs(0, -1);

    tree = new segTree(n);
    
  }

  void change(long long v, long long colour){
    tree->update(v, colour);

  }

  long long count(long long v){
    //cout << "tree: ";
    //tree -> printTree();
    long long mask = tree->query(v);

    long long ans = 0;
    ans = __builtin_popcountll(mask);
    /*while(mask){
      ans += (mask%2);
      mask >>= 1;
    }*/

    return ans;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  long long n, m;
  cin >> n >> m;

  g.resize(n);

  for(long long i=0; i<n; i++){
    cin >> cores[i];
    cores[i]--;
  }
  for(long long i=0; i<n-1; i++){
    long long a, b;
    cin >> a >> b;

    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  eulerTour solve(n);

  /*cout << "IN: ";
  for(long long i=0; i<n; i++) cout << in[i] << " ";
  cout << endl;
  cout << "OUT: ";
  for(long long i=0; i<n; i++) cout << out[i] << " ";
  cout << endl;
  cout << "LEGENDA: ";
  for(long long i=0; i<n; i++) cout << legenda[i] << " ";
  cout << endl;*/

  while(m--){
    long long cmd;
    cin >> cmd;

    if(cmd == 1){
      long long v, c;
      cin >> v >> c;
      v--;
      c--;

      solve.change(v, c);

      //cout << "COLOURS: ";
      //for(long long i=0; i<n; i++) cout << cores[i];
      //cout << endl;
    }
    else{
      long long v;
      cin >> v;
      v--;
      cout << solve.count(v) << "\n";
    }
  }

  return 0;
}