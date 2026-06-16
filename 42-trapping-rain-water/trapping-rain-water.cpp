class Solution {
public:

    vector<int> suffixMax(vector<int>& arr) {
        // result[i] = largest number strictly to the right of arr[i]

        int n = arr.size();
        vector<int> result(n, 0);

        result[n - 1] = 0;  // no element to the right

        for (int i = n - 2; i >= 0; i--) {
            result[i] = max(arr[i + 1], result[i + 1]);
        }

        return result;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        if (n < 3) return 0;

        int water = 0;

        vector<int> rightmax = suffixMax(height);

        int left = height[0];

        for (int i = 1; i < n - 1; i++) {
            left = max(left, height[i - 1]);

            int right = rightmax[i];

            water += max(0, min(left, right) - height[i]);
        }

        return water;
    }
};