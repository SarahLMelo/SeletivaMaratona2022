#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

vector <ii> findDiv(int n){
    vector <ii> ans;
    int cnt = 0;
    while(!(n%2)){
        cnt++;
        n /= 2;
    }
    if(cnt) ans.push_back({cnt, 2});
    
    for(int i=3; i*i<=n; i+=2){
        cnt = 0;
        while(!(n%3)){
            n /= 3;
            cnt++;
        }

        if(cnt) ans.push_back({cnt, i});
    }

    if(n != 1) ans.push_back({1, n});

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector <ii> primeDiv = findDiv(n);
    for(auto i:primeDiv) cout << i.second << " " << i.first << ", ";
    cout << endl;
    bool player = 0;

    while(!primeDiv.empty()){
        sort(primeDiv.begin(), primeDiv.end());
        if(!(primeDiv.size() % 2) && primeDiv.back().first > 1){ //Se a quantidade de divisores for par e der para não tirar um cara
            primeDiv.back().first = 1;
        }
        else primeDiv.pop_back();

        player = !player;
    }

    if(player) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}