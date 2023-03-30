#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
//old version not accepted because of run time
bool verifyPalindrome(string s, int startIndex, int endIndex){
    for(int k = 1; k <= (ceil((float)(endIndex - startIndex)/2)); k++){
        if(s[startIndex+k-2] != s[endIndex - k ]){
            return false;
        }
    }
    return true;
}
string longestPalindrome1(string s){

    int  n = s.size(),res = s.size(),i;
    while(res > 1 ){
        for( i = 0; i<= (n-res ); i++ ){
            if(verifyPalindrome(s, i+1 , (i + res)) == true){
                return s.substr(i,res);
            }
        }
        res--;
    }
    return s.substr(0,1);
}*/

string longestPalindrome(string s)
{
    int n = s.size(), maxPal=1;
    string ans = s.substr(0,1);
    if(n==1)
    {
        return s;
    }
    else
    {

        vector<vector<int>> v(n, vector<int>(n,1));
        for(int i = 0; i < n ; i++)
        {
            v[i][i] = 1;
        }
        for(int i = 1 ; i <n ; i++){
            for(int j = i-1 ; j >=0; j--){
                if(s[i] == s[j] ){
                        if(i-j > 1){
                            if(v[i-1][j+1] == i-j-1){
                                v[i][j] = 2 + v[i-1][j+1];
                            } else {
                                v[i][j] =1;
                            }

                        } else {
                            v[i][j] = 2 ;
                        }
                        if(v[i][j] > maxPal){
                            ans = s.substr(j, i-j+1);
                            maxPal = v[i][j];
                        }
                } else {
                    v[i][j] = 1;
                }


            }
        }

        return ans;
    }


}
int main()
{
     string s = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    //cout << longestPalindrome(s);
    //string s = "lkjsldkjsldjsll";
    //cout <<s.substr(0,3)<< " is " << verifyPalindrome(s,0,4) <<endl;
    cout << longestPalindrome(s) << endl;
     //cout << longestPalindrome1(s) <<endl;


    return 0;
}
