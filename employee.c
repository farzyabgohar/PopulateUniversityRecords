#include "employee.h"
#define FULL_NAME_LENGTH 30 //15 chars for firstname 15 chars for lastname


//takes as input the array of structures containing records of all people in carleton and only prints the ones that are employees
void printEmployees(struct person *person){
	for (int i=0;i<20;i++){
		if (person[i].emplyeeOrStudent == 0){
			char fullName[FULL_NAME_LENGTH+1];
			
			sprintf(fullName,"%s %s", person[i].firstName, person[i].familyName);
			printf("%-33s Years: %2u, Level: %2u, Salary: %9.2f\n", fullName, person[i].emp.yearsService, person[i].emp.level, person[i].emp.salary);
		}
	}
}
