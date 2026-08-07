#include <iostream>
using namespace std;
void TOH(int n, int sor, int hel, int des)
{
    if (n == 0)
        return;
    TOH(n - 1, sor, des, hel);
    cout << "move disk " << n << " from " << sor << " to " << des << endl;
    TOH(n - 1, hel, sor, des);
}
int main()
{
    cout << "Enter no of disks :";
    int n;
    cin >> n;
    TOH(n, 1, 2, 3);
}