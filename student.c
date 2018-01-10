#include "student.h"
#include <string.h>
#define FULL_NAME_LENGTH 30 //15 chars for firstname 15 chars for lastname

	
//function takes the array of structures containing the records of all people in carleton and prints the ones that are students. goes through each record to determine if it's a student record or not. If it is, then it prints the entire record in the required format
void printStudents(struct person *person){
	
	char fullName[FULL_NAME_LENGTH+1];
	for (int i=0;i<20;i++){
		if (person[i].emplyeeOrStudent == 1){
			
			sprintf(fullName,"%s %s", person[i].firstName, person[i].familyName);
			printf("%-33s GPA: %2u, Courses: %2u, Tuition: %8.2f\n", fullName, person[i].stu.gpa, person[i].stu.numCourses, person[i].stu.tuitionFees);
		}
	}
}

//takes as input the array of structures containing the records of all people in carleton, and the search term inputted by the user. Prints matching student records
void findStudent(struct person *person, char *familyName){
	_Bool match; //indicator variable for determining when a match is found
	_Bool flag; //if no match is found, flag remains 0 so the program can notify the user that no match was found
	char fullName[FULL_NAME_LENGTH+1]; //stores firstname + lastname
	
	//goes through all the records and only prints out students who have a matching lastname with the entered search term. The printed record matches the specified format in the assignment specifications
	for (int i=0;i<20;i++){
		if (person[i].emplyeeOrStudent == 1){
			match = strcmp(person[i].familyName, familyName);
			if (match == 0){
			sprintf(fullName,"%s %s", person[i].firstName, person[i].familyName);
			printf("%-33s GPA: %2u, Courses: %2u, Tuition: %8.2f\n", fullName, person[i].stu.gpa, person[i].stu.numCourses, person[i].stu.tuitionFees);
			flag = 1;
			}
		}
	}
	if (!flag){
		printf("No record found\n");
	}
}
