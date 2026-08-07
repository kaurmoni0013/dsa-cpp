#include <iostream>
using namespace std;
#include <vector>

bool find(vector<int> &nums, int n, int index, int target)
{   if(target == 0)return 1;
    if (index == n || target <= 0)
    return 0;
     

    return find(nums, n, index + 1, target)||find(nums, n, index + 1, target-nums[index]);
    
}

int main()
{ 
    vector<int> nums = {1, 2, 3, 4};
    int target = 21;
    cout << find(nums, 4, 0,target );
}