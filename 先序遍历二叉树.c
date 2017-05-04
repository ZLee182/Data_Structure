/*
先序遍历二叉树
例如树的格式为：       A
                  B    C
               null D E   null
输入格式为："AB D  CE   "
在CreateBiTree中传入的参数是T的地址，接受的是T这个数值的地址所对应的值
注意malloc的用法
*/
#include<stdio.h>
typedef char ElemType;
typedef
struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);

    if(' ' == c)
        *T = NULL;
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }

}

void visit(char c, int level)
{
    printf("%c, the element is stay at %d level\n",c, level);
}

BiTree PreOrderBiTree(BiTree T,int level)
{
    if( T )
    {
        visit(T->data,level);
        PreOrderBiTree(T->lchild,level+1);
        PreOrderBiTree(T->rchild,level+1);
    }
}
int main()
{
    int level =1;
    BiTree T = NULL;
    CreateBiTree(&T);
    PreOrderBiTree(T,level);
    return 0;
}
