#include <iostream>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout<< "Enter the number of element :\n"<< endl;
    cin >> n;

    int arr[n];
    cout<< "Enter the element of array :\n"<< endl;
    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    cout << "Maximum Sum Subarray: "<< maxSubarraySum(arr, n)<< endl;

    return 0;
}
