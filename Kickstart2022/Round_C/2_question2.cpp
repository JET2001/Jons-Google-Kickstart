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
vector<int> computeRatio(int n, int x, int y){
    int sum = (n)*(n+1)/2;
    //printS4("N, Sum, x, y", n, sum, x, y);
    if (sum % (x+y) != 0) return {}; //gcd == 1
    vector<int> output{};
    x = sum/(x+y) * x; // Scale x such that it is equivalent to the sum
    int largest_num = n;
    while (x > 0){
        //printS("==== x", x); cout << endl;
        if (x > largest_num){
            output.push_back(largest_num);
            x-= largest_num;
            --largest_num;
        }
        else{
            output.push_back(x);
            break;
        }
    }
    return output;
}






// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n{}, x{}, y{};
        cin >> n >> x >> y;


        // ============================================
        vector<int> ans = computeRatio(n,x,y);
        if (ans.size() == 0) cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        else{
            cout << "Case #" << i << ": POSSIBLE" << "\n"
            << ans.size() << "\n";
            printVec(ans);
            // for (auto &i : ans) cout << i << ", ";
            // cout << endl;
        }
        // cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
