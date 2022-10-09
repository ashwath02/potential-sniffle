class Solution {
public:
    int search(vector<int>& nums, int target) {
        //nums[low]--nums[mid] -> sorted ?
        //check if target available? high = mid-1: low = mid+1;
        
        //else nums[mid]--nums[high] -> sorted
        //check if target available? low = mid+1 : high = mid-1
    
        
        int low = 0, high = nums.size()-1, mid;
        while(low<=high) {
            mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            
            if(nums[low]<=nums[mid]) {
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else low = mid+1;
            }
            else {
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else high = mid-1;
            }
            
        }
        
        return -1;
    }
};
