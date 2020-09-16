#include"../Tree/tree.h"

int preData = INT_MIN;
int firstTime = true;

bool IsValidBST(Node *root){
    if(!root) return true;
    bool l = IsValidBST(root->left);
    if(root->data <= preData && !firstTime){
        return false;
    }
    preData = root->data;
    firstTime = false;
    bool r = IsValidBST(root->right);
    return l && r;
}

int main(){
    auto tree = BuildTree("5 3 8 1 2 6 9 N 4 N N N 7 N N N N N N");
    switch(IsValidBST(tree)){
        case true:
            cout << "Its BST!" << endl;
            break;
        case false:
            cout << "Its not BST" << endl;
            break;
    }
    return 0;
}