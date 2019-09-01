#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();

        int LCS[size1+1][size2+1];

        for(int i=0; i<=size1; i++){
            LCS[i][0]=0;
        }
        for(int j=0; j<=size2; j++){
            LCS[0][j]=0;
        }

        for(int i=1; i<=size1; i++){
            for(int j=1; j<=size2; j++){
                if(text1[i-1]==text2[j-1]){
                    LCS[i][j]=1+LCS[i-1][j-1];
                }
                else{
                    LCS[i][j]=max(LCS[i-1][j], LCS[i][j-1]);
                }
            }
        }

        return LCS[size1][size2];
    }
};

int main(){
  Solution temp;

  cout<<temp.longestCommonSubsequence("aceit","cthh")<<endl;

}
