#include<iostream>
using namespace std;
void input(int a[],int n){
  bool inp=false;    //bull�������Ƿ���������
  for(int i=0;i<n;i++){
   do{
    cin>>a[i];
    inp=false;
    for (int j=i-1;j>=0;j--){
      if (a[i]==a[j]){
        cout<<"false,pls input again"<<endl;
        inp=true;
      }
    }
              //forѭ����dowhileѭ����Ƕ�ף�dowhile�ڼ������������������ִֻ��һ�Σ��൱�ڲ�����
  }while(inp);      //ʹ��dowhile��䣬�ڲ�����������״̬����ִ��һ����䣬������
              //bull���ı�������ı�����ѭ����������cin������while��䵱�У�ʵ�ֶ�ͬһ���ַ���ѭ������
}
}
void jiao(int a[],int b[],int c[], int n,int m,int &countc){
                        //����countcʵ�ֶ�������main�ĸı�
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i]==b[j]){           //�򵥽�ab����ͬ��Ԫ�ظ��Ƶ�c����ʹ��¼��countc����1
        c[countc]=a[i];
        countc=countc+1;
      }
    }
  }
  
}
void bing(int a[], int b[], int c[], int n, int m,int &countc) {

  // ������a��Ԫ�ظ��Ƶ�c
  for (int i = 0; i < n; i++) {
    c[countc] = a[i];
    countc++;
  }

  // ������b��Ԫ�ظ��Ƶ�c���������Ʋ���c�е�Ԫ��
  for (int j = 0; j < m; j++) {
    bool existsInC = false;

    // ���b[j]�Ƿ���c��
    for (int k = 0; k < countc; k++) {
      if (b[j] == c[k]) {
        existsInC = true;
        break;
      }
    }

    // ���b[j]����c�У�������ӵ�c
    if (!existsInC) {
      c[countc] = b[j];
      countc++;
    }
  }
}

void jian(int a[],int b[],int c[], int n,int m,int &countc){
 for(int i=0;i<n;i++){
  int counta=0;
  for(int j=0;j<m;j++){
    if(a[i]!=b[j]){
      counta=counta+1;
    }          //ʹ��a�е�Ԫ�ض�b�е�Ԫ�ؽ��б���
  }      //���forѭ����a�е�һ��Ԫ��i��b�ı�������a[i]��ÿһ��bԪ�ض���ͬ����������a-b
        //ÿ����һ�β����ڱ�counta��¼������1����Ԫ�ظ���Ϊm��b��˵��counta=mʱ��Ϊ����
  if(counta==m){
    c[countc]=a[i];
    countc=countc+1;      //������������Ԫ�ظ��Ƶ�c
  }      //��Ȼ�Ƕ���ͬһ��a[i]
 } 
       //ѭ����ÿ��a����
  if(countc==0){
    cout<<"a-b����Ϊ��"<<endl;   //���Ͽ�ʱ��ʾ
  }
}
int main(){
  cout << "1---���뼯��A��B" << endl;
  cout << "2---�󼯺�A��B" << endl;
  cout << "3---�󼯺�A��B" << endl;
  cout << "4---�󼯺�A-B" << endl;
  cout << "�˳�������һ��������" << endl;
  
  int guide = 0;     //������
  int n = 0;
  int m = 0;
  int a[100];
  int b[100];
  int c[100];
  

  while (true) {
    cin >> guide;
    int countc=0;        //������while�ж�����case�У����ⷶΧ����//
    if (guide < 1 || guide > 4) {
      cout << "�˳�����" << endl;
      break; // �û�ѡ���˳�������ѭ��
    }

    switch (guide) {
      case 1:
        cout << "�������һ�������Ԫ�ظ���" << endl;
        cin >> n;
        cout << "�������һ�������Ԫ��" << endl;
        input(a, n);
        cout << "������ڶ��������Ԫ�ظ���" << endl;
        cin >> m;
        cout << "������ڶ��������Ԫ��" << endl;
        input(b, m);
        cout << "����������������һ������" << endl;
        break;
      case 2:
        jiao(a, b, c, n, m,countc);
        if(countc==0){
        cout<<"������û���ظ���Ԫ��,�������һ������"<<endl;     //����Ϊ��ʱ�����ʾ
                }
        else{
        cout << "����A��B�Ľ����" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
        cout<<"�������һ������"<<endl;
        }
        break;
      case 3:
          
          bing(a, b, c, n, m,countc);
          cout << "����A��B�Ľ����" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
          cout<<"�������һ������"<<endl;
              break;

      case 4:
        jian(a,b,c,n,m,countc);
        if(countc==0){
          cout<<"a-bΪ�ռ����������һ������"<<endl;     //����Ϊ��ʱ�����ʾ
              }
         else{ 
          cout << "����A��B�Ľ����" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
          cout<<"�������һ������"<<endl;
          }
        break;
        
      default:
        break;
    }
  }
  
  return 0;

 
  
       //��swithch�����ѡ����ǽ����ǲ�����������c��ʹ��һ����¼����
  
  
  
}