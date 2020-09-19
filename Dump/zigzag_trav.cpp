#include"../Tree/tree.h"

typedef Node TreeNode;

stack<TreeNode *> st[2];
int level = 0;

int NextLevel(){
    return (level + 1) % 2;
}

vector<vector<int>> ZigZagTrav(TreeNode *root){
    vector<vector<int>> res;
    if(!root) return res;
    st[0].push(root);
    while(!st[0].empty() || !st[1].empty()){
        vector<int> oneLevelRes;
        while(!st[level].empty()){
            TreeNode *node = st[level].top();
            st[level].pop();
            if(!node) continue;
            
            if(level){
                oneLevelRes.push_back(node->val);
                st[NextLevel()].push(node->right);
                st[NextLevel()].push(node->left);
            }
            else{
                oneLevelRes.push_back(node->val);
                st[NextLevel()].push(node->left);
                st[NextLevel()].push(node->right);
            }
        }
        level = NextLevel();
        if(!oneLevelRes.empty())
            res.push_back(oneLevelRes);
        oneLevelRes.clear();
    }
    return res;
}

int main(){
    Node *tree = BuildTree("5 3 8 1 4 6 9 N 2 N N N 7 N N N N N N");
    auto res = ZigZagTrav(tree);
    for(auto x : res){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}