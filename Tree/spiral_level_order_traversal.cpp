#include<bits/stdc++.h>
#include"gen_tree.cpp"
using namespace std;

int level = 0, next_level = 1;
void tog(){
    level = next_level;
    next_level = (next_level + 1) % 2;
}

void slot(Node *node){
    Node *temp;
    stack<Node *> s[2];
    s[level].push(node);
    while(!s[level].empty() || !s[next_level].empty()){
        while(!s[level].empty()){
            temp = s[level].top(); s[level].pop();
            if(!temp) continue;
            cout << temp->data << " ";
            s[next_level].push(temp->right);
            s[next_level].push(temp->left);
        }
        tog();
        while(!s[level].empty()){
            temp = s[level].top(); s[level].pop();
            if(!temp) continue;
            cout << temp->data << " ";
            s[next_level].push(temp->left);
            s[next_level].push(temp->right);
        }
        tog();
    }
    cout << endl;
}

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    slot(tree);
}