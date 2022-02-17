#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        queue <int> q;
        stack <int> s;
        bool possible = true;

        for(int i=0; i<n; i++){
            int car;
            cin >> car;
            q.push(car);
        }

        for(int i=1; i<=n && possible == true; i++){
            if(!q.empty() && q.front()==i) q.pop();
            else if(!s.empty() && s.top() == i) s.pop();
            else{
                while(!q.empty() && q.front()!=i){
                    s.push(q.front());
                    q.pop();
                }
                if(q.empty()) possible = false;
                else q.pop();
            }
        }

        if(possible == false) cout << "no\n";
        else cout << "yes\n";

        cin >> n;
    }

    return 0;
}