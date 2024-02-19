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
vector<string>  ORDER_OF_SUB {
    "01", "12", "23", "34", "45", "56", "67", "78", "89", "90"
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
        // For each target substring
        for (int target_substring_idx = 0; target_substring_idx < ORDER_OF_SUB.size(); ++target_substring_idx)
        {
            // Scan the string for the target substring.
            for (int i = 0; i < s.length()-1; ++i){
                // if string is null, then continue.
                if (s[i] == NULLCHAR) continue;
                string substring{}; substring += s[i];
                int j = i+1;
                //search for the next non null character.
                while (j < s.length() && s[j] == NULLCHAR) ++j;
                // no more possible substrings
                // nearest character is already null.
                if (j == s.length()) break;
                substring += s[j];
                //cout << "Target substring = " << ORDER_OF_SUB[target_substring_idx] << " i = " << i << " j = " << j << " substring = " << substring << "String = " << s << endl;
                // Check if this matches our target substring.
                if (substring == ORDER_OF_SUB[target_substring_idx]){
                    //cout << " Substitution of " << substring << " found!"<< endl;
                    char substitution = SUBSTITUTIONS[substring];
                    // Replace the smaller index with the non-null character.
                    s[i] = substitution; s[j] = NULLCHAR;
                    // Update change
                    change = true;
                }
                // if it doesn't match that's ok, we can try other substrings
                // within the current string if they exist.
            }
            // or we can try other substitutions.
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
