#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {1, 2, 3};
    int size = nums.size();
    vector<int> left;
    vector<int> right;
    int left_cumulative_sum{0};
    int right_cumulative_sum{0};
    for(int i = 0; i < size; i++) {
        left_cumulative_sum += nums[i];
        left.push_back(left_cumulative_sum);
    }
    for(int i = size - 1; i >= 0; i--) {
        right_cumulative_sum += nums[i];
        right.push_back(right_cumulative_sum);
    }
    reverse(right.begin(), right.end());
    for(int i = 0; i < size; i++) {
        if(left[i] == right[i]) {
            cout << i << endl;
        }
    }
    return 0;
}