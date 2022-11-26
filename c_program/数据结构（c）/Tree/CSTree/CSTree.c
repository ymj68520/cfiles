#include "CSTree.h"
void vi(TElemType c)
{
printf("%c ",c);
}
void main()
{
int i;
CSTree T,p,q;
TElemType e,e1;
InitTree(&T);
printf("构造空树后,树空否? %d(1:是 0:否) 树根为%c 树的深度为%d\n",TreeEmpty(T),Root(T),
TreeDepth(T));
CreateTree(&T);
printf("构造树T后,树空否? %d(1:是 0:否) 树根为%c 树的深度为%d\n",TreeEmpty(T),Root(T),
TreeDepth(T));
printf("层序遍历树T:\n");
LevelOrderTraverse(T,vi);
printf("请输入待修改的结点的值 新值: ");
scanf("%c%*c%c%*c",&e,&e1);
Assign(&T,e,e1);
printf("层序遍历修改后的树T:\n");
LevelOrderTraverse(T,vi);
printf("%c的双亲是%c,长子是%c,下一个兄弟是%c\n",e1,Parent(T,e1),LeftChild(T,e1),
RightSibling(T,e1));
printf("建立树p:\n");
InitTree(&p);
CreateTree(&p);
printf("层序遍历树p:\n");
LevelOrderTraverse(p,vi);
printf("将树p插到树T中，请输入T中p的双亲结点 子树序号: ");
scanf("%c%d%*c",&e,&i);
q = Point(T,e);
InsertChild(&T,q,i,p);
printf("层序遍历修改后的树T:\n");
LevelOrderTraverse(p,vi);
printf("先根遍历修改后的树T:\n");
PreOrderTraverse(T,vi);
printf("删除树T中结点e的第i棵子树，请输入e i: ");
scanf("%c%d",&e,&i);
q = Point(T,e);
DeleteChild(&T,q,i);
printf("层序遍历修改后的树T:\n");
LevelOrderTraverse(T,vi);
printf("后序遍历修改后的树T:\n");
PostOrderTraverse(T,vi);
DestroyTree(&T);
}