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

// vector< vector<bool> > detectPalindrome(string s)
// {
//     vector<bool> rows (s.length(), false); vector < vector<bool> > P (s.length(), rows); // P[i][j] stores whether [i...j] is a palindrome
//     // A string of size 1 is a palindrome. 
//     for (int i = 0; i < s.length(); ++i) P[i][i] = true;
//     // Detect palindromes of size 2
//     for (int i = 0; i < n - 1; ++i){
//         if (s[i] == s[i+1]) P[i][i+1] = true;
//     }
//     // Palindromes longer than 2. 
//     for (int gap = 2; gap < s.length(); ++gap){
//         // pick starting point of gap
//         for (int i = 0; i < s.length() - gap; ++i){
//             int j = gap + i; // ending point
//             // If current string is a palindrome
//             if (s[i] == s[j] && P[i+1][j-1]) P[i][j] = true;
//         }
//     }
//     return P;

// }

bool checkPalindromeFree(string& s){
    // check entire string and its substring for palindromes
    //cout << "Check string: " << s << ": ";
    bool palindromeFree = true;
    for (int gap = 4; gap < s.length(); ++gap){ // we start at gap 4, for length 5.
        // pick starting point of gap
        for (int i = 0; i < s.length() - gap; ++i){
            int start = i, end = gap + i; // start and end point
            // If current string is a palindrome
            while (start <= end){
                if (s[start] == s[end]){
                    if (start == end || start+1 == end){ // equality holds for final palindrome check
                        //cout << "Palindrome detected at " << i << " " << gap + i << endl;
                        return false;
                    }
                    ++start; --end; //decrement the pointers to check for a palindrome.
                }
                else break; // not a palindrome, still palindrome free. }
            }
            // if (palindromeFree == false) break;
        }
        // if (palindromeFree == false) break;
    }
    //cout << "Palindrome Free " << endl;
    return palindromeFree;
}

bool buildString(string s, int currIdx, const unordered_set<int>& qn_marks){
    // If we reach the end of the string. 
    while (currIdx < s.length() && qn_marks.count(currIdx) == 0) ++currIdx;
    if (currIdx == s.length()) return checkPalindromeFree(s);
    // Modify s[i] to be 1, and recursively call the function again.
    s[currIdx] = '1';
    bool perm_one = buildString(s, currIdx+1, qn_marks);
    s[currIdx] = '0';
    bool perm_two = buildString(s, currIdx+1, qn_marks);

    return perm_one || perm_two;
}

// Write implementation prototypes Here
bool palindromeFreeString(string s){
    // Traverse the input once and store all the substitution spots
    unordered_set<int> qn_marks{};
    for (int i = 0; i < s.length(); ++i) 
        if (s[i] == '?') qn_marks.insert(i);
    
    return buildString(s, 0, qn_marks);
}


// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int N; cin >> N;
        string S; cin >> S;
        
        // ============================================
        auto ans = (palindromeFreeString(S) == true)? "POSSIBLE" : "IMPOSSIBLE";
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
