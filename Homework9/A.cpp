#include <bits/stdc++.h>

using namespace std;

void dp(int pos, vector <vector <int>> &memo, vector <pair <vector <int>, int>> &graph, vector <bool> &vis){
    vis[pos] = 1;

    if(graph[pos].first.size() == 1 && vis[graph[pos].first.back()] == 1){ //É folha?
        memo[pos][0] = 0;
        memo[pos][1] = graph[pos].second;

        return;
    }

    //Achando todos os filhos
    vector <int> children;

    for(auto i:graph[pos].first)
        if(vis[i] == 0){
            children.push_back(i);
            dp(i, memo, graph, vis);
        }

    //Calculando a DP
    memo[pos][1] = graph[pos].second;
    for(auto i:children){
        memo[pos][0] += max(memo[i][0], memo[i][1]);
        memo[pos][1] += memo[i][0];
    }

    return;

}

int main(){
    int n;
    cin >> n;

    //Criando o grafo

    vector <pair <vector <int>, int>> graph(n);

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].first.push_back(b);
        graph[b].first.push_back(a);
    }

    for(int i=0; i<n; i++) cin >> graph[i].second;

    //Criando a dp

    vector <vector <int>> memo(n, vector <int> (2, 0));
    vector <bool> vis(n, 0);

    //Resolvendo

    dp(0, memo, graph, vis);

    cout << max(memo[0][0], memo[0][1]) << "\n";

    return 0;
}