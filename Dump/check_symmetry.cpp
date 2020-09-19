#include"../Tree/tree.h"

typedef Node TreeNode;

bool IsMirror(TreeNode *n1, TreeNode *n2){
    if(!n1 && !n2) return true;
    if(!n1 || !n2) return false;
    return (n1->val == n2->val) && 
        IsMirror(n1->left, n2->right) &&
        IsMirror(n1->right, n2->left);
}

bool IsSymmetric(TreeNode *root){
    if(!root) return true;
    return IsMirror(root->left, root->right);
}

int main(){
    auto tree = BuildTree("1 2 2 3 4 5 3");
    switch (IsSymmetric(tree))
    {
    case true:
        cout << "symmetric: yes";
        break;
    
    default:
        cout << "symmetric: no";
        break;
    }
}