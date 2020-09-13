#include<bits/stdc++.h>
using namespace std;

int prog(int *steps, int size){
    vector<int> minJumps(size, INT_MAX);
    minJumps[0] = 0;

    for(int i = 0; i < size; i++){
        if(minJumps[i] == INT_MAX) continue;

        int k = i + steps[i];
        for(int j = i + 1; j <= k; j++){
            if(j < size){
                minJumps[j] = min(minJumps[j], minJumps[i] + 1);
            }
        }
    }
    
    int res = minJumps[size - 1];
    if(res == INT_MAX) res = -1;
    return res;
}

int main(){
    int a[] = {1,3,5,8,9,2,6,7,6,8,9};
    cout << prog(a, 11);
}