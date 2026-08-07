#include <iostream>
#include <vector>
using namespace std;
int repetetion(vector<int> nums, int index, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (index == n || sum < 0)
        return 0;

    return repetetion(nums, index + 1, n, sum)
    +repetetion(nums, index, n, sum - nums[index]);
}
int main()
{
    vector<int> nums = {2, 3, 4};
    int sum = 6;
    cout << repetetion(nums, 0, 3, sum);
}