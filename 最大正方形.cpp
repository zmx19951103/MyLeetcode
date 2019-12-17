// 一开始的做法，遍历，比较傻逼
class Solution {
public:

    int  check (const vector<vector<char>>& matrix, int row,int col, int count){

        // how to 
             int  min_count = count;
             for(int i=row; i<row+count;i++)
                for(int j = col;j<col+count;j++){

                    if(matrix[i][j]=='0') min_count = std::min(min_count,std::max(j-col,i-row)); // the most important
                }

                return min_count;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        int max_ = 0;

        for(int i= 0;i<m;i++)
          for(int j = 0 ;j<n;j++){

              if(matrix[i][j]=='0')continue;
              int max_row=0, max_col=0;
              while(j+max_row<n&&matrix[i][j+max_row]=='1')max_row++;
              while(i+max_col<m&&matrix[i+max_col][j]=='1')max_col++;
              int temp =std::min(max_row,max_col);
              int  count  = check(matrix,i,j,temp);
              
             max_= std::max(max_,count*count);
             

          }

          return max_;
        
    }
};

// 看了提示，用动态规划

