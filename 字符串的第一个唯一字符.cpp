class Solution {
public:
    int firstUniqChar(string s) {

// 遍历 一下，统计一下，然后再遍历一下, 时间复杂度：O(N) 空间复杂度：O(N)
 std::unordered_map<char,int> ss;
 for(size_t i =0 ;i< s.size();i++) ss[s[i]]+=1;
 for(size_t i =0 ;i< s.size();i++) if(ss[s[i]]==1)return i;
 return -1;
    }
};