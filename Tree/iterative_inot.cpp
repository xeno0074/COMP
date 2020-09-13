#include"gen_tree.cpp"
using namespace std;

vector<int> IterInot(Node *node){
    vector<int> res;
    map<Node *, bool> vis;
    stack<Node *> st;
    st.push(node);
    while(!st.empty()){
        Node *temp = st.top(); 
        st.pop();
        if(!temp) continue;

        if(vis[temp]) res.push_back(temp->data);
        else{
            st.push(temp->right);
            if(temp->left) st.push(temp);
            else res.push_back(temp->data);
            st.push(temp->left);
        }
        vis[temp] = true;
    }
    return res;
}

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    vector<int> v = IterInot(tree);
    for(int x: v) cout << x << " "; cout << endl;
}