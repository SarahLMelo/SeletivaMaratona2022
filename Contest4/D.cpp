#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
#define inf 1e9

vector <int> dist;

void dijkstra(int pos, vector <vector <ii>> &g, int n){
    dist.assign(n, inf);
    
    dist[pos] = 0;
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, pos);

    while(!pq.empty()){
        int v = pq.top().second, w = pq.top().first;
        pq.pop();

        if(w > dist[v]) continue;

        for(auto i:g[v]){
            if(dist[i.first] > dist[v] + w){
                dist[i.first] = dist[v] + w;
                pq.emplace(dist[i.first], i.first);
            }
        }
    }

    return;
}

int main(){
    int n, s, l, u;
    cin >> n >> s >> l >> u;

    vector <vector <ii>> g(n);
    vector <bool> vis(n, 0);
    vis[0] = 1;
    for(int i=0; i<s; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    dijkstra(0, g, n);

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(dist[i] <= (u-1)/2){
            for(auto j:g[i]){
                if(dist[j.first]+dist[i] <= (u-1)/2 && vis[j.first] == 0){
                    cnt++;
                    //cout << i << " " << j.first << "\n";
                    vis[j.first] = 1;
                }
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}