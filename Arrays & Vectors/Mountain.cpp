#include <iostream>
#include <vector>
using namespace std;

int mountain(vector<int> vec) {
    int max_count{0};
    for (int i = 1; i < vec.size();) {
        if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) {
            int count{1};
            int j = i;
            while (vec[j] > vec[j - 1] && j >= 1) {
                count++;
                j--;
            }
            while (vec[i] > vec[i + 1] && i < vec.size()) {
                count++;
                i++;
            }
            if (count > max_count) {
                max_count = count;
            }
        }
        else {
            i++;
        }
        // if(vec[i] > vec[i+1]) {
        //     count++;
        // }
    }
    return max_count;
}

//5 6 1 2 3 4 5 4 3 2 0 1 2 3 -2 4
int main() {
    int n;
    cout << "Enter vector length: ";
    cin >> n;
    vector<int> vec;
    cout << "Enter vector elements: ";
    while (n > 0) {
        int element;
        cin >> element;
        vec.push_back(element);
        n--;
    }
    int largest_mountain = mountain(vec);
    cout << "Largest mountain have length: " << largest_mountain;
    return 0;
}