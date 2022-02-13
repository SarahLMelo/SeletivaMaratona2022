#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    while(cin >> N){
        stack <int> s;
        queue <int> q;
        priority_queue <int> pq;
        bool stack=true, queue=true, pqueue = true;

        for(int i=0; i<N; i++){
            int command, number;
            cin >> command >> number;
            
            if(command == 1){
                s.push(number);
                q.push(number);
                pq.push(number);
            }
            else{
                if(s.empty() || s.top() != number) stack = false;
                else s.pop();

                if(q.empty() || q.front() != number) queue = false;
                else q.pop();

                if(pq.empty() || pq.top() != number) pqueue = false;
                else pq.pop();
            }
        }

        if(stack == true){
            if(queue == true || pqueue == true) cout << "not sure\n";
            else cout << "stack";
        }

        else if(queue == true){
            if(pqueue == true) cout << "not sure\n";
            else cout << "queue\n";
        }

        else if(pqueue == true) cout << "priority queue\n";
        else cout << "impossible\n";

    }

    return 0;
}