class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answers;
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (target == nums[i] + nums[j])
                {
                    answers.push_back(i);
                    answers.push_back(j);
                    
                    goto lb_exit;
                }
            }
        }
        
lb_exit:
        return answers;
    }
};