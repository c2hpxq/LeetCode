class RangeSum {
public:
    RangeSum(int L, int R): L_(L), R_(R), bt_(4*(R - L + 1) + 1, 0) {}

    void Add(int i, int v) {
        assert(L_ <= i && i <= R_);
        AddInternal(1, i, v, L_, R_);
    }

    int Sum(int l, int r) {
        assert(L_ <= l && l <= r && r <= R_);
        return SumInternal(1, l, r, L_, R_);
    }

private:

    int L_;
    int R_;
    vector<int> bt_;

    void AddInternal(int n, int i, int v, int L, int R) {
        bt_[n] += v;
        if (L == R) {
            return ;
        }

        int M = (L + R) / 2;

        if (i <= M) {
            AddInternal(n * 2, i, v, L, M);
        } else {
            AddInternal(n * 2 + 1, i, v, M + 1, R);
        }
    }

    int SumInternal(int n, int l, int r, int L, int R) {
        if (l == L && r == R) {
            return bt_[n];
        }

        int M = (L + R) / 2;
        if (r <= M) {
            return SumInternal(n * 2, l, r, L, M);
        }

        if (l > M) {
            return SumInternal(n * 2 + 1, l, r, M + 1, R);
        }

        return SumInternal(n * 2, l, M, L, M) + SumInternal(n * 2 + 1, M + 1, r, M + 1, R);
    }
};

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

        long long cost = 1;
        RangeSum rs(0, n - 1);
        for (int i = 0; i < n; i++) {
            rs.Add(i, 1);
        }

        int last = 0;

        for (const auto &[val, idx]: val_idx) {
            if (idx == last) {
                rs.Add(idx, -1);
                continue ;
            }
            if (idx > last) {
                cost += rs.Sum(last + 1, idx);
            } else {
                if (last + 1 <= n - 1) {
                    cost += rs.Sum(last + 1, n - 1);
                }
                cost += rs.Sum(0, idx);
            }

            rs.Add(idx, -1);
            last = idx;
        }
        
        return cost;
    }
};