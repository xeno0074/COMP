#include"gen_tree.cpp"
using namespace std;

map<int, int> m;

vector<int> Bv(Node *node){
    vector<int> bv;
    queue<pair<Node *, int>> q;
    q.push(make_pair(node, 0));
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        if(!temp.first) continue;
        m[temp.second] = temp.first->data;
        q.push(make_pair(temp.first->left, temp.second - 1));
        q.push(make_pair(temp.first->right, temp.second + 1));
    }
    for(auto p: m){
        bv.push_back(p.second);
    }
    return bv;
}

int main(){
    //generate tree
    Node *tree = BuildTree("16 4 N 17 11 N 12 15 N 10 3 N 1 13 N 14 8 N 13 10 N 14 11 N 3 7 N 9 15");
    //display the resulting vector
    auto v = Bv(tree);
    for(auto x: v) cout << x << " "; cout << endl;

    return 0;
}