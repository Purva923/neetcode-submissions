class Solution {
public:
    vector <vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return res;
    }

    void dfs(int i, vector<int> cur, int total, vector<int>& nums, int target) {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < nums.size(); j++) {

            if (j > i && nums[j] == nums[j - 1])
            continue;

            if (total + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
            dfs(j+1, cur, total + nums[j], nums, target);
            cur.pop_back();
        }
    }
};
