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

struct Fabric {
    string colour {};
    int durability {}, id{};
    Fabric (string clr, int dur, int id_): colour (clr), durability (dur), id(id_) {}
    
    void printFabric (){
        cout << "{" << colour << " | " << durability << "|" << id << "}" << endl;
    }
};
// Write implementation prototypes Here
bool colour_sort(Fabric const& lhs, Fabric const& rhs){
    if (lhs.colour == rhs.colour) return lhs.id < rhs.id ;
    int i = 0; 
    while (i < min(lhs.colour.size(), rhs.colour.size())){
        if (lhs.colour[i] < rhs.colour[i]) return true;
        else if (lhs.colour[i] > rhs.colour[i]) return false;
        ++i;
    }
    if (i < lhs.colour.length()) return false;
    return true;
}
bool durability_sort(Fabric const& lhs, Fabric const& rhs){
    if (lhs.durability == rhs.durability) return lhs.id < rhs.id;
    return (lhs.durability < rhs.durability)? true: false;
}
int num_same_positions(vector<Fabric> fabrics){
    // Sort by Ada, and sort by Charles 
    vector<Fabric> fabric1 = fabrics, fabric2 = fabrics;
    // Sort fabric 1 by colour
    sort(fabric1.begin(), fabric1.end(), &colour_sort);
    // Sort fabric2 by durability
    sort(fabric2.begin(), fabric2.end(), &durability_sort);

    // for (auto &i : fabric1) i.printFabric();
    // for (auto &i: fabric2) i.printFabric();
    int num_same{};

    for (int i = 0; i < fabric1.size(); ++i){
        if (fabric1[i].id == fabric2[i].id) num_same++;
    }
    return num_same;
    
}





// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n; cin >> n;
        vector<Fabric> fabrics;
        for (int i = 0; i < n; ++i){
            string c{}; int d{}, ID{};
            cin >> c >> d >> ID;
            Fabric f = Fabric(c,d,ID);
            fabrics.push_back(f);
        }

        // ============================================
        auto ans = num_same_positions(fabrics) ; // function call
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
