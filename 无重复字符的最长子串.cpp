class Solution {
public:
    // bool isok(const string &s){

    //  std::unordered_map<int,int> map;
    //  for(int i = 0 ; i < s.size();i++){ 
    //     if(map.count(s[i])==0) {
    //       map[s[i]]=1; 
    //     } else {
    //         return false ;
    //     }

    //     }
    // return true;
    // }

    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;     
        //std::set<char> ss;
        std::unordered_map<char,int> ss;
        int maxlen=1;
        int i =0,j=0,n=s.size();
        while(i<n&&j<n){
            if(ss.count(s[j])==0){ 
                maxlen = std::max(maxlen,j-i+1); //ss.insert(s[j++]);
                ss[s[j]] = j;
                j++;
            }
            else {
                int pos = ss[s[j]];
                if(pos<i){ 
                    maxlen = std::max(maxlen,j-i+1); //ss.insert(s[j++]);
                    ss[s[j]]=j;
                    j++;
                }
                else{
                i = pos+1;
                ss[s[j]]=j;
                j++;
                }
            } //ss.erase(s[i++]); // 如果我们知道哪个字符与s[j]重复，那么我们就不用每次i++了，直接将i变为j'+1,s[j']就是与s[j]相同的字符
        }
        return maxlen;
    }
};