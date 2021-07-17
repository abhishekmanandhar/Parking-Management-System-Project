#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
class basicdetails{
	int hrs;
	int min;
   	char name[20];
	public:
		int vehicle_no;
		void getdata()
		{  
		    cout<<"Enter the owner name : ";
		    cin>>name;
			cout<<"Enter the vehicle number : ";
			cin>>vehicle_no;
			cout<<"Arrival time (hrs:min) : ";//it is the exact time when the data was entered
			cin>>hrs;
			cout<<":";
			cin>>min;
			
		}
		void showdata()
		{   
		    cout<<setw(33)<<"!!!Car Parking Details!!!\n";
		    cout<<"-----------------------------------------\n";
			cout<<"Name"<<setw(20)<<" \t\t: "<<name<<endl;
			cout<<"Vehicle number"<<setw(20)<<" \t: "<<vehicle_no<<endl;
		}
		
};
class twowheeler:public basicdetails{
	int duration;
	float total;
	public:
		void getdata()
		{
			cout<<"Estimated duratiom of stay (in hrs) : ";
			cin>>duration;
		}
		void display()
		{
			float rate=0.25;
		    total=duration*15;
			cout<<"Total duration of stay"<<setw(12)<<" : "<<duration<<" hrs"<<endl;
			cout<<"Parking charge"<<setw(20)<<" \t: Rs."<<total;
			cout<<"\n-----------------------------------------\n";
	    }
}t1;

class fourwheeler:public basicdetails{
	int duration;
	float total;
	public:
		void getdata()
		{
			cout<<"total duration of parking:";
			cin>>duration;
		}
	    void display()
		{
			float rate=0.25;
		    total=duration*15;
			cout<<"Total duration of stay"<<setw(12)<<" : "<<duration<<" hrs"<<endl;
			cout<<"Parking charge"<<setw(20)<<" \t: Rs."<<total;
			cout<<"\n-----------------------------------------\n";
	    }
}f1;

void delete_record(void);
void options(void);
inline re_turn(void);

int main()
{
	int login();
	login();
	system("cls");
	options();
}

void options()
{
	int choice;
	cout<<"\n\t\t\t\t*****************************************************\t\t\t\n"<<endl;
	cout<<"\t\t\t\t*****************************************************\t\t\t\n"<<endl;
	cout<<"\t\t\t\t1.Arrival of vehicle\t\t\t"<<endl;
	cout<<"\t\t\t\t2.Total parking charges of all vehicles with details\t\t\t"<<endl;
	cout<<"\t\t\t\t3.Departure of vehicles\t\t\t"<<endl;
	cout<<"\t\t\t\t4.Exit program"<<endl;
	cout<<"\n\t\t\t\t*****************************************************\n"<<endl;
	cout<<"\t\t\t\t*****************************************************\t\t\t\n"<<endl;
	cout<<"\t\t\t\tSelect your choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			system("CLS");
			int ch;
			cout<<"Is it two wheeler or four wheeler (2/4) : ";
			cin>>ch;
			if(ch==2)//if it is two wheeler then the data is stored in twowheels.txt
			{
				
				ofstream fout;
				fout.open("twowheels.txt",ios::binary|ios::out|ios::app);
				t1.basicdetails::getdata();
				t1.getdata();
				fout.write((char*)&t1,sizeof(t1));
				fout.close();
				re_turn();
			}
			else
			{
				ofstream fout;
				fout.open("fourwheels.txt",ios::binary|ios::out|ios::app);
				f1.basicdetails::getdata();
				f1.getdata();
				fout.write((char*)&f1,sizeof(f1));
				fout.close();
				re_turn();
			}
			break;
		
		case 2:
			system("CLS");
			int d;
			cout<<"Press 2 for two wheller and 4 for four wheller:"<<endl;
			cin>>d;
			if(d==2)
			{	
				ifstream fin;
				fin.open("twowheels.txt",ios::in|ios::binary);
				while(fin.read((char*)&t1,sizeof(t1)))
				{
					system("cls");	
					t1.showdata();
			    	t1.display();
			    	system("pause");
				}
				re_turn();
			}
			if(d==4)
			{
				ifstream fin;
				fin.open("fourwheels.txt",ios::in|ios::binary);
				while(fin.read((char*)&f1,sizeof(f1)))
				{
					system("cls");		
					f1.showdata();
			    	f1.display();
			   	 	system("pause");
				}
				re_turn();
			}
			break;	
		
		case 3:
			delete_record();
			re_turn();
			break;	
		
		case 4:
			exit(0);
			
		default:
			cout<<"\n!!!Invalid Choice!!!";		
	}

}
inline re_turn()
{
	char ch;
	cout<<"\n\nDo you want to return?(y/n) : ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		system("cls");
		options();
	}
	else
	{
		exit (0);
	}
}

void delete_record()
{
	int n,d;
	system("CLS");
	cout<<"\n\n\n\n\t\t\t\tEnter the type of vehicle 2 wheeler or 4 wheeler (2/4) : ";
    cin>>d;	
	cout<<"\n\n\n\t\t\t\t\tEnter the car number that has departed : ";
	cin>>n;	
    if(d==2)
    {
   		ifstream Fin_two("twowheels.txt",ios::binary);
   		ofstream saved_file("temp.txt", ios::out | ios::binary);
		while(Fin_two.read((char*)&t1, sizeof(t1)))
    	{
        	if(t1.vehicle_no!= n)
        	{	
        	    saved_file.write((char*)&t1, sizeof(t1));
        	}
        }
        cout<<"\n\n\n\t\t\t\t\t\t!!!Parking Record Deleted!!!";
    	Fin_two.close();
    	saved_file.close(); 
		remove("twowheels.txt");
    	rename("temp.txt", "twowheels.txt");	  	
	}
	else
	{
		ifstream Fin_four("fourwheels.txt",ios::binary);
		ofstream saved_file("temp.txt", ios::out | ios::binary);
		while(Fin_four.read((char*)&f1, sizeof(f1)))
    	{
        	if(t1.vehicle_no!= n)        	
        	{	
        	    saved_file.write((char*)&f1, sizeof(f1));
        	}
        }
        cout<<"\n\n\n\t\t\t\t\t\t!!!Parking Record Deleted!!!";
    	Fin_four.close();
    	saved_file.close(); 
		remove("fourwheels.txt");
    	rename("temp.txt", "fourwheels.txt");
   	}   
}

int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "prarup"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}

