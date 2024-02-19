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

// Write implementation prototypes Here
inline double compute_distance(int x, int y){ // these are these distances from the centre of the stone.
    return sqrt(pow(x,2) + pow(y,2));
}
inline bool inhouse(int x, int y, int rs, int rh){
    return compute_distance(x,y) <= (rs + rh);
}

pair<int,int> curling(vector<double>& dist_r, vector<double>& dist_y){
    // Sort these two vectors
    if (dist_r.size() == 0 && dist_y.size() == 0) return make_pair(0,0);
    // If either case is 0, then basically all seeds in house will be counted.
    if (dist_r.size() != 0 && dist_y.size() == 0) return make_pair(static_cast<int>(dist_r.size()), 0);
    if (dist_r.size() == 0 && dist_y.size() != 0) return make_pair(0, static_cast<int>(dist_y.size()));
    // Otherwise sort the two lists
    sort(dist_r.begin(), dist_r.end());
    sort(dist_y.begin(), dist_y.end());
    // print("Red"); printVec(dist_r); print("Yellow"); printVec(dist_y);
    // Now these vectors are in order of increasing distance.
    // Check which team will get points
    if (dist_r[0] < dist_y[0]){ // red team scores
        int i = 0;
        do
        {
            // printS3("i, dist_r[i], dist_y", i, dist_r[i],dist_y[0]);
            ++i;
        } while (i < dist_r.size() && dist_r[i] < dist_y[0]);
        return make_pair(i, 0);
    }
    else{ //yellow team scores
        int i = 0;
        do {
            // printS3("i, dist_r, dist_y[i]", i, dist_r[i],dist_y[0]);
            ++i;
        } while(i < dist_y.size() && dist_y[i] < dist_r[0]);
        return make_pair(0, i);
    }
}
// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int r_s, r_h; cin >> r_s >> r_h;
        vector<double> dist_r, dist_y; // only consider those disks in house
        int n; cin >> n;
        for (int j = 0 ; j < n; ++j){
            int x, y; cin >> x >> y;
            if (inhouse(x,y,r_s,r_h)){ // Filter those which are in house
                dist_r.push_back(compute_distance(x,y));
            }
        }
        int m; cin >> m;
        for (int j = 0; j < m; ++j){
            int w,z; cin >> z >> w;
            if (inhouse(w,z,r_s,r_h)){ // Filter those that are in house
                dist_y.push_back(compute_distance(w,z));
            }
        }
        // ============================================
        auto ans = curling(dist_r, dist_y); // function call
        cout << "Case #" << i << ": " << ans.first << " " << ans.second << endl;
    }
    return 0;
}

// Implementation Here
