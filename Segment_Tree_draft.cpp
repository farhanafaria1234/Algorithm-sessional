#include <iostream>
using namespace std;

vector<int> tree;

void buildTree(int node, int left, int right, vector<int> &arr)
{
    if(left == right)
    {
        tree[node] = arr[left];
        return;
    }

    int mid = (left + right) / 2;

    buildTree(2 * node + 1, left, mid, arr);
    buildTree(2 * node + 2, mid + 1, right, arr);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int left, int right, int ql, int qr)
{
    // No overlap
    if(right < ql || left > qr)
    {
        return 0;
    }

    // Complete overlap
    if(left >= ql && right <= qr)
    {
        return tree[node];
    }

    // Partial overlap
    int mid = (left + right) / 2;

    int leftTree = query(2 * node + 1, left, mid, ql, qr);
    int rightTree = query(2 * node + 2, mid + 1, right, ql, qr);

    return leftTree + rightTree;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Segment Tree-এর জন্য জায়গা
    tree.resize(4 * n);

    // Tree বানানো
    buildTree(0, 0, n - 1, arr);

    int ql, qr;

    cout << "Enter starting index: ";
    cin >> ql;

    cout << "Enter ending index: ";
    cin >> qr;

    int answer = query(0, 0, n - 1, ql, qr);

    cout << "Sum = " << answer << endl;

    return 0;
}
