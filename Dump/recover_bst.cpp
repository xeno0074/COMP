#include"../Tree/tree.h"

Node *buff[2];
bool firstRun[2] = {true};
bool found[2] = {false};

void Swap(){
    int temp = buff[0]->data;
    buff[0]->data = buff[1]->data;
    buff[1]->data = temp;
}

void UpdateBuff0(Node *node){
    if(firstRun[0]){
        firstRun[0] = false;
        buff[0] = node;
        return;
    }
    if(buff[0]->data > node->data){
        found[0] = true;
        return;
    }
    buff[0] = node;
}

void UpdateBuff1(Node *node){
    if(firstRun[1]){
        firstRun[1] = false;
        buff[1] = node;
        return;
    }
    if(buff[1]->data < node->data){
        found[1] = true;
        return;
    }
    buff[1] = node;
}

void Recov(Node *r0, Node *r1){
    if(!r0 && !r1) return;
    else if(r0){
        Recov(r0->left, r1);
        if(!found[0]) UpdateBuff0(r0);
        Recov(r0->right, r1);
    }
    else if(r1){
        Recov(r0, r1->right);
        if(!found[1]) UpdateBuff1(r1);
        Recov(r0, r1->left);
    }
    else{
        Recov(r0->left, r1->right);
        if(!found[0]) UpdateBuff0(r0);
        if(!found[1]) UpdateBuff1(r1);
        Recov(r0->right, r1->left);
    }
}

void Recovery(Node *root){
    Recov(root, root);
    if(found[0] && found[1]) Swap();
}

int main(){
    Node *tree = BuildTree("5 3 8 1 2 6 9 N 4 N N N 7 N N N N N N");
    Recovery(tree);
    cout << ToString(tree);
}