#include <iostream>

using namespace std;

string zigzag(string s , int numRows){
    int n = s.size() , i, inc, ajout , j;
    i=1;
    ajout = 0;

    if(numRows == 1){
        return s;
    } else {
        inc = numRows + (numRows - 2 );
         string ans = "";
         while(i <= numRows){
            ajout = (i -1)*2;
            j = i ;
            while(j <= n ) {
                   // cout << " j is "<< j <<endl;
                if( j > i && ajout > 0 && ajout != (numRows -1)*2){
                    ans+= s[j-ajout-1];
                }
                ans += s[j-1];
                j+= inc;
                if(j > n && (j- ajout) <= n  && ajout > 0 && ajout != (numRows -1)*2 ){
                      //  cout <<"enter and added " << s[j-ajout-1] << " j is " << j << " , ajout is " << ajout << " j - ajout is " << j-ajout<<endl;
                    ans+= s[j-ajout-1];
                }
            }
            i++;
         }

        return ans;
    }


}

int main()
{
    string s = "PAYPALISHIRING";
    int rows = 5;
    cout<< zigzag(s, rows)<<endl;
    return 0;
}
