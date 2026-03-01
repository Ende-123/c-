#include "salary.h"
float calcRealSalary(sal *p){
	if(p==NULL) return 0.0;
    float real = p->net_income - (p->net_income * p->tax_rate) - p->insurance;
    return real;  
}
