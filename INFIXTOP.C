#include<stdio.h>
#include<conio.h>
#define MAX 20

struct stack{
	int item[MAX];
	int top;
};

void initstack(struct stack *ps){
	ps->top = -1;
}

int isempty(struct stack *ps){
	return(ps->top == -1);
}

int pop(struct stack *ps){
	return(ps->item[ps->top--]);
}

void push(struct stack *ps, int n){
	ps->item[++ps->top] = n;
}

void main(){
	void postfix(char in[], char post[]);
	char in[20], post[20];
	clrscr();
	printf("\nEnter the Expression: ");
	scanf("%s", in);
	fflush(stdin);
	postfix(in, post);
	printf("\nThe postfix string is: ");
	printf("%s", post);
	getch();
}

void postfix(char in[], char post[]){
	int i, j=0;
	char ch;
	struct stack s1;
	initstack(&s1);

	for(i=0; in[i]!='\0'; i++){
		switch(in[i]){
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e': post[j] = in[i];
				  j++;
				  break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '(': push(&s1, in[i]);
				  break;
			case ')': while((ch=pop(&s1))!='('){
					post[j] = ch;
					j++;
				  }
		}
	}

	while(!isempty(&s1)){
		post[j] = pop(&s1);
		j++;
	}
	post[j] = '\0';
}
