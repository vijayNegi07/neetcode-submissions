class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto& num: nums){
            if(freq.count(num) == 0){
                freq[num]++;
            }else{
                return num;
            }
        }
    }
};
