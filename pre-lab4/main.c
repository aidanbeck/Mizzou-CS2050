#include <stdio.h>
#include <stdlib.h>

/*
    Employee data type.
    Contains id, job type, & salary.
*/
typedef struct {
    int empID, jobType;
    float salary;
} Employee;

/*
    Take a record file and return the int located on the first line.
*/
int getRecordCount(FILE *records) {
    int size;
    fscanf(records, "%d", &size);
    return size;
}

/*
    Take an Employee array and return the empID of the Employee at [-1]
    This is where readEmployeeArray() stores the array size.
*/
int getArraySize(Employee *array) {
    return array[-1].empID;
}

/*
    Reads records file, creates array of Employees based on records,
    hides size in the empID of an Employee in index -1. (This is hacky! Will learn better practice.)
*/
Employee *readEmployeeArray(FILE *records) {

    int size = getRecordCount(records);
    Employee *array = malloc(   (size+1) * sizeof(Employee));

    //create employee who's id holds the array size.
    Employee sizeValue = {
        .empID = size
    };
    array[0] = sizeValue;
    array++; //hide employee in [-1]


    for (int i = 0; i < size; i++) {
        
        int newId, newJob; float newPay;
        fscanf(records, "%d %d %f", &newId, &newJob, &newPay);

        Employee newEmployee = {
            .empID = newId,
            .jobType = newJob,
            .salary = newPay
        };
        
        array[i] = newEmployee;
    }

    fclose(records);

    return array;
}

/*
    Frees Employee array memory.
*/
void freeArray(Employee *array) {
    free(array);
}

/*
    Loops employee array, returns Employee if one matches empID.
    If none do, returns null.
*/
Employee *getEmployeeByID(Employee *array, int empID) {

    int size = getArraySize(array);

    for (int i = 0; i < size; i++) {
        if (array[i].empID == empID) {
            return &array[i];
        }
    }
    
    return NULL;
}

/*
    Sets the salary of an employee with a specific ID.
    If successful, return 1. else, return 0.
*/
int setEmpSalary(Employee *array, int empID, float salary) {
    Employee *target = getEmployeeByID(array, empID);
    
    if (target) {
        target->salary = salary;
        return 1;
    }
    return 0;
}


/*
    Sets the float of an address to the salary of an employee with a specific ID.
    If successful, return 1. else, return 0.
*/
int getEmpSalary(Employee *array, int empID, float *salary) {
    Employee *target = getEmployeeByID(array, empID);
    
    if (target) {
        *salary = target->salary;
        return 1;
    }
    return 0;
}

/*
    Sets the job type of an employee with a specific ID.
    If successful, return 1. else, return 0.
*/
int setEmpJobType(Employee *array, int empID, int job) {
    Employee *target = getEmployeeByID(array, empID);
    
    if (target) {
        target->jobType = job;
        return 1;
    }
    
    return 0;
}

/*
    Sets the int of an address to the job type of an employee with a specific ID.
    If successful, return 1. else, return 0.
*/
int getEmpJobType(Employee *array, int empID, int *jobType) {
    Employee *target = getEmployeeByID(array, empID);
    
    if (target) {
        *jobType = target->jobType;
        return 1;
    }
    
    return 0;
}

int main() {
    
    FILE* records = fopen("records.txt", "r");
    Employee *array = readEmployeeArray(records);

    int set = setEmpJobType(array, 88, 9);
    int job;
    int get = getEmpJobType(array, 88, &job);

    printf("%d,%d,%d\n", set, get, job);

    return 0;
}