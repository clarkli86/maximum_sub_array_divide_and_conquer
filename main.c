int maxSubArray(int A[], int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return A[0];

    int maxSub = INT_MIN;
    int leftPrefix = INT_MIN, rightSuffix = INT_MIN, all = INT_MIN;
    maxSubArrayHelper(A, 0, n - 1, leftPrefix, rightSuffix, all, maxSub);
    return maxSub;
}

// Return the maximum subarray starting with left, the maximum subarray ending with right, and the sum of all elements from left to right
void maxSubArrayHelper(int A[], int left, int right, int & leftPrefix, int & rightSuffix, int & all, int &maxSub)
{
    if(left == right)
    {
        leftPrefix = A[left];
        rightSuffix = A[left];
        all = A[left];
        maxSub = max(maxSub, A[left]);
        return;
    }

    int middle = (left + right) / 2;
    int leftPrefix1, rightSuffix1, all1, leftPrefix2, rightSuffix2, all2;
    maxSubArrayHelper(A, left, middle, leftPrefix1, rightSuffix1, all1, maxSub);
    maxSubArrayHelper(A, middle + 1, right, leftPrefix2, rightSuffix2, all2, maxSub);

    // Use the returned leftPrefix, rightSuffix instead of walling through the elements between left and right
    leftPrefix = max(all1, all1 + leftPrefix2);
    leftPrefix = max(leftPrefix, leftPrefix1);
    rightSuffix = max(all2, all2 + rightSuffix1);
    rightSuffix = max(rightSuffix, rightSuffix2);
    all = all1 + all2;
    // The maximum subarray must start with left, or end with right, or in the middle
    // Here we check all candidates
    maxSub = max(leftPrefix, maxSub);
    maxSub = max(rightSuffix, maxSub);
    maxSub = max(rightSuffix1, maxSub);
    maxSub = max(leftPrefix2, maxSub);
    maxSub = max(rightSuffix1 + leftPrefix2, maxSub);
}
