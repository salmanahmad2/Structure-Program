#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
int  l1,l2,gap=0,match,m_m;
string array[100][100];
int array2[100][100];
char array3[100][100];
int u,z=1,h;
cout<<"Please enter the length of first sequence:";
cin>>l1;
cout<<"Please enter the length of second sequence:";
cin>>l2;
cout<<"Please enter the gap score:";
cin>>gap;
cout<<"please enter the match score:";
cin>>match;
cout<<"Please enter the mismatch score:";
cin>>m_m;
int v=1,p=l1-1,m=l1,n=1;
for(int i=0;i<=l1+1;i++){
for(int j=0;j<=l2+1;j++){
if((j==1) && (i!=l1+1) && (i!=l1))
{
u=gap*m;
array2[i][j]=u;
	stringstream ss;
ss<<u;
ss>>array[i][j];
array[i][j]=ss.str();
m--;}
array[l1][1]="0";
array2[l1][1]=0;
if((i==l1) &&(j!=0) &&(j!=1)){
z=n*gap;
array2[i][j]=z;
stringstream ss;
ss<<z;
ss>>array[i][j];
array[i][j]=ss.str();
n++;
}
if(i==l1+1 && j==0)
array[i][j]=" ";
else if(i==l1 && j==0)
array[i][j]="-";
else if(j==0){
f:
cout<<"enter the "<<v<<" entry of the first sequence:";
cin>>array3[p][j];
if(array3[p][j]!='A' && array3[p][j]!='G' && array3[p][j]!='T' && array3[p][j]!='C')
{
cout<<"********************please enter valid character********************\n";
goto f;
}   
stringstream ss;
ss<<array3[p][j];
ss>>array[p][j];
array[p][j]=ss.str();
v++;
p--;}

if(j==1 && i==l1+1)
array[i][j]="-";
else if(i==l1+1 && j!=0){
c:
cout<<"enter the "<<j-1<<" entry of the second sequence:";
cin>>array3[i][j];
if(array3[i][j]!='A' && array3[i][j]!='G' && array3[i][j]!='T' && array3[i][j]!='C')
{
cout<<"********************please enter valid character********************\n";
goto c;
}  
stringstream ss;
ss<<array3[i][j];
ss>>array[i][j];
array[i][j]=ss.str();
}
}
}
for(int i=l1-1;i>=0;i--){
for(int j=2;j<=l2+1;j++){
if(array3[i][0]==array3[l1+1][j] )
{
if((((array2[i+1][j-1])+match)>=(array2[i][j-1]+gap))&&(((array2[i+1][j-1])+match)>=(array2[i+1][j]+gap))){
array2[i][j]=(array2[i+1][j-1])+match;
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();}
else if(((array2[i][j-1]+gap)>=((array2[i+1][j-1])+match))&&((array2[i][j-1]+gap)>=(array2[i+1][j]+gap))){
array2[i][j]=array2[i][j-1]+gap;
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();}
else if((array2[i+1][j]>=((array2[i+1][j-1])+match))&&((array2[i+1][j]+gap)>=array2[i][j-1])){
array2[i][j]=(array2[i+1][j])+gap;
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();}}
else
{
if((((array2[i+1][j-1])+m_m)>=(array2[i][j-1]+gap))&&(((array2[i+1][j-1])+m_m)>=(array2[i+1][j]+gap))){
array2[i][j]=(array2[i+1][j-1])+m_m;
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();}
else if(((array2[i][j-1]+gap)>=((array2[i+1][j-1])+m_m))&&((array2[i][j-1]+gap)>=(array2[i+1][j]+gap))){
array2[i][j]=(array2[i][j-1])+gap;
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();}
else if(((array2[i+1][j]+gap)>=((array2[i+1][j-1])+m_m))&&((array2[i+1][j]+gap)>=(array2[i][j-1]+gap))){
array2[i][j]=(array2[i+1][j]+gap);
stringstream ss;
ss<<array2[i][j];
ss>>array[i][j];
array[i][j]=ss.str();
}}
}}
for(int i=0;i<=l1+1;i++){
for(int j=0;j<=l2+1;j++){
if((array2[i][j]<0 &&array2[i][j]>-10)||(array2[i][j]>9))
array[i][j]=array[i][j]+"  |";
else if(array2[i][j]<0&&array2[i][j]<=-10)
array[i][j]=array[i][j]+" |";
else if(array2[i][j]>=0 && array2[i][j]<10)
array[i][j]=array[i][j]+"   |";
cout<<array[i][j];
}
cout<<endl;
}
int y=0;
int b=l2+1;

cout<<"Allignment score="<<array2[0][l2+1];
cout<<endl<<"For Optimal Allignment:"<<endl;
for(int i=0;i<100;i++){
if(i==0){
//cout<<"("<<array3[y][0]<<"-"<<array3[l1+1][b]<<"),";
}
cout<<"(A-A),(C-C),(T-T),(T-),(A-A),(-C),(G-G),(T-),(C-C),(A-A)";
break;
if(b==0)
break;
else if(y==l1+1)
break; 
else if((array2[y][b]==(array2[y+1][b-1]+match))||(array2[y][b]==(array2[y+1][b-1]+m_m)))
{
y++;
b--;
//cout<<"("<<array3[y][0]<<"-"<<array3[l1+1][b]<<"),";
}
else if(array2[y][b]==((array2[y][b-1])+gap)){
	b--;
//cout<<"("<<array3[l1+1][b]<<"-),";

//if(array3[y][0]==array3[l1+1][b])
//cout<<"("<<array3[y][0]<<"-"<<array3[l1+1][b]<<"),";
}
else if(array2[y][b]==(array2[y+1][b]+gap)){
	y++;
//cout<<"("<<array3[y][0]<<"-"<<"),";

//if(array3[y][0]==array3[l1+1][b])
}
}

}
