#include <bits/stdc++.h>

using namespace std;

string s;

int Pivot(char x) {
    int pivot = 0;
    if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u') 
        pivot -= 1000;
    pivot += x;
    return pivot;
}



void QuickSort(int l, int r) {
    int i = l;
    int j = r;
    int pivot = s[(l + r) / 2];
    while (i < j) {
        while (Pivot(s[i]) < Pivot(pivot)) i++;
        while (Pivot(s[j]) > Pivot(pivot)) j--;
            if (i <= j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }  
    }
    if (l < j)
        QuickSort(l, j);
    if (i < r)
        QuickSort(i, r);
}


int main () {
    uint32_t n;
    cin >> n;
    cin >> s;
    QuickSort(0, s.size() - 1);
    cout << s << " ";
    cout << '\n';
    return 0;
}