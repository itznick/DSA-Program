#include<stdio.h>
#include<conio.h>
#define MAX 20

struct stack{
 int item[MAX];
 int top;
};

void initstack(struct stack *ps){
 ps->top=-1;
}

void push(struct stack *ps, int ch1)
{
  if(!isfull(ps))
  {
  ps->top++;
  ps->item[ps->top]=ch1;
  }
 else
 {
  printf("\nThe Stack is Full\n");
 }
}

int pop(struct stack *ps){
 return(ps->item[ps->top--]);
}

int isempty(struct stack *ps){
 return(ps->top==-1);
}

int isfull(struct stack *ps){
 return(ps->top==MAX-1);
}

void main(){
 int n, ch;
 struct stack s1;
 initstack(&s1);
 clrscr();

 do{
  printf("\n1: PUSH\n2: POP\n3: EXIT");
  printf("\nEnter your choice: ");
  scanf("%d", &ch);

  switch(ch){
   case 1:
    printf("Enter the Element: ");
    scanf("%d", &n);
    push(&s1, n);
    break;
   case 2:
    if(isempty(&s1)==1){
     printf("\nThe Stack is Empty\n");
    }
    else{
     printf("The Popped Element is %d", pop(&s1));
    }
    break;
  }
 }while(ch!=3);

 getch();
}