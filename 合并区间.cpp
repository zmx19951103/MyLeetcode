class Solution {
public:
   
    static bool cmp(const std::vector<int>&a, const std::vector<int>&b){
        return a[0]<b[0];
    }

//思路就是根据区间的左边界排序，然后遍历逐个合并，思路比较直接
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size()<=1)return intervals;
        std::sort(intervals.begin(),intervals.end(),cmp); // sort
        std::vector<std::vector<int>> result;


        for(int i = 0 ; i< intervals.size();){
            if(result.size()==0) { result.push_back(intervals[i]);i++;}
            else{
            
            std::vector<int>& last = result[result.size()-1];

            if(last[1]>=intervals[i][0]){ 
                
                std::vector<int> temp;
                if(last[1]<=intervals[i][1])temp ={last[0],intervals[i][1]};
                else  temp ={last[0],last[1]};
            
            result.pop_back();result.push_back(temp);i++; }
            
            else{result.push_back(intervals[i]);i++;}

            }
        }

        return result;
    }
};