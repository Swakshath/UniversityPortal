#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<process.h>
#include<limits>
#include<ios>
using namespace std;

//Some variables needed for checking date format
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;
int s_size=9;
int f_size=5;
int w_size=1;

//classes marks,leave and profile are part of class student
class marks
{
	char sub[5][10];
	float cat1[5],cat2[5],fat[5];
	public:
	   	
		   
		marks()
		{
			strcpy(sub[0],"MAT1002");
			strcpy(sub[1],"CSE1001");
			strcpy(sub[2],"CSE1002");
			strcpy(sub[3],"ENG0001");
			strcpy(sub[4],"PHY1001");
			
			for(int i=0;i<5;i++)
			{
				cat1[i]=cat2[i]=fat[i]=-1;
			}
		}
		
		
		void enter_marks(char c[])//for getting input from the teacher for the marks of a particular subject
		{
			char code[10];
			int pos=-1;
			strcpy(code,c);
			for(int i=0;i<5;i++)
			{
				if(strcmp(code,sub[i])==0)
				{
					pos=i;
					break;
				}
			}
			if(pos>=0)
			{
				cout<<endl<<"Enter the marks for subject "<<sub[pos]<<endl;
				int n;
				cout<<"1:CAT 1\t\t2:CAT 2\t\t3:FAT"<<endl<<endl;
				cout<<"Enter your option:";
				cin>>n;
				switch(n)
				{
					case 1:
						while (cout << "Enter the marks:" && !(cin >> cat1[pos])) {
    					std::cin.clear(); //clear bad input flag
    					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    					std::cout << "Invalid input; please re-enter.\n";
						}
						/*cout<<"Enter the marks:";
						cin>>cat1[pos];
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout<<"Invalid input";*/
						cout<<endl;
						break;
					case 2:
						while (cout << "Enter the marks:" && !(cin >> cat2[pos])) {
    					std::cin.clear(); //clear bad input flag
    					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    					std::cout << "Invalid input; please re-enter.\n";
						}
						/* cout<<"Enter the marks:";
						cin>>cat2[pos]; */
						cout<<endl;
						break;
					case 3:
						while (cout << "Enter the marks:" && !(cin >> fat[pos])) {
    					std::cin.clear(); //clear bad input flag
    					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    					std::cout << "Invalid input; please re-enter.\n";
						}
						/*cout<<"Enter the marks:";
						cin>>fat[pos]; */
						cout<<endl;
						break;
					default:
						cout<<"You have entered the wrong option. Pls start from the begining."<<endl;
						break;
					}
					//system("cls");
					
				}
				else
					cout<<"You have entered the wrong option. Pls start from the begining."<<endl;
					
			}//input marks
		
		
		void print_marks(char a[]="Nil")//a contains teacher code if displaying for teacher
		{
			int pos=-1;
			if(strcmp(a,"Nil")!=0)
			{
				for(int i=0;i<f_size;i++)
				{
					if(strcmp(a,sub[i])==0)
					{
						pos=i;
						break;
					}
				}
				if(pos!=-1)
				{
					if(cat1[pos]!=-1)
					{
						cout<<"CAT 1:"<<cat1[pos]<<'\t';
					}
					else
					cout<<"CAT 1:"<<"Nil"<<'\t';

				if(cat2[pos]!=-1)
					{
						cout<<"CAT 2:"<<cat2[pos]<<'\t';
					}
					else
					cout<<"CAT 2:"<<"Nil"<<'\t';
				if(fat[pos]!=-1)
					{
						cout<<"FAT :"<<fat[pos]<<endl;
					}
					else
					cout<<"FAT :"<<"Nil"<<endl;

				}
				else
					cout<<"You have entered the wrong subject code. Pls start from the begining."<<endl;
			}
			else
			{
				for(int i=0;i<5;i++)
				{
					pos=i;
					cout<<sub[pos]<<'\t';
					if(cat1[pos]!=-1)
					{
						cout<<"CAT 1:"<<cat1[pos]<<'\t';
					}
					else
					cout<<"CAT 1:"<<"Nil"<<'\t';

				if(cat2[pos]!=-1)
					{
						cout<<"CAT 2:"<<cat2[pos]<<'\t';
					}
					else
					cout<<"CAT 2:"<<"Nil"<<'\t';
				if(fat[pos]!=-1)
					{
						cout<<"FAT :"<<fat[pos]<<endl;
					}
					else
					cout<<"FAT :"<<"Nil"<<endl;
				}
			}
		}
};
class leave
{
	public:
		char frm[10],tt[10];
	char from[10],to[10],reason[200];
	bool permission,applied;
		leave()
		{
			permission=false;
			applied=false;
		}
		/*check1(char a[],char b[])
		{
			strcpy(from,a);
			strcpy(to,b);
		}*/
		bool isLeap(int year)
		{
		  // Return true if year is a multiple pf 4 and
		  // not multiple of 100.
		  // OR year is multiple of 400.
		  return (((year%4==0) && (year%100!=0)) ||
		           (year%400==0));
		}
		 
		// Returns true if given year is valid or not.
		bool check(char fr[])
		{
			int d, m, y;
			d=((fr[0]-48)*10)+(fr[1]-48);
			m=((fr[3]-48)*10)+(fr[4]-48);
			y=((fr[6]-48)*1000)+((fr[7]-48)*100)+((fr[8]-48)*10)+(fr[9]-48);
		    // If year, month and day are not in given range
		    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		      return false;
		    if (m < 1 || m > 12)
		      return false;
		    if (d < 1 || d > 31)
		      return false;
		 
		    // Handle February month with leap year
		    if (m == 2)
		    {
		        if (isLeap(y))
		           return (d <= 29);
		        else
		           return (d <= 28);
		    }
		 
		    // Months of April, June, Sept and Nov
		    // must have number of days less than
		    // or equal to 30.
		    if (m==4 || m==6 || m==9 || m==11)
		        return (d <= 30);
		 
		    return true;
		}
			
		bool check_duration(char fr[],char to[])
		{
			int dayf,dayt,mf,mt;
			bool chk=true;
			dayf=((fr[0]-48)*10)+(fr[1]-48);
			dayt=((to[0]-48)*10)+(to[1]-48);
			mf=((fr[3]-48)*10)+(fr[4]-48);
			mt=((to[3]-48)*10)+(to[4]-48);
			if((mf==mt))
			{
				if(dayf>dayt)
					chk=false;
			}
			if(mt<mf)
				chk=false;
			return chk;
		}
		bool find()
		{
			if((check(from)==true)&&(check(to)==true)&&(check_duration(from,to)==true))
			{
				return true;
			}
			else
			return false;
		}
		/*void copydate()
		{
			strcpy(from,date1);
			strcopy(to,date2);
		}*/


	void apply_leave(int n=0)
	{
	
	char date1[10];
	char temp[2],yr[4];
	char date2[10];
	int fd,fm,fy,td,tm,ty;
	if(n==1)
	{
	permission=false;
	cout<<"Enter the from date(dd): ";
		cin>>temp;
			strcpy(date1,temp);
			strcat(date1,"-");
			cout<<"Enter to month (mm): ";
			cin>>temp;
			strcat(date1,temp);
			strcat(date1,"-");
			cout<<"Enter to year (yyyy): ";
			cin>>yr;
			strcat(date1,yr);
			strcpy(from,date1);
		//strcpy(frm,from);
	cout<<"Enter the to date(dd): ";
		cin>>temp;
			strcpy(date2,temp);
			strcat(date2,"-");
			cout<<"Enter to month (mm): ";
			cin>>temp;
			strcat(date2,temp);
			strcat(date2,"-");
			cout<<"Enter to year (yyyy): ";
			cin>>yr;
			strcat(date2,yr);
			strcpy(from,date1);
			strcpy(to,date2);
			fd=((from[0]-48)*10)+(from[1]-48);
			fm=((from[3]-48)*10)+(from[4]-48);
			fy=((from[6]-48)*1000)+((from[7]-48)*100)+((from[8]-48)*10)+(from[9]-48);
			td=((to[0]-48)*10)+(to[1]-48);
			tm=((to[3]-48)*10)+(to[4]-48);
			ty=((to[6]-48)*1000)+((to[7]-48)*100)+((to[8]-48)*10)+(to[9]-48);
			if(check(from)==false)
				{
					cout<<endl<<"Wrong input for from date";
					return;
				}
			if(check(to)==false)
				{
					cout<<endl<<"Wrong input for to date";
					return;
				}
			if(find()==true)
			{
				cout<<"Enter your reason for leave: ";
				cin.ignore();
				cin.getline(reason,200);
				applied=true;
				cout<<endl<<"Leave Saved."<<endl;
			}
			else
			{
				cout<<endl<<"From date cannot be greater than to date";
				return;
			}
		
	}
	
			
			if((find()==true))
			{
				//cout<<"From: "<<fd<<"-"<<fm<<"-"<<fy<<endl;
				//cout<<"To: "<<td<<"-"<<tm<<"-"<<ty<<endl;
				cout<<"Reason: "<<reason<<endl;
				cout<<"Leave status: "<<((permission==true)?"Approved":"Not Approved")<<endl;
			}
			else
			cout<<"leave not yet appplied"<<endl;
	}
		
};

class profile
{
	public:
	char father[50],mother[50],address[100],phone[15],blood[4],email[50],name[50];
	
		
		//functios for input 
		void get_profile()
		{
			cout<<"Enter The Details of the student mentioned below, in the same order"<<endl;
			cout<<"Student's name,Father's name, Mother's name, Address, phone, blood group, Email-ID"<<endl;
			cin.ignore();
			cin.getline(name,50);
			cin.getline(father,50);
			cin.getline(mother,50);
			cin.getline(address,100);
			cin.getline(phone,15);
			cin.getline(blood,4);
			cin.getline(email,50);
		}
		void print_profile()//??to print the details
		{
			cout<<"Student's name: "<<name<<endl;
			cout<<"Father's name : "<<father<<endl;
			cout<<"Mother's name : "<<mother<<endl;
			cout<<"Address : "<<address<<endl;
			cout<<"Phone Number : "<<phone<<endl;
			cout<<"Blood group : "<<blood<<endl;
			cout<<"Email-ID : "<<email<<endl;
		}
		void modify_profile()
		{
			char a[50];
			char detail[20];
			cout<<"Enter the detail you want to modify(Please enter the detail name as given in the profile): ";
			cin.ignore();
			cin.getline(detail,20);
			cout<<"Enter the change you want to make : ";
			//cin.ignore();
			cin.getline(a,50);
			cout<<endl;
			if(strcmpi(detail,"Father's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"Invalid format"<<endl;
						break;
					}
				}
			if(r==1)
			{
				strcpy(father,a);
				cout<<"Changes Saved."<<endl;
		}
			}
			else if(strcmpi(detail,"mother's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"Invalid format"<<endl;
						break;
					}
				}
			if(r==1)
			{
				strcpy(mother,a);
				cout<<"Changes Saved."<<endl;
		}
			}
			else if(strcmpi(detail,"Student's name")==0)
			{
				int r=1;
				for(int p=0;a[p]!='\0';++p)
				{
					if(!isalpha(a[p]))
					{
						r=0;
						cout<<"Invalid format"<<endl;
						break;
					}
				}
				if(r==1)
				{
				strcpy(name,a);
				cout<<"Changes Saved."<<endl;
			}
			}
			else if(strcmpi(detail,"Address")==0)
			{

				strcpy(address,a);
				cout<<"Changes Saved."<<endl;
			}
				else if(strcmpi(detail,"Phone number")==0)
			{
				int z=1;
				for(int q=0;a[q]!='\0';++q)
				{
					if(!isdigit(a[q]))
					{
						z=0;
						cout<<"Invalid number"<<endl;
						break;
					}
						
				}
				if(z==1)
				{
			
				strcpy(phone,a);
				cout<<"Changes Saved."<<endl;
			}
			}
				else if(strcmpi(detail,"Blood group")==0)
			{
				if(strcmp(a,"A-")!=0&&strcmp(a,"B-")!=0&&strcmp(a,"A+")!=0&&strcmp(a,"B+")!=0&&strcmp(a,"AB+")!=0&&strcmp(a,"AB-")!=0&&strcmp(a,"O+")!=0&&strcmp(a,"O+")!=0)
					cout<<"Invalid type"<<endl;
				else
				{
				strcpy(blood,a);
				cout<<"Changes Saved."<<endl;
			}
			}
				else if(strcmpi(detail,"Email-ID")==0)
			{
				if(strlen(a)<9)
				
					cout<<"Invalid format"<<endl;
					else{
				
					char b[50];
					int i;
					for(i=0;i<8;++i)
					{
						b[i]=a[strlen(a)-i-1];
					}
					b[i]='\0';
					
				if(strcmp(b,"moc.zyx@")!=0)
					cout<<"Invalid format"<<endl;
				else{
				
				strcpy(email,a);
				cout<<"Changes Saved."<<endl; }}
			}
			
			else
			{
				cout<<"Entered detail not in the same as given in the profile"<<endl;
				
			}
			
		}
	};



//All student related functions and classes

//class student contains all student info
class student
{
	public:
	profile p;
	marks m;
	leave l;
	char reg[20];
	int room_no;
	char password[20];
	int pcount;
	int acount;
	student *next;
	student()
	{
		pcount=0;
		acount=0;
		}	
	void get_student()
	{
		cout<<"reg:";
		cin>>reg;
		cout<<"password:";
		cin>>password;
		cout<<"room:";
		cin>>room_no;
		p.get_profile();
		
		
	}
	void print_attendence()
	{
		cout<<"Number of days present:"<<pcount<<endl;
		cout<<"Number of days absent:"<<acount<<endl;
		cout<<"Attendance Percentage:"<<((pcount*100)/(pcount+acount))<<"%";
	}
	
	
};

struct node
{
	student x;
	node *next;
}*top=NULL;

//extracts all the data in the student file to an array of type student(s[])
void extract_to(student s[])
{
	ifstream in("student.dat",ios::in|ios::binary|ios::app);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<s_size;i++)
	{
		node *temp;
		temp=new node;
		in.read((char*)&s[i],sizeof(s[i]));
		temp->x=s[i];
		temp->next=top;
		top=temp;
		
	}
	in.close();
	
}	

//returns podition of the object in student file with reg_no=rno
/* int find_student(int rno)
{
	student s;
	ifstream fin;
	fin.open("student.dat",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(rno==s.reg)
		{
			return(fin.tellg()-sizeof(s));
		}
	}
	fin.close();
	
} */
node* search(node *a,char r[])
{
	node* temp1=a;
	int n=s_size;
	int m=sqrt(n);
	int i;
	int order=0;
	//cout<<a->x.reg<<"a";
	a=a->next->next->next;
	
	if(strcmp(temp1->x.reg,temp1->next->x.reg)>=0)
	  order=-1;
	else 
	  order=1;
	  
	if(order>0)
	{	
	while(m<n&&strcmp(r,a->x.reg)>=0)
	{
		//cout<<"entered asc while";
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  temp1=temp1->next;
		}
		m+=sqrt(n);
	}
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}
    
    else
	{
	while(m<n&&strcmp(r,a->x.reg)<=0)
	{
		//cout<<"entered des while";
		//cout<<"value of temp1"<<temp1->x.reg<<"\n";
		for(i=0; i<sqrt(n); i++)
		{
			if(a!=NULL)
		      a=a->next;
		  temp1=temp1->next;
		  
		}
		//cout<<"for over";
		m+=sqrt(n);
	}
	//cout<<"value of temp1"<<temp1->x.reg<<"\n";
	for(i=0; i<sqrt(n); i++)
	{
	  if(strcmp(r,temp1->x.reg)==0)
		  return temp1;
		temp1=temp1->next;
	}
	}

	cout<<"Not found";
	system("pause");
	return NULL;		
}
//the student login page(asks for password and shows the student menu) 
void s_login()
{
	char r[20];char p[20],pos;
	student s1[s_size],s;
	cout<<"Reg no:"; cin>>r;
	
	/*ifstream in("student.dat",ios::in|ios::binary|ios::app);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<3;i++)
	{
		in.read((char*)&s1[i],sizeof(s1[i]));
	}
	in.close();*/
	extract_to(s1);
	
	/*ifstream i("student.dat",ios::in|ios::binary);
	i.seekg(pos);
	i.read((char*)&s,sizeof(s));
	i.close();
	if(strcmp(s.p.name,"Nil")==0)
	{
		cout<<"Reg number not found!!";
		return;
	}*/
	node *temp=top;
	temp=search(temp,r);
	if(temp==NULL)
		return;
	s=temp->x;
	cout<<"Enter Password:";cin>>p;
	if(strcmp(p,s.password)!=0)
	{
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		system("pause");
		return;
	}
		char ch='0';
		while(ch!='7')
		{
		
		system("cls");
		cout<<"\n\t\t\t\tSTUDENT LOGIN\n"<<endl;
		cout<<"Student reg no: "<<s.reg<<endl<<endl;
		cout<<"1-View profile\n2-Modify profile\n3-View marks\n4-Apply leave\n5-To view leave\n6-To view attendance\n7-Return to main menu\n\nEnter your choice : ";
		cin>>ch;
        switch(ch)
		{
			case '1':
				cout<<endl;
				s.p.print_profile();
				cout<<endl;
				system("pause");
				break;
			case '2':
				cout<<endl;
				s.p.print_profile();
				cout<<endl;
				s.p.modify_profile();
				system("pause");
				cout<<endl;
				break;
			case '3':
				cout<<endl;
				s.m.print_marks();
				cout<<endl;
				system("pause");
				break;
			case '4':
				cout<<endl;
			   	s.l.apply_leave(1);
			   	cout<<endl;
			   	system("pause");
			    break;
			case '5':
				cout<<endl;
				s.l.apply_leave();
				cout<<endl;
				system("pause");
				break;
			case '6':
				cout<<endl;
				s.print_attendence();
				cout<<endl;
				system("pause");
				break;
			case '7':
			    break;
		    default:
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
		    	//system("pause");
		    	break;
				    
		}		
    }
        temp->x=s;
		ofstream o("student.dat",ios::out|ios::binary);
		//o.seekp(pos);
		temp=top;
        while(temp)
        {
        	s=temp->x;
			o.write((char*)&s,sizeof(s));
			temp=temp->next;
		}
		o.close();
}




//All faculty related functions and classes

//class faculty contains all faculty info
class faculty
{
	public:
	char fac_no[20];
	char sub_code[10];
	char name[50];
	char password[20];
	//student s[100];
				
	
	
	void get_faculty()
	{
		cout<<"reg no:"<<endl;
		cin>>fac_no;
		cout<<"subject code"<<endl;
		cin>>sub_code;
		cout<<"name"<<endl;
		cin.ignore();
		cin.getline(name,50);
		cout<<"password"<<endl;
		cin>>password;
		
		
	}
	
	void print_faculty()
	{
		
		cout<<"Faculty number : "<<fac_no<<endl;
		cout<<"Subject code : "<<sub_code<<endl;
	    cout<<"Faculty name : "<<name<<endl;
		
		
	}
	
	void view_marks()
	{
		student s[s_size];
		extract_to(s);
		for(int i=0;i<s_size;i++)
			{
				cout<<"Reg no:"<<s[i].reg<<'\t';
				s[i].m.print_marks(sub_code);
			}
	}
	void enter_marks()
	{
		student s[s_size];
		extract_to(s);
		
		char reg_no[20]="0";
		while(strcmp(reg_no,"-1")!=0)
		{
			
			view_marks();
			cout<<endl<<"Enter the Reg no of the student to enter marks or -1 to quit: ";
			cin>>reg_no;
			for(int i=0;i<s_size;i++)
			{
				if(strcmp(reg_no,s[i].reg)==0)
				{
					s[i].m.enter_marks(sub_code);
				}
			}
			ofstream o("student.dat",ios::out|ios::binary);
			int i;
			for(i=0;i<s_size;i++)
			{
				o.write((char*)&s[i],sizeof(s[i]));
			}
		}
		
	}
	//void check_reval()//mark correction
};

struct nodef
{
	faculty y;
	nodef *next;
}*topf=NULL;

nodef* search(nodef *tempf,char r[])
{
	if(tempf==NULL)
		return NULL;
	if(strcmp(tempf->y.fac_no,r)==0)
		return tempf;
	search(tempf->next,r);
}
//the faculty login page(asks for password and shows the faculty menu) 
void f_login()
{
	/*ifstream in("faculty.dat",ios::in|ios::binary);
	faculty f1;
	in.seekg(ios::beg);
	for(int i=0;i<f_size;i++)
	{
		in.read((char*)&f1,sizeof(f1));
		f1.print_faculty();
	}
	in.close();
	system("pause");*/
	
	
	char p[20],r[20];
	faculty f;
	cout<<"Faculty no:"; cin>>r;
	nodef *tempf;
	ifstream in("faculty.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<f_size;i++)
	{
		tempf=new nodef;
		in.read((char*)&f,sizeof(f));
		tempf->y=f;
		tempf->next=topf;
		topf=tempf;
			}
	in.close();
	
	tempf=search(tempf,r);
	f=tempf->y;
	cout<<"Enter Password:";cin>>p;
	if(strcmp(p,f.password)!=0)
	{
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		system("pause");
		return;
	}

		char ch='0';
		while(ch!='4')
		{
		system("cls");
		cout<<"\n\t\t\t\tFACULTY LOGIN\n"<<endl;
		cout<<"Faculty no: "<<f.fac_no<<endl<<endl;
		cout<<"1-View profile\n2-View Students Marks\n3-Enter student marks\n4-Return to main menu\n\nEnter your choice : ";
		cin>>ch;
        switch(ch)
		{
			case '1':
				cout<<endl;
				f.print_faculty();
				cout<<endl;
				system("pause");
				break;
			case '2':
				cout<<endl;
				f.view_marks();
				cout<<endl;
				system("pause");
				break;
			case '3':
				cout<<endl;
				f.enter_marks();
				cout<<endl;
				//system("pause");
				break;
			case '4':
			    break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
				    
			}		
        }
        /*ofstream o("faculty.dat",ios::out|ios::binary);
		o.seekp(pos);
		o.write((char*)&f,sizeof(f));
		o.close();*/
		tempf->y=f;
		ofstream o("faculty.dat",ios::out|ios::binary);
		tempf=topf;
		while(tempf)
		{
			f=tempf->y;
			o.write((char*)&f,sizeof(f));
			tempf=tempf->next;
		}
		o.close();
		
}


//All warden related functions and classes
//class warden contains all warden info
class warden
{
	
	
	//student s[100];
	
	public:
	char ward_no[20];
	char name[20];
	char password[20];
	
	/*void extract_to(student& a[])
	{			
	}*/	
	void get_warden()
	{
		cout<<"Warden no:";	cin>>ward_no;
		cout<<"Name:";	cin>>name;
		cout<<"password:";	cin>>password;
	}
	
	void print_warden()
	{
		cout<<"Warden no: "<<ward_no<<endl;
		cout<<"Name: "<<name<<endl;
	}
	void mark_attendance()
	{
		struct q
		{
			int pcount;
			int acount;
			q *next;
		}*f=NULL,*r=NULL;
	
		student s[s_size];
		extract_to(s);
		q *temp;
		
		//has the object of the students from the file 
		//input to the student object is done here
		for(int i=0;i<s_size;i++)
		{	
			cout<<"Enter if Reg no: "<<s[i].reg<<" is present or absent (p/a): ";
			char a;
			temp=new q;
			cin>>a;
			if(a=='p')
			{
				temp->pcount=(++s[i].pcount);
				temp->acount=s[i].acount;
		}
		   	else
		   	
		{
				temp->acount=(++s[i].acount);
				temp->pcount=s[i].pcount;
		}
			temp->next=NULL;
			if (r==NULL)
				f=temp;
			else
				r->next=temp;
			r=temp;
	   	}
	   	int i=0;
	   	q *temp1=f;
	   	ofstream o("student.dat",ios::out|ios::binary);
		o.seekp(ios::beg);
		while(temp1)
		{
			s[i].pcount=temp1->pcount;
			s[i].acount=temp1->acount;
			o.write((char*)&s[i],sizeof(s[i]));
			temp1=temp1->next;
			++i;
		}
		o.close(); 
	}
	void approve_leave()
	{
		student s[s_size];
		extract_to(s);
		char l;
		int flag=0;
		for(int i=0;i<s_size;i++)
		{
			if(s[i].l.applied==true)
			{
				flag=1;
				cout<<"Reg no : "<<s[i].reg<<" has applied leave."<<endl;
				s[i].l.apply_leave();
				cout<<"Do you want to approve the leave? (y/n) "<<endl;
				cin>>l;
				if(l=='y')
				{
					s[i].l.permission=true;
					s[i].l.applied=false;
				}
				else
				{
					s[i].l.permission=false;
					s[i].l.applied=false;
				}
				
			}
		}
		if(flag==0)
		{
			cout<<endl<<"No leave applications yet"<<endl;
		}
		ofstream o("student.dat",ios::out|ios::binary);
		o.seekp(ios::beg);
		for(int i=0;i<s_size;i++)
		{
		o.write((char*)&s[i],sizeof(s[i]));
		
		}
		o.close();
	}
	
	void warden_search()
	{
		student s[s_size];
		extract_to(s);
		for(int i=0;i<s_size;i++)
		{
			cout<<"Reg no: "<<s[i].reg<<"\tName :"<<s[i].p.name<<endl;
		}
		cout<<endl<<"Enter the reg no of the student whose profile you want to view: ";
		char temp_reg[20];
		cin>>temp_reg;
		cout<<endl;
		for(int i=0;i<s_size;i++)
		{
			if(strcmp(s[i].reg,temp_reg)==0)
			{
				s[i].p.print_profile();
				cout<<"Room no: "<<s[i].room_no<<endl;
				s[i].print_attendence();
			}
		}
		
	}
};



struct nodew
{
	warden z;
	nodew *next;
}*topw=NULL;
//the warden login page(asks for password and shows the warden menu) 
void w_login()
{
	char r[20];char p[20];
	warden w;
	cout<<"Warden no:"; cin>>r;
	nodew *tempw;
	ifstream in("warden.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	int i;
	for(i=0;i<w_size;i++)
	{
		tempw=new nodew;
		in.read((char*)&w,sizeof(w));
		tempw->z=w;
		tempw->next=topw;
		topw=tempw;
			}
	in.close();
	
	while(tempw)
	{
		if(strcmp(r,tempw->z.ward_no)==0)
		{
			w=tempw->z;
			break;
		}
		tempw=tempw->next;
			
	}
	cout<<"Enter Password:";cin>>p;
	if(strcmp(p,w.password)!=0)
	{
		cout<<"Wrong Reg no/Password combination!!"<<endl;
		system("pause");
		return;
	}

		char ch='0';
		
		while(ch!='4')
		{
		
		system("cls");
		cout<<"\n\t\t\t\tWARDEN LOGIN\n"<<endl;
		cout<<"Warden no: "<<w.ward_no<<endl<<endl;
		cout<<"1-Mark attendence\n2-Approve leave\n3-View student detail\n4-Return to main menu\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<endl;
				w.mark_attendance();
				cout<<endl;
				system("pause");
				break;
			case '2':
				cout<<endl;
				w.approve_leave();
				cout<<endl;
				system("pause");
				break;
			case '3':
				cout<<endl;
			    w.warden_search();
			    cout<<endl;
				system("pause");
			    break;
			case '4':
				break;
		    default: ;
		    	//cout<<endl;
		    	//cout<<"You have entered Invalid option";
		    	//cout<<endl;
				//system("pause");
				    
				}		
        }
        ofstream o("warden.dat",ios::out|ios::binary);
		tempw->z=w;
		tempw=topw;
        while(tempw)
        {
        	w=tempw->z;
		o.write((char*)&w,sizeof(w));
		tempw=tempw->next;
	}
		o.close();
}





//The main function shows initial menu to login as stud, fac or warden
int main()
{
	
	//To input student data to file

	/* ofstream o("student.dat",ios::out|ios::binary);
	int i;
	for(i=0;i<s_size;i++)
	{
		student s1;
		s1.get_student();
		o.write((char*)&s1,sizeof(s1));
	}
	o.close(); */
	
	/*	 student ss[2];
		ifstream f("student.dat",ios::in|ios::binary);
		for(int i=0;i<2;++i)
		{
			f.read((char*)&ss[i],sizeof(ss[i]));
		}
		f.close();
		ss[0].pcount=0;
		ss[0].acount=0;
		ss[1].pcount=0;
		ss[1].acount=0;	
		ofstream o("student.dat",ios::out|ios::binary);
		for(int i=0;i<2;++i)
		{
			o.write((char*)&ss[i],sizeof(ss[i]));
		}
		o.close(); */
	//to view contents of student file
	
	/* student s;
	ifstream in("student.dat",ios::in|ios::binary);
	in.seekg(ios::beg);
	for(int i=0;i<s_size;i++)
	{
		in.read((char*)&s,sizeof(s));
		cout<<s.reg<<endl;
		cout<<s.password<<endl;
		s.p.print_profile();
	}
	in.close();
	system("pause"); */
	
	
	//To input faculty data to file
	/* ofstream o("faculty.dat",ios::out|ios::binary);
	for(int i=0;i<f_size;i++)
	{
		faculty f;
		f.get_faculty();
		o.write((char*)&f,sizeof(f));
	}
	o.close(); */

	
	//To view contents of faculty file
	
	/* fstream in("faculty.dat",ios::in|ios::binary);
	faculty f;
	in.seekg(ios::beg);
	for(int i=0;i<f_size;i++)
	{
		in.read((char*)&f,sizeof(f));
		f.print_faculty();
	}
	in.close();
	system("pause"); */
	
	//To input warden data to file
	
	/* ofstream o("warden.dat",ios::out|ios::binary);
		warden w;
		w.get_warden();
		o.write((char*)&w,sizeof(w));
	o.close(); */ 
	
	
	//To view contents of warden file
	
	/* ifstream in("warden.dat",ios::in|ios::binary);
	warden w;
	in.seekg(ios::beg);
		in.read((char*)&w,sizeof(w));
		w.print_warden();
	in.close(); */

	
	char choice='0';
	while(choice!=4)
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\tWELCOME\n\n"<<endl;
		cout<<"Enter 1 for Student , 2 for Faculty, 3 for Warden and 4 to exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case '1':
				system("cls");
				cout<<"\n\t\t\t\tSTUDENT LOGIN\n"<<endl;
				s_login();
				break;
			case '2':
				system("cls");
				cout<<"\n\t\t\t\tFACULTY LOGIN\n"<<endl;
				f_login();
				system("cls");
				break;
			case '3':
				system("cls");
				cout<<"\n\t\t\t\tWARDEN LOGIN\n"<<endl;
				w_login();
				system("cls");
				break;
			case '4': exit(0);
				break;
			default: ;
			//	cout<<"You have entered an invalid option."<<endl;
			//	system("pause");
		}
	}
}
