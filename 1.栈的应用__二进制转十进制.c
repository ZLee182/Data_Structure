/*
栈的应用：二进制转十进制
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define stack_init_size 20//栈的初始长度
#define stack_increment 10//栈每次增长的长度

typedef char ElemType;
typedef
struct stack{//定义栈的结构
    ElemType *top;
    ElemType *base;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)//初始化栈
{
    s->base = (ElemType *)malloc(sizeof(ElemType)*stack_init_size);

    if(!s->base)//如果s->base没有分配内存
    {
        exit(0);
    }

    s->top = s->base;//初始化顶指针等于尾指针
    s->stackSize = stack_init_size;

}

void Push(sqStack *s,ElemType e)
{
    if( s->top - s->base >= s->stackSize)//如果栈溢出
    {
        s->base = (ElemType *)realloc( s->base, ( s->stackSize + stack_increment)*sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;//赋值
    s->top++;//top指针加一
}

void Pop(sqStack *s, ElemType *e)
{
    if(s->top == s->base)//如果栈空
    {
        return;
    }

    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c;
    int i, len, num = 0;
    sqStack s;//我原本写的是   sqStack *s;
    InitStack(&s);

    printf("请输入二进制数组，以符号#为结束符号\n");
    scanf("%c",&c);

    while(c != '#')
    {
        Push(&s,c);//原本写的是Push(&s,&c);
        scanf("%c",&c);
    }

    getchar();//防止'\n'字符冲入缓冲区

    len = StackLen(s);
    printf("当前的栈的容量是：%d\n",len);


    for( i =0; i<len; i++)
    {
        Pop(&s,&c);
        num = num +(c - 48)*pow(2,i);
    }
    
    printf("得到的整数是：%d\n", num);
    return 0;
}

