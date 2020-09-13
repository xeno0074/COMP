#pragma once
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right, *nextSibling;

    Node(int);
};

Node *BuildTree(string);
void preot(Node *);
void posot(Node *);
void inot(Node *);
string ToString(Node *);