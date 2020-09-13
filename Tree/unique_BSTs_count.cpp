// link to mathematical derivation

#include<bits/stdc++.h>
using namespace std;

int NumBSTs(int n){
    int num[n + 1];
    num[0] = 1;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= i; j++){
            sum += num[j - 1] * num[i - j];
        }
        num[i] = sum;
    }
    return num[n];
}

int main(){
    for(int i = 1; i <= 10; i++)
        cout << NumBSTs(i) << endl;
    return 0;
}