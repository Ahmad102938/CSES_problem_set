#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;
vector<int> tree[MAX];
long long ans[MAX];
long long subTreeAns[MAX];
int subTreeSize[MAX];

//compuitng subTreeAns and subtreeSize
void preComputing(int v, int p){
    int noOfNodes = 1;
    long long ansForSubtree = 0;
    for(int u:tree[v]){
        if(u!=p){
            preComputing(u, v);
            noOfNodes+=subTreeSize[u];
            ansForSubtree += subTreeSize[u]+subTreeAns[u];
        }
    }
    subTreeSize[v] = noOfNodes;
    subTreeAns[v] = ansForSubtree;
}

void solve(int v, int p, long long p_ans, int totalNodes){
    ans[v] = subTreeAns[v] + p_ans + totalNodes -subTreeSize[v];

    for(int u:tree[v]){
        if(u!=p){
            solve(u, v, ans[v]-(subTreeAns[u]+subTreeSize[u]), totalNodes);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    long long t, n, m, x, i, j, k, q;
    t = 1;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        preComputing(1, 0);
        solve(1, 0, 0, n);

        for(int i = 1; i<n+1; i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}