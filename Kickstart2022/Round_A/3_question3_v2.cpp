#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;


// This method uses bottom-up dynamic programming. It involves processing the characters in the input from 
// left to right, while maintaining a set of possible prefixes truncated to the last five characters.
// To calculate an input character, we calculate a new set by extendign the prefixes from the old set.
// For example, if the set contains 10100 and the next input character is 1 then we can add 01001 to the
// next set. If the input character were ? instead, then we could also add 01000. If it becomes empty at
// any point, the answer is IMPOSSIBLE. If it is non-empty when we reach the end of the input, the answer
// is POSSIBLE. 

// This second approach effectively executes a non-deterministic finite state automation corresponding
// with the finite state graph shown in the notes. It is non-deterministic because whenever the input 
// contains a question mark, the transitions labelled with 0 and 1 are both possible, hence the need to 
// track a set of states rather than a single state only. This approach takes O(2^5 x N) = O(N) time as
// well, but since we only maintain a single set of possible states, the space requirement is reduced to
// O(2^5) = O(1). 
// ======================================================================
unordered_map < pair<int,string>, bool> dp{}; // memoization
string s {};

inline bool checkPalindrome(string s){
    if (s.length() <= 4) return false;
    for (int i = 0; i < s.length(); ++i) if (s[i] != s[s.size()-1-i]) return false;
    return true;
}

inline bool isPalindrome(string &s){
    if (s.length() == 6) return (checkPalindrome(s) || 
    checkPalindrome(s.substr(0,5)) || checkPalindrome(s.substr(1,5)));
    return checkPalindrome(s);
}
bool PFSHelper(string& s, int idx, string five){
    if (idx == s.length()) return true;
    if (dp.count(make_pair(idx, five)) == 0) return dp[make_pair(idx,five)];  // solution obtained via caching
    bool ans = false; 
    string tmp = "";
    int start = 0; // index of the start of the suffix of length >= 5
    if (five.length() == 6) start = 1;
    for (int i = start; i < five.length(); ++i){
        tmp += five[i];
    }
    if (s[idx] != '1'){
        string z = tmp + '0';
        if (!isPalindrome(z)) ans = ans | PFSHelper(s, idx+1, z);  
    }
    if (s[idx] != '0'){
        string z = tmp +"1";
        if (!isPalindrome(z)) ans = ans | PFSHelper(s, idx+1, z);
    }
    dp[make_pair(idx, five)] = ans;
    return ans;

}


// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int N; cin >> N;
        string S; cin >> S;
        dp.clear();
        // ============================================
        string ans = (PFSHelper(s, 0, "") == true)? "POSSIBLE" : "IMPOSSIBLE";
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
