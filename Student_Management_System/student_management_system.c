//STUDENT DATA MANAGEMENT SYSTEM

#include <stdio.h>
#include <string.h>
void add_records();
void display_records();
void delete_records();
void update_records();
void search_records();
void search_name();
void search_roll();
void search_dept();
void search_year();

struct stud
{
    int rno,year;
    char name[50],dept[30],phone[15];
    float cgpa;
}s;

void main()
{
    int choice;
    void (*fptr[5])()={add_records,display_records,delete_records,update_records,search_records};
    printf("---STUDENT MANAGEMENT SYSTEM---\n");
    while (1)
    {
        printf("------------------");
        printf("\n---MENU--- \n1. Add records \n2. Display record \n3. Delete record \n4. Update records \n5. Search records \n6. Exit\n");
        printf("------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        if (choice>=6)
        {
            printf("Thank You!!");
            break;
        } 
        fptr[choice-1]();
    }
}

void add_records()
{
    printf("\nADD STUDENT RECORDS\n");
    FILE *fp;
    int n, i, rno,year;
    char name[50],dept[30],phone[15];
    float cgpa;
    fp=fopen("student.txt", "ab+");
    printf("Enter number of records: ");
    scanf("%d", &n);
    printf("Enter roll number, name, year, department, cgpa, phone number of %d students: \n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %s %d %s %f %s", &s.rno, s.name,&s.year, s.dept, &s.cgpa, s.phone);
        fwrite(&s, sizeof(s), 1, fp);
    }
    printf("Details added successfully!\n");
    fclose(fp);

}
void display_records()
{
    printf("\nSTUDENT RECORDS\n");
    FILE  *fp;
    int i=0;
    fp=fopen("student.txt","rb");
    while(fread(&s, sizeof(s), 1, fp))
    {
        printf("%d %s %d %s %.2f %s\n", s.rno, s.name,s.year, s.dept, s.cgpa, s.phone);
    }
    fclose(fp);
}

void delete_records()
{
    printf("\nDELETE STUDENT RECORDS\n");
    FILE *fp, *fp2;
    int roll, flag = 0;
    fp = fopen("student.txt", "rb");
    fp2 = fopen("temp.txt", "wb");
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.rno == roll)
        {
            flag = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, fp2);
    }
    fclose(fp);
    fclose(fp2);
    remove("student.txt");
    rename("temp.txt", "student.txt");
    if (flag==1)
        printf("Details deleted successfully!\n");
    else
        printf("Details not found!\n");
}
void update_records()
{
    printf("\nUPDATE STUDENT RECORDS\n");
    FILE *fp;
    int roll,flag=0;
    fp=fopen("student.txt","rb+");
    printf("Enter the roll number to update: ");
    scanf("%d",&roll);
    while(fread(&s, sizeof(s), 1, fp))    
    {
        if(s.rno==roll)
        {
            s.rno=roll;
            flag=1;
            printf("Enter name, year, department, cgpa, phone number of the student: \n");
            scanf("%s %d %s %f %s", s.name,&s.year, s.dept, &s.cgpa, s.phone);
            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            printf("Details updated successfully!\n");
            break;
        }
    } 
    if (flag==0)
        printf("Student roll number not found!\n");
    fclose(fp);
}
void search_records()
{
    int c;
    printf("\nSEARCH STUDENT RECORDS\n");
    printf("Search students by \n1. Name \n2. Roll number \n3. Department \n4. Year \nEnter your choice: ");
    scanf("%d",&c);
    if (c==1)
        search_name();
    else if (c==2)
        search_roll();
    else if (c==3)
        search_dept();
    else if (c==4)
        search_year();           
}
void search_name()
{
    printf("\nSEARCH STUDENT RECORD BY NAME\n");
    char name[50];
    FILE *fp;
    int flag=0;
    fp=fopen("student.txt","rb+");
    printf("Enter the name to search: ");
    scanf("%s",name);
    while(fread(&s, sizeof(s), 1, fp))    
        {
            if(strcmp(s.name,name)==0)
            {
                flag=1;
                printf("Roll no: %d \nName: %s \nYear: %d \nDepartment: %s \nCGPA: %.2f \nPhone: %s\n", s.rno, s.name,s.year, s.dept, s.cgpa, s.phone);
                break;
            } 
        } 
    if (flag==0)
        printf("Student roll number not found!\n");
    fclose(fp);
}
void search_roll()
{ 
    printf("\nSEARCH STUDENT RECORD BY ROLL NUMBER\n");
    FILE *fp;
    int roll,flag=0;
    fp=fopen("student.txt","rb+");
    printf("Enter the roll number to search: ");
    scanf("%d",&roll);
    while(fread(&s, sizeof(s), 1, fp))    
        {
            if(s.rno==roll)
            {
                flag=1;
                printf("Roll no: %d \nName: %s \nYear: %d \nDepartment: %s \nCGPA: %.2f \nPhone: %s\n", s.rno, s.name,s.year, s.dept, s.cgpa, s.phone);
                break;
            } 
        }
    if (flag==0)
        printf("Student roll number not found!\n");
    fclose(fp);
}
void search_dept()
{
    printf("\nSEARCH STUDENTS BY DEPARTMENT\n");
    FILE *fp;
    char dept[30];
    int flag= 0,count=0;
    fp = fopen("student.txt","rb");
    printf("Enter the department: ");
    scanf("%s", dept);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.dept, dept)==0)
        {
            printf("%d %s %d %.2f %s\n", s.rno, s.name, s.year, s.cgpa, s.phone);
            count++;
        }
    }
    printf("\nTotal students in %s = %d\n",dept,count);
    fclose(fp);
}
void search_year()
{
    printf("\nSEARCH STUDENTS BY YEAR\n");
    FILE *fp;
    int year,flag= 0,count=0;
    fp = fopen("student.txt","rb");
    printf("Enter the year: ");
    scanf("%d", &year);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(s.year==year)
        {
            printf("%d %s %s %.2f %s\n", s.rno, s.name, s.dept, s.cgpa, s.phone);
            count++;
        }
    }
    printf("\nTotal students in year %d = %d\n",year,count);
    fclose(fp);
}