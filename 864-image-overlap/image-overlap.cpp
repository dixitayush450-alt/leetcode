class Solution {
public:
    // Ye function given shift ke according dono images ka overlap count karega
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B,int rowOff, int colOff) {

        int n = A.size();
        int count = 0;

        // A ke har cell ko check karenge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // A[i][j] ke corresponding B ka index nikal rahe hain
                int B_i = i + rowOff;
                int B_j = j + colOff;

                // Agar B ka index matrix ke bahar hai,
                // toh is cell ko skip kar do
                if (B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;

                // Agar dono images ke corresponding cells 1 hain,
                // toh overlap count badha do
                if (A[i][j] == 1 && B[B_i][B_j] == 1)
                    count++;
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1,vector<vector<int>>& img2) {

        int n = img1.size();
        int maxOverlap = 0;

        // Row ko -(n-1) se (n-1) tak shift karenge
        for (int rowOff = -n + 1; rowOff < n; rowOff++) {

            // Column ko bhi -(n-1) se (n-1) tak shift karenge
            for (int colOff = -n + 1; colOff < n; colOff++) {

                // Current shift par overlap count nikal rahe hain
                int count = countOverlap(img1, img2, rowOff, colOff);

                // Ab tak ka maximum overlap update karenge
                maxOverlap = max(maxOverlap, count);
            }
        }

        return maxOverlap;
    }
};