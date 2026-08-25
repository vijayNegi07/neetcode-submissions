class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid =   s + (e-s)/2;

            if(target > nums[mid]){
                s = mid  + 1;
            }else if(target < nums[mid]){
                e = mid - 1;
            }else{
                return mid;
            }
        }

        return s;
    }
};