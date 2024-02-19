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
using Matrix = vector<vector<int>>;

// Write implementation prototypes Here
int walktober(Matrix scores, int id){
    // Construct an array that has the maximum for each day.
    vector<int> maxSteps(scores[0].size(), 0); // ## number of days
    for (int i = 0; i < scores[0].size(); ++i){
        int max_steps_so_far = -1;
        for(int j = 0; j < scores.size(); ++j ){
            if (scores[j][i] > max_steps_so_far){
                max_steps_so_far = scores[j][i];
            }
        }
        // update the ith element of this array
        maxSteps[i] = max_steps_so_far;
    }
    int num_steps = 0;
    for (int i = 0; i < scores[0].size(); ++i){
        if (scores[id][i] < maxSteps[i]){
            num_steps += (maxSteps[i] - scores[id][i]);
        }
    }
    return num_steps;
}






// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int m, n, p; cin >> m >> n >> p;
        --p; // zero-based index
        Matrix participant_scores;

        for (int j = 0; j < m; ++j){
            vector<int> v;
            for (int k = 0; k < n; ++k){
                int steps; cin >> steps;
                v.push_back(steps);
            }
            participant_scores.push_back(v);
        }
        //Debug
        //printMat(participant_scores)

        // ============================================
        auto ans = walktober(participant_scores, p); // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
