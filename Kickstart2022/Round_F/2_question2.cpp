#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define print(p) cout << p << " ";
#define print2(p,q) cout << p << " " << q << endl;
#define print3(p,q,r) cout << p << " " << q << " " << r << endl;
#define print4(p,q,r,s) cout << p << " " << q << " " << r << " " << s << endl;
#define printS(fmt, p) {cout << fmt << ": " ; print(p);}
#define printS2(fmt, p, q) {cout << fmt << ": "; print2(p,q);}
#define printS3(fmt, p, q, r) {cout << fmt << ":"; print3(p,q,r);}
#define printS4(fmt, p, q, r,s) {cout << fmt << ": "; print4(p,q,r,s);}
#define printVec(vec) {for (auto i: vec) cout << i << " "; cout <<endl;}
#define printMat(matrix) {for (auto i : matrix) {printVec(i);} cout << endl;}
#define why {cout << "============= why --> have you foresaken me?! =============" << endl;}
#define lbk {cout << "==============================================================" << endl;}
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;
using QueueItem = pair<int, int>;

unordered_map<int,int> getCapacityAtHeights(unordered_map<int, vector<int>>& adjList, int root){
    unordered_map<int, int> height{};
    unordered_set<int> visited{};  // container 1 will always be the root, and the root has a capacity 1
    queue<QueueItem> q{}; q.push({root, 1}); // create a queue instance and push it.
    while (!q.empty()){
        auto item = q.front(); q.pop(); // remove item from queue.
        // printS2("Current Item: ", item.first, item.second);
        visited.insert(item.first); // add it to visited --> edges are bidirectional.
        // Add all this item's adjacencies to queue.
        for (const int& adj: adjList[item.first]){
            if (!visited.count(adj)) q.push({adj, item.second+1});
        }
        // Add the current height level, increase the capacity by 1.
        if (height.count(item.second) == 0) height[item.second] = 1;
        else ++height[item.second]; // new container at height item.second
    }
    return height; // we get a sum total of all nodes at their respective heights

}

// Write implementation prototypes Here
int same_water_level (unordered_map<int, vector<int> > adjList, vector<int> queries){
    // Corner case: If number of queries is equal to the number of containers, then all will be filled.
    if(adjList.size() <= queries.size()) return queries.size();
    // Corner case: If there are no queries, then none will be filled.
    if(queries.size() == 0) return 0;

    // Since 1 is the root of the tree, we do a breadth first search from root. (idx = 0)
    auto height_levels = getCapacityAtHeights(adjList, 0);
    // printS("Height 1", height_levels[1]);
    // printS("Height 2", height_levels[2]);

    int num_filled {}, curr_height{1}, total_queries = queries.size();
    while (total_queries > 0){

        total_queries -= height_levels[curr_height];
        if (total_queries >= 0) num_filled += height_levels[curr_height];
        // the logic here is that if the capacity at the current height exceeds the remaining number
        // of queries, the containers at that level will not be filled.
        ++curr_height;
    }
    return num_filled;
}

// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        why; 
        // Question IO Here ===========================
        int n{}, q{}; cin >> n >> q; // nodes, queries

        unordered_map<int, vector<int> >  adj{};
        for (int i = 0; i < n-1; ++i){
            int u {}, v{}; cin >> u >> v;
            --u; --v;
            if (adj.count(u) > 0) adj[u].push_back(v); // u has already been inserted
            else adj[u] = {v}; // u is a new node
            if (adj.count(v) > 0) adj[v].push_back(u);
            else adj[v] = {u}; // v is a new node
        }
        vector<int> queries{};
        for (int i = 0; i < q; ++i){
            int query{}; cin >> query;
            queries.push_back(query);
        }
        // ============================================
        auto ans = same_water_level(adj, queries); // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
