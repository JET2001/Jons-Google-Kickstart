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
using Point = pair<int,int>;
// Write implementation prototypes Here







// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ==========================='
        int n, e; cin >> n >> e;
        vector<Point> flowers; vector<int> values;
        for (int i = 0; i < n; ++i){
            int x, y, c; cin >> x >> y >> c;
            flowers.push_back(make_pair(x,y));
            values.push_back(c);
        }


        // ============================================
        auto ans = ; // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
