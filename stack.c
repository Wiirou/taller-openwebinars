#include "stack.h"

int top=-1;
int stack[max];

void push(int m){   
	top++;   
	stack[top]=m;
}


int pop(){   
	int j;   
	if(top==-1)
		return(top);   
	else   
	{      
		j=stack[top];      
		top--;      
		return(j);   
	}
}

int cpp_check_warning_function(){
	return stack[max];
}
