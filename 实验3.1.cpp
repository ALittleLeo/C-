#include <iostream>
#include <iomanip>
using namespace std;
class Double
{
public:
    Double(int x = 0, int y = 0)
    {
        m_x = x;
        m_y = y;
    }
    void show()
    {
        cout<<m_x<<"."<<m_y;
    }
    double getdouble()
    {
        double sum;
        double tmp = m_y;
        int t = m_y;
        tmp *= 0.1;
        while(t /10 > 0)
        {
            tmp *= 0.1;
            t /= 10;
        }
        sum = m_x + tmp;
        return sum;
    }
    void setX(int x)
    {
        m_x = x;
    }
    void setY(int y)
    {
        m_y = y;
    }
    ~Double()
    {

    }
private:
    int m_x;
    int m_y;
};
class DoubleArray
{
public:
    DoubleArray(int *a, int *b, int n)
    {
        int i;
        num = n;
        data = new Double[num];
        for(i = 0; i < num; i++)
        {
            data[i].setX(a[i]);
            data[i].setY(b[i]);
        }
    }
    void show()//��������ʾ���е�Ԫ�ء����ʱ������Ԫ������֮����1���ո��������ǰ���޶���ո�������һ�����з���
    {
        int i;
        data[0].show();
        for(i = 1; i < num; i++)
        {
            cout<<" ";
            data[i].show();
        }
        cout<<endl;
    }
    DoubleArray& sortArray(bool a)//��������������򡣵�����ֵΪtrueʱ��������Ϊ�����򣻷���Ϊ�ݼ���
    {
        int i,j;
        Double tap;
        if(a)
        {
            for(i = 1; i < num; i++)
            {
                for(j = 0; j < num - i; j++)
                {
                    if(data[j].getdouble() > data[j+1].getdouble())
                    {
                        tap = data[j];
                        data[j] = data[j+1];
                        data[j+1] = tap;
                    }
                }
            }
        }
        else
        {
            for(i = 1; i < num; i++)
            {
                for(j = 0; j < num - i; j++)
                {
                    if(data[j].getdouble() < data[j+1].getdouble())
                    {
                        tap = data[j];
                        data[j] = data[j+1];
                        data[j+1] = tap;
                    }
                }
            }
        }
        return *this;
    }
    DoubleArray& insertAtPos(Double a, int n)//���ڵ�2������ָ����λ�ò����1�����������Ķ���ע�⣺���ڳ���Ϊn�����飬�Ϸ��Ĳ���λ��Ϊ[0,n]��
    {
        if(n >= 0 && n <= num)
        {
            int i;
            Double *tmp = new Double[num];
            for(i = 0; i < num; i++)
            {
                tmp[i] = data[i];
            }
            data = new Double[num + 1];
            for(i = 0; i < n; i++)
            {
                data[i] = tmp[i];
            }
            num++;
            data[n] = a;
            for(i = n+1; i < num; i++)
            {
                data[i] = tmp[i-1];
            }
            delete []tmp;//�ͷ���ʱ����
            return *this;

        }
    }
    DoubleArray& deleteADouble(Double d)//��ɾ�����������������������ȵ�Ԫ�ء�
    {
        int i,j;
        for(i = 0; i < num; i++)
        {
            if(data[i].getdouble() == d.getdouble())
            {
                for(j = i; j < num; j++)
                {
                    data[j] = data[j+1];
                }
                num--;
            }
        }
        return *this;
    }
private:
    Double *data;
    int num;
};
int main()
{
    Double one, two(10,10);
    int num, i, a, b, c, *iPart, *dPart;
    cin>>num;
    iPart = new int[num];
    dPart = new int[num];
    for (i = 0; i < num; i++)
    {
        cin>>iPart[i]>>dPart[i];
    }
    DoubleArray test(iPart, dPart, num);
    test.show();
    test.sortArray(true).show();
    test.sortArray(false).show();
    cin>>num;
    for (i = 0; i < num; i++)
    {
        cin>>a>>b>>c;
        test.insertAtPos(Double(a, b), c);
    }
    test.show();
    test.deleteADouble(Double()).show();
    delete[] iPart;
    delete[] dPart;
    return 0;
}
