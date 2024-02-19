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
void printQueue(queue<pair<int,int>> q){
    while (!q.empty()){
        auto item = q.front(); q.pop();
        cout << "{idx, k: " << item.first << " | " << item.second << "}," ;
    }
    cout << endl;
}// pass by copy
inline int compute_sum(vector<int>&prefix, int L, int R){ // inclusive - O(1)
    if (L == 0) return prefix[R];
    return (prefix[R] - prefix[L-1]);
}
// Write implementation prototypes Here
int happy_subarrays(vector<int> A){
    // Corner case
    if (A.size() == 1) return (A[0] >= 0)? (A[0]) : (0); // the only possible subarray is iself
    vector<int> prefix(A.size(), 0);

    prefix[0] = A[0];
    for (int i = 1; i < A.size(); ++i){ // compute prefix sum - O(n)
        prefix[i] = prefix[i-1] + A[i];
    }
    // print("Prefix: "); printVec(prefix);
    int total_sum = 0;
    queue<pair<int,int>> possible;
    
    // The first time we iterate through, store all the non-negative indices.
    for (int i = 0 ; i < A.size(); ++i){ // O(n)
        if (A[i] >= 0){
            total_sum += A[i]; // subarray of length 1
            // Add to queue
            possible.push(make_pair(i, 1)); // insert, storing index i, and indicating that we just considered the happy subarray of length 1 from i. 
        }
    }
    while(!possible.empty()){ // O(n^2) worst case
        //printQueue(possible);
        auto item = possible.front();
        possible.pop(); // remove item from queue
        int curr_k = item.second + 1; // new length of subarray from this point.
        int idx = item.first; // get starting subarray index
        // Check if subarray does not exist.
        if (idx + curr_k - 1 >= A.size()) continue; // not possible subarray
        // Now the subarray exists. Check if subarray is happy
        if (compute_sum(prefix, idx, idx+curr_k-1) >= 0){
            // Add to the total sum
            total_sum += compute_sum(prefix, idx, idx+curr_k-1);
            // Reinsert it back into the queue.
            possible.push(make_pair(idx, curr_k));
        } 
    }
    // When this ends, we have considered all possible happy subarays
    return total_sum;
}





// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n; cin >> n; 
        vector<int> A;
        for (int i = 0 ; i < n; ++i){
            int ai; cin >> ai;
            A.push_back(ai);
        }
        // ============================================
        auto ans = happy_subarrays(A); // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
