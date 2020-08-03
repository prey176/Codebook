int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size() ;

    if (n == 0)
    {
        return 0; 
    }

    vector <int> dp;

    for (int i = 0; i < n ;i++)
    {
        int index = lower_bound (dp.begin(), dp.end(), nums [i]) - dp.begin();

        if (index == dp.size())
        {
            dp.push_back (nums [i]);
            continue;
        }

        dp [index] = nums [i];
    }

    return dp.size();
}
