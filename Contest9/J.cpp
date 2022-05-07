#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair<int, int> ii;
typedef pair <int, ii> iii;

const int inf = 1e8;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    vector <vector <ii>> graph(n);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int q;
    cin >> q;

    while(q--){
        int c, s, e;
        cin >> c >> s >> e;

        vector <vector <int>> custo(n, vector <int> (c, inf));
        priority_queue <iii, vector <iii>, greater<iii>> pq;

        pq.emplace(0, make_pair(s, 0));
        while(pq.top().second.first != e && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(auto i:graph[top.second.first])//Colocando todos os vértices que podem ser acessados
                    if(i.second <= top.second.second && custo[i.first][top.second.second - i.second] > top.first){
                        pq.emplace(top.first, make_pair(i.first, top.second.second - i.second));
                        custo[i.first][top.second.second - i.second] = top.first;
                    }

            if(top.second.second < c)
                pq.emplace(top.first + prices[top.second.first], make_pair(top.second.first, top.second.second + 1));

            //cout << top.second.first << endl;

        }

        if(pq.empty()) cout << "impossible\n";
        else cout << pq.top().first << "\n";
    }

    return 0;
}