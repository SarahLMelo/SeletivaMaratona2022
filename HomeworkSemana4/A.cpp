#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        queue <int> q;
        stack <int> s;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            q.push(x);
        }

        s.push(q.front());
        q.pop();
        while(!q.empty()){
            int x = q.front();
            q.pop();

            if(s.top() > x){
                int max = s.top();
                s.pop();

                while(!s.empty() && s.top() > x) s.pop();
                s.push(max);
            }
            else s.push(x);
        }

        cout << s.size() << endl;

    }


    return 0;
}