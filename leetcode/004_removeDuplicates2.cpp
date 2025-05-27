/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

说明：

为什么返回数值是整数，但输出的答案是数组呢？

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

示例 1：

输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
 

提示：

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
从后往前遍历，如果当前元素与前一个元素相同，则计数器加1，如果计数器大于2，则删除当前元素。
*/
/*
int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len <= 2){
        return len;
    }
    int lastNum = nums[len-1], count=1;
    for(int i = len-2; i >= 0; --i){
        if (nums[i] != lastNum){
            lastNum = nums[i];
            count = 1;
        }
        else
        {
            count++;
        }
        if (count > 2){
            nums.erase(nums.begin() + i);
        }
    }
    return nums.size();
}
*/

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for(auto& x: nums){
        if ( i < 2 || x != nums[i-2]){
            nums[i++] = x;
        }
    }
    return i;
}

int main(){
    // std::vector<int> vec = {1, 2, 3, 4, 5, 3, 6};
    // auto it = std::remove_if(vec.begin(), vec.end(), 
    //                   [](int x) { return x == 6; });
    // cout << *it << endl;
    
    // // 移除所有等于3的元素
    // vec.erase(
    //     std::remove_if(vec.begin(), vec.end(), 
    //                   [](int x) { return x == 3; }),
    //     vec.end()
    // );
    // for (auto& x : vec){
    //     cout << x << " ";
    // }
    // cout << endl;


    // std::vector<int> vec{1,1,1,2,2,3};
    std::vector<int> vec{0,0,1,1,1,1,2,3,3};
    int res = removeDuplicates(vec);
    cout << "res=" << res << endl;
    for (int i = 0; i < res; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}