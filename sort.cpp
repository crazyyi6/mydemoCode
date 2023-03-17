#include <bits/stdc++.h>
using namespace std;

/*

冒泡排序优化版
*/
void bubble_sort(vector<int> &nums)
{
    for(int i = 0; i < nums.size();i++)
    {
        bool flag = true;
        for(int j = 0 ; j < nums.size()-i-1;j++) //注意要多减去一个1 ，由于下面要用到j+1边界问题
        {
            if(nums[j] >= nums[j+1])
            {
                swap(nums[j],nums[j+1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }
}

/*
选择排序
*/
void slection_sort(vector<int> &nums)
{
    int temp = 0;
    for (int i = 0; i < nums.size()-1; i++)
    {
        temp = i;
        for(int j = i+1; j <nums.size()-1;j++)
        {
            if(nums[temp] >= nums[j])
                temp = j;
        }
        swap(nums[temp],nums[i]);
    }
}

/*
快速排序

*/

int findmid(vector<int> &nums, int l,int r)
{
    int pivot = nums[l];
    int i = l+1;
    int j = r;
    while (true)
    {
        while(i <= j && nums[i] >= pivot) i++;
        while(i <=j && nums[j] <= pivot) j--;
        if(i >j )
            break;
        swap(nums[i],nums[j]);
    }
    swap(nums[l],nums[j]); //这里是精髓
    return j; //注意返回的是j
}
void quick_sort(vector<int> &nums,int left,int right)
{
    if(left  < right)
    {
        int mid = findmid(nums,left,right);
        quick_sort(nums,left,mid-1);
        quick_sort(nums,mid+1,right);
    }
}   


int main()
{
    vector<int> nums = { 5,4,1,9,6,2,2,4,6};
    //bubble_sort(nums);
   // slection_sort(nums);
   quick_sort(nums,0,nums.size()-1);
    for (int a :nums)
    {
        cout<<a;
    }
    
;    return 0;
}