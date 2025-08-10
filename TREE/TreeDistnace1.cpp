#include<bits/stdc++.h>
using namespace std;

//at node 1 we can evalute by using depth/height using dp'
// depth[1] ans for 1'
// depth[u] = 1+max(depth(c1)) i.e c is the child of u;
// ans[i] = dist[i] to the farthest node for i;

const int MAX = 2e5;
vector<int> tree[MAX];
int depth[MAX];
int ans[MAX];

void calDepth(int v, int p){
    int ans = 0;
    for(int u:tree[v]){
        if(u!=p){
            calDepth(u, v);
            ans = max(ans, 1+depth[u]);
        }
    }
    depth[v] = ans;
}

void solve(int v, int p, int p_ans){
    vector<int> prefixMax, suffixMax;
    for(int u: tree[v]){
        if(u!=p){
            prefixMax.push_back(depth[u]);
            suffixMax.push_back(depth[u]);
        }
    }

    for(int i = 1; i<prefixMax.size(); i++){
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    }
    for(int i = suffixMax.size()-2; i>=0; i--){
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
    }
    //cal ans for every child
    int c_no = 0;
    for(int u:tree[v]){
        if(u!=p){
            int op1 = (c_no==0)?INT_MIN:prefixMax[c_no-1];
            int op2 = (c_no==suffixMax.size()-1)?INT_MIN:suffixMax[c_no+1];
            int partial_ans = 1+max(p_ans, max(op1, op2));
            solve(u, v, partial_ans);
            c_no++;
        }
    }
    ans[v] = 1+max(p_ans, (prefixMax.empty()?-1:prefixMax.back()));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    long long t, n, m, x, i, j, k, q;
    cin>>t;
    while(t--){
        cin>>n; 
        for(int i = 0; i<n-1; i++){
            int u, v; 
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        calDepth(1, 0);
        solve(1, 0, -1);
        for(int i = 1; i<n+1; i++){
            cout<<ans[i]<<' ';
        }
    }

    return 0;
}