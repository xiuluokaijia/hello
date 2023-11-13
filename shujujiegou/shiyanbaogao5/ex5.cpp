#include"iostream"
#include<cstdlib>
                            //空格格式不一样，有圆角空格有半角空格
using namespace std;
typedef int elementtype;
typedef struct lnode{
    elementtype ele; 
    struct lnode * next;
}lnode,*linklist;
typedef struct ptr{
    linklist head;  //充当头指针的作用
    linklist rear; //充当尾指针的作用
}ptr; 
ptr a={NULL,NULL} ;    //定义全局变量； 
                    
int create(){
  if(a.head!=NULL){
    return 0;    //链表已被初始化且未释放空间
  }
  
  a.head=(linklist)malloc(sizeof(lnode));
  a.head->ele=0;
  a.head->next=NULL; //对节点进行初始化操作
  if(a.head==NULL){
    return 2;    //初始化失败，即a的内存分配失败
  }
  a.rear=a.head;   //初始化分配结点，头尾指针指向同一个结点
  return 1;      //初始化成功
}
int destory(){     
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  while(a.head!=NULL){
    a.rear=a.head->next;
    free(a.head);
    a.head=a.rear;
  }
  return 1;      //销毁队列，最终状态下a.head,a.rear均指向null
}
int clear(){
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  while(a.head->next!=NULL){   //清除到最后一个结点时next等于null所以自动停止了
    a.rear=a.head->next;
    free(a.head);
    a.head=a.rear;
  }
  return 1;

}
int judge(){
    if(a.head==NULL){
    return 0;    //函数未初始化
  }
  if(a.head->next==NULL){
    return 1;    //队列为空
  }
  return 2;      //队列不为空
}
int GetLength(int& l){    //设队列长度为l
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  linklist i=a.head;
  l=0;        //初始化临时指针和队列长度！
  while(i!=a.rear){
    l++;
    i=i->next;
  }
  return 1;
}
int GetFirstEle(int& e){   //设e为第一个元素
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  if(a.head==a.rear){
    return 2 ;   //队列为空其内无元素
  }
  e=a.head->ele;
  return 1;

}
int insert(int& ele){    //ele表示元素，因为逻辑结构上是队列所以对于插入的位置不需要进行指定
  if(a.head==NULL){
    return 0;    //函数未初始化
  } 
  linklist x=NULL;
  x=(linklist)malloc(sizeof(lnode));
  x->ele=0;      //只要有新的结点出现就要对结点进行初始化设置以免出现问题
  x->next=NULL;    //创建新结点，等待插入队尾
  a.rear->ele=ele;
  a.rear->next=x;   //尾结点指向新节点，同时将数值赋值
  a.rear=x;      //移动尾结点成为尾
  return 1;
}
int Delete(){
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  if(a.head==a.rear){
    return 2;    //所有元素均已删除
  }
  linklist x=NULL;
  x=a.head->next;     //对于指针来说，引用其空间内的数据需要进行解引用   
  free(a.head);
  a.head=x;
  return 1;        //将头指针原本所在的那片空间释放，再将头指针指向现在的第一个结点
}
int ShowAll(){
  if(a.head==NULL){
    return 0;    //函数未初始化
  }
  if(a.head==a.rear){
    return 2;    //列表为空
  }
  linklist i=a.head;
  while(i!=a.rear){
    cout<<i->ele<<" ";
    i=i->next;
  }
  return 1;
}
int main(){
  cout<<"1.初始化队列"<<endl;
  cout<<"2.销毁队列"<<endl;
  cout<<"3.清空队列"<<endl;
  cout<<"4. 队列判空"<<endl;
  cout<<"5.求队列长度"<<endl;
  cout<<"6.获取队头元素"<<endl;
  cout<<"7.插入一个元素"<<endl;
  cout<<"8.删除一个元素"<<endl;
  cout<<"9.输出所有元素"<<endl;
  cout<<"输入一个负数退出程序"<<endl;
  int index=0;         //初始化操作数
  while(true){
  int ele=0;         //ele作为传参的元素
  int r=0;          //设置r作为返回值用以指示函数的运行的结果
  cout<<"请输入操作数"<<endl;
  cin>>index;
  if(index<0){
    cout<<"退出程序！"<<endl;
    break;
  }
  switch(index){
    case 1:
      r=create();
      if(r==0){
        cout<<"队列已被初始化且未释放空间"<<endl;
      }
      if(r==2){
        cout<<"初始化失败"<<endl;
      }
      if(r==1){
        cout<<"初始化成功"<<endl;
      }
      break;
    case 2:
      r=destory();
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"销毁成功"<<endl;
      }
      break;
    case 3:
      r=clear();
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"清除成功"<<endl;
      }
      break;
    case 4:
      r=judge();
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"队列为空"<<endl;
      }
      if(r==2){
        cout<<"队列不为空"<<endl;
      }
      break;
    case 5:
      r=GetLength(ele);
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"队列的长度为"<<ele<<endl;
      }
      break;
    case 6:
      r=GetFirstEle(ele);
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"队列的队头元素为"<<ele<<endl;
      }
      if(r==2){
        cout<<"队列为空无队头元素"<<endl;
      }
      break;
    case 7:
      cout<<"请输入插入的数据"<<endl;
      cin>>ele;
      r=insert(ele);
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"插入成功"<<endl;
      }
      break;
    case 8:
      r=Delete();
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"删除成功"<<endl;
      }
      if(r==2){
        cout<<"队列为空"<<endl;
      }
      break;
    case 9:
      r=ShowAll();
      if(r==0){
        cout<<"队列未初始化"<<endl;
      }
      if(r==1){
        cout<<"输出全部队列成功"<<endl;
      }
      if(r==2){
        cout<<"队列为空"<<endl;
      }
      break;
    default:
      break;
  }
  }
}