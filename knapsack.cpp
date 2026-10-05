#include <iostream>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    int weight[100], profit[100];
    int dp[101][101];

    // Input
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    // Initialize first row and first column
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i-1] + dp[i - 1][w - weight[i-1]]
                );
            }

            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Maximum profit
    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    // Find selected items
    int selected[100] = {0};
    int w = W;

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected[i - 1] = 1;
            w = w - weight[i - 1];
        }
    }

    // Print 0/1 selection
    cout << "Selected Items (0/1): ";

    for (int i = 0; i < n; i++)
    {
        cout << selected[i] << " ";
    }

    return 0;
}
