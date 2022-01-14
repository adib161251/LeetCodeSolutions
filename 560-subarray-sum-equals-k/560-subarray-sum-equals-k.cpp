class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int cursum =0;
        int count = 0;
        int n = nums.size();
        unordered_map<int,int> prefix;
        
        for(int i=0; i<n ; i++)
        {
            cursum += nums[i];
            if(cursum == k) count +=1;
            if(prefix.find(cursum-k) != prefix.end())
                count += prefix[cursum-k];
            
            prefix[cursum] += 1;
        }
        
        return count;
    }
};