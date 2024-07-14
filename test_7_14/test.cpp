#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        // 滑动窗口
        int sum = 0;
        int ret = INT_MAX;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ret = min(right - left + 1, ret);
                sum -= nums[left];
                left++;
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};

int minSubArrayLen(int target, vector<int>& nums)
{
    // 滑动窗口
    int left = 0, right = 0;
    int minSum = nums[right], len = 1;
    int ret = nums.size() + 1;

    while (left + 1 < nums.size())
    {
        while (right + 1 < nums.size())
        {
            if (minSum < target)
            {
                right++;
                minSum += nums[right];
                len++;
            }
            if (minSum >= target)
            {
                if (ret > len) ret = len;
                minSum -= nums[left];
                len--;
                break;
            }
        }
        left++;
    }
    if (ret == nums.size() + 1)
        return 0;
    return ret;
}

int main()
{
    vector<int> vIn = { 2,3,1,2,4,3 };
    cout << minSubArrayLen(7, vIn);
    return 0;
}


//vector<vector<int>> fourSum(vector<int>& nums, int target)
//{
//    vector<vector<int>> vRet;
//    int cur = 0;
//    sort(nums.begin(), nums.end());
//    while (cur <= nums.size() - 3)
//    {
//        int left = cur + 1;
//        int mid = left + 1;
//        int right = nums.size() - 1;
//
//        while (right > mid && mid > left)
//        {
//            while (mid < right)
//            {
//                int sum = nums[cur] + nums[left] + nums[mid] + nums[right];
//                if (sum > target)
//                {
//                    right--;
//                }
//                else if (sum < target)
//                {
//                    mid++;
//                }
//                else
//                {
//                    vRet.push_back({ nums[cur], nums[left], nums[mid], nums[right] });
//                    mid++;
//                    right--;
//                    while (mid < right && nums[right] == nums[right - 1])
//                        right--;
//                    while (mid < right && nums[mid] == nums[mid + 1])
//                        mid++;
//                }
//            }
//            left++;
//            mid = left + 1;
//            right = nums.size() - 1;
//            while (left < right && nums[left] == nums[left + 1])
//                left++;
//        }
//        cur++;
//        while (cur <= nums.size() - 3 && nums[cur] == nums[cur + 1])
//            cur++;
//    }
//    return vRet;
//}
//
//int main()
//{
//    vector<int> vInput = { 0 };
//    fourSum(vInput, 0);
//    return 0;
//}
//
//class Solution
//{
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target)
//    {
//        vector<vector<int>> ret;
//        // 1. 排序
//        sort(nums.begin(), nums.end());
//        // 2. 利⽤双指针解决问题
//        int n = nums.size();
//        for (int i = 0; i < n; ) // 固定数 a
//        {
//            // 利⽤ 三数之和
//            for (int j = i + 1; j < n; ) // 固定数 b
//            {
//                // 双指针
//                int left = j + 1, right = n - 1;
//                long long aim = (long long)target - nums[i] - nums[j];
//                while (left < right)
//                {
//                    int sum = nums[left] + nums[right];
//                    if (sum < aim) left++;
//                    else if (sum > aim) right--;
//                    else
//                    {
//                        ret.push_back({ nums[i], nums[j], nums[left++],
//                        nums[right--] });
//                        // 去重⼀
//                        while (left < right && nums[left] == nums[left - 1])
//                            left++;
//                        while (left < right && nums[right] == nums[right + 1])
//                            right--;
//                    }
//                }
//                // 去重⼆
//                j++;
//                while (j < n && nums[j] == nums[j - 1]) j++;
//            }
//            // 去重三
//            i++;
//            while (i < n && nums[i] == nums[i - 1]) i++;
//        }
//        return ret;
//    }
//};