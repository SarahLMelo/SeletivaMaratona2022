#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        priority_queue <ii> people;
        vector <ii> ans;
        cin >> n;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;

            if(x!=0) people.push({x, i});
        }

        while(!people.empty()){
            ii a = people.top();
            people.pop();
            if(people.empty()) break;
            ii b = people.top();
            people.pop();

            a.first--;
            b.first--;

            ans.push_back({a.second, b.second});

            if(a.first>0) people.push(a);
            if(b.first>0) people.push(b);
        }

        cout << ans.size() << "\n";
        for(auto i:ans){
            cout << i.first+1 << " " << i.second+1 << "\n";
        }

    }

    return 0;
}