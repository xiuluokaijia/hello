#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSTACK 100
#define INCREASE 10
typedef int elementtype;
typedef struct stack
{
  elementtype *base;
  elementtype *top;
  int stacklength;
}stack;
int create(stack *a){
  a->base=(elementtype *)malloc(MAXSTACK * sizeof(elementtype));
  if(!a->base){        //base既作为指针也作为数组，所以说指针与数组某种意义上相通
    return 0;        //分配失败
  }
  a->top=a->base;
  a->stacklength=MAXSTACK;
  return 1;
}
int destory(stack *a){
  if(a->base==NULL){
    return 0;       //栈未初始化或栈已被销毁
  }
  free(a->base);
  a->base=NULL;        //销毁之后空间不再存在原指针指向不可知处，将其指向null保证函数不会访问到未定义的值
  a->top=a->base;
  a->stacklength=0;
  return 1;
}
int clear(stack *a){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  a->top=a->base;       //其实就是返回到初始化刚刚完成的状态，等待输入赋值覆盖，已输入的值等同于随机分配的乱码了
  return 1;
}
int judge(stack *a){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  if(a->top-a->base==0){
    return 1;

  }
  return 2;    //判空失败，不为空；

}
int GetLength(stack *a,int &l){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  l=a->top-a->base;
return 1;
}
int GetTop(stack *a,int &ele){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  if(a->top-a->base==0){
    return 2;        //空栈无栈顶元素
  }
  ele=*(a->top-1);      //*解引用
  return 1;

}
int insert(stack *a ,int ele){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  if(a->top-a->base==MAXSTACK){
    a->base=(elementtype*)realloc(a->base,(MAXSTACK+INCREASE)*sizeof(elementtype));
  }
  if(a->base==NULL){
    return 2;        //重新分配内存失败
  }
  *(a->top)=ele;       //解引用之后对空间本身进行赋值
  a->top++;          //头指针再次进行自增    ！！top涉及到自增时注意数组本身的容量是否还足够
  return 1;
}
int Delete(stack *a){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  if(a->top-a->base==0){
    return 2;        //栈为空
  }
  a->top--;
  return 1;
}
int ShowAll(stack* a){
  if(a->base==NULL){
    return 0;        //栈未初始化或已经被销毁
  }
  if(a->top-a->base==0){
    return 2;        //栈为空
  }
  elementtype *ptr=a->top-1;
  while(ptr!=a->base){
    cout<<*(ptr)<<" ";
    ptr--;         //自减直到遍历到栈底
  }
  cout<<*(ptr)<<endl;
  return 1;
}
int ScaleChange(int ele,int scale){
  stack s={NULL,NULL,0};
  //stack型初始化不能直接初始化它的指针，指针总要有指向的空间，
  //如果不分配指针所指向的空间，总要声明指针原型的变量以此创建符合指针类型的空间
  //指针就是指针，不是指针原型所对应的变量，不能直接当作原型声明，更不能直接当原型使用，除非解引用
  create(&s);
  while(ele>=scale){
    insert(&s,ele%scale);
    ele=ele/scale;
  }
  insert(&s,ele);
  while(s.top!=s.base){
    cout<<*(s.top-1);
    s.top--;
  }
  destory(&s);
  return 1;
}
int main(){
  cout<<"1.初始化栈"<<endl;
  cout<<"2.销毁栈"<<endl;
  cout<<"3.清空栈"<<endl;
  cout<<"4.栈判空"<<endl;
  cout<<"5.求栈长度"<<endl;
  cout<<"6.获取栈顶元素"<<endl;
  cout<<"7.插入一个元素"<<endl;
  cout<<"8.删除一个元素"<<endl;
  cout<<"9.输出所有元素"<<endl;
  cout<<"10.进制转换"<<endl;
  cout<<"输入负数退出程序"<<endl;
  stack a={NULL,NULL,0};
  while(true){
    int index=0;
    int r=0;    //用于存储函数的返回值
   
    int ele=0;
    int s=0;    //scale
    cout<<"请输入操作数"<<endl;
    cin>>index;
    if(index<0){
      cout<<"退出成功"<<endl;
      break;
    }
    switch(index){
      case 1:
        r=create(&a);
        if(r==1){
          cout<<"初始化成功"<<endl;
        }
        if(r==0)
        {
          cout<<"初始化失败"<<endl;
        }
        break;
      case 2:
        r=destory(&a);
        if(r==1){
          cout<<"销毁成功"<<endl;
        }
        if(r==0){
          cout<<"栈未初始化或栈已被销毁"<<endl;
        }
        break;
      case 3:
        r=clear(&a);
        if(r==1){
          cout<<"清空成功"<<endl;
        }
        if(r==0)
        {
          cout<<"栈未初始化或栈已被销毁"<<endl;
        }
        break;
      case 4:
        r=judge(&a);
        if(r==1){
          cout<<"栈为空"<<endl;

        }
        if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==2){
          cout<<"栈不为空"<<endl;
        }
        break;
      case 5:
        r=GetLength(&a,ele);        //函数定义时已经定义ele为&值，传参时自动识别了这个类型
        if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==1){
          cout<<"长度为"<<ele<<endl;
        }
        break;
      case 6:
        r=GetTop(&a,ele);
        if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==1){
          cout<<"栈顶元素为"<<ele<<endl;
        }
        if(r==2)
        {
          cout<<"空栈无栈顶元素"<<endl;
        }
        break;
      case 7:
        cout<<"请输入要插入的数"<<endl;
        cin>>ele;
        r=insert(&a,ele);
        if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==1){
          cout<<"插入成功"<<endl;
        }
        if(r==2){
          cout<<"重新分配内存失败"<<endl;
        }
        break;
      case 8:
        r=Delete(&a);
        if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==2)
        {
          cout<<"栈为空"<<endl;
        }
        if(r==1){
          cout<<"删除成功"<<endl;
        }
        break;
      case 9:
        r=ShowAll(&a);
       if(r==0){
          cout<<"栈未初始化或已经被销毁"<<endl;
        }
        if(r==2)
        {
          cout<<"栈为空"<<endl;
        }
        if(r==1){
          cout<<"输出成功"<<endl;
        }
        break;
      case 10:
        cout<<"请输入要进行数制转换的数"<<endl;
        cin>>ele;
        cout<<"请输入要转换的进制"<<endl;
        cin>>s;
        r=ScaleChange(ele,s);
        if(r==1){
          cout<<"转换成功"<<endl;
        }
        break;
      default:
        break;
        
  }
}
}