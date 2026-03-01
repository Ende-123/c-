#ifndef SALARY_H
#define SALARY_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct teacher{
	char name[30]; 
    float net_income;    
    float tax_rate;     
    float insurance;    
    float real_salary;
    int work_days;
    int attendance;
    char level; 
    float bonus;         
	struct teacher *next;   
} sal;

float calcRealSalary(sal *p);  //计算实际工资函数 
void chart(sal *head,FILE *fp,int num);   //建立表格函数 
void sortSalaryList(sal *p,FILE *fp);    //排序函数 
void getPerformance(sal *p);   //绩效函数 
sal* sort2(sal *p);   //含绩效排序函数 

#endif // SALARY_H
