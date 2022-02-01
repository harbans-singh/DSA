#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<vector<int>> vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> final_ans;
    for(int i = 1; i <= n; i++) {
        vector<int> temp(i, 1);
        final_ans.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == 1) {
            continue;               //if we want to show either one or two rows, there is no need to do calculations, as vectors are initialised to 1, so, we can directly return it
        }
        for(int j = 1; j < i; j++) {
            final_ans[i][j] = final_ans[i - 1][j - 1] + final_ans[i - 1][j];
        }
    }
    printVec(final_ans);
    return final_ans;
}

int main() {
    int n;
    cout << "Enter number of rows in triangle: ";
    cin >> n;
    vector<vector<int>> ans = pascalTriangle(n);
    return 0;
}