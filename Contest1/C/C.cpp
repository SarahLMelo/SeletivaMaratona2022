#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(vector <int> s){
    for(int i=0; i<(s.size()/2); i++){
        if(s[i]!=s[i+(s.size()/2)]) return false;
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> s(n);

        for(int i=0; i<n; i++) cin >> s[i];

        

    }

    return 0;
}