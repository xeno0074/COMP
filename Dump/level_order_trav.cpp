#include"../Tree/tree.h"

typedef Node TreeNode;

vector<vector<int>> LevelOrder(TreeNode *root){
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    vector<vector<int>> res;
    int level = 0;

    // in case NULL root, return vector[vector[NULL]]
    vector<int> temp;
    if(!root){
        res.push_back(temp);
        return res;
    }


    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(!p.first) continue;
        
        if(p.second == res.size()){
            res.resize(res.size() + 1);
            level++;
        }
        res[p.second].push_back(p.first->data);

        q.push(make_pair(p.first->left, p.second + 1));
        q.push(make_pair(p.first->right, p.second + 1));
    }
    return res;
}

int main(){
    auto tree = BuildTree("5 3 8 1 2 6 9 N 4 N N N 7 N N N N N N");
    auto trav = LevelOrder(tree);
    for(auto x : trav){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
}