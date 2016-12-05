#include<iostream>

using namespace std;

int i=0,j=0;

int naive(int x,int y,string str, string sub)
{
	if(str[i] == sub[j])
	{   i++; j++; }
	if(j == y)
	{   cout<<"\npattern is matched at: "<<i-j+1<<endl;
		i=i-j+1;
		j=0; }
	else if(i < x && str[i] != sub[j])
	{   i=i-j+1;
		j=0; }
	if(i < x)
		naive(x,y,str,sub);
	else
		return 0;
}

int main()
{
	string str,sub;
    cout<<"enter a string: "; cin>>str;
    cout<<"enter the substring: "; cin>>sub;
	naive(str.size(),sub.size(),str,sub);

	return 0;
}

