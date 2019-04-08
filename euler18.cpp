#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n][n] = { { 0 } };
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) 
                a[i][j]  += a[i-1][j];
            else if(j == i)
                a[i][j]  += a[i-1][j-1];
            else 
                a[i][j] = max(a[i][j]+a[i-1][j-1], a[i][j]+a[i-1][j]);
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[n-1][i] > max) max = a[n-1][i]; 
    }
    cout << max;
    return 0;
}
