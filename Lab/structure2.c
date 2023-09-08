#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char course[20];
    int marks;
} grade;

typedef struct
{
    char name[30], program[10];
    int roll, num_courses;
    grade *grades;
} student;

int main()
{
    int num_students;
    scanf("%d", &num_students);

    student *students;
    students = (student *) malloc (num_students * sizeof(student));
    if (students == NULL)
    {
        return 1;
    }

    // char *name1, *program1;
    // int roll1, num_courses1;

    for (int i = 0; i < num_students; i++)
    {
        scanf("%s%s%d%d", students[i].name, students[i].program, &students[i].roll, &students[i].num_courses);
        students[i].grades = (grade *) malloc (students[i].num_courses * sizeof(grade));
        // char *courses[students[i].num_courses];
        
        for(int j = 0; j < students[i].num_courses; j++)
        {
            scanf("%s%d", students[i].grades[j].course, &students[i].grades[j].marks);
        }
    }

    // 
    
    for (int i = 0; i < num_students; i++)
    {
        printf("Name: %s, Program: %s,Roll:  %d ", students[i].name, students[i].program, students[i].roll);
        printf("Marks: ");
        for(int j = 0; j < students[i].num_courses; j++)
        {
            printf("%s: %d ", students[i].grades[j].course, students[i].grades[j].marks);
        }
        printf("\n");
    }
}
