/*
 * =====================================================================================
 *
 *       Filename:  692前K个高频单词.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/11/27 22时26分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // O(nlogk)
        std::unordered_map<string,int> mapp;
        for(auto e: words){
            if(mapp.count(e)==0) mapp[e]=0;
            else mapp[e]+=1;
        }
        struct cmp{

          bool operator()(const pair<string,int>& a, const pair<string,int>&b){
            // string的比较就是根据字典序来的
            return (a.second > b.second || a.second == b.second && a.first < b.first );

        
          }

        };
              
        priority_queue< pair<string,int>,vector<pair<string,int> >,cmp> pqueue;

       // std::vector<pair<string,int>> vec(mapp.begin(),mapp.end());

        for(auto e:mapp){
            pqueue.push(e);
            if(pqueue.size()>k) pqueue.pop(); 
        }
        std::vector<string> res;
        while(k--){
            res.push_back(pqueue.top().first);
            pqueue.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
