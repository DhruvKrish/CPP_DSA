#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int m, int *lps){
  //length of previous largest prefix suffix
  int len=0;

  lps[0]=0;

  int i=1;
  while(i<m){
    if(pat[i]==pat[len]){
      len++;
      lps[i]=len;
      i++;
    }
    else{
      if(len!=0){
        len=lps[len-1];
      }
      else{
        lps[i]=0;
        i++;
      }
    }
  }

}

void KMPSearch(string pat, string txt){
  int m=pat.size();
  int n=txt.size();

  //longest prefix suffix array for pat
  int lps[m];

  //Preprocess pat to lps
  computeLPS(pat, m ,lps);

  //index txt
  int i;

  //index pat
  int j;

  while(i<n){
    if(pat[j]==txt[i]){
      i++;j++;
    }
    if(j==m){
      cout<<"Pattern at: "<<i-j<<endl;
      //go to prev prefix suffix match
      j=lps[j-1];
    }
    else if(i<n && pat[j]!=txt[i]){
      if(j!=0){
        j=lps[j-1];
      }
      else{
        i++;
      }
    }
  }


}

// Driver program to test above function
int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
