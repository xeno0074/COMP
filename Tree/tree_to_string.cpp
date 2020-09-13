#include"tree.h"

bool IsLeaf(Node *node){
    return !node->left && !node->right;
}

string ToStr(int n){
    string str = "";
    while(n){
        char c = char(n % 10) + '0';
        str = &c + str;
        n /= 10;
    }
    return str;
}

string ToString(Node *root){
    string str = "";
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *t = q.front();
        q.pop();
        
        if(!t) str += " N";
        else if(IsLeaf(t)){
            str += " " + ToStr(t->data);
        }
        else{
            str += " " + ToStr(t->data);
            q.push(t->left);
            q.push(t->right);
        }
    }
    return str.substr(1);
}