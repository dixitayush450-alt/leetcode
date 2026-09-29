class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // First k cards from left
        int currentSum = 0;

        for (int i = 0; i < k; i++) {
            currentSum += cardPoints[i];
        }

        int maxSum = currentSum;

        // j = last selected card from left
        int j = k - 1;

        // right = last card of array
        int right = n - 1;

        while (j >= 0) {

            // Remove one card from left
            currentSum -= cardPoints[j];
            j--;

            // Add one card from right
            currentSum += cardPoints[right];
            right--;

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};