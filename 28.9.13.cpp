#include<iostream>
#include<fstream>
//#include<stdlib>
#include<cstring>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
string rNumber;
int i2;
int y;
int r1;
char response;
class courses
{
	public:
		string courseCode;
		string coursePrerequisite;
		string faculty1;
		string slot1;
		string faculty2;
		string slot2;
		int credits;
		string cgpaRequired;
		int seats1;
		int seats2;
		int seats;
		
	void takeCourse()
	{
		seats--;
	};
	
	void dropCourse()
	{
		seats--;
	}
		
	courses()
	{
		seats1=6;
		seats2=6;
	};
	
	void takeCourse1()
	{
		seats1--;
	};
	
	void dropCourse1()
	{
		seats1++;
	};
	
	void takeCourse2()
	{
		seats2--;
	};
	
	void dropCourse2()
	{
		seats2++;
	};
	
	void courseDetails()
	{
		cout << courseCode <<"\t"<< coursePrerequisite <<"\t"<< faculty1 <<"\t"<< slot1 << "\t" << seats1 <<"\t"<< faculty2  << "\t" << slot2 <<"\t"<< seats2 <<"\t"<< credits <<"\t"<< cgpaRequired << endl;
		   
	};
	
	void showCourse1()
	{
		cout << courseCode << "\t" << faculty1 << "\t" << slot1 << "\t" << credits << endl;
	};
	
	void showCourse2()
	{
		cout << courseCode << "\t" << faculty2 << "\t" << slot2 << "\t" << credits << endl;
	};
			
};

class students
{
	public:
		string regNumber;
		string name;
		string cgpa;
		string year;
		string finishedCourses[20];
		string requestedCourses[20][20];
		string registeredCourses[20][20];
		int numberOfRequestedCourses;
		int numberOfRegisteredCourses;
		int numberOfFinishedCourses;
		int n;
		int maxCredits;
		
		students()
		{
			maxCredits = 0;
		}
		
	void studentDetails()
	{
		cout << regNumber <<"\t"<< name <<"\t"<< cgpa;
	}
		
};

int main()
{
	// variables for courses
	string code;
	string pre;
	string fac1;
	string slot1;
	string fac2;
	string slot2;
	int cred;
	string gpareq;
	
	
	courses course[20];
	//
	
	students student[20];
	int nC=1;
	int nS;
	
	ifstream inCourses("courses.txt");
	while(inCourses >> code >> pre >> fac1 >> slot1 >> fac2 >> slot2 >> cred >> gpareq)
	{
		course[nC].courseCode = code;
		course[nC].coursePrerequisite = pre;
		course[nC].faculty1 = fac1;
		course[nC].slot1 = slot1;
		course[nC].faculty2 = fac2;
		course[nC].slot2 = slot2;
		course[nC].credits = cred;
		course[nC].cgpaRequired = gpareq;
		nC++;
	}
	nC=nC-1;
	
	cout << "TOTAL NUMBER OF COURSES:"<<nC << endl;
	cout << "CODE\tPREREQ\tFAC1\tSLOT\tSEATS1\tFAC2\tSLOT\tSEATS2\tCREDIT\tGRA-REQUIRED\n";
	int i=1;
	while(i<=nC)
	{
	     course[i].courseDetails();
	     i++;
    }
    
    //
    //ALL courses read
    //
    
    //
    //DISPLAY REQUESTED COURSES
    //
    
    int a;
    int b;
    int i3;
    string temp;
    string end;
    i=1;
    int i1=1;
    a = temp=="end";
    b = temp=="z";
    ifstream inStudents("students.txt");
    while(!inStudents.eof())
    {
    	//cout << "top\n";
    	
    		inStudents >> temp;
    		student[i].regNumber = temp;
    		
    		inStudents >> temp;
    		student[i].name = temp;
    		
    		inStudents >> temp;
    		student[i].cgpa = temp;
    		
    		inStudents >> temp;
    		student[i].year = temp;
    		
    		i1=1;
    	//	a = temp=="end";
    		do
    		{
    			int i2 = 1;
    			
    		    inStudents >> temp;
    		    student[i].requestedCourses[i1][i2] = temp;
    		    i2 = i2+1;
    		    inStudents >> temp;
    		    student[i].requestedCourses[i1][i2] = temp;
    		    //cout << student[i].requestedCourses[i1] << endl;
    		    i1++;
    	    }while(temp!="end");
    	    
    	    //NO IDEA WHY THIS IS i1-2??????
    	    
    	    student[i].numberOfRequestedCourses = i1-2;
    	   // cout << student[i].numberOfRequestedCourses <<endl;
    	    //getch();

    	    i++;	
    }
    
    //cout << "hi4";
    
    nS=i-1;
   // cout << "hi1";
    getch();
    cout << "\n\n";
    cout << "REGISTER-NO.\tNAME\tCGPA\tREQUESTED COURSES\n";
    for(i=1; i<=nS; i++)
    {
    	cout <<endl;
    	student[i].studentDetails();
    	cout << " ";
    	
    	/*
    	IN THE BELOW LINE , i1<student[i].numberOfRequestedCourses    
    	IS ON PURPOSE !!!!!!!DONOT CHANGE!!!!!!!!!
    	*/
    	
    	for(i1=1;i1<=student[i].numberOfRequestedCourses;i1++)
    	{
    		i2 = 1;
    		cout <<"\t" << student[i].requestedCourses[i1][i2] << " ";
    	}
    }
    
    
    
    //
    //SWITCH CASE STARTS HERE
    //
    int x;
    do
    {
    	cout << "\n\tWELCOME TO COURSE REGISTREATION\n\n\n";
    	cout << "\n1-START REGISTRATION\n2-SEE ALL AVAILABLE COURSES\n3-SEE RULES AND REGULATIONS\n4-LOGIN\t:";
    	cin >> x;
    	switch(x)
{
   	case 1:
	   {
	   //SORTING
    		//int i;
    		//int i1;
    		//int i2;
    		
    		for(i=1; i<=nS; i++)
    		{
    			for(i1=i; i1<=nS; i1++)
    			{
    				if(student[i1].year>student[i].year)
    				{
    					students temp;
    					temp = student[i];
    					student[i] = student[i1];
    					student[i1] = temp;
    				}
    			}
    		}
    		
    		//TESTING SORTING
    		cout << "\n\n";
    cout << "REGISTER-NO.\tNAME\tCGPA\tREQUESTED COURSES\n";
    for(i=1; i<=nS; i++)
    {
    	cout <<endl;
    	student[i].studentDetails();
    	cout << " ";
    	
    	
    	//IN THE BELOW LINE , i1<student[i].numberOfRequestedCourses    
    	//IS ON PURPOSE !!!!!!!DONOT CHANGE!!!!!!!!!
    	
    	
    	for(i1=1;i1<=student[i].numberOfRequestedCourses;i1++)
    	{
    		i2 = 1;
    		cout <<"\t" << student[i].requestedCourses[i1][i2] << " ";
    	}
    }
    
	//*/
    								//START DEBUGGING!!!!!!!!!!!!!
       //READ DATABASE
       i1 = 1;
       ifstream inDatabase("database.txt");
       
       /*
       int i;
    		int i1;
    		int i2;
    		
    		for(i=1; i<=nS; i++)
    		{
    			for(i1=i; i1<=nS; i1++)
    			{
    				if(student[i1].year>student[i].year)
    				{
    					students temp;
    					temp = student[i];
    					student[i] = student[i1];
    					student[i1] = temp;
    				}
    			}
    		}
       */
       string rNumber;
       string temp;
       i=1;
       while(!inDatabase.eof())
       {
       	
       	inDatabase >> temp;
       	
       	for( y=1; y<=nS ; y++)
       	{
       		i1 = 1;
       		if(temp==student[y].regNumber)
       		{
       			while(temp!="end")
       			{
       				inDatabase >> temp;
       				student[y].finishedCourses[i1] = temp;
       				/*cout << student[y].finishedCourses[i1] << endl;
       				getch();*/
       				i1++;
       			}
       			student[y].numberOfFinishedCourses = i1-2;
       			//cout << student[y].regNumber << " " <<student[y].numberOfFinishedCourses << endl;
       		}
       	}
       }
       //cout << "\nendtest\n";
       
    //COURSE REGISTRATION
     i1=1;
     i=1;
     i2=1;
     i3=1;
     int i4=1;
     
    // cout << "hi1\n";
     //getch();
     i=1;
     while(i<=nS)
     {
     	//cout << "hi2\n";
     	//getch();
     	//i++;
     	//student[i].numberOfRegisteredCourses = i4-1;
     	//i4 = 1;
     	for(i1=1; i1<=student[i].numberOfRequestedCourses; i1++)
     	{
     		//cout << student[i].regNumber << " " << student[i].numberOfRequestedCourses << endl;
     		for(i2=1; i2 <= nC; i2++)
     		{
     			//check faculty
     			//cout << "!\n";
     			if(student[i].requestedCourses[i1][2]=="1")
     			{
     				//now check for matching course code and seat availability
     				//cout << "!!\n";
     				if((student[i].requestedCourses[i1][1]==course[i2].courseCode) && (course[i2].seats1 >=1) && (student[i].cgpa>=course[i2].cgpaRequired) && (student[i].maxCredits<=20))
     				{
     					//now check for pre-reqs
     					//cout << "!!!\n";
     					for(i3=1 ; i3 <= student[i].numberOfFinishedCourses ; i3++)
     					{
     						if((course[i2].coursePrerequisite==student[i].finishedCourses[i3]) || (course[i2].coursePrerequisite=="null"))
     						{
     							//now allot the course
     							//cout << "!!!!\n"
     							student[i].registeredCourses[i4][1] = course[i2].courseCode;
     							student[i].registeredCourses[i4][2] = "1";
     							course[i2].takeCourse1();
     							student[i].maxCredits = student[i].maxCredits + course[i2].credits;
     							i4 = i4 + 1;
     						}
     					}
     				}
     			}
     			else
     			{
     				//now check for matching course code and seat availability
     				if((student[i].requestedCourses[i1][1]==course[i2].courseCode) && (course[i2].seats2 >=1) && (student[i].cgpa>=course[i2].cgpaRequired) && (student[i].maxCredits<=20))
     				{
     					//now check for pre-reqs
     					for(i3=1 ; i3 <= student[i].numberOfFinishedCourses ; i3++)
     					{
     						if(course[i2].coursePrerequisite==student[i].finishedCourses[i3]  || (course[i2].coursePrerequisite=="null"))
     						{
     							//now allot the course
     							student[i].registeredCourses[i4][1] = course[i2].courseCode;
     							student[i].registeredCourses[i4][2] = "2";
     							course[i2].takeCourse2();
     							student[i].maxCredits = student[i].maxCredits + course[i2].credits;
     							i4 = i4 + 1;
     						}
     					}
     				}
     			}
     		}
     	}
     	student[i].numberOfRegisteredCourses = i4-1;
		 i++;
		 i4 =1;
     }

//cout << "!!!!!!!!!!\n";
     /*for(i=1; i<=nS; i++)
     {
     	cout << student[i].regNumber <<" "<<student[i].numberOfRegisteredCourses << endl;
     }*/
  
		
		//end of case 1
		break;
		}//for CASE 1
		
		case 2:
			{
			
			cout << "TOTAL NUMBER OF COURSES:"<<nC << endl;
			cout << "CODE\tPREREQ\tFAC1\tSLOT\tSEATS1\tFAC2\tSLOT\tSEATS2\tCREDIT\tGRA-REQUIRED\n";
			int i=1;
			while(i<=nC)
			{
			     course[i].courseDetails();
	    		 i++;
    		}
			//end CASE 2
			break;
			}//for case 2
			
		case 3:
			{
				//
	 	//
	 	//
	 	//RULES AND
	 	//REGULATIONS
	 	//
	 	//
	   cout << "1-.....\n2-.....\n3-bbbbblabalboaloab\n";		
				break;
			}
			
		case 4:
			{
				////////////////////////////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////////
				
					cout << "ENTER REGISTRATION NUMBER-";
	 	cin >> rNumber;
	 	for(i=1; i<=nS ; i++)
	 	{
	 		if(student[i].regNumber == rNumber)
	 		{
	 			//
	 			//
	 			do
	 			{	
	 				cout << "Welcome " << student[i].name << " " << student[i].regNumber <<endl;
	 				int r1;
	 				cout << "5-ADD COURSE\n6-DELETE COURSE\n7-VIEW ACADEMIC RECORD\n8-VIEW TIME TABLE\n9-PRINT TIME TABLE\n0-LOGOUT\t:";
	 				cin >> r1;
	 				//cout << student[i].numberOfRegisteredCourses;
	 				//switch(r1)
	 				//case 5:
	 					if(r1==5)
	 				{
	 					cout << "TOTAL NUMBER OF COURSES:"<<nC << endl;
						cout << "CODE\tPREREQ\tFAC1\tSLOT\tSEATS1\tFAC2\tSLOT\tSEATS2\tCREDIT\tGRA-REQUIRED\n";
						i1=1;
						while(i1<=nC)
						{
	     					course[i1].courseDetails();
	     					i1++;
    					}
    					
    					string addCourse;
    					string slot;
    					cout << "COURSE YOU WANT TO ADD :";
    					cin >> addCourse;
    					cout << "SLOT(1/2) :";
    					cin >> slot;
    					
    					// COURSE ADDITION PROCESS SIMILAR TO INITIAL REGISTRATION
    					//check slot
    					if(slot == "1")
    					{
    						for(i1=1; i1<=nC; i1++)
    						{
    							if((addCourse==course[i1].courseCode) && (course[i1].seats1>=1) && (student[i].cgpa>=course[i1].cgpaRequired))
    							{
    								string theCourse = course[i1].courseCode;
    								//now check for prereq
    								{
    									for(i2=1; i2<=student[i].numberOfFinishedCourses ;i2++)
    									{
    										if(course[i1].coursePrerequisite == student[i].finishedCourses[i2])
    										{
    											cout << "COURSE " << addCourse << " REGISTERED SUCCESSFULLY!\n";
    											//cout << student[i].numberOfRegisteredCourses;
    											getch();
    											student[i].numberOfRegisteredCourses = student[i].numberOfRegisteredCourses +1;
    											student[i].registeredCourses[student[i].numberOfRegisteredCourses][1] = addCourse;
    											student[i].registeredCourses[student[i].numberOfRegisteredCourses][2] = "1";
    											//student[i].maxCredits = student[i].maxCredits + course[i2].credits;
    											student[i].maxCredits = student[i].maxCredits + course[i1].credits;
    											course[i1].takeCourse1();
    										}
    									}
    								}
    							}
    						}
    					}
    					
    					else
    					{
    						for(i1=1; i1<=nC; i1++)
    						{
    							if((addCourse==course[i1].courseCode) && (course[i1].seats1>=1) && (student[i].cgpa>=course[i1].cgpaRequired))
    							{
    								string theCourse = course[i1].courseCode;
    								//now check for prereq
    								{
    									for(i2=1; i2<=student[i].numberOfFinishedCourses ;i2++)
    									{
    										if(course[i1].coursePrerequisite == student[i].finishedCourses[i2])
    										{
    											cout << "COURSE " << addCourse << " REGISTERED SUCCESSFULLY!\n";
    											//cout << student[i].numberOfRegisteredCourses;
    											getch();
    											student[i].numberOfRegisteredCourses = student[i].numberOfRegisteredCourses + 1;
    											student[i].registeredCourses[student[i].numberOfRegisteredCourses][1] = addCourse;
    											student[i].registeredCourses[student[i].numberOfRegisteredCourses][2] = "2";
    											student[i].maxCredits = student[i].maxCredits + course[i1].credits;
    											course[i1].takeCourse2();
    										}
    									}
    								}
    							}
    						}
    					}
    			//	break;
    				}
    				
    				
    				//case 6:
    					else if(r1==6)
    					{
    						
    						cout << student[i].regNumber;
    						cout << "course delete:\n";
    						//cout << student[i].numberOfRegisteredCourses;
    						getch();
    							for(i2=1; i2<=student[i].numberOfRegisteredCourses; i2++)
    							{//cout << "q\n";
    								if(student[i].registeredCourses[i2][2]=="1")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											course[i3].showCourse1();
    										}
    									}
    								}
    								
    								else if(student[i].registeredCourses[i2][2]=="2")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											course[i3].showCourse2();
    										}
    									}
    								}
    							}
    							string deleteCourse;
    							cout << "enter course to delete :";
    							cin >> deleteCourse;
    							
    							i1 = 1;
    							while(student[i].registeredCourses[i1][1]!=deleteCourse)
    							{
    								i1++;
    							}
    							cout << student[i].registeredCourses[i1][1] <<"\n";
    							getch();
    							
    							//ADDING SEATS use 13,14,15
    							if(student[i].registeredCourses[i1][2]=="1")
    							{
    								i3=1;
    								while(course[i3].courseCode != deleteCourse)
    								{
    									i3++;
    								}
    								course[i3].dropCourse1();
    								student[i].maxCredits = student[i].maxCredits - course[i3].credits;
    							}
    							
    							else
    							{
    								i3=1;
    								while(course[i3].courseCode != deleteCourse)
    								{
    									i3++;
    								}
    								course[i3].dropCourse2();
    								student[i].maxCredits = student[i].maxCredits - course[i3].credits;
    							}
    							
    							
    							for(i2=i1; i2<=student[i].numberOfRegisteredCourses; i2++)
    							{
    								student[i].registeredCourses[i2][1] = student[i].registeredCourses[i2 +1][1];
    								student[i].registeredCourses[i2][2] = student[i].registeredCourses[i2 +1][2];
    							}
    							student[i].numberOfRegisteredCourses = student[i].numberOfRegisteredCourses-1;
    							//ADDING SEATS
    							cout<< "COURSE DELETION SUCCESSFUL\n";
    							
    							
    							//////test DELETE
    							/*for(i1=1; i1<=student[i].numberOfRegisteredCourses; i1++)
    							{
    								cout << student[i].registeredCourses[i1][1] <<" " <<student[i].registeredCourses[i1][2] << endl;
    							}*/
    						//break;
    					}
    					
    					else if(r1==7)
    					{
    						//academic record
    						
    						cout << endl << student[i].regNumber << endl;
    						cout << "COMPLETED COURSES: ";
    						for(i1=1; i1<=student[i].numberOfFinishedCourses; i1++)
    						{
    							cout << student[i].finishedCourses[i1] << " ";
    						}
    						cout << "CGPA: " << student[i].cgpa << endl;
    					}
    					
    					else if(r1 == 8)
    					{
    						//time table
    						cout << student[i].name << " " << student[i].regNumber << endl;
    						cout << "COURSE\tFACULTY\tSLOT\tCREDITS\n";
    						for(i2=1; i2<=student[i].numberOfRegisteredCourses; i2++)
    							{//cout << "q\n";
    								if(student[i].registeredCourses[i2][2]=="1")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											
    											course[i3].showCourse1();
    										}
    									}
    								}
    								
    								else if(student[i].registeredCourses[i2][2]=="2")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											course[i3].showCourse2();
    										}
    									}
    								}
    							}
    							cout << "TOTAL CREDITS = " << student[i].maxCredits << endl;
    					}
    					
    					else if(r1==9)
    					{
    						//print time table on txt
    						ofstream timeTable;
    						timeTable.open("YOUR TIME TABLE.txt");
    						
    						timeTable << student[i].name << " " << student[i].regNumber << endl;
    						timeTable << "COURSE\tFACULTY\tSLOT\tCREDITS\n";
    						for(i2=1; i2<=student[i].numberOfRegisteredCourses; i2++)
    							{//cout << "q\n";
    								if(student[i].registeredCourses[i2][2]=="1")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											
    											//course[i3].showCourse1();
    											timeTable << course[i3].courseCode <<"\t" << course[i3].faculty1 << "\t" << course[i3].slot1 << "\t" << course[i3].credits << endl; 
    										}
    									}
    								}
    								
    								else if(student[i].registeredCourses[i2][2]=="2")
    								{
    									for(i3=1;i3<=nC ; i3++)
    									{
    										if(student[i].registeredCourses[i2][1]==course[i3].courseCode)
    										{
    											//course[i3].showCourse2();
    											timeTable << course[i3].courseCode <<"\t" << course[i3].faculty2 << "\t" << course[i3].slot2 << "\t" << course[i3].credits << endl;
    										}
    									}
    								}
    							}
    							timeTable << "TOTAL CREDITS = " << student[i].maxCredits << endl;
    							
    							cout << "PLEASE COLLECT YOUR TIME TABLE\n";
    					}
    					
    					cout << "LOGOUT??";
    					cin >> response;
    					
    					
	 			}while(response=='n');
	 		}
	 		else
	 		{
	 		 cout << "NO RECORDS FOUND\n";
	 		}
	 	}
				break;
			}
			
			
}//for end of switch case
    //switchcase ends		
    }while(x<=4);// the brace is for do while
    
}//for int main()
