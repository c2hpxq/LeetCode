class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> val_idx;
        val_idx.reserve(n);

        for (int i = 0; i < n; i++) {
            val_idx.emplace_back(nums[i], i);
        }

        sort(val_idx.begin(), val_idx.end());

        long long cost = 0;
        int last = n;
        for (int i = 0; i < n; i++) {
            const auto &[_, idx] = val_idx[i];
            if (idx < last) {
                cost += n - i;
            }
            last = idx;
        }

        return cost;
    }
};