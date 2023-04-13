#include<iostream> 
using namespace std;
void insertion(int arr[],int size);
    int main(){
    int size1, size2;
    int i, j;
    cin >> size1;
    int fre[size1];
    int ans = 0, num = 1, count = 0;
    int sum = 0;
    for (i = 0; i < size1; i++)
        cin >> fre[i];
    cin >> size2;
    int key[size2];
    for (i = 0; i < size2; i++)
    {
        cin >> key[i];
        sum += key[i];
    }
    if (sum < size1)
    {
        cout << "-1";
        return 0;
    }
    insertion(fre, size1);
    insertion(key, size2);
    for (i = size1 - 1, j = 0; i >= 0; i--)
    {
        int temp = count;
        if (num <= key[j])
        {
            ans += (num * fre[i]);
            count++;
        }
        if (temp == count)
            i++;
        if (j == size2 - 1)
        {
            j = 0;
            num++;
        }
        else
            j++;
    }
    cout << ans;
    return 0;
}
void insertion(int a[], int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > temp))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
void print(int a[], int size)
{
    int i;
    cout << "Array is as follows:-" << endl;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
}