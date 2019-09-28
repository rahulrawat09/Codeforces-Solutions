#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 100000;
 
int N;
double answer = 0.0;
vector<int> adjacency[MAXN];
 
void dfs (int at, int parent, double probability, int depth) {
    /// count how many nodes are below the current node
    int below = 0;
    for (int i: adjacency[at]) {
        if (i != parent) {
            below++;
        }
    }
    /// split the probability of the current node with all the nodes below
    for (int i: adjacency[at]) {
        if (i != parent) {
            dfs (i, at, probability/below, depth+1);
        }
    }
    /// check if the current node is a leaf node
    if (below == 0) {
        answer += probability*depth;
    }
}
 
int main() {
    cin >> N;
    for (int i=0; i<N-1; i++) {
        /// N-1 because there are only N-1 edges
        int a, b;
        cin >> a >> b;
        /// 0-based indexing
        a--;
        b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
 
    dfs(0, 0, 1.0, 0);
    cout << fixed << setprecision(7) << answer <<endl;
}
