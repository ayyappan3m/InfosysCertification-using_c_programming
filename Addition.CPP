#include <stdio.h>
#include<iostream>
using namespace std;
int numCount(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num /= 10;
    }
    return count;
}
int numMod(int count)
{
    int mod = 1;
    for(int i = 1;i <= count;i++)
        mod *= 10;
    return mod;
}
int main()
{
    int num = 1348129;
    int mod = numMod(numCount(num) - 1);
    //cout<<num<<"\t"<<mod<<"\n";
    int temp = num;
    int first = 0;
    int second = 0;
    int flag = 1;
    while(num > 10)
    {
        int t = (num/mod);
        if(t == 3){
            flag = 0;
            //cout<<"inside";
            
        }
        //cout<<num/mod<<"\t"<<flag<<"\n";
        if(num/mod != 3 && flag == 1)
        {
            first += num/mod;
            //cout<<num/mod<<"\n";
        }
        
        //cout<<t<<"\t"<<flag<<"\n";
        if(num/mod == 8)
            flag = 1;
        num = num%mod;
        mod /= 10;
        if(num<10)
            mod = 10;
    }
    first += num;
    flag = 0;
    mod = numMod(numCount(temp) - 1);
    //cout<<temp/mod;
    cout<<"Input:"<<temp<<"\n";
    while(temp/mod!=8)
    {
        //cout<<temp/mod<<"\n";
        if(temp/mod == 3)
        {
            
            flag = 1;
        }
        if(flag == 1)
            second = second * 10 + (temp/mod);
        temp = temp%mod;
        mod /= 10;
        if(temp<10)
            mod = 10;
            
    }
    second =second * 10 + 8;
    cout<<"Output:"<<first+second;
    return 0;
}
