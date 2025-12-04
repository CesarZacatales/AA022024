#include <bits/stdc++.h>

using namespace std;

int max_cross_sum(int arr[], int l, int mid, int r)
{
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;

    for (int i = mid; i >= l; i--)
    {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int i = mid; i <= r; i++)
    {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return max(
        max(left_sum, right_sum),
        left_sum + right_sum - arr[mid]);
}

int mss(int arr[], int l, int r)
{
    if (l > r)
        return INT_MIN;

    if (l == r)
        return arr[l];

    int mid = (l + r) / 2;

    return max(
        max(
            mss(arr, l, mid - 1),
            mss(arr, mid + 1, r)),
        max_cross_sum(arr, l, mid, r));
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int len = 8;

    cout << mss(arr, 0, len - 1) << endl;

    return 0;
}