#include"gen_tree.cpp"
using namespace std;

void  Connect(Node *node){
    queue<pair<Node *, int>> q;
    q.push(make_pair(node, 0));
    Node *dummy = new Node(0);
    Node *prev = dummy;
    int currLevel = 0;
    while (!q.empty()){
        pair<Node *, int> t = q.front();
        q.pop();
        if(t.second > currLevel){
            prev->nextSibling = NULL;
        }
        else if(t.second == currLevel){
            prev->nextSibling = t.first;
        }
        prev = t.first;
        currLevel = t.second;
        if(t.first->left) q.push(make_pair(t.first->left, t.second + 1));
        if(t.first->right) q.push(make_pair(t.first->right, t.second + 1));
    }
    prev->nextSibling = NULL;
    node->nextSibling = NULL;
    delete dummy;
}

void pre(Node *node){
    if(!node) return;
    auto v = node;
    while(v){
        cout << v->data << " ";
        v = v->nextSibling;
    }
    cout << "\n";
    pre(node->left);
    pre(node->right);
}

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    Connect(tree);
    pre(tree);
}