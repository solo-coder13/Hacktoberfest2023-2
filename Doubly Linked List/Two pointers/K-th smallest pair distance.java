class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums[nums.size()-1]-nums[0],mid,ans;
        int le,ri,count;
        while (left <right){
            int mid = left + (right - left) / 2;
            count=0,le=0,ri=0;
            while (le<nums.size()) {
                while((ri<nums.size()) && nums[ri]-nums[le]<=mid){
                    ri++;
                }
                count+=(ri-le-1);
                le++;
            } 
            if (count>=k) {
                right = mid;
            } 
            else {
                left = mid+1;
            }
        }
        return left;   
    }
};
