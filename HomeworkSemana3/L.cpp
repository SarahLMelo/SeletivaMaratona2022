#include <bits/stdc++.h>

using namespace std;

void bfs(vector <vector <int> > &tree, vector <int> &height, vector <bool> vis, int root){
    queue <pair <int, int> > q;
    q.push({root, root});
    while(!q.empty()){
        pair <int, int> now = q.front();
        q.pop();

        if(vis[now.first] == 1) continue;
        
        vis[now.first] = 1;
        if(now.first != root) height[now.first] = height[now.second]+1;
        for(auto i:tree[now.first]) q.push({i, now.first});
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <vector <int> > tree(n);   
    vector <int> height(n, 0);
    vector <bool> vis(n, 0);

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    height[0] = 0;
    bfs(tree, height, vis, 0);
    int edge = max_element(height.begin(), height.end()) - height.begin();
    height[edge] = 0;
    bfs(tree, height, vis, edge);

    cout << 3* (*(max_element(height.begin(), height.end()))) << "\n";

    return 0;
}