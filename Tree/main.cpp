#include"tree.h"

int main(){
    Node *tree = BuildTree("5 3 8 1 4 6 9 N 2 N N N 7 N N N N N N");
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