#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int damage1 = ((2*100)/5) + 2;
    int damage2 = damage1 * 90;
     double damage3 = (double)204/236;
    int damage4 = damage3 * 10;

    int damage = round(damage3);
    cout << damage << "\n";
}