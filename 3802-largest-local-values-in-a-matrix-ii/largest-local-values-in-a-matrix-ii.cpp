class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;

        int cols = matrix[0].size();
        if (cols == 0) return 0;

        // Precompute log values
        int rowLog[201] = {0};
        int colLog[201] = {0};

        for (int len = 2; len <= 200; len++) {
            rowLog[len] = rowLog[len / 2] + 1;
            colLog[len] = colLog[len / 2] + 1;
        }

        int maxPower = 8;

        // Sparse table
        vector<vector<vector<vector<int>>>> sparseTable(
            maxPower,
            vector<vector<vector<int>>>(
                maxPower,
                vector<vector<int>>(
                    rows,
                    vector<int>(cols, 0)
                )
            )
        );

        // Base case
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                sparseTable[0][0][r][c] = matrix[r][c];
            }
        }

        // Build sparse table
        for (int rowPow = 0; rowPow < maxPower; rowPow++) {
            for (int colPow = 0; colPow < maxPower; colPow++) {

                if (rowPow == 0 && colPow == 0)
                    continue;

                for (int r = 0; r + (1 << rowPow) <= rows; r++) {
                    for (int c = 0; c + (1 << colPow) <= cols; c++) {

                        if (rowPow == 0) {
                            sparseTable[rowPow][colPow][r][c] =
                                max(
                                    sparseTable[rowPow][colPow - 1][r][c],
                                    sparseTable[rowPow][colPow - 1][r]
                                               [c + (1 << (colPow - 1))]
                                );
                        }
                        else if (colPow == 0) {
                            sparseTable[rowPow][colPow][r][c] =
                                max(
                                    sparseTable[rowPow - 1][colPow][r][c],
                                    sparseTable[rowPow - 1][colPow]
                                               [r + (1 << (rowPow - 1))][c]
                                );
                        }
                        else {
                            int topLeft =
                                sparseTable[rowPow - 1][colPow - 1][r][c];

                            int topRight =
                                sparseTable[rowPow - 1][colPow - 1]
                                           [r][c + (1 << (colPow - 1))];

                            int bottomLeft =
                                sparseTable[rowPow - 1][colPow - 1]
                                           [r + (1 << (rowPow - 1))][c];

                            int bottomRight =
                                sparseTable[rowPow - 1][colPow - 1]
                                           [r + (1 << (rowPow - 1))]
                                           [c + (1 << (colPow - 1))];

                            sparseTable[rowPow][colPow][r][c] =
                                max({
                                    topLeft,
                                    topRight,
                                    bottomLeft,
                                    bottomRight
                                });
                        }
                    }
                }
            }
        }

        // Query maximum inside a rectangle
        auto getRangeMaximum =
            [&](int topRow, int leftCol,
                int bottomRow, int rightCol) -> int {

            if (topRow > bottomRow || leftCol > rightCol)
                return 0;

            int height = bottomRow - topRow + 1;
            int width = rightCol - leftCol + 1;

            int rowPower = rowLog[height];
            int colPower = colLog[width];

            int value1 =
                sparseTable[rowPower][colPower]
                           [topRow][leftCol];

            int value2 =
                sparseTable[rowPower][colPower]
                           [topRow]
                           [rightCol - (1 << colPower) + 1];

            int value3 =
                sparseTable[rowPower][colPower]
                           [bottomRow - (1 << rowPower) + 1]
                           [leftCol];

            int value4 =
                sparseTable[rowPower][colPower]
                           [bottomRow - (1 << rowPower) + 1]
                           [rightCol - (1 << colPower) + 1];

            return max({value1, value2, value3, value4});
        };

        int localMaximumCount = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                int currentValue = matrix[r][c];

                if (currentValue == 0)
                    continue;

                int topBoundary = max(0, r - currentValue);
                int bottomBoundary = min(rows - 1, r + currentValue);

                int leftBoundary = max(0, c - currentValue);
                int rightBoundary = min(cols - 1, c + currentValue);

                int maximumWithoutCorners = 0;

                // Top row
                if (topBoundary <= bottomBoundary) {

                    int left = leftBoundary;
                    int right = rightBoundary;

                    if (topBoundary == r - currentValue) {
                        if (leftBoundary == c - currentValue)
                            left++;

                        if (rightBoundary == c + currentValue)
                            right--;
                    }

                    if (left <= right) {
                        maximumWithoutCorners =
                            max(
                                maximumWithoutCorners,
                                getRangeMaximum(
                                    topBoundary,
                                    left,
                                    topBoundary,
                                    right
                                )
                            );
                    }
                }

                // Bottom row
                if (bottomBoundary > topBoundary) {

                    int left = leftBoundary;
                    int right = rightBoundary;

                    if (bottomBoundary == r + currentValue) {
                        if (leftBoundary == c - currentValue)
                            left++;

                        if (rightBoundary == c + currentValue)
                            right--;
                    }

                    if (left <= right) {
                        maximumWithoutCorners =
                            max(
                                maximumWithoutCorners,
                                getRangeMaximum(
                                    bottomBoundary,
                                    left,
                                    bottomBoundary,
                                    right
                                )
                            );
                    }
                }

                // Middle rows
                int middleTop =
                    max(topBoundary, r - currentValue + 1);

                int middleBottom =
                    min(bottomBoundary, r + currentValue - 1);

                if (middleTop <= middleBottom) {
                    maximumWithoutCorners =
                        max(
                            maximumWithoutCorners,
                            getRangeMaximum(
                                middleTop,
                                leftBoundary,
                                middleBottom,
                                rightBoundary
                            )
                        );
                }

                if (maximumWithoutCorners <= currentValue)
                    localMaximumCount++;
            }
        }

        return localMaximumCount;
    }
};