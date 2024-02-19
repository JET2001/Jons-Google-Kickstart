#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;
int getClosestLetter(string& f, char c); // Each operation would take log f time.

// Write implementation prototypes Here - n log n time
int minNumOperations(string s, string f){
    int minOperations{};
    for (auto& c: s){
        minOperations += getClosestLetter(f, c);
    }
    return minOperations;
}


// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        string s, f;
        cin >> s; cin >> f;


        // ============================================
        auto ans = minNumOperations(s, f); /* replace this with function call */
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
// Does a binary search - logarithmic time
int getClosestLetter(string& f, char c){
    int left = 0, right = f.length() - 1;
    while (left <= right){
        int midpt = (left + right)/2;
        if (f[midpt] == c) return 0; // no operations needed.
        if (f[midpt] > c) right = midpt - 1;
        else left = midpt + 1;
    }
    // Character not present in the set.
    // The minimum number of operations would be to calculate the
    // minimum among 4 cases:
    // consider the case where a wraparound is expected.
    //cout << "c = " << c << " left = " << left << " f[left] = " << f[left] << " right = " << right << " f[right] = " << f[right] << endl;
    if (right < 0) return min (abs(f[0]-c), abs(c - 'a' + 1 + ('z'-f[f.length()-1])));
    //cout << ('z' - c) + (f[0]-'a')+1 << endl;
    if (left >= f.length()) return min (abs(f[f.length()-1] - c), abs(('z' - c) + (f[0]-'a')+1));
    // No wrap around needed.
    return abs(min (c - f[right], f[left] - c));


}
