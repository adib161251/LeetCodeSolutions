class Solution {
public:
    
    
    int MaxCrossing(vector<int> &nums, int low, int mid, int high)
    {
        int sum = 0;
        int leftSubSum = INT_MIN;
        for(int i=mid ; i>=low ; i--)
        {
            sum = sum + nums[i];
            if(sum> leftSubSum)
            {
                leftSubSum = sum;
            }
        }
        
        sum = 0;
        int rightSubSum = INT_MIN;
        for(int i= mid+1 ; i<= high; i++)
        {
            sum = sum + nums[i];
            if(sum> rightSubSum)
            {
                rightSubSum = sum;
            }
        }
        
        
        return max(leftSubSum+rightSubSum, max(rightSubSum,leftSubSum));
    }
    
    int MaximumSubarray(vector<int> &nums, int low, int high)
    {
        if(low == high) return nums[low];
        
        int mid = (low+high)/2;
        
        int left = MaximumSubarray(nums, low, mid);
        int right = MaximumSubarray(nums,mid+1, high);
        int crossing = MaxCrossing(nums, low, mid, high);
        
        return max(crossing, max(left, right));
    }
    
    
    int maxSubArray(vector<int>& nums) {
        return MaximumSubarray(nums, 0, nums.size()-1);
    }
};