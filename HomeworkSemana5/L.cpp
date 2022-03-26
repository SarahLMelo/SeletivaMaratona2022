#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

/*
4 (tempo que inicio)
4 (vertices)
4 (arestas)
1 (peso)

Arestas:
1 2
2 3
3 4
4 1

(Tempo, Custo)
1 2
2 1
5 4
3 3
*/

int n, t, x, m;
const ll inf = 1e9;
vector <vector <int>> p;
vector <ii> r;
vector <vector <int>> dp;

int solve(int x, int remaining){
    if(remaining < 0) return inf;
    if(remaining == 0){
        if(x==0) return 0;
        else return inf; //Flag de inválido
    }
    int &ans = dp[x][remaining];
    if(dp[x][remaining] != -1) return dp[x][remaining];

    ans = solve(x, remaining - r[x].first); //Se ficar no mesmo brinquedo
    for(auto i:p[x]){
        ans = min(ans, solve(i, remaining - r[i].first - t)); //Se for válido
    }
    ans += r[x].second;

    //cout << x << " " << remaining << " " << ans << "\n";
    return ans;
}

int main(){
    cin >> x >> n >> m >> t;
    
    p.assign(n, vector<int>());
    r.assign(n,{0, 0});
    dp.assign(n, vector <int> (1001, -1));

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        p[a].push_back(b);
        p[b].push_back(a);
    }

    for(int i=0; i<n; i++) cin >> r[i].first >> r[i].second;

    int ans = r[0].second + solve(0, x-r[0].first);
    if(ans<inf) cout << ans << "\n";
    else cout << "It is a trap.\n";
    

    return 0;
}