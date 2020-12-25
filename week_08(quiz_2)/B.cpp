#include <bits/stdc++.h>

using namespace std;

struct age {
    int day;
    int month;
    int year;
};

int main() {
    int n; 
    cin >> n;
    struct age a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].day;
        cin >> a[i].month;
        cin >> a[i].year;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1 ; j < n; j++) {
            if (a[i].year > a[j].year) {
                struct age tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            else if (a[i].year == a[j].year and a[i].month > a[j].month) {
                struct age tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            else if (a[i].year == a[j].year and a[i].month == a[j].month and a[i].day > a[j].day) {
                struct age tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i].day << " " << a[i].month << " " << a[i].year << '\n';
    return 0;
}