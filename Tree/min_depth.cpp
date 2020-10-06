#include"tree.h"

int MinDepth(TreeNode *root){
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 1));
    while(!q.empty()){
        TreeNode *node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        // node == NULL:
        if(!node) continue;
        
        // check if leaf node:
        if(!node->left && !node->right) return level;

        // non leaf => push childs:
        q.push(make_pair(node->left, level + 1));
        q.push(make_pair(node->right, level + 1));
    }
    return 0;
}

int main(){
    auto tree = BuildTree("1 9 3 5 N 2 N");
    cout << MinDepth(tree);
}