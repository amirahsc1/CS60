//Problem 5 on page 614 of textbook.
#include <iostream>
using namespace std;
void towerGame(int n, int initial, int final, int spare) {
    if (n == 1) {
        cout << "Disk 1 moves from post " << initial << " then moves to post " << final << "." << std::endl;
    } else {
       towerGame(n - 1, initial, spare, final);
        cout << "Disk " << n << " at post " << initial << " then moves to post " << final << "." << std::endl;
       towerGame(n - 1, spare, final, initial);
    }
}

int main() {
cout << "If you start the game with five disks: " << endl;
   towerGame(5, 1, 2, 3);
   cout << endl;
cout << "If you start the game with two disks: " << endl;
   towerGame(2, 1, 2, 3);
    return 0;
}

