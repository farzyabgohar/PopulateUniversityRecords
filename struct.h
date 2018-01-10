#define NAME_SIZE 15
#define NUM_LENGTH 10

//structures for student and employee data
struct student {
	unsigned short int gpa : 4;
	unsigned short int numCourses : 6;
	float tuitionFees;
}student;

struct employee{
	float salary;
	unsigned short int yearsService : 6;
	unsigned short int level : 4;
}employee;

struct person {
	char firstName[NAME_SIZE+1]; 
	char familyName[NAME_SIZE+1];
	unsigned char telephoneNumber[NUM_LENGTH+1];
	unsigned char emplyeeOrStudent : 1;
	union {
		struct student stu;
		struct employee emp;
	};
} person[20]; //populates the array person[] with records of 20 people
