#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int paper[n][m];
    int nextColor = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin >> x;

            if(x == '.') paper[i][j] = -2;
            else paper[i][j] = -1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(paper[i][j] == -1){
                stack <ii> q;
                q.push({i, j});
                while(!q.empty()){
                    int x, y;
                    x = q.top().first;
                    y = q.top().second;
                    q.pop();
                    if(paper[x][y] != -1) continue;

                    if(x+1<n && paper[x+1][y] == -1) q.push({x+1, y});
                    if(x-1>=0 && paper[x-1][y] == -1) q.push({x-1, y});
                    if(y+1<m && paper[x][y+1] == -1) q.push({x, y+1});
                    if(y-1>=0 && paper[x][y-1] == -1) q.push({x, y-1});

                    paper[x][y] = nextColor; 
                }

                nextColor++;
            }
        }
    }

    cout << nextColor << "\n";

    return 0;
}