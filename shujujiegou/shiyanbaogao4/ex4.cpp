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
  if(!a->base){        //base����Ϊָ��Ҳ��Ϊ���飬����˵ָ��������ĳ����������ͨ
    return 0;        //����ʧ��
  }
  a->top=a->base;
  a->stacklength=MAXSTACK;
  return 1;
}
int destory(stack *a){
  if(a->base==NULL){
    return 0;       //ջδ��ʼ����ջ�ѱ�����
  }
  free(a->base);
  a->base=NULL;        //����֮��ռ䲻�ٴ���ԭָ��ָ�򲻿�֪��������ָ��null��֤����������ʵ�δ�����ֵ
  a->top=a->base;
  a->stacklength=0;
  return 1;
}
int clear(stack *a){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  a->top=a->base;       //��ʵ���Ƿ��ص���ʼ���ո���ɵ�״̬���ȴ����븳ֵ���ǣ��������ֵ��ͬ����������������
  return 1;
}
int judge(stack *a){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  if(a->top-a->base==0){
    return 1;

  }
  return 2;    //�п�ʧ�ܣ���Ϊ�գ�

}
int GetLength(stack *a,int &l){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  l=a->top-a->base;
return 1;
}
int GetTop(stack *a,int &ele){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  if(a->top-a->base==0){
    return 2;        //��ջ��ջ��Ԫ��
  }
  ele=*(a->top-1);      //*������
  return 1;

}
int insert(stack *a ,int ele){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  if(a->top-a->base==MAXSTACK){
    a->base=(elementtype*)realloc(a->base,(MAXSTACK+INCREASE)*sizeof(elementtype));
  }
  if(a->base==NULL){
    return 2;        //���·����ڴ�ʧ��
  }
  *(a->top)=ele;       //������֮��Կռ䱾����и�ֵ
  a->top++;          //ͷָ���ٴν�������    ����top�漰������ʱע�����鱾��������Ƿ��㹻
  return 1;
}
int Delete(stack *a){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  if(a->top-a->base==0){
    return 2;        //ջΪ��
  }
  a->top--;
  return 1;
}
int ShowAll(stack* a){
  if(a->base==NULL){
    return 0;        //ջδ��ʼ�����Ѿ�������
  }
  if(a->top-a->base==0){
    return 2;        //ջΪ��
  }
  elementtype *ptr=a->top-1;
  while(ptr!=a->base){
    cout<<*(ptr)<<" ";
    ptr--;         //�Լ�ֱ��������ջ��
  }
  cout<<*(ptr)<<endl;
  return 1;
}
int ScaleChange(int ele,int scale){
  stack s={NULL,NULL,0};
  //stack�ͳ�ʼ������ֱ�ӳ�ʼ������ָ�룬ָ����Ҫ��ָ��Ŀռ䣬
  //���������ָ����ָ��Ŀռ䣬��Ҫ����ָ��ԭ�͵ı����Դ˴�������ָ�����͵Ŀռ�
  //ָ�����ָ�룬����ָ��ԭ������Ӧ�ı���������ֱ�ӵ���ԭ��������������ֱ�ӵ�ԭ��ʹ�ã����ǽ�����
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
  cout<<"1.��ʼ��ջ"<<endl;
  cout<<"2.����ջ"<<endl;
  cout<<"3.���ջ"<<endl;
  cout<<"4.ջ�п�"<<endl;
  cout<<"5.��ջ����"<<endl;
  cout<<"6.��ȡջ��Ԫ��"<<endl;
  cout<<"7.����һ��Ԫ��"<<endl;
  cout<<"8.ɾ��һ��Ԫ��"<<endl;
  cout<<"9.�������Ԫ��"<<endl;
  cout<<"10.����ת��"<<endl;
  cout<<"���븺���˳�����"<<endl;
  stack a={NULL,NULL,0};
  while(true){
    int index=0;
    int r=0;    //���ڴ洢�����ķ���ֵ
   
    int ele=0;
    int s=0;    //scale
    cout<<"�����������"<<endl;
    cin>>index;
    if(index<0){
      cout<<"�˳��ɹ�"<<endl;
      break;
    }
    switch(index){
      case 1:
        r=create(&a);
        if(r==1){
          cout<<"��ʼ���ɹ�"<<endl;
        }
        if(r==0)
        {
          cout<<"��ʼ��ʧ��"<<endl;
        }
        break;
      case 2:
        r=destory(&a);
        if(r==1){
          cout<<"���ٳɹ�"<<endl;
        }
        if(r==0){
          cout<<"ջδ��ʼ����ջ�ѱ�����"<<endl;
        }
        break;
      case 3:
        r=clear(&a);
        if(r==1){
          cout<<"��ճɹ�"<<endl;
        }
        if(r==0)
        {
          cout<<"ջδ��ʼ����ջ�ѱ�����"<<endl;
        }
        break;
      case 4:
        r=judge(&a);
        if(r==1){
          cout<<"ջΪ��"<<endl;

        }
        if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==2){
          cout<<"ջ��Ϊ��"<<endl;
        }
        break;
      case 5:
        r=GetLength(&a,ele);        //��������ʱ�Ѿ�����eleΪ&ֵ������ʱ�Զ�ʶ�����������
        if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==1){
          cout<<"����Ϊ"<<ele<<endl;
        }
        break;
      case 6:
        r=GetTop(&a,ele);
        if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==1){
          cout<<"ջ��Ԫ��Ϊ"<<ele<<endl;
        }
        if(r==2)
        {
          cout<<"��ջ��ջ��Ԫ��"<<endl;
        }
        break;
      case 7:
        cout<<"������Ҫ�������"<<endl;
        cin>>ele;
        r=insert(&a,ele);
        if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==1){
          cout<<"����ɹ�"<<endl;
        }
        if(r==2){
          cout<<"���·����ڴ�ʧ��"<<endl;
        }
        break;
      case 8:
        r=Delete(&a);
        if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==2)
        {
          cout<<"ջΪ��"<<endl;
        }
        if(r==1){
          cout<<"ɾ���ɹ�"<<endl;
        }
        break;
      case 9:
        r=ShowAll(&a);
       if(r==0){
          cout<<"ջδ��ʼ�����Ѿ�������"<<endl;
        }
        if(r==2)
        {
          cout<<"ջΪ��"<<endl;
        }
        if(r==1){
          cout<<"����ɹ�"<<endl;
        }
        break;
      case 10:
        cout<<"������Ҫ��������ת������"<<endl;
        cin>>ele;
        cout<<"������Ҫת���Ľ���"<<endl;
        cin>>s;
        r=ScaleChange(ele,s);
        if(r==1){
          cout<<"ת���ɹ�"<<endl;
        }
        break;
      default:
        break;
        
  }
}
}