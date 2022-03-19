#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

void dijkstra(vector <vector <ii>> &g, vector <int> &dist, int n){
    priority_queue <ii, vector <ii>, greater<ii>> pq;
    vector <bool> vis(n, 0);
    pq.push({0, 0});

    while(!pq.empty()){
        ii x = pq.top();
        pq.pop();

        dist[x.second] = min(dist[x.second], x.first);
        if(vis[x.second] == 1) continue;
        vis[x.second] = 1;

        for(auto i:g[x.second]){
            pq.push({x.first+i.first, i.second});
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ii begin, end;
    cin >> begin.first >> begin.second >> end.first >> end.second;

    int ans = abs(begin.first - end.first) + abs(begin.second - end.second);

    vector<ii> pontos;
    vector <vector <ii>> g(m+2);
    vector <int> dist(m+2, 1e10);
    pontos.push_back({begin.first, begin.second});

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        pontos.push_back({x, y});
    }

    for(int i=0; i<m; i++){
        for(int j=i+1; j<=m; j++){
            int w = min(abs(pontos[i].first - pontos[j].first), abs(pontos[i].second - pontos[j].second));
            g[i].push_back({w, j});
            g[j].push_back({w, i});
        }
        int w = abs(pontos[i].first - end.first) + abs(pontos[i].second - end.second);
        g[i].push_back({w, m+1});
    }

    dijkstra(g, dist, m+2);

    for(auto i:dist) cout << i <<" ";
    cout << endl;

    ans = dist[m+1];

    cout << ans << "\n";

    return 0;
}