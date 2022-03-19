#include <bits/stdc++.h>

using namespace std;

struct node{
    int u, v, w;
    bool operator <(node b){
        return w < b.w;
    }
};

int unionFind(int x, vector <int> &parents){
    if(parents[x] != x) parents[x] = unionFind(parents[x], parents);
    return parents[x];
}

int main(){
    int n, m;
    cin >> n >> m;

    while(n!=0){
        vector <node> g(m);
        vector <int> parents;
        vector <int> size;

        for(int i=0; i<n; i++){
            parents.push_back(i); //unionBuild
            size.push_back(1);
        }

        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;

            g[i] = {u, v, w};
        }

        sort(g.begin(), g.end());

        int cnt = 0, ans;

        for(int i=0; i<m && cnt < n; i++){
            int a = unionFind(g[i].u, parents), b = unionFind(g[i].v, parents);
            if(a!=b){ //UnionUnion
                if(size[a] < size[b]){
                    size[b] += size[a];
                    parents[a] = b;
                }
                else{
                    size[a] += size[b];
                    parents[b] = a;
                }

                ans = g[i].w;
                cnt++;
            }   
        }

        if(cnt == n-1) cout << ans << "\n";
        else cout << "IMPOSSIBLE\n";
        cin >> n >> m;
    }

    return 0;
} 