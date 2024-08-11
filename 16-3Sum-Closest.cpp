class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int x=INT_MAX;



        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);

                if(diff<x){
                    x=diff;
                    ans=sum;
                }

                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }


        return ans;
    }
};