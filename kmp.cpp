#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string a="aabaabaaa";
    vector<int>f;
    int i=1,j=0;
    f.push_back(0);

    while (i < a.size())
    {
        if (a[i] == a[j])
        {   j++; f.push_back(j); i++; }
        else
        {   if (j != 0)
                j = f[j-1];
            else
            { f.push_back(0); i++;}
        }
    }

    for(i=0;i<f.size();i++)
        cout<<" "<<f[i]<<" ";
}
