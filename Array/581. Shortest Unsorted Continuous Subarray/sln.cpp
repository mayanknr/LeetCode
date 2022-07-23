class Solution {

//using monotonic stack
  /*  public int findUnsortedSubarray(int[] nums) {
         Stack<Integer> incr = new Stack();
         int start = Integer.MAX_VALUE;
         int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            while (!incr.isEmpty() && nums[i] < nums[incr.peek()]) {
                start = Math.min(start, incr.pop());
            }
            incr.push(i);
        }
        System.out.print("start"+start);
        int end = Integer.MIN_VALUE;
        Stack<Integer> decr = new Stack();
        
        for (int j = n - 1; j >= 0 ; j--) {
            while (!decr.isEmpty() && nums[j] > nums[decr.peek()]) {
                end = Math.max(end, decr.pop());
            }
            
            decr.push(j);
        }
        return  end >= start ? end - start + 1 : 0;
    }*/
  }
    
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=nums.size();
        int wStart=0;
        int wEnd=l-1;
        
        int wMin=INT_MAX;
        int wMax=INT_MIN;
        int flag=0;
        int start,end;
        for(int i=0;i<l-1;i++)
            if(nums[i]<=nums[i+1])
                continue;
        else
        {
        wStart=i;
        flag=1;
        break;
        }
        
        if(!flag)
            return 0;
        
        for(int i=l-1;i>0;i--)
            if(nums[i]>=nums[i-1])
                continue;
        else
        {
        wEnd=i;
        break;
        }
        
        for(int i=wStart;i<=wEnd;i++)
        {
            wMin=min(wMin,nums[i]);
            wMax=max(wMax,nums[i]);
        }
        
        for(int i=0;i<wStart;i++)
            if(nums[i]>wMin)
            {
                wStart=i;
                break;
            }
        
        for(int i=l-1;i>=wEnd-1;i--)
            if(nums[i]<wMax)
            {
                wEnd=i;
                break;                
            }
        
        return wEnd-wStart+1;
        
    }
};
}
