#include"../Tree/tree.h"

vector<Node *> nodes;
pair<Node *, Node *> defect;

void ConvertToArray(Node *root){
    if(!root) return;
    ConvertToArray(root->left);
    nodes.push_back(root);
    ConvertToArray(root->right);
}

void FixBST(Node *root){
    ConvertToArray(root);
    bool firstTime[2] = {true, true};
    for(int i = 0; i < nodes.size(); i++){
        if(!firstTime[0]){
            if(nodes[i]->data < defect.first->data){
                break;
            }
        }
        defect.first = nodes[i];
        firstTime[0] = false;
    }
    for(int i = nodes.size() - 1; i >= 0; i--){
        if(!firstTime[1]){
            if(nodes[i]->data > defect.second->data){
                break;
            }
        }
        defect.second = nodes[i];
        firstTime[1] = false;
    }

    int temp = defect.first->data;
    defect.first->data = defect.second->data;
    defect.second->data = temp;
}

int main(){
    Node *tree = BuildTree("5 3 8 1 2 6 9 N 4 N N N 7 N N N N N N");
    cout << ToString(tree) << endl;
    FixBST(tree);
    cout << ToString(tree);
}