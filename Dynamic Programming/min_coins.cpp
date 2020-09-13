#include<bits/stdc++.h>
using namespace std;

void Min_coins(int n){
    int denos[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    sort(denos, denos + sizeof(denos)/sizeof(*denos), greater<int>());
    int q, r = n;
    for(auto change: denos){
        q = r / change;
        r = r % change;
        while(q--) cout << change << " ";
        if(!r) break;
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Min_coins(n);
    }
}