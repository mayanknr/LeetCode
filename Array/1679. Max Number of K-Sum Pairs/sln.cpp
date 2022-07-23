
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int size=nums.size();
        int maxOperations=0;
        sort(nums.begin(),nums.end());
    
            int low=0;
            int high=size-1;
            while(low<high)
            {
                int mid=low+(high-low)/2;
                
                if(nums[low]+nums[high]==k)
                {
                    //cout<<nums[i]<<" "<<nums[mid]<<endl;
                    maxOperations++;
                    low++;
                    high--;
                    
                }
                else if(nums[low]+nums[high]>k)
                    high--;
                else
                    low++;
            }
        
        
        return maxOperations;
    }
};
