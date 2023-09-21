#include <iostream>
using namespace std;
int n, a[200000];
void search()
{
    int i, j = -1;
    for (i = 0; i <= n && j < 0; i++)
    {
        if (a[i] == 0)
            j = i;
    }
    cout << j << " ";
}
int main()
{
    int k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        a[k]++;
        search();
    }
}