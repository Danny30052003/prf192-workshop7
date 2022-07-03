#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
const int MAX = 100;
int addValue = 0;
char studentName[MAX][30];
char studentNameSort[MAX][30];
//MODULE
void showMenu();
void addStudent(char studentName[][30]);
void removeStudent(char studentName[][30]);
void searchStudent(char studentName[][30]);
void sortStudent(char studentName[][30]);
void printSortList(char studentNameSort[][30]);
int findStudentIndex(char studentName[][30], char key[]);
void capital(char studentName[][30]);
void removeExtraBlank(char studentName[][30]);

int main() {
    int option;
    showMenu();
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Selected 1!\n");
            addStudent(studentName);
            main();
            break;
        case 2:
            printf("Selected 2!\n");
            removeStudent(studentName);
            main();
            break;
        case 3:
            printf("Selected 3!\n");
            searchStudent(studentName);
            main();
            break;
        case 4:
            printf("Selected 4!\n");
            sortStudent(studentName);
            printSortList(studentNameSort);
            main();
            break;
        case 5:
            printf("Quitted!\n\n");
            break;
        default:
            printf("%d is not an option, please try again!\n", option);
            main();
            break;
    }
}

void showMenu() {
    printf("-------------\n");
    printf("1 - Add a student\n");
    printf("2 - Remove a student\n");
    printf("3 - Search a student\n");
    printf("4 - Print student in ascending order list\n");
    printf("5 - Quit\n");
    printf("-------------\n");
}

void addStudent(char studentName[][30]) {
    int numberOfStudent;
    printf("\nCurrent: %d students in the list\n", addValue);
    printf("How many more student to you want to add? ");
    scanf("%d", &numberOfStudent);
    printf("ADDING LIST:\n");
    for(int i = 0; i <= numberOfStudent-1; i++) {
        fflush(stdin);
        printf("%d/ ", addValue+1);
        gets(studentName[addValue]);
        addValue++;
        removeExtraBlank(studentName);
    }
    printf("\nAdded %d student to the list!\n\n", numberOfStudent);
    capital(studentName);
}

void removeStudent(char studentName[][30]) {
    char removeName[30];
    if(addValue == 0) {
        printf("\nThere is nothing to remove!\n\n");
        main();
    }
    fflush(stdin);
    printf("\nEnter name to remove: ");
    gets(removeName);
    for(int a = 0; a <= 30; a++) {
        removeName[a] = toupper(removeName[a]);
    }
    int pos = findStudentIndex(studentName, removeName);
    if(pos >= 0) {
        for(int i = pos; i < addValue; i++) {
            strcpy(studentName[i], studentName[i+1]);
        }
        addValue--;
        printf("Student %s have been removed!\n\n", removeName);
    }
}

void searchStudent(char studentName[][30]) {
    if(addValue == 0) {
        printf("\nThere is no student in the list to search!\n\n");
        main();
    }
    char key[30];
    fflush(stdin);
    printf("Enter name to search: ");
    gets(key);
    for(int a = 0; a <= 30; a++) {
        key[a] = toupper(key[a]);
    }
    sortStudent(studentName);
    int pos = findStudentIndex(studentName, key);
    int pos2 = findStudentIndex(studentNameSort, key);
    if(pos >= 0) {
        printf("\nStudent %s have position %d in the Adding list!", key, pos+1);
        printf("\nStudent %s have position %d in the Ascending list!\n\n", key, pos2+1);
    } else {
        printf("Student not exist!\n\n");
    }
}

void sortStudent(char studentName[][30]) {
    if(addValue == 0) {
        printf("\nThere is no student in the list to print!\n\n");
        main();
    }
    int i, j, minIndex;
    char t[31];
    for(i = 0; i < addValue; i++) {
        strcpy(studentNameSort[i], studentName[i]);
    }
    for(i = 0; i < addValue - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < addValue; j++) {
            if(strcmp(studentNameSort[minIndex], studentNameSort[j]) > 0) minIndex = j;
            if(minIndex > i) {
                strcpy(t, studentNameSort[minIndex]);
                strcpy(studentNameSort[minIndex], studentNameSort[i]);
                strcpy(studentNameSort[i], t);
            }
        }
    }
}
void printSortList(char studentNameSort[][30]) {
    printf("\nASCENDING LIST:\n");
    for(int i = 0; i < addValue; i++) {
        printf("%d/ %s\n", i+1, studentNameSort[i]);
    }
    printf("\n");
}

int findStudentIndex(char studentName[][30], char key[]) {
    int i;
    for(int i = 0; i < addValue; i++) {
        if(strcmp(studentName[i], key) == 0) {
            return i;
        } 
    }
    return -1;
}

void capital(char studentName[][30]) { 
    for(int j = 0; j < addValue; j++) {
        int len = strlen(studentName[j]);
        char tmp[MAX]; 
        strcpy(tmp,studentName[j]);
        for(int i=0; i<=len-1;i++) { 
            tmp[i]=toupper(tmp[i]);
        }
        strcpy(studentName[j], tmp); 
    }
}

void removeExtraBlank(char studentName[][30]) {
    char tmp[30];
    int len = strlen(studentName[addValue-1]);
    strcpy(tmp, studentName[addValue-1]);
    for(int i = 0; i <= len; i++) {
        if(tmp[0] == ' ') {
            for(int j = 0; j <= len; j++) {
                tmp[j] = tmp[j+1];
            }
        }
        if(tmp[i] == ' ' && tmp[i+1] == ' ') {
            for(int a = i + 1; a <= len; a++) {
                tmp[a] = tmp[a+1];
            }
        }
    }
    strcpy(studentName[addValue-1], tmp);
}
