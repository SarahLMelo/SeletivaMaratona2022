#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n!=0){
        int ans = 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; i++){
            int a;
            cin >> a;
            pq.push(a);
        }

        while(pq.size() != 1){
            int a, b;

            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            ans += a+b;
            pq.push(a+b);
        }

        cout << ans << "\n";

        cin >> n;
    }

    return 0;
}