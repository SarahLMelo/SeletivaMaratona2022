#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    cin.ignore(1);
    while(t--){
        stack <char> s;
        string sentence;
        bool possible = true;

        getline(cin, sentence);
        for(auto x:sentence){
            if(x == '(' || x == '[') s.push(x);
            else if(x == ')'){
                if(s.empty() || s.top() != '(') possible = false;
                else s.pop();
            }
            else if(x == ']'){
                if(s.empty() || s.top() != '[') possible = false;
                else s.pop();
            }
        }

        if(possible == false || !s.empty()) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}