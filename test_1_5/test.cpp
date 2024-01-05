class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            int count = 0;
            for (size_t j = 0; j < nums.size(); ++j)
            {
                count += (nums[j] >> i) & 1;
            }
            if (count % 3 == 1)
            {
                ret |= 1 << i;
            }
        }
        return ret;
    }
};

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int tmp = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            tmp ^= nums[i];
        }

        int end1 = 0;
        if (tmp == INT_MIN)
            end1 = tmp;
        else
            end1 = tmp & (-tmp);

        vector<int> ret;
        ret.resize(2);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & end1) != 0)
            {
                ret[0] ^= nums[i];
            }
            else
            {
                ret[1] ^= nums[i];
            }
        }

        return ret;
    }
};