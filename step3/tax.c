#include <stdio.h>
#include <stdlib.h>

/*
∗ CSE 251 step3 tax.c
∗ By: AuroraCode2020
*/

int main(){
	double income;
	printf("Enter your annual income: ");
	scanf("%lf",&income);
	if(income<9350)
	{
		printf("0");
		exit(0);
	}
	else{
		int people,choose,children;
		double shuihou,tk,rk,result;
		printf("What is your filing status?\n");
		printf("1) single\n");
		printf("2) married filing jointly\n");
		printf("3) married filing separately\n");
		printf("Please enter a number: ");
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				people = 1;
				tk = 5700;
				break;
			}
			case 2:{
				printf("How many children do you have? ");
				scanf("%d",&children);
				people = 2 + children;
				tk = 11400;
				break;
			}
			case 3:{
				people = 1;
				tk = 5700;
				break;
			}
		}
		rk = people*3650 + tk;
		shuihou = income - rk;
		if(shuihou<=16750){
			result = 0 + 0.1*shuihou;
		}
		else if(shuihou>16750 && shuihou<=68000){
			result = 1675 + 0.15*(shuihou-16750);
		}
		else if(shuihou>68000 && shuihou<=137300){
			result = 9362.5 + 0.25*(shuihou-68000);
		}
		else{
			result = 26687.5 + 0.28*(shuihou-137300);
		}
		printf("%.2f",result);
		exit(0);
	}
}
