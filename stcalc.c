// See LICENSE file for copyright and license details.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void prevAns(char *inp1,char *inp2);

static double num1,num2,ans;

int
main(int argc,char *argv[]) {
	signal(SIGINT,SIG_IGN); // Disable SIGINT (Ctrl-C)
	if(argc>1) {
		if(!strcmp(argv[1],"-h")) {
			printf("Improper Usage:\n> ""\033[31m""1+2""\033[37m""\nProper Usage:\n> ""\033[32m""1 + 2\n""\033[37m");
			return EXIT_SUCCESS;
		} else {
			printf("Only passable argument if \"-h,\" for help\n");
			return EXIT_FAILURE;
		}
	}
	printf("Operators: {+,-,*,/,%%}\nCtrl + D (EOF) to exit\n\n");
	int ansSet,err,eof;
	char inp1[16],inp2[16],op;
	while(eof!=EOF) {
		if(ansSet) {
			if(err) printf("\033[31m""Invalid operator\n""\033[37m"); else printf("Answer: %.2lf\n",ans);
		}
		err=0;	
		printf("> ");
		eof=scanf("%15s %1c %15s",inp1,&op,inp2);
		prevAns(inp1,inp2);
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
			case '%':
				ans=(double)((int)num1%(int)num2);
				break;
			default:
				err=1;
		}
		ansSet=1;
	}	
	printf("\n");
	return EXIT_SUCCESS;
}

/** @brief Convert string input to double.
 *
 *  If user inputs "ans" for either input, the
 *  corresponding variable will be set to the
 *  previous answer.
 *
 *  @param inp1 First number given by user.
 *  @param inp2 Second number given by user.
 *  @return Void.
 */
void
prevAns(char *inp1,char *inp2) {
	if(!strcmp(inp1,"ans")) num1=ans; else num1=atoi(inp1);
	if(!strcmp(inp2,"ans")) num2=ans; else num2=atoi(inp2);
}