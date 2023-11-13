#include"iostream"
#include<cstdlib>
                            //�ո��ʽ��һ������Բ�ǿո��а�ǿո�
using namespace std;
typedef int elementtype;
typedef struct lnode{
    elementtype ele; 
    struct lnode * next;
}lnode,*linklist;
typedef struct ptr{
    linklist head;  //�䵱ͷָ�������
    linklist rear; //�䵱βָ�������
}ptr; 
ptr a={NULL,NULL} ;    //����ȫ�ֱ����� 
                    
int create(){
  if(a.head!=NULL){
    return 0;    //�����ѱ���ʼ����δ�ͷſռ�
  }
  
  a.head=(linklist)malloc(sizeof(lnode));
  a.head->ele=0;
  a.head->next=NULL; //�Խڵ���г�ʼ������
  if(a.head==NULL){
    return 2;    //��ʼ��ʧ�ܣ���a���ڴ����ʧ��
  }
  a.rear=a.head;   //��ʼ�������㣬ͷβָ��ָ��ͬһ�����
  return 1;      //��ʼ���ɹ�
}
int destory(){     
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  while(a.head!=NULL){
    a.rear=a.head->next;
    free(a.head);
    a.head=a.rear;
  }
  return 1;      //���ٶ��У�����״̬��a.head,a.rear��ָ��null
}
int clear(){
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  while(a.head->next!=NULL){   //��������һ�����ʱnext����null�����Զ�ֹͣ��
    a.rear=a.head->next;
    free(a.head);
    a.head=a.rear;
  }
  return 1;

}
int judge(){
    if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  if(a.head->next==NULL){
    return 1;    //����Ϊ��
  }
  return 2;      //���в�Ϊ��
}
int GetLength(int& l){    //����г���Ϊl
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  linklist i=a.head;
  l=0;        //��ʼ����ʱָ��Ͷ��г��ȣ�
  while(i!=a.rear){
    l++;
    i=i->next;
  }
  return 1;
}
int GetFirstEle(int& e){   //��eΪ��һ��Ԫ��
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  if(a.head==a.rear){
    return 2 ;   //����Ϊ��������Ԫ��
  }
  e=a.head->ele;
  return 1;

}
int insert(int& ele){    //ele��ʾԪ�أ���Ϊ�߼��ṹ���Ƕ������Զ��ڲ����λ�ò���Ҫ����ָ��
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  } 
  linklist x=NULL;
  x=(linklist)malloc(sizeof(lnode));
  x->ele=0;      //ֻҪ���µĽ����־�Ҫ�Խ����г�ʼ�����������������
  x->next=NULL;    //�����½�㣬�ȴ������β
  a.rear->ele=ele;
  a.rear->next=x;   //β���ָ���½ڵ㣬ͬʱ����ֵ��ֵ
  a.rear=x;      //�ƶ�β����Ϊβ
  return 1;
}
int Delete(){
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  if(a.head==a.rear){
    return 2;    //����Ԫ�ؾ���ɾ��
  }
  linklist x=NULL;
  x=a.head->next;     //����ָ����˵��������ռ��ڵ�������Ҫ���н�����   
  free(a.head);
  a.head=x;
  return 1;        //��ͷָ��ԭ�����ڵ���Ƭ�ռ��ͷţ��ٽ�ͷָ��ָ�����ڵĵ�һ�����
}
int ShowAll(){
  if(a.head==NULL){
    return 0;    //����δ��ʼ��
  }
  if(a.head==a.rear){
    return 2;    //�б�Ϊ��
  }
  linklist i=a.head;
  while(i!=a.rear){
    cout<<i->ele<<" ";
    i=i->next;
  }
  return 1;
}
int main(){
  cout<<"1.��ʼ������"<<endl;
  cout<<"2.���ٶ���"<<endl;
  cout<<"3.��ն���"<<endl;
  cout<<"4. �����п�"<<endl;
  cout<<"5.����г���"<<endl;
  cout<<"6.��ȡ��ͷԪ��"<<endl;
  cout<<"7.����һ��Ԫ��"<<endl;
  cout<<"8.ɾ��һ��Ԫ��"<<endl;
  cout<<"9.�������Ԫ��"<<endl;
  cout<<"����һ�������˳�����"<<endl;
  int index=0;         //��ʼ��������
  while(true){
  int ele=0;         //ele��Ϊ���ε�Ԫ��
  int r=0;          //����r��Ϊ����ֵ����ָʾ���������еĽ��
  cout<<"�����������"<<endl;
  cin>>index;
  if(index<0){
    cout<<"�˳�����"<<endl;
    break;
  }
  switch(index){
    case 1:
      r=create();
      if(r==0){
        cout<<"�����ѱ���ʼ����δ�ͷſռ�"<<endl;
      }
      if(r==2){
        cout<<"��ʼ��ʧ��"<<endl;
      }
      if(r==1){
        cout<<"��ʼ���ɹ�"<<endl;
      }
      break;
    case 2:
      r=destory();
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"���ٳɹ�"<<endl;
      }
      break;
    case 3:
      r=clear();
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"����ɹ�"<<endl;
      }
      break;
    case 4:
      r=judge();
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"����Ϊ��"<<endl;
      }
      if(r==2){
        cout<<"���в�Ϊ��"<<endl;
      }
      break;
    case 5:
      r=GetLength(ele);
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"���еĳ���Ϊ"<<ele<<endl;
      }
      break;
    case 6:
      r=GetFirstEle(ele);
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"���еĶ�ͷԪ��Ϊ"<<ele<<endl;
      }
      if(r==2){
        cout<<"����Ϊ���޶�ͷԪ��"<<endl;
      }
      break;
    case 7:
      cout<<"��������������"<<endl;
      cin>>ele;
      r=insert(ele);
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"����ɹ�"<<endl;
      }
      break;
    case 8:
      r=Delete();
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"ɾ���ɹ�"<<endl;
      }
      if(r==2){
        cout<<"����Ϊ��"<<endl;
      }
      break;
    case 9:
      r=ShowAll();
      if(r==0){
        cout<<"����δ��ʼ��"<<endl;
      }
      if(r==1){
        cout<<"���ȫ�����гɹ�"<<endl;
      }
      if(r==2){
        cout<<"����Ϊ��"<<endl;
      }
      break;
    default:
      break;
  }
  }
}