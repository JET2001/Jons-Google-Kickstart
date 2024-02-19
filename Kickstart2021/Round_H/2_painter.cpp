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
// Red - index 0, Yellow - index 1, Blue - index 2
unordered_map<char, vector<bool> > COLOUR_PALETTE{
    {'U', {false, false,false}}, // uncoloured
    {'R', {true, false, false}}, // red
    {'Y', {false, true, false}}, // yellow
    {'B', {false, false, true}}, // blue
    {'O', {true, true, false}}, // orange
    {'P', {true, false, true}}, // purple
    {'G', {false, true, true}}, // green
    {'A', {true, true, true}} // gray
};
// Write implementation prototypes Here
int minNumStrokes(string &target)
{
    int numStrokes{};
    // First paint everything red
    for (int i = 0; i < target.length(); ++i){
        if (COLOUR_PALETTE[target[i]][0]){ // red == true
            numStrokes++;
            //cout << "New Stroke!" << endl;
            while (i < target.length()-1 && COLOUR_PALETTE[target[++i]][0]){
                //cout << "i = " << i << "target[i] = " << target[i] << endl;
            }
            // if this while loop breaks, we will finish 1 stroke of our painting.
        }
    }
    // Now paint everything yellow
    for (int i = 0; i < target.length(); ++i){
        if (COLOUR_PALETTE[target[i]][1]){ // yellow == true
            numStrokes++;
            //cout << "New Stroke!" << endl;
            while (i < target.length()-1 && COLOUR_PALETTE[target[++i]][1]){
                //cout << "i = " << i << "target[i] = " << target[i] << endl;
            }
            // if this while loop breaks, we will finish 1 stroke of our painting.
        }
    }
    // Now paint everything Blue
    for (int i = 0; i < target.length(); ++i){
        if (COLOUR_PALETTE[target[i]][2]){ // blue == true
            numStrokes++;
            //cout << "New Stroke!" << endl;
            while (i < target.length()-1 && COLOUR_PALETTE[target[++i]][2]){
                //cout << "i = " << i << "target[i] = " << target[i] << endl;
            }
            // if this while loop breaks, we will finish 1 stroke of our painting.
        }
    }
    return numStrokes;
}
// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n; cin >> n;
        string finalPainting; cin >> finalPainting;


        // ============================================
        auto ans = minNumStrokes(finalPainting);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}

// Implementation Here
