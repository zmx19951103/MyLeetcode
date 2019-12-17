// 思路很简单，用哈希表统计一下每个字母出现的次数（频率），然后排序，排序的话，我用的sort,也可以用优先队列。根据次数排序
class Solution {
public:
    static bool cmp(const pair<char,int>& a, const pair<char,int>& b){
      return a.second == b.second ? a.first <= b.first  : a.second>b.second;
    }
    string frequencySort(string s) {

        // pair
        std::unordered_map<char,int> ss;
        for(int i =0 ; i < s.size(); i++){
         if(ss.count(s[i])==0)ss[s[i]]=1;
         else ss[s[i]]+=1;
        }
        std::vector<pair<char,int>> vec(ss.begin(),ss.end());
        std::sort(vec.begin(),vec.end(),cmp); // 可以用优先队列
        string result;
        for(auto & e: vec){
            int temp = e. second;
            while(temp--)
            result+=e.first;
        
        }
        return result;
    }
};

//其他人写的用lambda表达式，更简洁,实际跑的时候非常耗时

        // pair
        std::unordered_map<char,int> ss;
        for(int i =0 ; i < s.size(); i++){
         //if(ss.count(s[i])==0)ss[s[i]]=1;
          ss[s[i]]+=1;
        }
      std::sort(s.begin(),s.end(),[&](const char& a, const char& b){ return ss[a]==ss[b]? a< b : ss[a]>ss[b]; });
      return s;
