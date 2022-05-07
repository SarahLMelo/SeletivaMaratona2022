#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        stack <char> pilha;

        for(auto i:s){
            if(i == '(') continue;
            else if(i == ')'){
                if(!pilha.empty()){
                    cout << pilha.top();
                    pilha.pop();
                }
            }
            else if(i>= 'a' && i<= 'z') cout << i;
            else pilha.push(i);
        }

        cout << endl;
    }


    return 0;
}