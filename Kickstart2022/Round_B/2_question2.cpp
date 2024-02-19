#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;

// Write implementation prototypes Here
unordered_set<string> findFactors(long long& A) // O(sqrt(N)* log N) time, space
{
    unordered_set <string> factors {};
    for (int i = 1; i <= sqrt(A); ++i)
    {
        if (A % i == 0){
            factors.insert(to_string(i));
            factors.insert(to_string(A/i));
        }
    }
    return factors;
} 

int numberofPalindromes(long long A){
    unordered_set<string> factors = findFactors(A);
    int count_factors {};
    for (const auto& elem: factors){
        // Corner case: a factor of length 1 is a palindrome.
        if (elem.length() == 1) {++count_factors; continue;}
        // otherwise, create a stack to detect the palindrome.
        stack<char> s{};
        int i = 0;
        for (; i < elem.length()/2; ++i) s.push(elem[i]);
        if (elem.length()%2 == 1) ++i;  // skip the middle element.
        for (; i < elem.length(); ++i){
            if (elem[i] != s.top()) break;
            else s.pop();
        }
        if (s.empty()) 
        {
            ++count_factors;
            //cout << "Factor Detected: " << elem << endl;
        }  // if stack is empty, but stack should be empty(?)
    }
    return count_factors;
}



// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        long long A {}; cin >> A;
        // ============================================
        auto ans = numberofPalindromes(A);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
