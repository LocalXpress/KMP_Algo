#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string a="aabaabaaa",b="aab";// a is the text and b is the sub-string searching for. I have dynamically taken
                                 //so as to save me the hassle of taking string input again and again.
    vector<int>f;                //I have taken a vector or a dynamic array so that I don't have to recalculate the
    int i=1,j=0;                 //the value of the length. The initial index is given as 0.
    f.push_back(0);

    while (i < a.size())         //Calculating the Pattern Factor of the parent string
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
    /*for(i=0;i<f.size();i++)      //Uncomment this code to check the pf array
        cout<<" "<<f[i]<<" ";*/
    i = 0, j  = 0;                //i is the index of the text and j is the index of the patter we are searching for
    while (i < a.size())
    {
        if (b[j] == a[i])
        {   j++; i++; }
        if (j == b.size())
        { cout<<"Pattern found at: "<<i-j<<endl; j = f[j-1]; }
        else if (i < a.size() && b[j] != a[i])
        {
            if (j != 0)
                j = f[j-1];
            else
                i = i+1;
        }
    }
    return 0;
    //If the pattern is found then then index is given and the pattern found is given! If the pattern is not found then
    // no output is given. I am not able to resolve this issue that if the pattern is not found than the output will be
    //patter not found.
}
