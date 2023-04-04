#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int reverse(int x)
{
    string s= to_string(x),res = "";
    int n = s.size(), minVal, maxVal;
    minVal = pow(2,31)* -1;
    maxVal = pow(2,31) -1;

    /*if(s.size() > 10 || (s.size() == 10 && s[0]!= '-')){
            return 0;
    }*/

    if((n > 10 && s[0] != '-') || (  n > 11 && s[0] == '-') || (n == 10 && s[0] != '-' && (int)(s[n-1] - '0') > 2) || (n == 11 && s[0] == '-' && (int)(s[n-1] - '0') > 2))
    {
        return 0;
    }

    for(int i = s.size() - 1; i >= 1; i--)
    {
        res+= s[i];
    }


    if((char)s[0] == '-')
    {

        res.insert(0,"-");
    }
    else
    {
        res+= s[0];
    }

    if(res.size() < 10 )
    {
        return stoi(res);
    }
    else
    {
        if(res.size() == 10 && res[0] == '-')
        {
            return stoi(res);
        }
        int temp;
        string maxValString = to_string(maxVal);
        string minValString = to_string(minVal);
        if(res.size() == 10)
        {
            temp = (stoi(res.substr(0,1)) * pow(10,9)) - (stoi(maxValString.substr(0,1)) * pow(10,9) ) + stoi(res.substr(1,9)) - stoi(maxValString.substr(1,9)) ;
        }
        else
        {
            temp = (stoi(res.substr(1,1)) * pow(10,9)) - (stoi(minValString.substr(1,1)) * pow(10,9) ) + stoi(res.substr(2,9)) - stoi(minValString.substr(2,9));
        }

        if( temp > 0  )
        {
            return 0;
        }
        return stoi(res);
    }
}

int main()
{
    cout << reverse(-1563846412)<< endl;
    //1563847412
    // cout <<  pow(2,31) +1000 <<endl;
    return 0;
}
