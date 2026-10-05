#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int weight[100], profit[100];
    double ratio[100];

    // Input weights
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // Input profits
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    // Calculate ratio
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)profit[i] / weight[i];
    }

    // Sort according to ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    double totalProfit = 0;

    cout << "\nSelected Items:\n";

    // Fractional Knapsack
    for (int i = 0; i < n; i++)
    {
        if (W >= weight[i])
        {
            // Take full item
            W = W - weight[i];
            totalProfit = totalProfit + profit[i];

            cout << "Item " << i + 1 << " = 1 (Full)" << endl;
        }
        else
        {
            // Take fraction
            double fraction = (double)W / weight[i];

            totalProfit =
                totalProfit + profit[i] * fraction;

            cout << "Item " << i + 1
                 << " = " << fraction << " (Fraction)" << endl;

            W = 0;
            break;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
