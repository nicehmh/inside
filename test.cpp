#include<iostream>
using namespace std;
#define N 30
int D[N][N];
typedef struct dian{
   int x;
   int y;
}DIAN;
/* 21*21 */
/*void huatu(int x,int y){
   for(int i=0;i<21;i++){
        for(int j=flag;j<x+11;j++){
             if(j==x+10&&i==10-y){
                cout<<"* ";
             }else if(i==10&&j==10){
               cout<<"0 ";
             }else{
                cout<<"_ ";
             }
        }
        cout<<endl;
   }
   flag=x+11;
}*/
void Bresenham(DIAN A,DIAN B){

   int dx,dy,x,y,e,k=0;
   dx=B.x-A.x;
   dy=B.y-A.y;
   if(dx==0){
      dy=B.y-A.y;
      if(dy>0){
        y=A.y;
        x=A.x;
        while(y<=B.y){
            D[x+10][10-y]=1;
            y++;
        }
      }else{
        y=B.y;
        x=B.x;
        while(y<=A.y){
            D[x+10][10-y]=1;
            y++;
        }
      }
   }else{
      float k=(float)dy/dx;

      if(0<=k&&k<=1){

          e=-dx;x=A.x;y=A.y;
          while(x<=B.x){
             D[x+10][10-y]=1;
             x++;
             e=e+2*dy;
             if(e>0){
                y++;
                e=e-2*dx;
             }
          }
      }else if(-1<=k&&k<0){
          dy=A.y-B.y;
          e=-dx;x=A.x;y=-A.y;
          while(x<=B.x){
             D[x+10][10+y]=1;
             x++;
             e=e+2*dy;
             if(e>0){
                y++;
                e=e-2*dx;
             }
          }
      }else if(k>1){
          dx=B.y-A.y;
          dy=B.x-A.x;
          e=-dx;x=A.y;y=A.x;
          while(x<=B.y){
             D[y+10][10-x]=1;
             x++;
             e=e+2*dy;
             if(e>0){
                y++;
                e=e-2*dx;
             }
          }
      }else{
          int m;
          m=A.y;
          A.y=-A.x;
          A.x=m;
          m=B.y;
          B.y=-B.x;
          B.x=m;
          e=-dx;x=A.x;y=A.y;
          while(x<=B.x){
             D[-y+10][10-x]=1;
             x++;
             e=e+2*dy;
             if(e>0){
                y++;
                e=e-2*dx;
             }
          }
      }

   }

}
int main(){
   DIAN A[N];
   int n;
   cout<<"请输入多边形的边数:";
   cin>>n;
   for(int i=0;i<n;i++){
        cout<<"请输入第"<<i<<"个点:";
        cin>>A[i].x>>A[i].y;
        cout<<endl;
   }
   for(int j=0;j<n-1;j++){
           Bresenham(A[j],A[j+1]);
   }
   Bresenham(A[0],A[n-1]);
   cout<<endl;
   int flag=0;
   for(int i=0;i<21;i++){
      for(int j=0;j<21;j++){
         if(D[j][i]==1){
            cout<<"* ";
            if(flag==0){
              flag=1;
            }else{
              flag=0;
            }
         }else if(flag==1&&D[j][i]==0){
            cout<<"* ";
         }else if(i==10&&j==10){
            cout<<"0 ";
         }else{
            cout<<"_ ";
         }
      }
      flag=0;
      cout<<endl;
   }
 }
