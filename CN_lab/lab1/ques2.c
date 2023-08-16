#include<stdio.h>

struct dob{
    int day;
    int month;
    int year;
};
struct student_info{
    int roll;
    char name[50];
    float CGPA;
    struct dob age;
};
void fun(struct student_info s){
    printf("Name: ");
    puts(s.name);
    printf("Roll: %d\n",s.roll);
    printf("CGPA: %0.2f\n",s.CGPA);
    printf("Date of birth: %d-%d-%d\n",s.age.day,s.age.month,s.age.year);
}
void fun1(struct student_info *s){
    printf("\n\nName: ");
    puts(s->name);
    printf("Roll: %d\n",s->roll);
    printf("CGPA: %0.2f\n",s->CGPA);
    printf("Date of birth: %d-%d-%d\n",s->age.day,s->age.month,s->age.year);
}
int main(){
    struct student_info s={434,"Aditya",9.99,{99,99,9999}};

    fun(s);
    fun1(&s);
}