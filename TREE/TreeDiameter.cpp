#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;

//adj list
vector<int> adj[MAX];
vector<int> heights(MAX);

int calHeight(int v, int p){
    int ans = 0;
    for(int u: adj[v]){
        if(u!=p){
            ans = max(ans, calHeight(u, v)+1);
        }
    }

    heights[v] = ans;
    return ans;
}

int dfs(int v, int p){
    int ans = 0;
    priority_queue<int> pq;
    for(int u:adj[v]){
        if(u!=p){
            pq.push(heights[u]+1);
        }
    }
    int i  = 0;
    while(!pq.empty() && i<2){
        ans+=pq.top();
        pq.pop(); i++;
    }

    for(int u: adj[v]){
        if(u!=p){
            ans = max(ans, dfs(u, v));
        }
    }

    return ans;
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

    calHeight(1, 0);

    cout<<dfs(1, 0)<<endl;
    for(int i = 0; i<N; i++){
        cout<<heights[i]<<" ";
    }
    cout<<endl;

    return  0;
}