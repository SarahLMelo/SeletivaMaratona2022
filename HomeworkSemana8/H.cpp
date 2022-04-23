#include <bits/stdc++.h>

using namespace std;

#define alphabetSize 26

class trieNode{
    public:
    trieNode *children[alphabetSize];
    bool isEnd;

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

    void insert(string key){
        trieNode *cur = root;
        for(auto i:key){
            int id = i - 'a';

            if(!cur->children[id]){
                cur->children[id] = new trieNode;
            }

            cur = cur->children[id];
        }

        cur->isEnd = true;
    }

    bool search(string key){
        trieNode *cur = root;
        
        for(auto i:key){
            int id = i - 'a';

            if(!cur->children[id]) return false;

            cur = cur->children[id];
        }

        return cur->isEnd;
    }
};

int main(){

    return 0;
}