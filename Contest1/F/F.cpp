#include <bits/stdc++.h>

using namespace std;

int main(){
    int h1, a1, c, h2, a2;
    cin >> h1 >> a1 >> c >> h2 >> a2;
    vector <bool> solution; // 0-> Attack, 1 ->Heal

    while(h2>0){
        if(a1>=h2){
            solution.push_back(0);
            h2 -= a1;
        }
        else if(a2>=h1){
            solution.push_back(1);
            h1 += c;
        }
        else{
            solution.push_back(0);
            h2 -= a1;
        }

        if(h2<=0) break;

        h1 -= a2;
    
    }

    cout << solution.size() << "\n";
    for(auto i:solution){
        if(i == 0) cout << "STRIKE\n";
        else cout << "HEAL\n";
    }

    return 0;
}