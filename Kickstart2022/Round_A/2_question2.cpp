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
int computeDigitSum(string num){
    int sum = 0;
    for (auto &c: num){
        sum += static_cast<int>(c - '0');
    }
    return sum;
}
// main implementation
string challengeNine(string N)
{
    int digit_sum = computeDigitSum(N);
    int value_to_add = 9 - (digit_sum % 9);
    if (digit_sum % 9  == 0){
        // Insert 0 at the second position and return
        N.insert(N.begin()+1, '0');
        return N;
    }
    int i = 0;
    for (; i < N.length(); ++i)
    {
        if (value_to_add >= static_cast<int>(N[i] - '0')) continue;
        else break;
    }
    // Insert number at index i.
    N.insert(N.begin() + i, static_cast<char>(value_to_add + '0'));
    return N;
}



// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        string N;
        cin >> N;
        string ans = challengeNine(N);
        // ============================================
        // auto ans = /* replace this with function call */;
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
