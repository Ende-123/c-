#include "salary.h"
void sortSalaryList(sal *p,FILE *fp){
    
    if(p == NULL || p->next == NULL) {
        printf("单节点/空链表，无需排序\n");
        fprintf(fp,"单节点/空链表，无需排序"); 
        return;  
    }
    
    sal *i, *j;
    float temp;  
    char temp_name[30];  
    
    for(i = p; i->next != NULL; i = i->next){
        for(j = p; j->next != NULL; j = j->next){
            if(j->real_salary < j->next->real_salary){
               
                strcpy(temp_name, j->name);
                strcpy(j->name, j->next->name);
                strcpy(j->next->name, temp_name);
                
                temp = j->net_income;
                j->net_income = j->next->net_income;
                j->next->net_income = temp;
                
                temp = j->tax_rate;
                j->tax_rate = j->next->tax_rate;
                j->next->tax_rate = temp;
                
                temp = j->insurance;
                j->insurance = j->next->insurance;
                j->next->insurance = temp;
                
                temp = j->real_salary;
                j->real_salary = j->next->real_salary;
                j->next->real_salary = temp;
            }
        }
    }
}
