#include <iostream>
#include <cstdlib>
using namespace std;
typedef int elementtype;
typedef struct lnode
{
  elementtype elem;
  struct lnode *next;
} lnode, *linklist;                 // linklist*本身就可以指向linklist型，又定义linklist型内置指针指向linklist型，结构体内置了指向自己的指针
linklist head = NULL;
int create()
{
  if (head != NULL)
  {
    return 2;            // 链表已经被初始化完成
  }
  linklist l = (linklist)malloc(sizeof(lnode)); // l设为头结点
  if (l == NULL)
  {
    return 0;
  }              // 指针本身声明时没有所指向的空间，因此需要分配内存空间，无论是使用&分配有空间的地址
  head = l;
  l->next = NULL;
  l->elem = 0;                // 长度初始化为0；
  return 1;            // 还是使用malloc函数直接分配空间，都是分配空间的手段
}                    // 链表本身是隐形的，通过如指针来对链表进行访问操作。不需要专门使用某个结构体来索引
int destroy()
{                              // 顺序表不同，顺序表是在结构体内部使用数组存储元素，maxsize个元素被直接存储在某一个单一的结构体内部；而链表则是一个结构体相当于一个元素隐式地隐藏在计算机内部，通过头指针寻找
  if (head == NULL)
  {
    return 0;                      // 链表未初始化
  }
  linklist l = NULL;
  linklist p = NULL;
  l = head;
  while (l != NULL)
  {
    p = l->next;
    free(l);            //在这里p指向了野指针
    l = p;
  }
  head = l;
  return 1;
}
int clear()
{
  if (head == NULL || head->next == NULL)
  {
    return 0;                    // 链表未初始化或链表已经为空
  }
  linklist l = head->next;
  linklist p = NULL;
  while (l != NULL)
  {
    p = l->next;
    free(l);     //释放了l此时的结点1地址31680内存放的ele和next，但是head的next仍然指向31680，31680这块空间被释放之后
    l = p;      //所指向的空间位置不确定，出现了指针悬空的情况
  }          //为什么释放空间后的031680依然呈现出结构体的结构？因为head.next是一个结构体指针，指向的这块未定义的空间自然也是结构体空间
  head->elem=0;
  head->next=NULL;      //headnext依然指向结点1，但是结点1的空间已经被free，headnext成了野指针
  return 1;
}
int FindEle(int &ele, int pos)
{
  if (head == NULL || head->next == NULL)
  {
    return 2;                    // 链表未初始化或链表已经为空
  }
  if(pos>head->elem){
    return 0;        //位置不合法
  }
  linklist l = head;
  linklist p = NULL;
  for (int i = 0; i < pos; i++)
  {
    p = l->next;
    l = p;
  }
  ele = l->elem;
  return 1;
}
int FindPos(int &pos, int ele)
{
  if (head == NULL || head->next == NULL)
  {
    return 2;                // 链表未初始化或链表已经为空
  }
  linklist l = head->next;
  linklist p = NULL;
  pos = 1;
  while (l != NULL)
  {
    if (l->elem == ele)
    {
      return 1;
    }
    p = l->next;
    l = p;
    pos++;
  }
  
    return 0;                // l指向null遍历结束仍然未找到ele
  
}
int FindFront(int ele, int &front)
{
  if (head == NULL || head->next == NULL)
  {  
    return 3;                // 链表未初始化或链表已经为空
  }
  linklist l = head->next;
  linklist p = head;
  while (l != NULL)
  {
    if (l->elem == ele)
    {
      if (p == head)
      {
        return 0;            // l的上一位是head头结点，l为第一位，无前驱
      }
      front = p->elem;
      return 1;
    }
    p = l;
    l = l->next;
  }
  
    return 2;            // 链表遍历结束之后依然没找到ele元素，说明ele元素不存在
  
}
int FindNext(int ele, int &next)
{
  if (head == NULL || head->next == NULL)
  {
    return 3;            // 链表未初始化或链表已经为空
  }
  linklist l = head->next;
  linklist p = l->next;
  while (l != NULL)
  {
    if (l->elem == ele)
    {
      if (p == NULL)
      {
        return 0;        // 后继指向null空，说明l是链表最后一个结点无后继
      }
      next = p->elem;
      return 1;
    }
    if (p == NULL)
    {
      break;      // 遍历结束之后依然没找到ele，提前结束避免执行之后两个有bug的语句
    }
    l = p;
    p = l->next;
  }
  return 2;
}
int CreateInsert(int n)
{                        // 设n为插入的元素数量
  if (head != NULL)
  {
    return 2;          // 链表已经被初始化完成
  }
  linklist l = (linklist)malloc(sizeof(lnode)); // l设为头结点
  if (l == NULL)
  {
    return 0;          // 内存分配失败
  }                // 指针本身声明时没有所指向的空间，因此需要分配内存空间，无论是使用&分配有空间的地址
  head = l;
  l->next = NULL;
  l->elem = 0;
  for (int i = 1; i <= n; i++)
  {
    linklist p = (linklist)malloc(sizeof(lnode));
    p->next = NULL;                         // 使用尾插法，在结点结尾插入新结点
    cin >> p->elem;
    l->next = p;
    l = p;
    p = NULL;
    head->elem++;
  }
  return 1;
}
int GetLength(int &length)
{
  if (head == NULL)
  {
    return 0;    // 链表未初始化
  }
  length = head->elem;
  return 1;
}
int Insert(int pos, int ele)
{
  if (head == NULL)
  {
    return 0;              // 链表未初始化
  }
  linklist l = head;
  linklist p = NULL;
  if (pos > head->elem + 1)
  {
    return 2;                    // 插入位置超出长度限制；
  }
  for (int i = 0; i <= pos - 1; i++)
  {
    p = l;       // i=0时p=head，他的指针指向结点0
    l = l->next;
  }
  linklist s = (linklist)malloc(sizeof(lnode));
  s->next = NULL;
  s->elem = ele;
  l = p->next;                  // 使用暂时用不上的l存储p所指向的下一位原址
  p->next = s;            // 将p所指向的指针调整为新建的结点s，
  s->next = l;                 // 同时将s所指向的指针数值设为l，即p先所指向的节点位置，实现插入
  head->elem++;
  return 1;
}
int Delete(int pos)
{
  if (head == NULL)
  {
    return 0;          // 链表未初始化
  }
  linklist l = head;
  linklist p = NULL;
  if (pos > head->elem)
  {
    return 2;              // 删除位置超出长度限制；
  }
  for (int i = 0; i <= pos - 1; i++)
  {
    p = l;                   // i=0时p=head，他的指针指向结点0
    l = l->next;
  }
  p->next = l->next;
  free(l);
  head->elem--;
  return 1;
}
int Show()
{
  if (head == NULL || head->next == NULL)
  {
    return 0;                // 链表未初始化或链表已经为空
  }
  linklist l = head->next;
  linklist p = NULL;
  for (int i = 1; i <= head->elem; i++)
  {
    cout << l->elem << endl;
    p = l->next;
    l = p;               // 最后一次运行时p=null，l=p=null；并未发生冲突
  }
  return 1;
}
int Opposite(){
   if (head == NULL || head->next == NULL)
  {
    return 0;                // 链表未初始化或链表已经为空
  }
  linklist current= head->next;
  linklist next = NULL;
  linklist pre = current->next;
  for(int i=1;i<head->elem;i++){
  current->next=next;
  next=current;
  current=pre;
  pre=current->next;
  }
  current->next=next;
  head->next=current;
return 1;
  
}
int main()
{
  cout<<"1.初始化或重置链表"<<endl;
  cout<<"2.销毁链表"<<endl;
  cout<<"3.清空链表"<<endl;
  cout<<"4.链表长度"<<endl;
  cout<<"5.指定位置的元素值"<<endl;
  cout<<"6.链表已存在元素的位序"<<endl;
  cout<<"7.求输入元素的直接前驱"<<endl;
  cout<<"8.求输入元素的直接后继"<<endl;
  cout<<"9.在第i个位置插入一个元素"<<endl;
  cout<<"10.删除第i个元素"<<endl;
  cout<<"11.输出有的链表元素"<<endl;
  cout<<"12.初始化并用头插法（或尾插法）输入元素"<<endl;
  cout<<"13.实现单链表的逆序存放"<<endl;

while(true){
  int index=0;  //索引
  int pos=0;   //位置
  int ele=0;   //元素
  int n=0;    //返回数
  int i=0;
  cout<<"-----------请输入操作数,输入一个负数退出程序"<<endl;
  cin>>index;
  if(index<0){
    cout<<"退出程序!"<<endl;
    break;
  }
  switch(index){
    case 1:
    n=create();
    if(n==1){
      cout<<"初始化成功"<<endl;
    }
    if(n==0){
      cout<<"初始化失败"<<endl;
    }
    if(n==2){
      cout<<"链表已经被初始化"<<endl;
    }
    break;
    case 2:
    n=destroy();
    if(n==1){
      cout<<"销毁成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化"<<endl;
    }
    break;
    case 3:
    n=clear();
    if(n==1){
      cout<<"清空成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化或链表已经为空"<<endl;
    }
    break;
    case 4:
    n=GetLength(i);
    if(n==1){
      cout<<"获取成功"<<endl;
      cout<<"链表的长度是"<<i<<endl;
    }
    if(n==0){
      cout<<"链表未初始化"<<endl;
    }
    break;
    case 5:
    cout<<"请输入想查找元素值的指定位置"<<endl;
    cin>>pos;
    n=FindEle(ele,pos);
    if(n==1){
      cout<<"查找成功"<<endl;
      cout<<"该位置上的元素为"<<ele<<endl;
    }
    if(n==0){
      cout<<"位置不合法"<<endl;
    }
    if(n==2){
      cout<<"链表未初始化或链表已经为空"<<endl;
    }
    break;
    case 6:
    cout<<"请输入查找位置的元素"<<endl;
    cin>>ele;
    n=FindPos(pos,ele);
    if(n==1){
      cout<<"查找成功"<<endl;
      cout<<"该元素的位置为"<<pos<<endl;
    }
    if(n==0){
      cout<<"链表中不存在该元素"<<endl;
    }
    if(n==2){
      cout<<"链表未初始化或链表已经为空"<<endl;
    }
    break;
    case 7:
    cout<<"请输入想查找前驱的元素"<<endl;
    cin>>ele;
    n=FindFront(ele,i);
    if(n==1){
      cout<<"查找成功"<<endl;
      cout<<"前驱为"<<i<<endl;
    }
    if(n==0){
      cout<<"所查找元素为第一位无前驱"<<endl;
    }
    if(n==2){
      cout<<"该元素不存在"<<endl;
    }
    if(n==3){
      cout<<"链表未初始化或链表为空"<<endl; 
    }    
    break;
    case 8:
    cout<<"请输入想查找后驱的元素"<<endl;
    cin>>ele;
    n=FindNext(ele,i);
    if(n==1){
      cout<<"查找成功"<<endl;
      cout<<"后驱为"<<i<<endl;
    }
    if(n==0){
      cout<<"所查找元素为最后一位无后继"<<endl;
    }
    if(n==2){
      cout<<"该元素不存在"<<endl;
    }
    if(n==3){
      cout<<"链表未初始化或链表为空"<<endl; 
    }    
    break;
    case 9:
    cout<<"请输入插入的位置"<<endl;
    cin>>pos;
    cout<<"请输入插入的元素"<<endl;
    cin>>ele;
    n=Insert(pos,ele);
    if(n==1){
      cout<<"插入成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化"<<endl;
    }
    if(n==2){
      cout<<"插入位置不合法"<<endl;
    }
    break;
    case 10:
    cout<<"请输入删除元素的位置"<<endl;
    cin>>pos;
    n=Delete(pos);
    if(n==1){
      cout<<"删除成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化"<<endl;
    }
    if(n==2){
      cout<<"删除位置不合法"<<endl;
    }
    break;
    case 11:
    n=Show();
    if(n==1){
      cout<<"输出成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化或链表已为空"<<endl;
    }
    break;
    case 12:
    cout<<"请输入想创建的链表的长度"<<endl;
    cin>>i;
    cout<<"请输入元素"<<endl;
    n=CreateInsert(i);
    if(n==1){
      cout<<"创建并初始化成功"<<endl;
    }
    if(n==0){
      cout<<"内存分配失败"<<endl;
    }
    if(n==2){
      cout<<"链表已被创建"<<endl;
    }
    break;
    case 13:
    n=Opposite();
    if(n==1){
      cout<<"逆序存放成功"<<endl;
    }
    if(n==0){
      cout<<"链表未初始化或链表为空"<<endl;
    }
    break;
    default:
    break;


  }
}
}