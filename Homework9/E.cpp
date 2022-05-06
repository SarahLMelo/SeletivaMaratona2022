#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int;

int dp(int pos, int parPos, vector <vector <ii>> &g, vector <int> &memo){
    for(auto i:g[pos]){
        if(i.first == parPos) continue;

        memo[pos] = max(memo[pos], i.second + dp(i.first, pos, g, memo));
    }

    return memo[pos];
}

void dfsMax(int pos, int parPos, int parAns, vector <vector <ii>> &g, vector <int> &memo, vector <int> &ans){
    int max1 = 0, max2 = 0;

    for(auto i:g[pos]){
        if(i.first == parPos) continue; //É o pai
        int cur = i.second + memo[i.first];

        if (max1 < cur) swap(max1, cur); //Coloca o menor no cur
        if (max2 < cur) swap(max2, cur); //Coloca o menor no cur
    }

    ans[pos] = max(parAns, max1);

    for(auto i:g[pos]){
        if(i.first == parPos) continue;
        int cur = i.second + memo[i.first];

        int maxUp, temp;
        if(max1 == cur) temp = max2;
        else temp = max1;

        maxUp = max(parAns, temp);
        dfsMax(i.first, pos, i.second + maxUp, g, memo, ans);
    }

    return;
}

void dfsMin(int pos, int parPos, int parAns, vector <vector <ii>> &g, vector <int> &memo, vector <int> &ans){
    int min1 = LONG_LONG_MAX, min2 = LONG_LONG_MAX;

    for(auto i:g[pos]){
        if(i.first == parPos) continue; //É o pai
        int cur = i.second + memo[i.first];

        if (min1 > cur) swap(min1, cur); //Coloca o menor no cur
        if (min2 > cur) swap(min2, cur); //Coloca o menor no cur
    }

    ans[pos] = min(parAns, min1);

    for(auto i:g[pos]){
        if(i.first == parPos) continue;
        int cur = i.second + memo[i.first];

        int minUp, temp;
        if(min1 == cur) temp = min2;
        else temp = min2;

        minUp = min(parAns, temp);
        dfsMin(i.first, pos, i.second + minUp, g, memo, ans);
    }

    return;
}

__int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

    int t;
    cin >> t;

    for(int cnt = 1; cnt <= t; cnt++){
        int n;
        cin >> n;

        vector <vector <ii>> g(n);
        

    }

  return 0;
}