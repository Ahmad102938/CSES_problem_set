#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;

vector<int> childrens[MAX];
int subord[MAX];

void dfs(int node) {
    subord[node]  =1;
    for(int child: childrens[node]){
        dfs(child);
        subord[node]+=subord[child];
    }
}

int main() {
    int N;
    cin>>N;
    for(int i = 2; i<=N; i++){
        int parent;
        cin>>parent;
        childrens[parent].push_back(i);
    }
    dfs(1);
    //printing
    for(int i = 1; i<=N; i++){
        cout<<subord[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}