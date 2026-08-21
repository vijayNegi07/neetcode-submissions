class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> arr(len1 + len2);
        copy(nums1.begin(), nums1.end(), arr.begin());
        copy(nums2.begin(), nums2.end(), arr.begin() + len1);

        sort(arr.begin(), arr.end());

        int s = 0;
        int e = arr.size();

        if(arr.size() % 2 == 0){
            return (arr[e/2-1] + arr[e/2])/2.0 ;
        }else{
            return arr[e/2];
        }
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        cout << "EH";
        int k = 0;
        int i = 0;
        int j = 0;

        vector<int> res;

        while( i< nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                res[k] = nums1[i];
                k++;
                i++;
            }else{
                res[k] = nums2[j];
                k++;
                j++;
            }
        }

        while( i< nums1.size()){
            res[k] = nums1[i];
            i++;
            k++;
        }

        while( j< nums2.size()){
            res[k] = nums2[j];
            j++;
            k++;
        }

        return res;
    }

};
