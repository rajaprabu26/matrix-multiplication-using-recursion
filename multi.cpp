#include <iostream>
using namespace std;
#include"multi.h"
int main()
{
    static int m1,n1,m2,n2,n,ex;
    cout<<"Enter rows and columns for Matrix A respectively: ";
    cin>>m1>>n1;
    cout<<"Enter rows and columns for Matrix B respectively: ";
    cin>>m2>>n2;
    if (n1 != m2)
    {
        cout<<"Matrix multiplication not possible.\n";
    }
    mul mu1(m1,m2);
    mul mu2(m1,m2),mu3(m1,m2),mu4(m1,m2),mu5(m1,m2);
    do
    {
        cout<<"1.insert\n2.display\n";
        cin>>n;
        switch(n)
        {
        case 1:
            {
                mu1.get(mu1.a,n1);
                mu1.get(mu1.b,n2);
                mu1.get(mu1.c,n2);
                mu4.get(mu4.c,n2);
                cout<<"Enter elements in Matrix A:\n";
                mu2.getdata1(mu1.a,m1,n1);
                cout<<"\nEnter elements in Matrix B:\n";
                mu3.getdata2(mu1.b,m2,n2);
                mu4.multiply(m1, n1, mu1.a, m2, n2, mu1.b, mu1.c);
                break;
            }
        case 2:
            {
                cout<<"On matrix multiplication of A and B the result is:\n";
                mu4.display(m1, n2, mu1.c);
                break;
            }
        default:
            {

                cout<<"enter the correct choice\n";
                break;
            }
        }
        cout<<"do you want continue\n1.yes\n0.no\n";
        cin>>ex;
    }while(ex!=0);
}
