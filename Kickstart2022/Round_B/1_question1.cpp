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
#include <iomanip>
#include <limits>
using std::cin; using std::cout; using std::endl;
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >

// Write implementation prototypes Here

unsigned long long calculateArea(int R, int A, int B)
{
    unsigned long long area = R*R;
    while (R > 0){
        R*=A;
        area += R*R;
        R/= B;
        area += R*R;
    }
    return area;
}


// Driver code
int main(){
    const double PI = atan(1)*4;
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int R, A, B;
        cin >> R >> A >> B;
        // ============================================
        long double ans = PI * calculateArea(R,A,B)/* replace this with function call */;
        cout << "Case #" << i << ": " << std::setprecision(std::numeric_limits<double>::digits10 + 1) << ans << endl;
    }
    return 0;
}

// Implementation Here