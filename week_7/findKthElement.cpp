// Simple C++ program to find k'th smallest element 
#include <bits/stdc++.h>

using namespace std; 
  
// Function to return k'th smallest element in a given array 
int kthSmallest(int a[], int n, int k) { 
    sort(a, a + n); 
    return a[k - 1]; 
} 

int main() { 
    int a[] = { 223, 123, 34436, 432, 2, 13, 3, 5, 7, 19, 14, 16, 28 }; 
    int n = sizeof(a) / sizeof(a[0]);
    int k; 
    cout << "Enter the K'th element: ";
    cin >> k; 
    cout << "K'th smallest element is " << kthSmallest(a, n, k) << '\n';
    return 0; 
} 