#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solutions {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i <static_cast<int>(nums.size()); i++) {
            m[i] = nums[i];
            if(i == 0) {
                continue;
            }
            int difference = target - nums[i];
            unordered_map<int, int>::iterator it = m.begin();
            while(it != m.end()) {
                if(it->second == nums[i] && i == it->first) {
                    it++;
                    continue;
                }
                if(it->second == difference) {
                    ans.push_back(it->first);
                    ans.push_back(i);
                }
                it++;
            }
        }
        return ans;
    }
};

int main() {
    Solutions s;
    vector<int> vec {3, 2, 4};
    vector<int> ans = s.twoSum(vec, 6);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}