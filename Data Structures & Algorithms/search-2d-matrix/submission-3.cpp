class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int arrSize = matrix[0].size();
        int sa = 0;
        int ls = matrix.size() - 1;

        while (sa <= ls) {
            int mid = sa + (ls - sa) / 2;

            if (matrix[mid][0] == target || matrix[mid][arrSize - 1] == target) {
                return true;
            }

            if (matrix[mid][0] < target && matrix[mid][arrSize - 1] > target) {
                return simpleBinarySearch(matrix[mid], target);
            }
            if (matrix[mid][0] > target) {
                ls = mid - 1;
            }
            if (matrix[mid][arrSize - 1] < target) {
                sa = mid + 1;
            }
        }

        return false;
    }

    bool simpleBinarySearch(vector<int> arr, int target) {
        cout << "HELLO";
        int s = 0;
        int e = arr.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) return true;

            if (arr[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }
};
