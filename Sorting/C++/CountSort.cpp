//C++ Implementation of Count Sort
#include <bits/stdc++.h>
using namespace std;
void countingSort(int a[], int n)
{
    //Finding largest element
    int larg = -1;
    for (int i = 0; i < n; i++)
    {
        larg = max(larg, a[i]);
    }
    //Creating freq array
    int *freq = new int[larg + 1]{0};
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    //Putting elements back into the array
    int j = 0;
    for (int i = 0; i <= larg; i++)
    {
        while (freq[i] > 0)
        {
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
}
//Driver Function
int main()
{
    int a[5] = {4, 3, 5, 2, 1}; //Input Array
    countingSort(a, 5);         //Calling Count Sort function
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << ",";
    }

    return 0;
}
