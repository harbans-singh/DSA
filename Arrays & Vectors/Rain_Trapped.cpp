#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rain_amount(vector<int> vec, int n) {
    int result {0};
    vector<int> left;
    vector<int> right;
    left.push_back(vec[0]);
    right.push_back(vec[n-1]);
    for(int i = 1; i < n; i++) {
        int element = max(left[i-1], vec[i]);
        left.push_back(element);
    }
    for(int i = n-2; i >= 0; i--) {
        int element = max(right[n-i-2], vec[i]);
        right.push_back(element);
    }
    reverse(right.begin(), right.end());
    for(int i = 0; i < n; i++) {
        result = result + (min(left[i], right[i]) - vec[i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int element;
        cin >> element;
        vec.push_back(element);
    }
    int rain = rain_amount(vec, n);
    cout << "Rain trapped is: " << rain << " units" << endl;
    return 0;
}