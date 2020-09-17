#include"../Tree/tree.h"

typedef Node TreeNode;

bool IsSameTree(TreeNode *p, TreeNode *q){
    if(!p && !q) return true;
    if(!p || !q){
        return false;
    }
    return (p->data == q->data) &&
        IsSameTree(p->left, q->left) &&
        IsSameTree(p->right, q->right);
}

int main(){
    auto t1 = BuildTree("1 2 3 4 N N 5 N N N N");
    auto t2 = BuildTree("1 2 3 N N N 5 N N");
    auto res = (IsSameTree(t1, t2))? "same" : "not same";
    cout << res;
}