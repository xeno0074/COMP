#include"tree.h"

Node::Node(int x){
    data = x;
    left = NULL;
    right = NULL;
}

Node *BuildTree(string seq){
    //fill queue
    vector<int> stream;
    stringstream ss(seq);
    string word;
    int num;
    while(getline(ss, word, ' ')){
        if(word == "N") num = -1;
        else num = stoi(word);
        stream.push_back(num);
    }
    //use queue to build
    queue<Node **> q;
    //first node
    int temp = stream[0];
    stream.erase(stream.begin());
    Node *tree = new Node(temp);
    q.push(&(tree->left)); q.push(&(tree->right));
    //rest nodes
    for(int x: stream){
        if(x == -1){
            q.pop();
            continue;
        }
        Node **npp = q.front(); q.pop();
        *npp = new Node(x);
        q.push(&((*npp)->left));
        q.push(&((*npp)->right));
    }
    //return tree
    return tree;
}

void preot(Node *node){
    if(!node) return;
    cout << node->data << " ";
    preot(node->left);
    preot(node->right);
}
void posot(Node *node){
    if(!node) return;
    posot(node->left);
    posot(node->right);
    cout << node->data << " ";
}
void inot(Node *node){
    if(!node) return;
    inot(node->left);
    cout << node->data << " ";
    inot(node->right);
}

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
Node *DuplicateTree(Node *root, int s){
    if(!root) return root;
    Node *node = new Node(root->data + s);
    node->left = DuplicateTree(root->left, s);
    node->right = DuplicateTree(root->right, s);
    return node;
}