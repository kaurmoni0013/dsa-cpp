#include <iostream>
using namespace std;
#include<vector>

void subsetsSum(vector<int> &nums,int n,int index,vector<int>&ans,int temp){
    if(index == n) {
        ans.push_back(temp);
        return;
    }
    // no
    subsetsSum(nums , n , index+1,ans,temp);
    // yes
    subsetsSum(nums , n , index+1,ans,temp+nums[index]);
 
}

int main(){
    vector<int>nums = {1,2,3,4};
    vector<int>ans;
    int temp = 0;
   subsetsSum(nums,4,0,ans,temp);
   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";

}