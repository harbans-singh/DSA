#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> subarray(vector<int> vec, int n) {
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x = vec[i];
        if(i == 0 && x > vec[1]) {
            largest = max(x, largest);
            smallest = min(x, smallest);
        }
        else if(i == n-1 && x < vec[n-2]) {
            largest = max(x, largest);
            smallest = min(x, smallest);
        }
        else if(i != 0 && i != n-1 && (x > vec[i+1] || x < vec[i-1])) {
            largest = max(x, largest);
            smallest = min(x, smallest);
        }
    }
    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
    if(smallest == INT_MAX) {
        return {0, 0};
    }
    int left_index {0};
    int right_index {n-1};
    while(smallest >= vec[left_index]) {
        left_index++;
    }
    while(largest <= vec[right_index]) {
        right_index--;
    }
    return {left_index, right_index};
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
    pair<int, int> result = subarray(vec, n);
    cout << result.first << " " << result.second << endl;
    return 0;
}
