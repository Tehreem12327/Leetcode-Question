class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        int maxOverlap = 0;

        // Try every possible row shift
        for (int rowShift = -(n - 1); rowShift <= n - 1; rowShift++) {
            
            // Try every possible column shift
            for (int colShift = -(n - 1); colShift <= n - 1; colShift++) {
                
                int overlap = 0;

                // Compare every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        
                        // Position of img1[i][j] after translation
                        int newRow = i + rowShift;
                        int newCol = j + colShift;

                        // Check if translated position is inside img2
                        if (newRow >= 0 && newRow < n &&
                            newCol >= 0 && newCol < n) {
                            
                            if (img1[i][j] == 1 && img2[newRow][newCol] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                maxOverlap = max(maxOverlap, overlap);
            }
        }

        return maxOverlap;
    }
};