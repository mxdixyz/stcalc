/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc,char *argv[]) {
	if(argc>1) {
		if(!strcmp(argv[1],"-h")) {
			printf("Improper Usage:\n> ""\033[31m""1+2""\033[37m""\nProper Usage:\n> ""\033[32m""1 + 2\n""\033[37m");
			return 0;
		} else {
			printf("Only passable argument if \"-h,\" for help\n");
			return 1;
		}
	}
	double num1,num2,ans;
	char inp1[5],inp2[5],op;
	int ansSet,err;
	for(;;) {
		system("clear");
		printf("Operators: [+, -, *, /]\nType \"ans\" for previous answer\n(Ctrl + C) - exit\n\n\n\n\n");
		if(ansSet) {
			if(!err) {
				printf("Answer: %.2lf\n",ans);
			} else {
				printf("Answer: ""\033[31m""Error\n""\033[37m");
			}
		}
		err=0;
		printf("> ");
		scanf("%s %c %s",inp1,&op,inp2);
		if(!strcmp(inp1,"ans")) {
			num1=ans;
			num2=atoi(inp2);
		} else if(!strcmp(inp2,"ans")) {
			num1=atoi(inp1);
			num2=ans;
		} else {
			num1=atoi(inp1);
			num2=atoi(inp2);
		}
		switch(op) {
			case '+':
				ans=num1+num2;
				break;
			case '-':
				ans=num1-num2;
				break;
			case '*':
				ans=num1*num2;
				break;
			case '/':
				ans=num1/num2;
				break;
			default:
				err=1;
				break;
		}
		ansSet=1;
	}	
}
