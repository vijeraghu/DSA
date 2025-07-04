class Solution {
private:
    void solve(vector<vector<int>>&ans,vector<int>nums,  int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        else{
            for(int j= index; j<nums.size(); j++){
                swap(nums[index],nums[j]);
                solve( ans,nums, index+1);
                    swap(nums[index],nums[j]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index =0;
        solve(ans,nums,index);
        return ans;
    }
};
