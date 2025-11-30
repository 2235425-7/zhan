#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define overflow -2
#define ok 1
typedef int selemtype;
 typedef struct{
    selemtype *base;
    selemtype *top;
    int stacksize;
 }sqstack;

int initstack(sqstack *s){
    s->base = (selemtype*) malloc(MAXSIZE*sizeof(selemtype));

    if(!s->base) exit(overflow);  
    s->base = s->top;
    s->stacksize = MAXSIZE;
    printf("栈初始化完成\n");
    return ok;
}

int main (){
    sqstack stack;
    initstack(&stack);
    return 0;
}