#include "salary.h"
void freeSalaryList(sal *head) {
    sal *temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); 
    }
}

int main(){
	int num;
	printf("请输入老师人数：");
	scanf("%d",&num);
	sal *head=NULL;
	sal *tail=NULL; 
	if(num<=0){
		printf("错误输入");
		freeSalaryList(head);
		return  0; 
	}
	int i=0;
	for(i=0;i<num;i++){
		printf("请输入第%d个老师的信息：\n",i+1);
		sal *p=(sal *)malloc(sizeof(sal));
		if(p==NULL){
			printf("分配失败");
			return 1; 
		}
		printf("姓名：");
		scanf("%s",p->name);
		printf("纯收入：");
		scanf("%f",&p->net_income);
		printf("税率：");
		scanf("%f",&p->tax_rate);
		printf("五险一金：");
		scanf("%f",&p->insurance);
		float salary=calcRealSalary(p);  //计算实际工资函数 
		p->real_salary=salary; 
		p->next=NULL; 
		p->level='e';
		p->bonus=0;
		
		if(head==NULL){
			head=p;
			tail=p;
		}else{
			tail->next=p;
			tail=p;
	}		
	}
	printf("正在写入表格……\n"); 
	FILE *fp=fopen("salary_chart.csv","w");
	if(fp==NULL){
		printf("文件打开失败");
		exit(1);
	}
	chart(head,fp,num);    //建立表格函数 
	
	sortSalaryList(head,fp);   //排序函数 
	fprintf(fp,"不加绩效排序：\n");
	chart(head,fp,num);   //再次调用建立表格函数 
	
	fprintf(fp,"加入绩效考核：\n");
	getPerformance(head);   //调用绩效函数 
	
	
	sal *fp3=sort2(head);    //调用含绩效排序函数 
	chart(fp3,fp,num);   //再次调用建立表格函数 
	
    printf("绩效排序结果已写入salary_chart.csv\n");
	
	fclose(fp);
	freeSalaryList(head);
	printf("表格已生成：salary_chart.csv\n");
	return 0; 
}
