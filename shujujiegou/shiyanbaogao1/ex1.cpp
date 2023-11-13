#include<iostream>
using namespace std;
void input(int a[],int n){
  bool inp=false;    //bull数监视是否满足条件
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
              //for循环与dowhile循环的嵌套，dowhile在监视数不触发的情况下只执行一次，相当于不存在
  }while(inp);      //使用dowhile语句，在不满足条件的状态下先执行一次语句，若触发
              //bull数改变条件则改变满足循环条件，将cin设置在while语句当中，实现对同一个字符的循环覆盖
}
}
void jiao(int a[],int b[],int c[], int n,int m,int &countc){
                        //引用countc实现对主函数main的改变
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i]==b[j]){           //简单将ab中相同的元素复制到c，并使记录数countc自增1
        c[countc]=a[i];
        countc=countc+1;
      }
    }
  }
  
}
void bing(int a[], int b[], int c[], int n, int m,int &countc) {

  // 将数组a的元素复制到c
  for (int i = 0; i < n; i++) {
    c[countc] = a[i];
    countc++;
  }

  // 将数组b的元素复制到c，但仅复制不在c中的元素
  for (int j = 0; j < m; j++) {
    bool existsInC = false;

    // 检查b[j]是否在c中
    for (int k = 0; k < countc; k++) {
      if (b[j] == c[k]) {
        existsInC = true;
        break;
      }
    }

    // 如果b[j]不在c中，则将其添加到c
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
    }          //使用a中的元素对b中的元素进行遍历
  }      //这个for循环是a中的一个元素i对b的遍历，当a[i]与每一个b元素都不同，则其属于a-b
        //每触发一次不等于便counta记录数自增1，对元素个数为m的b来说，counta=m时便为所求
  if(counta==m){
    c[countc]=a[i];
    countc=countc+1;      //将符合条件的元素复制到c
  }      //依然是对于同一个a[i]
 } 
       //循环对每个a遍历
  if(countc==0){
    cout<<"a-b集合为空"<<endl;   //集合空时提示
  }
}
int main(){
  cout << "1---输入集合A和B" << endl;
  cout << "2---求集合A交B" << endl;
  cout << "3---求集合A并B" << endl;
  cout << "4---求集合A-B" << endl;
  cout << "退出，输入一个负数！" << endl;
  
  int guide = 0;     //导航数
  int n = 0;
  int m = 0;
  int a[100];
  int b[100];
  int c[100];
  

  while (true) {
    cin >> guide;
    int countc=0;        //设置在while中而不是case中，避免范围错误//
    if (guide < 1 || guide > 4) {
      cout << "退出程序" << endl;
      break; // 用户选择退出，跳出循环
    }

    switch (guide) {
      case 1:
        cout << "请输入第一个数组的元素个数" << endl;
        cin >> n;
        cout << "请输入第一个数组的元素" << endl;
        input(a, n);
        cout << "请输入第二个数组的元素个数" << endl;
        cin >> m;
        cout << "请输入第二个数组的元素" << endl;
        input(b, m);
        cout << "输入结束，请进行下一步操作" << endl;
        break;
      case 2:
        jiao(a, b, c, n, m,countc);
        if(countc==0){
        cout<<"两集合没有重复的元素,请进行下一步操作"<<endl;     //集合为空时输出提示
                }
        else{
        cout << "集合A交B的结果：" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
        cout<<"请进行下一步操作"<<endl;
        }
        break;
      case 3:
          
          bing(a, b, c, n, m,countc);
          cout << "集合A并B的结果：" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
          cout<<"请进行下一步操作"<<endl;
              break;

      case 4:
        jian(a,b,c,n,m,countc);
        if(countc==0){
          cout<<"a-b为空集，请进行下一步操作"<<endl;     //集合为空时输出提示
              }
         else{ 
          cout << "集合A减B的结果：" << endl;
          for(int i=0;i<countc;i++){
           if(i<countc-1){
            cout<<c[i]<<",";
           }
           else{
            cout<<c[i]<<endl;
           } 
          }
          cout<<"请进行下一步操作"<<endl;
          }
        break;
        
      default:
        break;
    }
  }
  
  return 0;

 
  
       //在swithch里根据选择的是交还是并来创建数组c，使用一个记录数？
  
  
  
}