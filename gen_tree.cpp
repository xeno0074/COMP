// #pragma once
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

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

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    preot(tree);
    cout << endl;
    inot(tree);
    cout << endl;
    posot(tree);
    cout << endl;
}