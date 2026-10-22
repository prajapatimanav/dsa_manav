
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        int k = nums[0];
        bool normal = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                normal = false;
                break;
            }
        }

        if (normal) {
            return min(n - k, k + 2);
        }

        int first = nums[0];
        bool reversed = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (first - i + n) % n) {
                reversed = false;
                break;
            }
        }

        if (reversed) {
            int rotations = (n - 1 - first + n) % n;
            return 1 + min(rotations, n - rotations);
        }

        return -1;
    }
};

