#include "salary.h"
void chart(sal *head,FILE *fp,int num){
	if(head==NULL ){
		printf("传入空指针");
		return;
	} 
	if(fp==NULL){
		printf("文件为空");
		return; 
	} 
	int i;
	fprintf(fp, "名字,纯收入,税率,五险一金,实际工资,绩效等级,绩效奖金\n");
	sal *current = head; 
	for(i=0;i<num && current!=NULL;i++){
		fprintf(fp, "%s,%.2f,%.2f,%.2f,%.2f,%c,%.2f\n", 
        current->name,          
        current->net_income,   
        current->tax_rate,     
        current->insurance,    
        current->real_salary,
        current->level,       
        current->bonus);       
		current = current->next;
	}
}
