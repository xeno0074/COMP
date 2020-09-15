#include"tree.h"

vector<Node *> T(int n, int s){
    vector<vector<Node *>> forest(n + 1);
    vector<Node *> temp;

    //  insert item for forest[0]
    temp.push_back(NULL);
    forest[0] = temp;

    for(int index = 1; index <= n; index++){
        for(int rootNum = 1; rootNum <= index; rootNum++){
            
        }
    }
    
}

vector<Node *> GenUniqueBSTs(int n){
    
}
