class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> output;
        int l = 0;
        int r= 0;

        for(int i = 0; i< arr.size(); i++){
            if(r-l+1 <= k){
                r++;
            }
            else{
                if(abs(arr[i] - x) >= abs(arr[l] - x)) continue;
                else{
                    r = i+1;
                    l = r-k;
                }
            }
        }


        for(int i = l; i< r; i++){
            output.push_back(arr[i]);
        }

        return output;
    }
};