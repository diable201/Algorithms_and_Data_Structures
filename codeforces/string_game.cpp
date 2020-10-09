#include <iostream>
#include <stack>

using namespace std;

int main() {
	char s; 
    int c = 0;
	stack<char> x;
	while ((s = getchar()) != '\n') {
		if (!x.empty() && x.top() == s)
            c++, x.pop();
        else 
            x.push(s);
	}
    c % 2 ? cout << "Yes\n" : cout << "No\n";
}