class Solution {
public:
    
    int bs(vector<int>& nums, int target, int lo, int hi) {
        int mid;
        while(lo<hi) {
            mid = lo + (hi-lo)/2;
            if(nums[mid]<target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        int pos = bs(nums, target, 0, nums.size()-1);
        
        if(nums[pos]!=target) return {-1, -1};
        
        return {pos, bs(nums, target+1, pos, nums.size())-1};
    }
};

//Remember the second binary search shou''''''ld go till nums.size() for some below cases
//[1, 2, 3] Target = 3, we need a buffer for the index to move to next index and minus 1
// hence the condition: bs(nums, target+1, pos, nums.size())-1
