#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {

        // 🔥 skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // 🔥 skip duplicates for left & right
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;

            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);
    for (auto& triplet : ans) {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }
    
}