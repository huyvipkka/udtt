#include <iostream>
using namespace std;

void thapHaNoi(int n, char start, char end, char temp) {
    // Điều kiện dừng: chỉ còn 1 đĩa
    if (n == 1) {
        cout << start << " -> " << end << endl;
        return;
    }

    thapHaNoi(n - 1, start, temp, end);
    cout <<  start << " -> " << end << endl;
    thapHaNoi(n - 1, temp, end, start);
}

int main() {
    int n = 4;
    thapHaNoi(n, 'A', 'C', 'B');
    return 0;
}
