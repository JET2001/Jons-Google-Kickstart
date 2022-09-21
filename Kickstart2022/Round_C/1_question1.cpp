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

// inline bool hasDigits(string &s){ 
//     for (auto c: s)if (c >= '0' && c <= '9') return true;
//     return false;
// }
// inline bool hasUpper(string &s){
//     for (auto c: s) if (c >= 'A' && c <= 'Z') return true;
//     return false;
// }
// inline bool hasLower(string &s){
//     for (auto c : s) if (c >= "a" && c <= 'z') return true;
//     return false;
// }
// inline bool hasSpecial(string &s){
//     for (auto)
//}
string newPassword(string s){
    char digit = '1', lower = 'a', upper = 'A', special = '#';
    bool hasUpper {false}, hasLower {false}, hasDigit{false}, hasSpecial{false}, hasSeven{false};
    for (const auto &c : s){
        if (c >= '0' && c <='9') hasDigit = true;
        else if (c >= 'a' && c <= 'z') hasLower = true;
        else if (c >= 'A' && c <= 'Z') hasUpper = true;
        else if (c == '#' || c == '@' || c == '*' || c == '&') hasSpecial = true;
        else;
    }
    if (!hasUpper) s += upper;
    if (!hasLower) s+=lower;
    if (!hasDigit) s+=digit;
    if (!hasSpecial) s+=special;
    // Now check if there is already 7 characters.
    if (s.length() >= 7) return s;
    // Do this if s is less than 7
    while (s.length() < 7) s += digit;
    return s;
}






// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n; cin >> n;
        string old; cin >> old;


        // ============================================
        string ans = newPassword(old); // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
