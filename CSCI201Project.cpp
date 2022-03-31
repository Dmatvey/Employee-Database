//Dennis Matveyev
//CSCI201 Project
//Human Resources Management
//Purpose: This program is a database of employees that include thier Name, hours worked per week, pay per hour
//and deduction. Annual salary is calculated based off that info. The program prompts user to Add new employee, delete
//employee, update employee or search for an employee.
//
//Classes:
//	Employee: Includes the private members employee Id, First name, last name, working hours, cost per hour and deduction and annual salary
//			  Public functions include the get and set functions
//	HRM: Includes the private members array of employees, and amount of employees
//       Public functions include addEmployee(), deleteEmployee(), updateEmployee(), and searchEmployee().

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Employee ID initialized at 1000 globally
int empID=1000;
//Number of employees
int count=0;
//Class Employee
class Employee
{
	//Private memebers for class Employee
	private:
		int employeeID;
		string firstName;
		string lastName;
		float workingHours;
		float costPerHour;
		float deduction;
		double annualSalary;
	//Public get and set functions
	public:
		Employee();
		void setEmployeeID(int=0);
		int getEmployeeID();
		void setFirstName(string);
		string getFirstName();
		void setLastName(string);
		string getLastName();
		void setWorkingHours(float);
		float getWorkingHours();
		void setCostPerHour(float);
		float getCostPerHour();
		void setDeduction(float);
		float getDeduction();
		void setAnnualSalary(float,float,float);
		double getAnnualSalary();
};

//Class HRM
class HRM
{
	//Private members including array of class employee objects of 100
	//and number of employees
	private:
		Employee emp[100];
		int count;
	//Public functions for modify employee objects
	public:
		static int addEmployee(Employee*, int);
		static void deleteEmployee(Employee*, int);
		static void updateEmployee(Employee*, int);
		static void searchEmployee(Employee*, int);
};
//Default constructor for class Employee
Employee::Employee()
{
		employeeID=0;
		firstName="?";
		lastName="?";
		workingHours=0;
		costPerHour=0;
		deduction=0;
		annualSalary=0;
};
//Function for setting employee id.
void Employee::setEmployeeID(int id)
{
	//If Parameter -1 is passed, employeeID is set to -1 for deletion
	if(id==-1)
		employeeID=-1;
	//If parameter 0 is passed then new employee ID is created using empID.
	else if(id==0)
		employeeID=empID;
	//If all other parameters are passed then private member is set to that value
	else
		employeeID=id;
};

//Function for returning private member employeeID
int Employee::getEmployeeID()
{
	return employeeID;
};

//Private member firstName is set to parameter fn
void Employee::setFirstName(string fn)
{
	firstName=fn;
};

//set functions used for returning private member firstName
string Employee::getFirstName()
{
	return firstName;
};

//Private member lastName is set to parameter ln
void Employee::setLastName(string ln)
{
	lastName=ln;
};

//set function used for returning private member lastName
string Employee::getLastName()
{
	return lastName;
};

//Private member workingHours is set to parameter h
void Employee::setWorkingHours(float h)
{
	workingHours=h;
};
//Get function used for returning private member workingHours
float Employee::getWorkingHours()
{
	return workingHours;
};

//Private member costPerHour is set to parameter w
void Employee::setCostPerHour(float w)
{
	costPerHour=w;
};

//Get function used for returning private member costPerHour
float Employee::getCostPerHour()
{
	return costPerHour;
};

//Private member deduction is set to parameter d
void Employee::setDeduction(float d)
{
	deduction=d;
};

//Get function used for returning private member deduction
float Employee::getDeduction()
{
	return deduction;
};

//Private member annualSalary set to paramters (h*w-d)*52.
void Employee::setAnnualSalary(float h,float w,float d)
{
	annualSalary=(h*w-d)*52;
};

//Get Function used for returing private member annualSalary.
double Employee::getAnnualSalary()
{
	return annualSalary;
};

//function used for display menu for user
void menu()
{
	
	cout<<"\n      Main Menu";
	cout<<"\n----------------------";
	cout<<"\n1.Add New Employee.";
	cout<<"\n2.Delete an Employee.";
	cout<<"\n3.Update Employee Information.";
	cout<<"\n4.Search for an Employee.";
	cout<<"\n5.Quit.";
	cout<<"\nPlease enter your choice 1..5 :";
};

//Function addEmployee with parameters emp[], and count passed
int HRM::addEmployee(Employee emp[], int count)
{
	//Argument variables declared 
	string fn,ln;
	float h, w,d;
	//Char variable declared here
	char ch='y';
	
	do
	{
		//When Add employee is selected empID is incremented by 1 and count
		empID++;
		count++;
		//New employee ID is created
		emp[count].setEmployeeID(0);
		//Program prompts user to enter Employee first name then set function is called to set
		//parameter to new private member of new employee
		cout<<"Please Enter the First Name of an Employee : ";
		cin>>fn;
		emp[count].setFirstName(fn);
		//Program prompts user to enter Employee last name then set function is called to set
		//parameter to new private member of new employee
		cout<<"Please Enter the Last Name of an Employee : ";
		cin>>ln;
		emp[count].setLastName(ln);
		//Do while loop used for input validation
		do
		{
			//Program prompts user to enter Employee working hours then set function is called to set
			//parameter to new private member of new employee
			cout<<"How many hours a week is his/her work? 1..60 : ";
			cin>>h;
			//While loop used to check for integer values for user input
			while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> h;
    		}
			//If input numbers are valid paramter is passed to set function for private member
			if((h>=0) && (h<=60))
				emp[count].setWorkingHours(h);
			//If value is incorrect program displays error message
			else
				cout<<"Wrong value for working hours .. please enter valid value\n";
		}while(!((h>=0) && (h<=60)));
		//Do while loop used for input validation
		do
		{
			//Program prompts user to enter Employee pay per hour then set function is called to set
			//parameter to new private member of new employee
			cout<<"How Much per Hour is His/Her Work? Cannot be negtive: ";
			cin>>w;
			//While loop used to check for integer values for user input
			while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> w;
    		}
			//If input numbers are valid paramter is passed to set function for private member
			if(w>=0)
				emp[count].setCostPerHour(w);
			//If value is incorrect program displays error message
			else
				cout<<"Wrong value for cost per hour .. please enter valid value\n";
		}while(!(w>=0));
		//Do while loop used for input validation
		do
		{
			//Program prompts user to enter Employee deduction then set function is called to set
			//parameter to new private member of new employee
			cout<<"How Much Total Deduction? Cannot be negative: ";
			cin>>d;
			//While loop used to check for integer values for user input
			while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> d;
    		}
			//If input numbers are valid paramter is passed to set function for private member
			if(d>=0)
				emp[count].setDeduction(d);
			//If value is incorrect program displays error message
			else
				cout<<"Wrong value for Deduction .. please enter valid value\n";
		}while(!(d>=0));
		//Annual Salary is recalculated based of the inputs for hours, pay and deduction
		emp[count].setAnnualSalary(h,w,d);
		//Program displays New employee info
		cout<<"The employee with the following information has been added to the system :\n";
		cout<<"Employee ID\tFirst Name\tLast Name\tSalary per year ($)"<<endl;
		cout<<"--------------- --------------- --------------- ----------------"<<endl;
		cout<<emp[count].getEmployeeID()<<"\t\t"<<emp[count].getFirstName()<<"\t\t"<<emp[count].getLastName()<<"\t"<< emp[count].getAnnualSalary()<<endl;
		//Program prompts if the want to add another employee
		cout<<"Do you want to add another employee (y/n)?";
		cin>>ch;
	}while(ch=='y');
	return count;
};

//This Function is used for deleting an employee with array emp and count passed as parameters.
void HRM::deleteEmployee(Employee emp[], int count)
{
	//Variable id declared for paramter
	int id;
	//variable used to mark location of found ID
	int loc=-1;
	//Bool flag used to determine if id found or not
	bool idFound=0;
	//Variable used when prompting user if they are sure they want to delete
	char del = 'n';
	//Variable used when prompting user if they want to delete another employee
	char choice = 'y';
	//Variable used when ID not found and prompt user if the want to search again
	char wrongchoice = 'y';
	do
	{
		do
		{
			//Program prompts user to input Id for deletion
			cout<<"Enter Employee ID Number that you want to Delete: ";
			cin>>id;
			//Input validation making sure only number is entered
			while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> id;
    		}
			//If input is valid, for loop is used to search for ID in database
			for(int i=0;i<=count;i++)
			{
				//IF Id is found employee info displayed
				if(emp[i].getEmployeeID()==id)
				{
					cout<<"Employee Information :\n";
					cout<<"Employee ID\tFirst Name\tLast Name\tAnnual Salary ($)";
					cout<<"--------------- --------------- --------------- ---------------"<<endl;
					cout<<emp[i].getEmployeeID()<<"\t\t"<<emp[i].getFirstName()<<"\t\t"<<emp[i].getLastName()<<"\t"<< emp[i].getAnnualSalary();
					//Location of employee in array is marked
					loc=i;
					//Bool flag idFound set to true
					idFound = 1;
					//Wrongchoice set to n to exit nested for loop
					wrongchoice='n';
				}
			}
			//If id is not found message displayed and prompts user to search again.
			if(!idFound)
			{
					cout<<"Sorry, There is not an employee with this ID."<<endl<<endl;
					cout<<"Do you want to repeat delete by entering new employee ID (y/n)?";
					cin>>wrongchoice;
			}
		//While wrongchoice is yes, program continues searching for id
		}while(wrongchoice=='y');
		//If id is not found, and the user does not want to search again then break statement exits out of loop to go back to main menu
		if(((!(wrongchoice=='y'))&& idFound==0))
		{
			break;
		}
		//if id is found program prompts user to confirm if they are sure they want the id to bee deleted
		cout<<"\nAre you sure you want to delete Employee "<<emp[loc].getFirstName()<<" "<<emp[loc].getLastName()<<"?  (y/n): ";
		cin>>del;
		//If user says y then employee is deleted
		if (del=='y')
		{
			cout<<"\nThe employee "<<emp[loc].getFirstName()<<" "<<emp[loc].getLastName()<<" has been deleted. "<<endl;
			emp[loc].setEmployeeID(-1);
		}
		//Program prompts user to decide if they want to delete another employee
		cout<<"Do you want to repeat delete by entering another employee? (y/n):  ";
		cin>>choice;
	}while(choice=='y');
};

//Function is used for updating employee info with emp and count passed as parameters
void HRM::updateEmployee(Employee emp[], int count)
{
 	//Variables declared for paramters passed to set functions
	 int id;
 	string fn,ln;
	int h;
	float w,d;
	//Bool flag used if id is found or not
	bool idFound=0;
	//variable used for marking location of found id
	int locId=0;
	//Char variable used for searching another id
	char choice = 'y';
	//Char variable used for repeating search if id not found
	char repeatsearch= 'y';
	do
	{
		do
		{
			//Program prompts user to enter employee id for update
			cout<<"Enter Employee ID Number that you want to update: ";
			cin>>id;
			//Input validation used to make sure only a number is entered
			while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> id;
    		}
			//For loop searches for ID
			for(int i=0;i<=count;i++)
			{
				//If found employee info is displayed
				if(emp[i].getEmployeeID()==id)
				{
					cout<<"\nEmployee Information :\n";
					cout<<"Employee ID\tFirst Name\tLast Name\tSalary per year ($)"<<endl;
					cout<<"--------------- --------------- --------------- ----------------"<<endl;
					cout<<emp[count].getEmployeeID()<<"\t\t"<<emp[count].getFirstName()<<"\t\t"<<emp[count].getLastName()<<"\t"<< emp[count].getAnnualSalary()<<endl;
					//location if emp in array is marked
					locId=i;
					//idFound set to ture
					idFound = 1;
					break;
				}
			}
			//If id not found, program prompts user to choose if they want to search again
			if(!idFound)
			{
					cout<<"No such Employee found in the system.\n";
					cout<<"Do you want to repeat update by searching for another employee(y/n)? ";
					cin>>repeatsearch;
					
			}
		//If if is not found and user wants to search again, loop repeats	
		}while(!idFound && repeatsearch=='y');
		//if id not found and user does not want to search again the break statement exits loop
		if(!(repeatsearch=='y'))
		{
			break;
		}
		//If id is found program prompts user to choose which field to update using a switch case
		int ch;
		do
		{
			cout<<"\n\nWhich Employee field do you want to update? "<<endl;
			cout<<"\n----------------------";
			cout<<"\n1.First Name.";
			cout<<"\n2.Last Name.";
			cout<<"\n3.Hours Worked.";
			cout<<"\n4.Cost Per Hour.";
			cout<<"\n5.Deduction.";
			cout<<"\n6.Quit.";
			cout<<"\nPlease enter your choice 1..6 :";
			cin>>ch;
			//User input is checked to make sure only a number is entered
			while(cin.fail()) 
			{
	    		cout << "Error! Not a number, Please try again:";
	    		cin.clear();
	    		cin.ignore(256,'\n');
	    		cin >> ch;
			}
			switch (ch)
			{
				//Switch cases display which field to upated based on options chosen
				//Enter employee new first name
				case 1: cout<<"Enter Employee First Name : ";
						cin>>fn;
						emp[locId].setFirstName(fn); 
						break;
				//Enter employee new last name
				case 2: cout<<"Enter Employee Last Name : ";
						cin>>ln;
						emp[locId].setLastName(ln); 
						break;
				//Enter employee new hours a week worked with user input validation
				case 3: do
						{
							cout<<"How many hours a week is his/her work? 1..60 : ";
							cin>>h;
							while(cin.fail()) 
							{
				        		cout << "Error! Not an number, Please try again:";
				        		cin.clear();
				        		cin.ignore(256,'\n');
				        		cin >> h;
				    		}
							if((h>=0) && (h<=60))
								emp[locId].setWorkingHours(h);
							else
								cout<<"Wrong value for working hours .. please enter valid value\n";
						}while(!((h>=0) && (h<=60)));
						//New employee salary calculated 
						emp[locId].setAnnualSalary(emp[locId].getWorkingHours(),emp[locId].getCostPerHour(),emp[locId].getDeduction());
						break;
				//Enter employees new cost per hour with user input validation
				case 4: do
						{
							cout<<"What is the cost per hour? Cannot be negtive: ";
							cin>>w;
							while(cin.fail()) 
							{
				        		cout << "Error! Not an number, Please try again:";
				        		cin.clear();
				        		cin.ignore(256,'\n');
				        		cin >> w;
				    		}
							if(w>=0)
								emp[locId].setCostPerHour(w);
							else
								cout<<"Wrong value for cost per hour .. please enter valid value\n";
						}while(!(w>=0));
						//New employee salary calculated 
						emp[locId].setAnnualSalary(emp[locId].getWorkingHours(),emp[locId].getCostPerHour(),emp[locId].getDeduction()); 
						break;
				//Enter employees new deduction wiht user input validation
				case 5: do
						{
							cout<<"What is the Deduction? Cannot be negative: ";
							cin>>d;
							while(cin.fail()) 
							{
				        		cout << "Error! Not an number, Please try again:";
				        		cin.clear();
				        		cin.ignore(256,'\n');
				        		cin >> d;
				    		}
							if(d>=0)
								emp[locId].setDeduction(d);
							else
								cout<<"Wrong value for Deduction .. please enter valid value\n";
						}while(!(d>=0));
						//New employee salary calculated 
						emp[locId].setAnnualSalary(emp[locId].getWorkingHours(),emp[locId].getCostPerHour(),emp[locId].getDeduction()); 
						break;
				case 6: break;
				default: cout<<"Wrong Choice !\n";
			}
			
		}while (!(ch==6));
		cout<<"The information for "<<emp[locId].getFirstName()<<" "<<emp[locId].getLastName()<<" has been updated."<<endl;
		cout<<"Do you want to update another Employee (y/n)? ";
		cin>>choice;
	}while(choice=='y');
};
//Function used to search and display employee with emp and count passed as parameters
void HRM::searchEmployee(Employee emp[], int count)
{
	//Variable for employee id
	int id;
	//Variable for repeating search
	char choice = 'y';
	//Bool flag used if id found or not
	bool idFound=0;
	do
	{
		//Program prompts user to input id that is searched
		cout<<"Enter Employee ID Number: ";
		cin>>id;
		//Input validation for numbers
		while(cin.fail()) 
			{
        		cout << "Error! Not a number, Please try again:";
        		cin.clear();
        		cin.ignore(256,'\n');
        		cin >> id;
    		}
		//For loop used to location ID
		for(int i=0;i<=count;i++)
		{
			//IF found, employee info is displayed
			if(emp[i].getEmployeeID()==id)
			{
				cout<<"\nEmployee Information :\n";
				cout<<"Employee ID\tFirst Name\tLast Name\tSalary per year ($)"<<endl;
				cout<<"--------------- --------------- --------------- ----------------"<<endl;
				cout<<emp[i].getEmployeeID()<<"\t\t"<<emp[i].getFirstName()<<"\t\t"<<emp[i].getLastName()<<"\t"<< emp[i].getAnnualSalary()<<endl;
				idFound=1;
				break;
			}
		}
		//If not found, program displays error
		if(idFound==0)
		{
			cout<<"No such Employee found in the system.";
		}
		//Program prompts user to do a new search
		cout<<"\nDo you want to do a new search (y/n)? ";
		cin>>choice;
		idFound=0;
	}while(choice=='y');
};

int main()
{
	//Array of classes objects emp created 100
	Employee emp[100];
	//Employee info is read into the array from File employee.txt
	ifstream infile;
	//Parameter variables declared
	int i=0,count=-1;
	int id;
	string fn,ln;
	float h,w,d;
	infile.open("employee.txt");
	//While loop reads in fields until end of file
	while(infile >> id >> fn >> ln >> h >> w >> d)
	{
		count++;
		emp[i].setEmployeeID(id);
		emp[i].setFirstName(fn);
		emp[i].setLastName(ln);
		emp[i].setWorkingHours(h);
		emp[i].setCostPerHour(w);
		emp[i].setDeduction(d);
		emp[i].setAnnualSalary(h,w,d);
		//Iteration +1 for array
		i++;
		//empID is iterated by 1
		empID++;
		//Program error displays if 100 employees are reached
		if(count==100)
			cout<<"You cannot add more Employees the array is full.\n";
	}
	//File is closed
	infile.close();
	int choice=0;

	do
	{
		//Do while loop displays menu for options in changing employees or adding
		menu();
		cin>>choice;
		//User input used in ensure a number is enter
		while(cin.fail()) 
		{
    		cout << "Error! Not a number, Please try again:";
    		cin.clear();
    		cin.ignore(256,'\n');
    		cin >> choice;
		}
		//Switch case for user input for changing employee info or adding
		switch (choice)
		{
			case 1: count=HRM::addEmployee(emp,count);break;
			case 2: HRM::deleteEmployee(emp,count); break;
			case 3: HRM::updateEmployee(emp,count); break;
			case 4: HRM::searchEmployee(emp,count); break;
			case 5: break;
			default: cout<<"Wrong Choice !\n";
			break;
		}

 	}while(!(choice==5));
 	//File employee.txt is opened to output employee info in to file and overwrite previous data
	ofstream outfile;
	outfile.open("employee.txt");
	for(int i=0;i<=count;i++)
	{
		if (emp[i].getEmployeeID()!=-1)
		{
			outfile<<emp[i].getEmployeeID()<<" ";
			outfile<<emp[i].getFirstName()<<" ";
			outfile<<emp[i].getLastName()<<" ";
			outfile<<emp[i].getWorkingHours()<<" ";
			outfile<<emp[i].getCostPerHour()<<" ";
			outfile<<emp[i].getDeduction()<<"\n";
		}
	}
	outfile.close();
	return 0;
}
