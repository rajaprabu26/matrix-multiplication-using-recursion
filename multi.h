#include <iostream>
using namespace std;

class mul
{
    public:
    int **a,**b,**c;
    mul(int m11,int m22)
    {
        a = new int *[m11];
        b = new int *[m22];
        c = new int *[m11];
    }
    void get(int *ma[10],int size1)
    {
        static int i = 0;
        if(size1>i)
        {
            ma[i] = new int[size1];
            i++;
            get(ma,size1);
        }
        else
        {
            i = 0;
            return;
        }
    }

    void getdata1(int *a[10],int m11,int n11)
    {
        static int i = 0,j = 0;
        if(m11 > i)
		{
			if(n11 > j)
			{
                cin>>a[i][j];
                j++;
                getdata1(a,m11,n11);
			}
            j = 0;
			i++;
			getdata1(a,m11,n11);
		}
		else
        {
            return;
        }
    }

    void  getdata2(int *b[10],int m22,int n22)
    {
        static int l = 0,s = 0;
        if(m22>l)
		{
			if(n22>s)
			{
				cin>>b[l][s];
				s++;
				getdata2(b,m22,n22);
			}
			s = 0;
			l++;
			getdata2(b,m22,n22);
		}
		else
        {
            return;
        }
    }
    void multiply (int m11, int n11, int *a[10], int m22, int n22, int *b[10], int *c[10])
    {
        static int i = 0, j = 0, k = 0;
        if (i >= m11)
        {
            return;
        }
        else if (i < m11)
        {
            if (j < n22)
            {
                if (k < n11)
                {
                    c[i][j] += a[i][k] * b[k][j];
                    k++;
                    multiply(m11, n11, a, m22, n22, b, c);
                }
                k = 0;
                j++;
                multiply(m11, n11, a, m22, n22, b, c);
            }
            j = 0;
            i++;
            multiply(m11, n11, a, m22, n22, b, c);
        }
    }

    void display(int m11, int n11, int *c[10])
    {
        static int i = 0, j = 0;
        if(i < m11)
        {
            if(j < n11)
            {
                cout<<c[i][j]<<"\t";
                j++;
                display(m11,n11,c);
            }
            j = 0;
            i++;
            display(m11,n11,c);
        }
        else
        {
            return;
        }
    }
};
