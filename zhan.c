#include <stdio.h>
#include <stdlib.h>

#define error -1
#define MAXSIZE 100
#define overflow -2
#define ok 1
//定义栈
typedef int selemtype;
 typedef struct{
    selemtype *base;
    selemtype *top;
    int stacksize;
 }sqstack;
//初始化栈
int initstack(sqstack *s){
    s->base = (selemtype*) malloc(MAXSIZE*sizeof(selemtype));

    if(!s->base) exit(overflow);  
    s->top = s->base;
    s->stacksize = MAXSIZE;
    printf("栈初始化完成\n");
    return ok;
}
//入栈
int push(sqstack *s,selemtype e){
    if(s->top-s->base == s->stacksize){
        printf("栈满\n");
        return error;
    }
    *s->top=e;
    s->top++;
        return ok;
}
//出栈
int pop(sqstack *s,selemtype *e){
    if(s->top == s->base){
        printf("栈空\n");
        return error;
    }
    s->top--;
    *e=*s->top;
        return ok;
}
//打印栈
void printstack(sqstack *s) {
     if (s->base == s->top) {
         printf("栈为空\n");
         return;
     }
     printf("栈中的元素：");
     selemtype *p = s->base;
     while (p < s->top) {
         printf("%d ", *p);
         p++;
     }
     printf("\n");
 }
//销毁栈
int destorystack(sqstack *s){
    if(s->base){
        free(s->base);
        s->stacksize = 0;
        s->base = NULL;
        s->top =NULL;
        printf("栈销毁成功\n");
        return ok;
    }
    printf("销毁失败\n");
    return error;
}
//主函数测试
int main (){
    sqstack stack;
    selemtype e;
    initstack(&stack);
    push(&stack,10);
    push(&stack,20);
    printf("入栈前\n");
    printstack(&stack);
    pop(&stack,&e);
    printf("出栈的元素：%d\n",e);
    printf("出栈后\n");
    printstack(&stack);
    destorystack(&stack);
    printstack(&stack);
    printf("按任意键继续\n");
    getchar();
    getchar();
    return 0;
}