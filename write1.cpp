#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
	char 		name[10];
	int 		salary;
	char 		position[10];

public: 

	void input()
	{
		cout<<"Enter the name: "; 		cin>>name;
		cout<<"Enter the salary: "; 	cin>>salary;
		cout<<"Enter the position: "; 	cin>>position;
	}

	void output()
	{
		cout<<endl;
		cout<<"========================================\n";
		cout<<"The name: "<<name<<endl;
		cout<<"The salary: "<<salary<<endl;
		cout<<"The position: "<<position<<endl;
		cout<<"========================================\n";
		cout<<endl;
	}

};

int main(int argc, char const *argv[])
{
	
/*	
	//WRITING INTO A BINARY FILE USING WRITE FUNCTION
	
	Employee Emp;
	fstream f;
	f.open("Input.txt",ios::in|ios::out|ios::app);
	int i;

	for(i=0;i<3;i++){
		Emp.input();
		f.write((char*)&Emp,sizeof(Emp));
	}

	f.close();

	//END

*/

	//READING FROM AN ALREADY CREATED BINARY FILE	
	Employee Emp;
	fstream f;
	f.open("Input.txt",ios::in|ios::out|ios::app);

	f.read((char *)&Emp,sizeof(Emp));

	while(!f.eof()){
		Emp.output();
		f.read((char *)&Emp,sizeof(Emp));
	}

	f.close();
	//END

	
	return 0;
}