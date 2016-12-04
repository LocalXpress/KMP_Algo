#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string a="abcdabca";
    vector<int>b;
    int i,j=0;
    b.push_back(0);

    for(i=1;i<a.size();i++)
    {
        if(a[j]==a[i])
            {cout<<a[j]<<" = "<<a[i]<<endl;j++;}
        else if(!(a[j]==a[i])&&j)
            {j=(b[j]-1);}
        else
            {cout<<a[j]<<" = "<<a[i]<<endl;}
    }

}
