#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(10000);
    for (int i = 0; i < 10000; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] == 42)
        {
            break;
        }
        cout << arr[i] << "\n";
    }
}