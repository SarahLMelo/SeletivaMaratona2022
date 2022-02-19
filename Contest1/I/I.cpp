#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string, string> m;
    string line;
    getline(cin, line);

    while(!line.empty()){
        string english, strange;
        bool mode = 0;
        for(auto i:line){
            if(i == ' ') mode = !mode;
            else{
                if(mode == 0) english.push_back(i);
                else strange.push_back(i);
            }
        }
        
        
        m[strange] = english;

        getline(cin, line);
    }

    //cin.ignore(1);
    while(cin>>line){
        //cout << line << " ";
        if(m.find(line) != m.end()) cout << m[line] << "\n";
        else cout << "eh\n";
    }

    return 0;
}