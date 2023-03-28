// See LICENSE file for copyright and license details.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void prevAns(void),
     calculate(void);

static char inp1[16], inp2[16], op;
static double num1, num2, ans;
static int err=0;

int
main(int argc, char *argv[]) {
	signal(SIGINT, SIG_IGN); // Disable SIGINT (Ctrl-C)
	int eof, ansSet=0;
	if(argc>1) {
		if(!strcmp(argv[1], "-h")||!strcmp(argv[1], "--help")) {
			fprintf(stderr, "usage: stcalc [OPTION] [EQUATION]\n"
			       "-i\t\tnon-interactive; prints to stdout\n"
			       "\t\tuse \"x\" instead of \"*\" for multiplication\n"
			       "-h, --help\tprints this menu\n\n"
			       "Equation Example: 1 + 2\n"
			       "Invalid Example: 1+2\n\n"
			);
			return EXIT_SUCCESS;
		} else if(!strcmp(argv[1], "-i")) {
			if(argc!=5) {
				fprintf(stderr, "Not enough or too many arguments\n");
				return EXIT_FAILURE;
			}
			num1=atoi(argv[2]);
			num2=atoi(argv[4]);
			op=argv[3][0];
			calculate();
			if(err) {
				fprintf(stderr, "Invalid operator\n");
				return EXIT_FAILURE;
			}
			printf("%.2lf\n", ans);
			return ans;
		} else {
			fprintf(stderr, "Invalid argument\n");
			return EXIT_FAILURE;
		}
	} else {
		printf("Operators: {+,-,*,/,%%}\n"
		       "Ctrl + D (EOF) to exit\n\n"
		);
		while(eof!=EOF) {
			if(ansSet) {
				if(err) printf("\033[31m""Invalid operator\n""\033[37m"); else printf("Answer: %.2lf\n", ans);
				err=0;
			}
			printf("> ");
			eof=scanf("%15s %1c %15s", inp1, &op, inp2);
			prevAns();
			calculate();
			ansSet=1;
		}
	}	
	printf("\n");
	return EXIT_SUCCESS;
}

/** @brief Convert string input to double.
 *
 *  If user inputs "ans" for either input, the
 *  corresponding static variable will be set to
 *  the previous answer.
 *
 *  @param Void.
 *  @return Void.
 */
void
prevAns(void) {
	if(!strcmp(inp1, "ans")) num1=ans; else num1=atoi(inp1);
	if(!strcmp(inp2, "ans")) num2=ans; else num2=atoi(inp2);
}


/** @brief Calculates answer.
 *
 *  Checks for valid operator and assigns the answer
 *  to static variable "ans."
 *
 *  @param Void.
 *  @return Void.
 */
void
calculate(void) {
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
		case 'x':
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
}