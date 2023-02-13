#include <iostream>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    long data[N];
    long ans = 0;
    for (auto i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    for (auto j = 0; j < N; j++)
    {
        ans = (ans * 10 + (data[j] % 10)) % 10;
    }
    if (ans % 10 == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}