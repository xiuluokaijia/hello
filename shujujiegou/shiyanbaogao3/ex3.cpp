#include <iostream>
#include <cstdlib>
using namespace std;
typedef int elementtype;
typedef struct lnode
{
  elementtype elem;
  struct lnode *next;
} lnode, *linklist;                 // linklist*����Ϳ���ָ��linklist�ͣ��ֶ���linklist������ָ��ָ��linklist�ͣ��ṹ��������ָ���Լ���ָ��
linklist head = NULL;
int create()
{
  if (head != NULL)
  {
    return 2;            // �����Ѿ�����ʼ�����
  }
  linklist l = (linklist)malloc(sizeof(lnode)); // l��Ϊͷ���
  if (l == NULL)
  {
    return 0;
  }              // ָ�뱾������ʱû����ָ��Ŀռ䣬�����Ҫ�����ڴ�ռ䣬������ʹ��&�����пռ�ĵ�ַ
  head = l;
  l->next = NULL;
  l->elem = 0;                // ���ȳ�ʼ��Ϊ0��
  return 1;            // ����ʹ��malloc����ֱ�ӷ���ռ䣬���Ƿ���ռ���ֶ�
}                    // �����������εģ�ͨ����ָ������������з��ʲ���������Ҫר��ʹ��ĳ���ṹ��������
int destroy()
{                              // ˳���ͬ��˳������ڽṹ���ڲ�ʹ������洢Ԫ�أ�maxsize��Ԫ�ر�ֱ�Ӵ洢��ĳһ����һ�Ľṹ���ڲ�������������һ���ṹ���൱��һ��Ԫ����ʽ�������ڼ�����ڲ���ͨ��ͷָ��Ѱ��
  if (head == NULL)
  {
    return 0;                      // ����δ��ʼ��
  }
  linklist l = NULL;
  linklist p = NULL;
  l = head;
  while (l != NULL)
  {
    p = l->next;
    free(l);            //������pָ����Ұָ��
    l = p;
  }
  head = l;
  return 1;
}
int clear()
{
  if (head == NULL || head->next == NULL)
  {
    return 0;                    // ����δ��ʼ���������Ѿ�Ϊ��
  }
  linklist l = head->next;
  linklist p = NULL;
  while (l != NULL)
  {
    p = l->next;
    free(l);     //�ͷ���l��ʱ�Ľ��1��ַ31680�ڴ�ŵ�ele��next������head��next��Ȼָ��31680��31680���ռ䱻�ͷ�֮��
    l = p;      //��ָ��Ŀռ�λ�ò�ȷ����������ָ�����յ����
  }          //Ϊʲô�ͷſռ���031680��Ȼ���ֳ��ṹ��Ľṹ����Ϊhead.next��һ���ṹ��ָ�룬ָ������δ����Ŀռ���ȻҲ�ǽṹ��ռ�
  head->elem=0;
  head->next=NULL;      //headnext��Ȼָ����1�����ǽ��1�Ŀռ��Ѿ���free��headnext����Ұָ��
  return 1;
}
int FindEle(int &ele, int pos)
{
  if (head == NULL || head->next == NULL)
  {
    return 2;                    // ����δ��ʼ���������Ѿ�Ϊ��
  }
  if(pos>head->elem){
    return 0;        //λ�ò��Ϸ�
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
    return 2;                // ����δ��ʼ���������Ѿ�Ϊ��
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
  
    return 0;                // lָ��null����������Ȼδ�ҵ�ele
  
}
int FindFront(int ele, int &front)
{
  if (head == NULL || head->next == NULL)
  {  
    return 3;                // ����δ��ʼ���������Ѿ�Ϊ��
  }
  linklist l = head->next;
  linklist p = head;
  while (l != NULL)
  {
    if (l->elem == ele)
    {
      if (p == head)
      {
        return 0;            // l����һλ��headͷ��㣬lΪ��һλ����ǰ��
      }
      front = p->elem;
      return 1;
    }
    p = l;
    l = l->next;
  }
  
    return 2;            // �����������֮����Ȼû�ҵ�eleԪ�أ�˵��eleԪ�ز�����
  
}
int FindNext(int ele, int &next)
{
  if (head == NULL || head->next == NULL)
  {
    return 3;            // ����δ��ʼ���������Ѿ�Ϊ��
  }
  linklist l = head->next;
  linklist p = l->next;
  while (l != NULL)
  {
    if (l->elem == ele)
    {
      if (p == NULL)
      {
        return 0;        // ���ָ��null�գ�˵��l���������һ������޺��
      }
      next = p->elem;
      return 1;
    }
    if (p == NULL)
    {
      break;      // ��������֮����Ȼû�ҵ�ele����ǰ��������ִ��֮��������bug�����
    }
    l = p;
    p = l->next;
  }
  return 2;
}
int CreateInsert(int n)
{                        // ��nΪ�����Ԫ������
  if (head != NULL)
  {
    return 2;          // �����Ѿ�����ʼ�����
  }
  linklist l = (linklist)malloc(sizeof(lnode)); // l��Ϊͷ���
  if (l == NULL)
  {
    return 0;          // �ڴ����ʧ��
  }                // ָ�뱾������ʱû����ָ��Ŀռ䣬�����Ҫ�����ڴ�ռ䣬������ʹ��&�����пռ�ĵ�ַ
  head = l;
  l->next = NULL;
  l->elem = 0;
  for (int i = 1; i <= n; i++)
  {
    linklist p = (linklist)malloc(sizeof(lnode));
    p->next = NULL;                         // ʹ��β�巨���ڽ���β�����½��
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
    return 0;    // ����δ��ʼ��
  }
  length = head->elem;
  return 1;
}
int Insert(int pos, int ele)
{
  if (head == NULL)
  {
    return 0;              // ����δ��ʼ��
  }
  linklist l = head;
  linklist p = NULL;
  if (pos > head->elem + 1)
  {
    return 2;                    // ����λ�ó����������ƣ�
  }
  for (int i = 0; i <= pos - 1; i++)
  {
    p = l;       // i=0ʱp=head������ָ��ָ����0
    l = l->next;
  }
  linklist s = (linklist)malloc(sizeof(lnode));
  s->next = NULL;
  s->elem = ele;
  l = p->next;                  // ʹ����ʱ�ò��ϵ�l�洢p��ָ�����һλԭַ
  p->next = s;            // ��p��ָ���ָ�����Ϊ�½��Ľ��s��
  s->next = l;                 // ͬʱ��s��ָ���ָ����ֵ��Ϊl����p����ָ��Ľڵ�λ�ã�ʵ�ֲ���
  head->elem++;
  return 1;
}
int Delete(int pos)
{
  if (head == NULL)
  {
    return 0;          // ����δ��ʼ��
  }
  linklist l = head;
  linklist p = NULL;
  if (pos > head->elem)
  {
    return 2;              // ɾ��λ�ó����������ƣ�
  }
  for (int i = 0; i <= pos - 1; i++)
  {
    p = l;                   // i=0ʱp=head������ָ��ָ����0
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
    return 0;                // ����δ��ʼ���������Ѿ�Ϊ��
  }
  linklist l = head->next;
  linklist p = NULL;
  for (int i = 1; i <= head->elem; i++)
  {
    cout << l->elem << endl;
    p = l->next;
    l = p;               // ���һ������ʱp=null��l=p=null����δ������ͻ
  }
  return 1;
}
int Opposite(){
   if (head == NULL || head->next == NULL)
  {
    return 0;                // ����δ��ʼ���������Ѿ�Ϊ��
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
  cout<<"1.��ʼ������������"<<endl;
  cout<<"2.��������"<<endl;
  cout<<"3.�������"<<endl;
  cout<<"4.������"<<endl;
  cout<<"5.ָ��λ�õ�Ԫ��ֵ"<<endl;
  cout<<"6.�����Ѵ���Ԫ�ص�λ��"<<endl;
  cout<<"7.������Ԫ�ص�ֱ��ǰ��"<<endl;
  cout<<"8.������Ԫ�ص�ֱ�Ӻ��"<<endl;
  cout<<"9.�ڵ�i��λ�ò���һ��Ԫ��"<<endl;
  cout<<"10.ɾ����i��Ԫ��"<<endl;
  cout<<"11.����е�����Ԫ��"<<endl;
  cout<<"12.��ʼ������ͷ�巨����β�巨������Ԫ��"<<endl;
  cout<<"13.ʵ�ֵ������������"<<endl;

while(true){
  int index=0;  //����
  int pos=0;   //λ��
  int ele=0;   //Ԫ��
  int n=0;    //������
  int i=0;
  cout<<"-----------�����������,����һ�������˳�����"<<endl;
  cin>>index;
  if(index<0){
    cout<<"�˳�����!"<<endl;
    break;
  }
  switch(index){
    case 1:
    n=create();
    if(n==1){
      cout<<"��ʼ���ɹ�"<<endl;
    }
    if(n==0){
      cout<<"��ʼ��ʧ��"<<endl;
    }
    if(n==2){
      cout<<"�����Ѿ�����ʼ��"<<endl;
    }
    break;
    case 2:
    n=destroy();
    if(n==1){
      cout<<"���ٳɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ��"<<endl;
    }
    break;
    case 3:
    n=clear();
    if(n==1){
      cout<<"��ճɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ���������Ѿ�Ϊ��"<<endl;
    }
    break;
    case 4:
    n=GetLength(i);
    if(n==1){
      cout<<"��ȡ�ɹ�"<<endl;
      cout<<"����ĳ�����"<<i<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ��"<<endl;
    }
    break;
    case 5:
    cout<<"�����������Ԫ��ֵ��ָ��λ��"<<endl;
    cin>>pos;
    n=FindEle(ele,pos);
    if(n==1){
      cout<<"���ҳɹ�"<<endl;
      cout<<"��λ���ϵ�Ԫ��Ϊ"<<ele<<endl;
    }
    if(n==0){
      cout<<"λ�ò��Ϸ�"<<endl;
    }
    if(n==2){
      cout<<"����δ��ʼ���������Ѿ�Ϊ��"<<endl;
    }
    break;
    case 6:
    cout<<"���������λ�õ�Ԫ��"<<endl;
    cin>>ele;
    n=FindPos(pos,ele);
    if(n==1){
      cout<<"���ҳɹ�"<<endl;
      cout<<"��Ԫ�ص�λ��Ϊ"<<pos<<endl;
    }
    if(n==0){
      cout<<"�����в����ڸ�Ԫ��"<<endl;
    }
    if(n==2){
      cout<<"����δ��ʼ���������Ѿ�Ϊ��"<<endl;
    }
    break;
    case 7:
    cout<<"�����������ǰ����Ԫ��"<<endl;
    cin>>ele;
    n=FindFront(ele,i);
    if(n==1){
      cout<<"���ҳɹ�"<<endl;
      cout<<"ǰ��Ϊ"<<i<<endl;
    }
    if(n==0){
      cout<<"������Ԫ��Ϊ��һλ��ǰ��"<<endl;
    }
    if(n==2){
      cout<<"��Ԫ�ز�����"<<endl;
    }
    if(n==3){
      cout<<"����δ��ʼ��������Ϊ��"<<endl; 
    }    
    break;
    case 8:
    cout<<"����������Һ�����Ԫ��"<<endl;
    cin>>ele;
    n=FindNext(ele,i);
    if(n==1){
      cout<<"���ҳɹ�"<<endl;
      cout<<"����Ϊ"<<i<<endl;
    }
    if(n==0){
      cout<<"������Ԫ��Ϊ���һλ�޺��"<<endl;
    }
    if(n==2){
      cout<<"��Ԫ�ز�����"<<endl;
    }
    if(n==3){
      cout<<"����δ��ʼ��������Ϊ��"<<endl; 
    }    
    break;
    case 9:
    cout<<"����������λ��"<<endl;
    cin>>pos;
    cout<<"����������Ԫ��"<<endl;
    cin>>ele;
    n=Insert(pos,ele);
    if(n==1){
      cout<<"����ɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ��"<<endl;
    }
    if(n==2){
      cout<<"����λ�ò��Ϸ�"<<endl;
    }
    break;
    case 10:
    cout<<"������ɾ��Ԫ�ص�λ��"<<endl;
    cin>>pos;
    n=Delete(pos);
    if(n==1){
      cout<<"ɾ���ɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ��"<<endl;
    }
    if(n==2){
      cout<<"ɾ��λ�ò��Ϸ�"<<endl;
    }
    break;
    case 11:
    n=Show();
    if(n==1){
      cout<<"����ɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ����������Ϊ��"<<endl;
    }
    break;
    case 12:
    cout<<"�������봴��������ĳ���"<<endl;
    cin>>i;
    cout<<"������Ԫ��"<<endl;
    n=CreateInsert(i);
    if(n==1){
      cout<<"��������ʼ���ɹ�"<<endl;
    }
    if(n==0){
      cout<<"�ڴ����ʧ��"<<endl;
    }
    if(n==2){
      cout<<"�����ѱ�����"<<endl;
    }
    break;
    case 13:
    n=Opposite();
    if(n==1){
      cout<<"�����ųɹ�"<<endl;
    }
    if(n==0){
      cout<<"����δ��ʼ��������Ϊ��"<<endl;
    }
    break;
    default:
    break;


  }
}
}