#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void combinationSumHelper(
        vector<vector<int>>& result,
        vector<int>& current,
        vector<int>& candidates,
        int i,
        int target
    ) {

        if (i >= candidates.size() || target < 0)
            return;

        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Skip current element
        combinationSumHelper(result, current, candidates, i + 1, target);

        // Take current element (reuse allowed)
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);

            combinationSumHelper(
                result,
                current,
                candidates,
                i,
                target - candidates[i]
            );

            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {
        vector<vector<int>> result;
        vector<int> current;

        combinationSumHelper(
            result,
            current,
            candidates,
            0,
            target
        );

        return result;
    }
};

int main() {

    int n;
    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter elements:\n";
    for(int i=0;i<n;i++){
        cin >> candidates[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<vector<int>> ans =
        obj.combinationSum(candidates, target);

    cout << "\nCombinations:\n";

    for(auto &vec : ans){
        cout << "[ ";
        for(int x : vec){
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}