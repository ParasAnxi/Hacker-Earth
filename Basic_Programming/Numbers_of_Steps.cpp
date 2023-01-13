#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int min = INT16_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min) {
            min = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i]>min){
            a[i]-=b[i];
            count++;
            if (a[i]==min){
                break;
            }
        }
        if (min>a[i]){
            min=a[i];
            i=-1;
        }
        if (a[i]<0){
            count=-1;
            break;
        }
    }
    cout<<count<<"\n";
}