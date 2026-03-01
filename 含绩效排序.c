#include "salary.h"

sal* sort2(sal *p){
	if(p==NULL){
		printf("空链表\n");
		return NULL;
	}
	float real[100][2];
	//这里real[sum][0]存储的是节点位置；
	//real[sum][1]是教师工资（含绩效奖金） 
	int sum=0;	
	sal *head=p;	
	for(;p!=NULL;p=p->next){
	real[sum][0]=sum+1;
	real[sum][1]=p->real_salary;
	sum++; 
	} 
	if (sum >= 100) {
        printf("节点数超过100，无法处理\n");
        return head;
    }
	//选择排序 
	for(int i=0;i<sum-1;i++){
		int k=i;
		for(int j=i+1;j<sum;j++){  
			if(real[j][1]>real[k][1]){
				k=j;
			}
		}
		if(k!=i){
	float temp0 = real[i][0]; 
    float temp1 = real[i][1]; 
    real[i][0] = real[k][0];
    real[i][1] = real[k][1];
    real[k][0] = temp0;
    real[k][1] = temp1;
	}
}
	
	//用排序后的节点构建新链表 

for(int n=0;n<sum;n++){
	sal *temp=head;
	for(int j=0;j<real[n][0]-1;j++){
		temp=temp->next;
	}
	sal *temps=head;
	for(int j=0;j<n;j++){
		temps=temps->next;
	}
	if(temp != temps) {    /*若节点不同，交换数据*/ 
    float temp_ins = temps->insurance;
    float temp_net = temps->net_income;
    float temp_sal = temps->real_salary;
    float temp_tax = temps->tax_rate; 
    char temp_level = temps->level;
    char temp_name[100];
    strcpy(temp_name, temps->name);

    temps->insurance = temp->insurance;
    strcpy(temps->name, temp->name); 
    temps->level = temp->level;
    temps->net_income = temp->net_income;
    temps->real_salary = temp->real_salary;
    temps->tax_rate = temp->tax_rate;

    temp->insurance = temp_ins;
    strcpy(temp->name, temp_name); 
    temp->level = temp_level;
    temp->net_income = temp_net;
    temp->real_salary = temp_sal;
    temp->tax_rate = temp_tax;
}
}
return head;

}
	

