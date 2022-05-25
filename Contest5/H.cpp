#include <bits/stdc++.h>

using namespace std;

#define inf 1e9+5
typedef pair<int, int> ii;

int n, w;
vector <vector <int>> memo;
vector <ii> items;
int bestAns;

void dp(int pos, int value){
    if(pos==n) return;
    if(memo[pos][value] != inf) return;

    //Taking
    memo[pos+1][value+items[pos].second] = min(memo[pos+1][value+items[pos].second], memo[pos][value] + items[pos].first);
    if(memo[pos+1][value+items[pos].second] <= w) bestAns = max(bestAns, value+items[pos].second);
    if(memo[pos+1][value+items[pos].second] <= w) dp(pos+1, value+items[pos].second);    

    //NotTaking
    memo[pos+1][value] = min(memo[pos+1][value], memo[pos][value]);
    if(memo[pos+1][value] <= w) dp(pos+1, value);

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w;
    memo.assign(n+2, vector <int>(1e5 + 5, inf));
    items.resize(n);
    bestAns = 0;
    memo[0][0] = 0;

    for(int i=0; i<n; i++){
        int w, v;
        cin >> w >> v;
        items[i] = {w, v};
    }

    dp(0, 0);

    cout << bestAns << "\n";

    return 0;
}