#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d;
    cin >> b >> a >> d >> c;

    for(int x=0; x<=100; x++){
        for(int y = 0; y<=100; y++){
            if((a + b*x) == (c + d*y)){
                cout << a + b*x  << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";

    return 0;
}

/*
t = a + bx;
t = c + dy;

a + bx = c + dy

*/