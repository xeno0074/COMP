#include"tree.h"

int main(){
    Node *tree = BuildTree("1 2 3 4 6 N 7 N N N 5 8 9");
    preot(tree);
    cout << endl;
    inot(tree);
    cout << endl;
    posot(tree);
    cout << endl;
    cout << endl;
    cout << ToString(tree) << "\n"
        << ToString(DuplicateTree(tree, 5)) << "\n"
        << ToString(tree) << "\n";
}