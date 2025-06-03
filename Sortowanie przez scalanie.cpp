#include <iostream>
using namespace std;

void merge(int* tab, int l, int m, int r);
void mergeSort(int* tab, int l, int r);

int main()
{
    cout << "Ile liczb do posortowania? ";
    int n;
    cin >> n;

    int* tab = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Wpisz liczbe : ";
        cin >> tab[i];
    }

    mergeSort(tab, 0, n - 1);

    cout << "Posortowane liczby: ";
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }

    delete[] tab;
    return 0;
}

void merge(int* tab, int l, int m, int r)
{
    int lSize = m - l + 1;
    int rSize = r - m;

    int* tabL = new int[lSize];
    int* tabR = new int[rSize];

    for (int i = 0; i < lSize; i++)
    {
        tabL[i] = tab[l + i];
    }
    for (int i = 0; i < rSize; i++)
    {
        tabR[i] = tab[m + 1 + i];
    }

    int indexL = 0;
    int indexR = 0;
    int currIndex = l;

    while (indexL < lSize && indexR < rSize)
    {
        if (tabL[indexL] <= tabR[indexR])
        {
            tab[currIndex++] = tabL[indexL++];
        }
        else
        {
            tab[currIndex++] = tabR[indexR++];
        }
    }

    

    while (indexL < lSize)
    {
        tab[currIndex++] = tabL[indexL++];
    }

    while (indexR < rSize)
    {
        tab[currIndex++] = tabR[indexR++];
    }

    delete[] tabL;
    delete[] tabR;
}

void mergeSort(int* tab, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);
        merge(tab, l, m, r);
    }
}