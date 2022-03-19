#include <bits/stdc++.h>

using namespace std;

vector<pair <int, int>> prim(vector <int> &d, vector <vector <int>> &g, int source){
    vector <bool> vis(d.size(), 0);
    vector <pair <int, int>> ans;
    priority_queue<pair<int,int>, vector <pair <int, int>>, greater <pair<int, int>>> pq;
    int index = 0;
    pq.emplace(1, index);
    vector <pair <int, int>> edges(1, {source, source});

    while(!pq.empty()){
        pair <int, int> x = pq.top();
        pq.pop();

        if(vis[edges[x.second].second] == 1) continue;

        //cout << "HERE" << endl;

        vis[edges[x.second].second] = 1;
        d[edges[x.second].second] = x.first;
        ans.push_back({edges[x.second].first, edges[x.second].second});

        for(auto i:g[edges[x.second].second]){
            if(vis[i] != 0) continue;
            index++;
            edges.push_back({edges[x.second].second, i});
            pq.emplace(x.first+1, index);
            //cout << x.first+1 << " " << edges[index].first << " " << edges[index].second << "\n";
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n);
    vector <pair <int, int>> ans;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int maxSize = 0;
    int index = 0;
    for(int i=0; i<n; i++){
        if(maxSize < graph[i].size()){
            maxSize = graph[i].size();
            index = i;
        }
    }

    //cout << index << "\n";

    vector <int> dist(n, (int)1e18);
    ans = prim(dist, graph, index);

    for(auto i:ans){
        if(i.first == i.second) continue;
        cout << ++i.first << " " << ++i.second << "\n";
    }

    return 0;
}