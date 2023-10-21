#include<iostream>
using namespace std;

class Person{
	protected:
	string Fname,Lname;
	int id;
	public:
		static int count;
		Person()
		{
			Fname="abc";
			Lname="xyz";
			id=1;
		}
		Person(string Fname,string Lname,int id)
		{
			this->Fname=Fname;
			this->Lname=Lname;
			this->id=id;
			count++;
		}
		virtual char calc()=0;
		void display()
		{
			cout<<"First name: "<<Fname<<"\nLast name: "<<Lname<<"\nID: "<<id<<endl;
		}
};

class Student:public Person{
	int Score[10];
	int sum;
	float av;
	char grade;
	public:
		Student()
		{
			Fname="abc";
			Lname="xyz";
			id=1;
		}
		Student(string Fname,string Lname,int id):Person(Fname,Lname,id)
		{
			
		}
		char calc()
		{
			sum=0;
			for(int i=0;i<5;i++)
			{
				sum+=Score[i];
			}
			av=sum/5.0;
			
			if(av>90)
			grade='A';
			else if(av<=90&&av>80)
			grade='B';
			else if(av<=80&&av>70)
			grade='C';
			else if(av<=70&&av>60)
			grade='D';
			else if(av<=60&&av>50)
			grade='E';
			else if(av<=50)
			grade='F';
				
			return grade;
		}
};

int Person:: count=0;

int main()
{
	int Score[10];
	int id,n,g;
	string Fname,Lname;
	int i=0;
	Student *st[10];
	
	cout<<"1. Accept details\n2. Display details\n3. Exit"<<endl;

do{	
	cout<<"enter choice: ";
	cin>>n;
	
	switch(n)
	{
		case 1:
		{
		cout<<"Enter student details: ";
		cin>>Fname>>Lname>>id;
		st[i]=new Student(Fname,Lname,id);
		i++;
		cout<<"Enter score of 2 subjects: ";
		for(int j=0;j<2;j++)
		{
		cin>>Score[j];	
		}
		break;
	   }
		
		case 2:
		{
		for(int l=0;l<i;l++)
		{
		st[l]->display();
		for(int m=0;m<2;m++)
		{
			cout<<"Grade: "<<st[l]->calc();
		}	
		}
		
		break;
		}
		
		case 3:
		{
		break;
		}
	}
			
}while(n!=3);
	
}
