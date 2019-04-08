#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1000;

int n, e;

vector<int> v[MX];

bool visited[MX] = { false };

void dfs(int source){
    stack <int> st;
    st.push(source);
    visited[source] = true;
    while(!st.empty()){
        int t = st.top();
        st.pop();
        for(auto i : v[t]){
            if(!visited[i]) st.push(i);
            visited[i] = true;
        }
    }
}

int main(){ 
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    int numberOfGroups = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == false) {
            dfs(i);
            numberOfGroups++;
        }
    }
    cout << numberOfGroups << endl;
    return 0; 
}
