//program to find triplets with particular sum in a vector
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*Using brute force
//void print_vec(vector<int> vec) {
//    for(auto x: vec) {
//        cout << x << " ";
//    }
//    cout << endl;
//}
//
//void triplets(vector<int> vec, int sum) {
//    set<vector<int>> s;
//    vector<int> temp;
//    for(auto i = 0; i < vec.size(); i++) {
//        for(auto j = i + 1; j < vec.size(); j++) {
//            for(auto k = j + 1; k < vec.size(); k++) {
//                if(vec[i] + vec[j] + vec[k] == sum) {
//                    temp.push_back(vec[i]);
//                    temp.push_back(vec[j]);
//                    temp.push_back(vec[k]);
//                    s.insert(temp);
//                    temp.clear();
//                }
//            }
//        }
//    }
//    set<vector<int>>::iterator it = s.begin();
//    while(it != s.end()) {
//        print_vec(*it);
//        it++;
//    }
//}
//
//int main() {
//    int n;
//    cout << "Enter size of vector: ";
//    cin >> n;
//    vector<int> vec;
//    cout << "Enter vector elements: ";
//    for(int i = 0; i < n; i++) {
//        int element {0};
//        cin >> element;
//        vec.push_back(element);
//    }
//    int sum {0};
//    cout << "Enter the value of sum: ";
//    cin >> sum;
//    triplets(vec, sum);
//}
*/

void print_vec(vector<int> vec) {
    for(auto x: vec) {
        cout << x << " ";
    }
    cout << endl;
}

void triplets(vector<int> vec, int sum) {
    set<vector<int>> s;
    vector<int> temp;
    sort(vec.begin(), vec.end());
    for(auto i = 0; i < vec.size(); i++) {
        int j = i + 1;
        int k = vec.size() - 1;
        int temp_sum = sum - vec[i];
        while(j < k) {
            if(vec[j] + vec[k] == temp_sum) {
                temp.push_back(vec[i]);
                temp.push_back(vec[j]);
                temp.push_back(vec[k]);
                s.insert(temp);
                temp.clear();
                j++;
                k--;
            }
            else if(vec[j] + vec[k] > temp_sum) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    
    set<vector<int>>::iterator it = s.begin();
    while(it != s.end()) {
        print_vec(*it);
        it++;
    }
}


int main() {
    int n;
    cout << "Enter size of vector: ";
    cin >> n;
    vector<int> vec;
    cout << "Enter vector elements: ";
    for(int i = 0; i < n; i++) {
        int element {0};
        cin >> element;
        vec.push_back(element);
    }
    int sum {0};
    cout << "Enter the value of sum: ";
    cin >> sum;
    triplets(vec, sum);
    return 0;
}