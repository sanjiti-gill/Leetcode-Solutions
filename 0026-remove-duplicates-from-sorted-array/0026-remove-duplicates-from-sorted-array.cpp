class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;

        int slow=0;

        for(int fast=1; fast<nums.size(); fast++) {
            if(nums[fast]!=nums[slow]) {
                slow++;
                nums[slow]=nums[fast];
            }
        }

        return slow+1;
    }
};
