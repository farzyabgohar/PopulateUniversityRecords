

#include "stdio.h"
#include "stdlib.h"
#include "populateRecords.c"
#include "student.c"
#include "employee.c"

#define NUM_RECORDS 20

//takes no input. simply presents the menu options to the user and returns the selected option to main() for further processing
int menu(){
	int option;
	printf("Please pick one of the following options\n");
	printf("1.Print all employees\n2.Print all students\n3.Search students using Family Name\n4.Summary of Data\n0.Quit\n");
	scanf(" %d", &option);
	return option;
}


int main(int argc, char* argv[])
{
    struct person person[NUM_RECORDS];


    populateRecords(person, NUM_RECORDS); //populates the array person[] with NUM_RECORDS of people at carleton. Mix of student and employees
    
    _Bool quit; //indicator variable to determine if user picked the quit option
    unsigned short int selection; //selected menu option
    char yn; //stores "y" or "n" when user is asked if he's sure he wants to quit the program
    
    char nameToFind[16]; //stores the search term for finding student record by familyname
    
    int numRecords;
    int numStudents, numEmployees;
    
    unsigned short int minYears, maxYears;
    
    float totalGpa, totalCourses, totalTuition, totalYears, totalSalary;
    float averageGpa, averageCourses, averageTuition, averageYears, averageSalary;
  
    quit = 0; 
    //the loop will keep running until the user wants to quit. variables at the beginning of each iteration
    while (!quit)  {
    	totalGpa=0.0f; totalCourses=0.0f; totalTuition=0.0f; totalYears=0.0f; totalSalary=0.0f;
    	averageGpa=0.0f; averageCourses=0.0f; averageTuition=0.0f; averageYears=0.0f; averageSalary=0.0f;
    	numStudents = 0; numEmployees=0;
    	//needed a large initial value. I don't think anyone is going to be working for a company for 127 years
    	minYears=127; 
    	maxYears=0;
    	
    	selection = menu(); //calls the menu function to present the menu and determine the selected option
  		
		//based on the menu option selected, the program will either quit, print all employees, print all students, 		find a student by family name, or print a summary of all the records. If a valid menu option isn't selected, 			the user is told that he has entered an invalid selection and is presented with the menu again to pick a 			correct option
    	switch(selection){
    		case 0:
    			printf("Are you sure you want to proceed? (y/n)\n");
    			scanf(" %s", &yn);
    			if (!(strcmp(&yn, "y"))){
    				quit = 1;
    				break;
    			}
    			printf("\n");
    			break;
    		case 1:
    			printEmployees(person);
    			printf("\n");
    			break;
    		case 2:
    			printStudents(person);
    			printf("\n");
    			break;	
    		case 3:
    			printf("Enter Family Name: ");
    			scanf(" %s", nameToFind);
    			findStudent(person, nameToFind);
    			printf("\n");
    			break;
    		case 4:
    			numRecords = sizeof(person) / sizeof(person[0]);
    			printf("Total number of records: %2d\n\n", numRecords);
    		
    			for (int i=0;i<20;i++){
    				if (person[i].emplyeeOrStudent == 1){
    					//does all the tallying of the required data for students
    					numStudents+=1;
    					totalGpa += person[i].stu.gpa;
    					totalCourses+=person[i].stu.numCourses;
    					totalTuition+=person[i].stu.tuitionFees;
    				} else{
    					//does all the tallying of the required data for employees
    					numEmployees+=1;
    					totalYears+=person[i].emp.yearsService;
    					totalSalary+=person[i].emp.salary;
    				
    					if (person[i].emp.yearsService<minYears){
    						minYears=person[i].emp.yearsService;
    					}
    					if (person[i].emp.yearsService>maxYears){
    						maxYears=person[i].emp.yearsService;
    					}
    				}
    			}
    			
    				averageGpa = totalGpa/numStudents;
    				averageCourses = totalCourses/numStudents;
    				averageTuition = totalTuition/numStudents;
    				averageYears = totalYears/numEmployees;
    				averageSalary = totalSalary/numEmployees;
    			
    				printf("Student stats:\n\n");
    				printf("Number of Students: %d\n\n", numStudents);
    				printf("Average GPA: %1.2f, Average Number of courses: %1.2f, Average Tuition Fees: %1.2f\n\n", 					averageGpa, averageCourses, averageTuition);
    				printf("Employee Stats:\n\n");
    				printf("Number of employees: %-2d Min Level: %-2d Max Level: %d\n\n", numEmployees, minYears, 						maxYears);
    				printf("Average Years of Service: %1.2f, Average Salary: %1.2f\n\n", averageYears, 						averageSalary);
    			
    				break;
    			
    			default:
    				printf("Invalid option\n\n");
    		
    	}
  	}

    return 0;
}

