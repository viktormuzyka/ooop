class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size(), i = 0, j = 0;
        while (j < sz) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        return i;
    }
};