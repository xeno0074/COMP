#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void prog1(){
    // all inputs
    int n; cin >> n;
    vector<int> a(n);
    int break_index = 0, max_val = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < max_val) break_index = i;
        max_val = max(max_val, a[i]);
    }
    int k; cin >> k;
    // main prog
    bool found = false;
    if(k >= a[break_index] && k <= a[n - 1]){
        for(int i = break_index; i < n; i++){
            if(k == a[i]){
                cout << i;
                found = true;
            }
        }
    }
    else{
        for(int i = 0; i < break_index; i++) 
            if(k == a[i]){ 
                cout << i;
                found = true;
            }
    }
    if(!found) cout << -1;
    
    
}

int prog2(int *a, int l, int r, int k){
    int m = (l + r) / 2;
    if(k == a[m]){
        return m;
    }
    else if(k < a[m] && m > l){
        return prog2(a, l, m - 1, k);
    }
    else if(k > a[m] && m < r){
        return prog2(a, m + 1, r, k);
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        //*
        int n; cin >> n;
        int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
        int k; cin >> k;
        cout << prog2(a, 0, n - 1, k);
        //*/
        cout << endl;
    }
    return 0;
}