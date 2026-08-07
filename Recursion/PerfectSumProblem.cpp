#include <iostream>
using namespace std;
#include <vector>

int find(vector<int> &nums, int n, int index, int target,int sum)
{   if(sum == 0)return sum;
    if (index == n || sum <= 0)
    return 0;
     

    return find(nums, n, index + 1, target,sum)+find(nums, n, index + 1, target-nums[index],sum);
    
}

int main()
{ 
    vector<int> nums = {1, 2, 3, 4};
    int target = 6;
    cout << find(nums, 4, 0,target ,0);
}