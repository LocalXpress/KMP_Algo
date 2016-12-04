#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string a="aabaabaaa",b="aab";
    vector<int>f;
    int i=1,j=0;
    f.push_back(0);

    while (i < a.size())//Calculating the Pattern Factor of the parent string
    {
        if (a[i] == a[j])
        {f.push_back(++j); i++;}
        else
        {   if (j)
                j = f[j-1];
            else
            { f.push_back(0); i++;}
        }
    }

    for(i=0;i<f.size();i++)
        cout<<" "<<f[i]<<" ";

    cout<<endl;
    i = 0, j  = 0;
    while (i < a.size())
    {
        if (b[j] == a[i])
        {
            j++;
            i++;
        }

        if (j == b.size())
        {
            cout<<"Pattern found at: "<<i-j<<endl;
            j = f[j-1];
        }
        else if (i < a.size() && b[j] != a[i])
        {

            if (j != 0)
                j = f[j-1];
            else
                i = i+1;
        }
    }
}
