#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <string> index;
    vector <bool> alphabet(26, 0);
    string s;
    string ans;

    vector <int> prioridade(26, 0);
    vector <vector <int>> libera(26);
    
    cin >> s;
    while(s!="#"){
        for(auto i:s) alphabet[i - 'A'] = true;
        index.push_back(s);

        cin >> s;
    }

    for(int i=1; i<index.size(); i++){
        for(int j=0; j<index[i].size() && j<index[i-1].size(); j++){
            if(index[i][j] == index[i-1][j]) continue;
            prioridade[(index[i][j] - 'A')]++;
            libera[index[i-1][j] - 'A'].push_back(index[i][j] - 'A');
            break;
        }
    }

    //for(auto i:prioridade) cout << i << " ";
    //cout << endl;

    bool end = false;
    while(!end){
        end = true;
        for(int i=0; i<prioridade.size(); i++){
            if(alphabet[i] == 0) continue;
            if(prioridade[i] == 0){
                end = false;
                ans.push_back(i + 'A');
                if(!libera[i].empty()) for(auto j:libera[i]){
                    prioridade[j]--;
                }
                prioridade[i]--;
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}