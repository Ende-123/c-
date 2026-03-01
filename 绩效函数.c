#include "salary.h"
void getPerformance(sal *p) {
    if (p == NULL) return;
    int i=1;
	while(p!=NULL){
	
    printf("%s老师应出勤天数：",p->name);
    scanf("%d", &p->work_days);
    
    printf("实际出勤天数：");
    scanf("%d", &p->attendance);
    
    if (p->attendance > p->work_days) {
        p->attendance = p->work_days;
    }
    if (p->attendance < 0) {
        p->attendance = 0;
    }
    if(p->work_days==0){
    	printf("出勤天数错误！");
		continue; 
	} 
    float rate = (float)p->attendance / p->work_days;

    if (rate >= 0.95) {
        p->level = 'A';
        p->bonus = p->net_income * 0.2;  // 20%奖金
    } else if (rate >= 0.90) {
        p->level = 'B';
        p->bonus = p->net_income * 0.15; // 15%奖金   
    } else if (rate >= 0.80) {
        p->level = 'C';
        p->bonus = p->net_income * 0.1;  // 10%奖金
    } else if (rate >= 0.70) {
        p->level = 'D';
        p->bonus = p->net_income * 0.05; // 5%奖金
    } else {
        p->level = 'E';
        p->bonus = 0.0;  // 无奖金
    }   
	p->real_salary += p->bonus; 
    p=p->next;
    i++;
}
printf("加入绩效考核中……"); 
}

