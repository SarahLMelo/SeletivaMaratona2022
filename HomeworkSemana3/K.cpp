#include <bits/stdc++.h>

using namespace std;

void process(vector <vector <bool>> &g, vector <bool> &dead, int n){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(g[i][j] == 0) continue;
                if(dead[i] == true) continue;
                bool kill = true;
                bool haveAFriend = false;

                for(int j=0; j<g[i].size(); j++){
                    if(dead[g[i][j]] == 1) continue;
                    haveAFriend = true;
                    if(j < i) kill = false;
                }

                if(kill & haveAFriend){
                    cout << "HERE" << endl;
                    dead[i] = 1;
                    g[i][j] = 0;
                    g[j][i] = 0;
                    flag = true;
                }
            }
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <vector<bool>> g(n, vector <bool> (n, 0));
    vector <bool> dead(n, 0);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        g[x][y] = 1;
        g[y][x] = 1;
    }

    int q;
    cin >> q;

    while(q--){
        int query;
        cin >> query;

        if(query == 1){
            int a, b;
            cin >> a >> b;

            g[a][b] = 1;
            g[b][a] = 1;
        }

        if(query == 2){
            int a, b;
            cin >> a >> b;

            g[b][a] = 0;
            g[a][b] = 0;
        }

        if(query == 3){
            process(g, dead, n);
            int cnt = 0;
            for(auto i:dead) if(i == 0) cnt++;
            cout << cnt << "\n";
        }
    }

    return 0;
}