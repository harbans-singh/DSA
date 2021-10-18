#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longest_band(vector<int> vec) {
    unordered_set<int> myset;
    for(auto x: vec) {
        myset.insert(x);
    }
    int max_count {0};
    unordered_set<int>::iterator it = myset.begin();
    while(it != myset.end()) {
        int count {1};             //count is initialised to 1 because we will use x = n + 1 will will not count n, the value at iterator's address 
        int n = *it;
        if(myset.find(n-1) != myset.end()) {
            it++;
            continue;
        }
        else {
            int x = n + 1;
            while(myset.find(x) != myset.end()) {
                count++;
                x += 1;
            }
        }
        if(count > max_count) {
            max_count = count;
        }
        it++;
    }
    return max_count;
}

int main() {
    int n;
    cout << "Enter vector size: ";
    cin >> n;
    vector<int> vec;
    cout << "Enter vector elements: ";
    while(n > 0) {
        int element;
        cin >> element;
        vec.push_back(element);
        n--;
    }
    int result = longest_band(vec);
    cout << "Length of longest band: " << result << endl;
    return 0;
}