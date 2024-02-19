#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;
unordered_map< string, char > SUBSTITUTIONS = {
    {"01", '2'},
    {"12", '3'},
    {"23", '4'},
    {"34", '5'},
    {"45", '6'},
    {"56", '7'},
    {"67", '8'},
    {"78", '9'},
    {"89", '0'},
    {"90", '1'}
};
const char NULLCHAR = 'a';
// Write implementation prototypes Here
// O(n^2 time.)
string sillySubstitutions(string s)
{
    bool change = false;
    do
    {
        change = false;
        // Iterate through the string.
        // For each index i, we will have to consider the substrings from this index i. Given null characters on the way we will have 2 for loops,
        // which will arise to O(n^2) time.
        // With the exception of while loop, other operations runs in O(1) time.
        for (int i = 0; i < s.length()-1; ++i){
            if (i == 'a') continue; // If character is null, skip.
            string substring{};
            // Create a substring using any non-null characters that you can find.
            substring += s[i];
            int j = i + 1;
            while (j < s.length() && s[j] == NULLCHAR) ++j;
            // If we are not able to make a substring because we ran out of
            // characters
            if (j == s.length()) continue; // go to another index i.
            substring.push_back(s[j]);
            // If a substitution needs to occur,
            if (SUBSTITUTIONS.count(substring)){
                char substitution = SUBSTITUTIONS[substring];
                // Replace the smaller index with the non-null character.
                s[i] = substitution; s[j] = NULLCHAR;
                // Update change
                change = true;
            }
        }
    }
    while (change);
    // loop breaks out when substitutions are complete.
    // construct the resultant string.
    string result{};
    for (auto & c : s){ //O(n)
        if (c == NULLCHAR) continue;
        result+=c;
    }
    return result;
}



// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n; cin >> n;
        string s; cin >> s;
        // ============================================
        auto ans = sillySubstitutions(s);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
