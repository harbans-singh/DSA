#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int> vec, int n) {
    pair<int, int> pair_array [n];
    for(int i=0; i<n; i++) {
        pair_array[i].first = vec[i];
        pair_array[i].second = i;
    }

    sort(pair_array, pair_array + n);
    int ans{0};
    vector<bool> visited(n, false); 
    for(int i=0; i<n; i++) {
        int old_index = pair_array[i].second;
        if(visited[i] == true || old_index == i) {
            continue;
        }
        int node = i;
        int count{0};
        while(!visited[node]) {
            visited[node] = true;
            int next_node = pair_array[node].second;
            node = next_node;
            count++;
        }
        ans += (count - 1);
    }
    return ans;
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
    int answer = minSwaps(vec, n);
    cout << "Minimum swaps required to sort array: " << answer << endl;
    return 0;
}