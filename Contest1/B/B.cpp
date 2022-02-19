#include <bits/stdc++.h>

using namespace std;

vector <set <string>> dictionary(20);

void savingPermutations(string s, int id){
    for(int i=0; i<s.size()-1; i++){
        for(int j = 0; j<s.size(); j++){
            swap(s[i], s[j]);
            if(dictionary[id].find(s) == dictionary[id].end()){
                dictionary[id].emplace(s);
                savingPermutations(s, id);
            }
            swap(s[i], s[j]);
        }
    }

    return;
}

int main(){
    int l, c;
    int ans = 0;
    cin >> l >> c;
    char matriz[l][c];
    vector <vector <int>> coloring (l, vector <int> (c, 0));

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin >> matriz[i][j];
        }
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        bool newWord = true;
        for(int j=i; j>=0; j--){
            if(dictionary[j].find(s) != dictionary[j].end()){
                newWord = false;
                dictionary[i] = dictionary[j];
            }
        }
        if(newWord){
            dictionary[i].emplace(s);
            savingPermutations(s, i);
        }
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            for(int k=0; j+k<c || i+k<l; k++){
                string sl, sc, sd1, sd2;
                for(int a = 0; a<=k; a++){
                    if(j+a<c) sl += matriz[i][j+a];
                    if(i+a<l) sc += matriz[i+a][j];
                    if(i+a<l && j+a<c)sd1 += matriz[i+a][j+a];
                    if(i+a<l && j-a>=0)sd2 += matriz[i+a][j-a];
                }

                for(int b=0; b<n; b++){
                    if(dictionary[b].find(sl) != dictionary[b].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i][j+a] != 0 && coloring[i][j+a] != b+1 && coloring[i][j+a] != 21){
                                coloring[i][j+a] = 21;
                                ans++;
                            }
                            else coloring[i][j+a]=b+1;
                        }
                    }
                    
                    if(dictionary[b].find(sc) != dictionary[b].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j] != 0 && coloring[i+a][j] != b+1 && coloring[i+a][j] != 21){
                                coloring[i+a][j] = 21;
                                ans++;
                            }
                            else coloring[i+a][j]=b+1;
                        }
                    }

                    if(dictionary[b].find(sd1) != dictionary[b].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j+a] != 0 && coloring[i+a][j+a] != b+1 && coloring[i+a][j+a] != 21){
                                coloring[i+a][j+a] = 21;
                                ans++;
                            }
                            else coloring[i+a][j+a]=b+1;
                        }
                    }

                    if(dictionary[b].find(sd2) != dictionary[b].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j-a] != 0 && coloring[i+a][j-a] != b+1 && coloring[i+a][j-a] != 21){
                                coloring[i+a][j-a] = 21;
                                ans++;
                            }
                            else coloring[i+a][j-a]=b+1;
                        }
                    }  
                }
            }
        }
    }
    /*for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            //cout << coloring[i][j];
            if(coloring[i][j]==21) ans++;
        }
        //cout << endl;
    }
    //cout << endl;*/

    cout << ans << "\n";

    return 0;
}