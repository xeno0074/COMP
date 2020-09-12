#include"gen_tree.cpp"
using namespace std;

Node *BTDLL(Node *node){
    if(!node) return node;
    auto r = BTDLL(node->right);
    node->right = r;
    if(r) r->left = node;
    auto l = BTDLL(node->left);
    auto t = l;
    if(!l){
        node->left = NULL;
        return node;
    }
    while(t) {
        node->left = t;
        t = t->right;
    }
    node->left->right = node;
    return l;
}

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    auto t = BTDLL(tree);
    while(t){
        cout << t->data << " ";
        t = t->right;
    }
    cout << "\n";
}