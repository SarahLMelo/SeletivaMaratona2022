#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    while(N--){
        int B, SG, SB;
        priority_queue <int> green, blue;
        cin >> B >> SG >> SB;

        while(SG--){
            int x;
            cin >> x;
            green.push(x);
        }

        while(SB--){
            int x;
            cin >> x;
            blue.push(x);
        }

        while(!green.empty() && !blue.empty()){
            vector <int> gSol, bSol;

            for(int i = 0; i<B && !green.empty() && !blue.empty(); i++){
                if(green.top() > blue.top()) gSol.push_back(green.top()-blue.top());
                else if(green.top() < blue.top()) bSol.push_back(-(green.top()-blue.top()));
                green.pop();
                blue.pop();
            }

            while(!gSol.empty()){
                green.push(gSol.back());
                gSol.pop_back();
            }

            while(!bSol.empty()){
                blue.push(bSol.back());
                bSol.pop_back();
            }
        }

        if(!green.empty()){
            cout << "green wins" << "\n";
            while(!green.empty()){
                cout << green.top() << "\n";
                green.pop();
            }
        }
        else if(!blue.empty()){
            cout << "blue wins" << "\n";
            while(!blue.empty()){
                cout << blue.top() << "\n";
                blue.pop();
            }
        }
        else cout << "green and blue died\n";
        
        if(N != 0) cout << "\n";

    }

    return 0;
}