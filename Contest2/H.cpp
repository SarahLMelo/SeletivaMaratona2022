#include <bits/stdc++.h>

using namespace std;

#define ii pair<ll, ll>
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector <ii> friends(n);

    for(int i=0; i<n; i++){
        cin >> friends[i].first >> friends[i].second; //1 ->Money e 2 ->Friendship
    }

    sort(friends.begin(), friends.end());

    ll int ans = 0;

    int i = 0, j = 0;

    ll nowAns = 0;
    while(j<n){
        if(abs(friends[i].first- friends[j].first) >= d){
            ans = max(ans, nowAns);
            nowAns -= friends[i].second;
            i++;
        }
        else{
            nowAns += friends[j].second;
            j++;
        }

        ans = max(ans, nowAns);
    }

    cout << ans << "\n";

    return 0;
}