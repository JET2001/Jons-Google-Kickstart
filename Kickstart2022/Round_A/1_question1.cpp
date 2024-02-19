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
using namespace std;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;

// Write implementation prototypes Here
int questionOne(string I, string P)
{
    // Corner case: P < I
    if (I.length() > P.length()) return -1; // flag for impossible
    if (I.length() == P.length()) return (I == P) ? 0 : -1; // impossible

    // Create 2 pointers to the front of both strings
    int i {0}, p {0};
    int output {};
    while (i < I.length() && p < P.length())
    {
        // Case 1: they are equal
        if (I[i] == P[p]) {++i; ++p;} // move both pointers forward
        // Case 2: they are not equal,
        else {output+=1; ++p;}
    }
    // It is impossible to return the string because we have different number of characters.
    if (i != I.length()) return -1;
    output += (P.length() - p);
    return output;
}
// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        string I {}, P {};
        cin >> I >> P;
        // ============================================
        auto ans = questionOne(I, P);
        if (ans == -1) cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        else cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
