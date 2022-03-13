#include <bits/stdc++.h>

using namespace std;

#define N {-1, 0}
#define S {1, 0}
#define W {0, -1}
#define E {0, 1}
#define ii pair<int, int>

int loop(vector <vector <char>> g, ii pos, ii bot){
    int ans = 0;
    while(bot != pos){
        ans ++;
        if(g[bot.first][bot.second] == 'N') bot = {bot.first-1, bot.second};
        else if(g[bot.first][bot.second] == 'S') bot = {bot.first+1, bot.second};
        else if(g[bot.first][bot.second] == 'W') bot = {bot.first, bot.second-1};
        else bot = {bot.first, bot.second+1};
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;
    b--;

    while(n!=0){
    vector <vector <char>> g(n, vector <char> (m));
    vector <vector <bool>> vis(n, vector <bool> (m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    bool leave = false;
    ii bot = {0, b};
    int ans = 0;
    int loopSize = 0;

    while(!leave){
        ans++;
        vis[bot.first][bot.second] = 1;

        if(g[bot.first][bot.second] == 'N') bot = {bot.first-1, bot.second};
        else if(g[bot.first][bot.second] == 'S') bot = {bot.first+1, bot.second};
        else if(g[bot.first][bot.second] == 'W') bot = {bot.first, bot.second-1};
        else bot = {bot.first, bot.second+1};

        if(bot.first >= n || bot.first < 0 || bot.second >= m || bot.second < 0) leave = true;

        else if(vis[bot.first][bot.second] == 1){
            //cout << "HERE" << endl;
            loopSize = ans - loop(g, bot, {0, b});
            ans -= loopSize;
            leave = true;
        }
    }

    if(loopSize != 0) cout << ans << " step(s) before a loop of " << loopSize <<  " step(s)\n";
    else cout << ans << " step(s) to exit\n";

      cin >> n >> m >> b;
      b--;  
    }

    return 0;
}