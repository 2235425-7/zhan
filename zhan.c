#include <stdio.h>
#include <stdlib.h>

#define error -1
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

int destorystack(sqstack *s){
    if(s->base){
        free(s->base);
        s->stacksize = 0;
        s->base = NULL;
        s->top =NULL;
        printf("栈销毁成功\n");
        fflush(stdout);
        return ok;
    }
    printf("销毁失败\n");
    return error;
}

int main (){
    sqstack stack;
    initstack(&stack);
    destorystack(&stack);
    system("pause");
    return 0;
}