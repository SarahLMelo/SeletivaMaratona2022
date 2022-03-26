#include <bits/stdc++.h>

using namespace std;

#define iii pair <int, pair<int, int>>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    vector <vector <iii>> dp (s.size()+1, vector <iii> (t.size()+1, {-1, {0,0}}));

    for(int i=0; i<=s.size(); i++){
        for(int j=0; j<=t.size(); j++){
            if(i==0 || j==0) dp[i][j] = {0, {0,0}};
            else if(s[i-1] == t[j-1]){
                dp[i][j] = {(dp[i-1][j-1].first + 1), {(i-1), (j-1)}};
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else dp[i][j] = dp[i][j-1];
            }

            //cout << "i: " << i << " j: " << j << "\n";
            //cout << "size: " << dp[i][j].first << " sFather: " << dp[i][j].second.first << " tFather: " << dp[i][j].second.second << endl;
        }
    }

    stack <int> ans;
    int x = s.size(), y = t.size();
    //cout << dp[x][y].second.first << " " << dp[x][y].second.second <<  endl;
    //cout << x << " " << y << "\n";
    int nX, nY;
    while(dp[x][y].first){
        if(s[x-1] == t[y-1]){
            //cout << "HERE" << endl;
            ans.push(x-1);
            nX = dp[x][y].second.first;
            nY = dp[x][y].second.second;
            x = nX;
            y = nY;
        }

        else{
            nX = dp[x][y].second.first;
            nY = dp[x][y].second.second;
            x = nX;
            y = nY;
            //if(x != 0 || y != 0){
                x++;
                y++;
            //}
        }
        
        //cout << x << " " << y << "\n";
    }

    while(!ans.empty()){
        cout << s[ans.top()];
        ans.pop();
    }
    cout << "\n";

    return 0;
}