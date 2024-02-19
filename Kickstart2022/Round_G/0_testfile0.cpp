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
int test(void){
    print(1);
    print2(2,3);
    print3(4,5,6);
    print4(7,8,9,10);
    lbk;
    printS("1 elem", 1); cout << "\n";
    printS2("2 elem", 2,3);
    printS3("3 elem", 4,5,6);
    printS4("4 elem", 7,8,9,10);
    vector<int> vec {1,2,3,4,5,6,7}, vec2{7,6,5,4,3,2,1};
    print(maxa(vec.begin(), vec.end()));
    print(mina(vec.begin(), vec.end()-2));
    why;
    vector < vector<int> > matrix (7, vec2);
    printVec(vec);
    printMat(matrix);
    return 0;
}
// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================


        // ============================================
        auto ans = test();
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
