#include<iostream>
using namespace std;
struct book{
int price;
char author[20];
int pages;
};
book func(book &b1,book &b2,book &b3)
{
if(b1.price>b2.price)
b3=b1;
else if(b2.price>b1.price)
b3=b2;
return b3;
}
int main()
{
book b1,b2,b3;
cout<<"enter the price of the 1ST book:";
cin>>b1.price;
cout<<"enter the name of the 1ST author:";
cin>>b1.author;
cout<<"enter the pages of the 1ST book:";
cin>>b1.pages;
cout<<"enter the price of the 2ND book:";
cin>>b2.price;
cout<<"enter the name of the 2ND author:";
cin>>b2.author;
cout<<"enter the pages of the 2ND book:";
cin>>b2.pages;
func(b1,b2,b3);
cout<<"The details of the more price book are:"<<endl;
cout<<"Price="<<b3.price<<endl<<"Author="<<b3.author<<endl<<"Pages="<<b3.pages;
}
