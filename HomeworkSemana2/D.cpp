#include <bits/stdc++.h>

using namespace std;

bool check(string *s, int m){
    int one = 0, two = 0, three = 0;
    bool ans = false;

    for(int i=0; i<m; i++){
        if((*s)[i] == '1') one++;
        else if((*s)[i] == '2') two++;
        else if((*s)[i] == '3') three++;
    }

    int pos = m;
    while(pos<(*s).size() && (one == 0 || two == 0 || three == 0)){
        //cout << one << " " << two << " " << three << "\n";

        if((*s)[pos] == '1') one++;
        else if((*s)[pos] == '2') two++;
        else if((*s)[pos] == '3') three++;

        if((*s)[pos-m] == '1') one--;
        if((*s)[pos-m] == '2') two--;
        if((*s)[pos-m] == '3') three--;

        pos++;
    }

    if(one>0 && two > 0 && three > 0) ans = true;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int l = 1, r = s.size()+1;
        while(r>l){
            int m = (r+l)/2;

            if(check(&s, m) == false) l = m+1;
            else r = m;
            //cout << check(&s, m) << "\n";
        }

        if(l == s.size()+1) l = 0;
        cout << l << "\n";
    }


    return 0;
}