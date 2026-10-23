class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                int newIndex = (i + nums[i]) % n;

                // fix negative index
                if (newIndex < 0) {
                    newIndex += n;
                }

                result[i] = nums[newIndex];
            } else {
                result[i] = 0;
            }
        }

        return result;
    }
};
