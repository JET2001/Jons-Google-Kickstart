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
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define print(p) cout << p << " ";
#define print2(p,q) cout << p << " " << q << endl;
#define print3(p,q,r) cout << p << " " << q << " " << r << endl;
#define print4(p,q,r,s) cout << p << " " << q << " " << r << " " << s << endl;
#define printS(fmt, p) {cout << fmt << ": " ; print(p);}
#define printS2(fmt, p, q) {cout << fmt << ": "; print2(p,q);}
#define printS3(fmt, p, q, r) {cout << fmt << ":"; print3(p,q,r);}
#define printS4(fmt, p, q, r,s) {cout << fmt << ": "; print4(p,q,r,s);}
#define printVec(vec) {for (auto i: vec) cout << i << " "; cout <<endl;}
#define printMat(matrix) {for (auto i : matrix) {printVec(i);} cout << endl;}
#define why {cout << "============= why --> have you foresaken me?! =============" << endl;}
#define lbk {cout << "==============================================================" << endl;}
// using Vector = vector < TYPE >;
// using Matrix = vector< vector<TYPE> >;
struct Ant{
    int idx {};
    int curr_pos{};
    int dir{};
    int time{};
    bool fallen {false};
    Ant* left {nullptr};
    Ant* right {nullptr};
    Ant(int idx, int pos, int dir, Ant* left = nullptr, Ant* right = nullptr): idx(idx), curr_pos(pos), dir (dir), left (left), right(right), time(0)
    {}
    void processCollision(){
        if (dir == 0){ // ant moving left, colliding with ant on its left
            int curr_time = max(time, left->time);
            if (time != curr_time) curr_pos -= (curr_time - time);
            if (left->time != curr_time) left->curr_pos += (curr_time - left->time);
            int dist = abs(curr_pos - left->curr_pos);
            // left->time += dist;
            dir = 1; left->dir = 0;
            if (dist % 2 == 0) {
                curr_pos = left->curr_pos = (curr_pos + left->curr_pos)/2;
                time = left->time = curr_time + dist/2;
            } else {
                curr_pos = curr_pos - (dist / 2); left->curr_pos = left->curr_pos +(dist/2);
                time = left->time = curr_time + (dist/2 + 1);
            }
            //printS4("Collision:", this->idx, left->idx, this, left);
        }
        else {
            // time += dist;
            int curr_time = max(time, right->time);
            if (time != curr_time) curr_pos += (curr_time - time);
            if (right->time != curr_time) right->curr_pos -= (curr_time - right->time);
            int dist = abs(curr_pos - right->curr_pos); // colliding with right
            dir = 0; right->dir = 1;
            if (dist % 2 == 0) {
                curr_pos = right->curr_pos = (curr_pos + right->curr_pos)/2;
                time = right->time = curr_time + dist/2;
            } else {
                curr_pos = curr_pos + (dist / 2); right->curr_pos = right->curr_pos -(dist/2);
                time = right->time = curr_time + (dist/2 + 1);
            }
            //printS4("Collision:", this->idx, right->idx, this, right);
        }
    }
    Ant* processFall(int L){
        if (dir == 0) {
            //print(curr_pos);
            time += curr_pos; 
            if (right!=nullptr) right->left = nullptr;
            fallen = true;
            return right;
        }
        else {
            //print(curr_pos);
            time += L + 1 - curr_pos;
            if (left != nullptr) left->right = nullptr;
            fallen = true;
            return left;
        }
    }
    Ant* isBlocked(){
        if (dir == 0) return left;
        return right;
    }
    // bool operator<(const Ant* other){
    //     if (time == other->time){
    //         return idx < other->idx;
    //     }
    //     return time < other->time;
    // }
    // ~Ant(){
    //     delete this;
    // }
    friend ostream& operator<< (ostream& os, const Ant* ant){
        os << "{idx: " << ant->idx << "| fallen: " << ant->fallen << "| curr_pos:" << ant->curr_pos << "| time: " << ant->time << "| left: ";
        if (ant->left == nullptr) os <<  "[null]";
        else os << ant->left->idx;
        os << "| Right: ";
        if (ant->right == nullptr) os << "[null]";
        else os << ant->right->idx;
        os << "}";
        return os;
    }
};
// Comparison for final output
bool compareAnts(const pair<int, int> & p1, const pair<int, int>& p2){
    return (p1.second == p2.second)? (p1.first < p2.first) : (p1.second < p2.second);
}
// Write implementation prototypes Here
vector<int> orderOfFall(int stick_length, vector<int> pos, vector<int> dir, vector<int> stick){
    // Use the stick to determine which ant is adjacent to which. 
    //printVec(pos);
    //printVec(dir);
    //printVec(stick);
    vector<Ant*> all_ants{};
    vector< pair<int, int> > fallen_ants{};
    int ant_count {}; Ant* curr_ant{nullptr}, *prev_ant{nullptr};
    int i = 0;
    while (ant_count < pos.size()) // O(n)
    {
        //printS("i",i);
        if (stick[i] == -1) {++i; continue;}// no ants there
        ant_count += 1;
        if (ant_count == 1) {
            //lbk;
            curr_ant = new Ant(stick[i]+1, pos[stick[i]], dir[stick[i]]);
            //cout << curr_ant << endl;
            all_ants.push_back(curr_ant);
            //print("New ant inserted!");
            //lbk;
        }
        else{ // ant is probably in between two ants
            //lbk;
            curr_ant = new Ant(stick[i]+1, pos[stick[i]], dir[stick[i]], prev_ant);
            prev_ant->right = curr_ant;
            all_ants.push_back(curr_ant);
        }
        prev_ant = curr_ant;
        i++;
    }
    //why;
    //printVec(all_ants);
    prev_ant = curr_ant = nullptr; // reset the pointers.
    curr_ant = all_ants[0];
    while (curr_ant != nullptr){
        //printS2("Curr_ant, size of fallen: ", curr_ant->idx, fallen_ants.size());
        // Check if it is blocked.
        if (curr_ant->isBlocked() != nullptr) {
            //print ("Ant is blocked!");
            prev_ant = curr_ant;
            curr_ant = curr_ant->isBlocked();
            // Check if ants are colliding with its neighbour
            if (curr_ant->isBlocked() == prev_ant) curr_ant->processCollision();
        }
        else { // If it is not blocked it is going to fall.
            //print("Ant is not blocked!");
            Ant* temp = curr_ant->processFall(stick_length); // curr_ant changes to the neighbour
            //printS("Ant has fallen!", curr_ant);
            //print(curr_ant);
            fallen_ants.push_back(make_pair(curr_ant->idx, curr_ant->time));
            curr_ant = temp;
        }
        //lbk;lbk;
        //printS("Size of fallen", fallen_ants.size());
    }
    //print("Out of loop");
    // Sort the fallen vector.
    sort(fallen_ants.begin(), fallen_ants.end(), compareAnts); // O(NlogN) time
    vector<int> output;
    for (auto& ant: fallen_ants) {
        output.push_back(ant.first);
    }
    // Clear heap memory
    for (auto& ant: all_ants){
        delete ant; ant = nullptr;
    }
    return output;
}

// Driver code
int main(){
    int test_cases{};
    cin >> test_cases;
    for (int i = 1 ; i <= test_cases; ++i){
        // Question IO Here ===========================
        int n, l; cin >> n >> l;
        vector<int> position{}, direction{}; // position of ant currently and direction of i-th ant.
        vector<int> stick (l, -1);// would hold a reference to the starting positions of the ants on the stick.
        for (int i = 0; i < n; ++i){
            int pos, dir; cin >> pos >> dir;
            position.push_back(pos); direction.push_back(dir);
            stick[pos-1] = i; // store the ith ant (Zero-based) at index pos-1 on the stick.
        }

        // ============================================
        auto ans = orderOfFall(l, position, direction, stick);
        cout << "Case #" << i << ": "; printVec(ans);   
    }
    return 0;
}

// Implementation Here
