#include <bits/stdc++.h>

using namespace std;

#define alphabetSize 2

class trieNode{
    public:
    trieNode *children[alphabetSize];
    bool isEnd;
    int value;

    trieNode(){
        for(int i=0; i<alphabetSize; i++) children[i] = NULL;
        isEnd = false;
    }
};

class trie{
    trieNode *root;


    public:
    trie(){
        root = new trieNode();
    }

    void insert(int x){
        trieNode *cur = root;
        for(int i = 31; i>=0; i--){
            bool bit = (1<<i) & x; //Olhando para o bit certo

            if(!cur->children[bit]){
                cur->children[bit] = new trieNode;
            }

            cur = cur->children[bit];
        }

        cur->isEnd = true;

        return;
    }

    int query(int x){
        trieNode *cur = root;

        for(int i=31; i>=0; i--){ 
            bool bit = (1<<i) & x;

            if(cur->children[!bit]){ //Se tiver o bit oposto para ficar 1 no ^
                cur = cur->children[!bit];
            }
            else cur = cur->children[bit]; //O famoso é o jeito
        }

        return x ^ cur->value;
    }

    bool mayIremove(trieNode &node[alphabetSize], int pos, int x){
        if(pos == 0){
            if(node[0]->children == NULL && node[1]->children == NULL) return true;
            return false;
        }

        bool bit = (1<<pos) & x;
        if(mayIremove(node[bit]->children, pos-1, x)){
            *node[bit]->children = NULL;
        }

    }

    void remove(int x){

    }
};

int main(){
    int q;
    cin >> q;

    trie dic;
    dic.insert(0);

    while(q--){

    }

    return 0;
}