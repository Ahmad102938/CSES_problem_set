#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;

//adj list
vector<int> adj[MAX];
//2D dp 1 for taking and 0 for didn't take;
int dp[MAX][2];


void dfs(int v, int p){
    //taking no edges;
    for(int u: adj[v]){
        if(u!=p){
            dfs(u, v);
            dp[v][0] += max(dp[u][0], dp[u][1]);
        }
    }
    //taking one edges;
    for(int u: adj[v]){
        if(u!=p){
            dp[v][1] = max(dp[v][1], 1+dp[u][0]+dp[v][0]-max(dp[u][0], dp[u][1]));
        }
    }
}


int main() {

    int N;
    cin>>N;
    for(int i = 1; i<N; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    cout<<max(dp[1][0], dp[1][1])<<endl;

    return 0;
}