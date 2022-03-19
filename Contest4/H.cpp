#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector <vector <ii>> g(n);

    while(m--){
        int v, u, w;
        cin >> v >> u >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }

    while(q--){
        bool quest;
        cin >> quest;
        if(quest){
            int x, y;
            vector <int> dist(n, 1e18);
            priority_queue <ii, vector <ii>, greater<ii>> pq;
            vector <bool> vis(n, 0);
            cin >> x >> y;
             
            pq.emplace(0,0);

            while(!pq.empty()){
                ii top = pq.top();
                pq.pop();

                if(dist[top.second] <= top.first) continue;
                dist[top.second] = top.first;
                vis[top.second] = 1;

                for(auto i:g[top.second]){
                    if(dist[i.first] > i.second+top.first) pq.emplace(i.second+top.first, i.first);
                }

            }

            if(!vis[y]) cout << "IMPOSSIBLE" << endl;
            else cout << dist[y] << endl;
        }

        else{
            int x, y, erasePos;
            cin >> x >> y;

            for(int i=0; i<g[x].size(); i++){
                if(g[x][i].first == y){
                    erasePos = i;
                    break;
                }
            }
            g[x].erase(g[x].begin()+erasePos);

            for(int i=0; i<g[y].size(); i++){
                if(g[y][i].first == x){
                    erasePos = i;
                    break;
                }
            }
            g[y].erase(g[y].begin()+erasePos);
        }
    }

    return 0;
}