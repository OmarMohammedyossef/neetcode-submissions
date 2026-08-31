class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  
    int res = nums[0];
    int n = nums.size();
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur += nums[i];
        res = max(res, cur);
        if (cur < 0) {
            cur = 0;
        }
    }
    return res;
    }
};