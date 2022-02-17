#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    deque <int> d;
    bool mode = 0;
    cin >> t;

    while(t--){
        string command;
        cin >> command;

        if(command == "back"){
            if(d.empty() == true) cout << "No job for Ada?\n";
            else{
                if(mode == 1){
                    cout << d.front() << "\n";
                    d.pop_front();
                }
                else{
                    cout << d.back() << "\n";
                    d.pop_back();
                }
            }
        }

        else if(command == "front"){
            if(d.empty() == true) cout << "No job for Ada?\n";
            else{
                if(mode == 0){
                    cout << d.front() << "\n";
                    d.pop_front();
                }
                else{
                    cout << d.back() << "\n";
                    d.pop_back();
                }
            }
        }

        else if(command == "reverse"){
            mode = !mode;
        }

        else if(command == "push_back"){
            int N;
            cin >> N;
            if(mode == 0) d.push_back(N);
            else d.push_front(N);
        }

        else if(command == "toFront"){
            int N;
            cin >> N;
            if(mode == 1) d.push_back(N);
            else d.push_front(N);
        }
    
    }

    return 0;
}