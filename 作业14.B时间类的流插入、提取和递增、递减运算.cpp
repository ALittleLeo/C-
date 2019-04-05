#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time()
    {

    }
    friend istream& operator>>(istream &is, Time &t);//ȫ��Ҫ���ã�����ֵ�����ã�������������á��������þ��ã�ʵ�ڲ����õ�ʱ���ٲ���
    friend ostream& operator<<(ostream &os, const Time &t);//����constΪʲô�ᱨ���أ�ΪʲôҪ��const�أ���ס�ɣ�һ�㶼Ҫ��const
    Time& getTime(int a)
    {
        if(a < 0)
            a += 3600*24;
        m_hour = a/3600%24;
        m_minute = a%3600/60;
        m_second = a%60;
        return *this;
    }
//    Time& getTime(int a)
//    {
//        if(a < 0)
//        {
//            a += 3600*24;
//        }
//        m_hour = a/3600%24;
//        m_minute = a%3600/60;
//        m_second = a /60;
//        return *this;
//    }
    Time& operator++()//ǰ׺++�����
    {
        ++data;
        getTime(data);
        return *this;
    }
    Time& operator--()//ǰ׺--�����
    {
        --data;
        getTime(data);
        return *this;
    }
    Time operator++(int)//��׺++�����
    {
        Time tmp;
        tmp = *this;
        data++;
        getTime(data);
        return tmp;
    }
    Time operator--(int)//��׺--�����
    {
        //��ȡֵ�ټ�һ����Ҫһ����ʱ����
        Time tmp;
        tmp = *this;
        data--;
        getTime(data);
        return tmp;
    }
private:
    int m_hour;
    int m_minute;
    int m_second;
    int flag;
    int data;
};
istream& operator>>(istream &is, Time &t)
{
    t.flag = 0;
    is>>t.m_hour>>t.m_minute>>t.m_second;
    t.data = t.m_hour*3600 + t.m_minute*60 + t.m_second;
    if(t.m_hour >= 24 || t.m_minute >= 60 || t.m_second >= 60 || t.m_hour < 0 || t.m_minute < 0 || t.m_second < 0)
    {
        t.flag = 1;
    }
    return is;
}
ostream& operator<<(ostream &os, const Time &t)
{
    if(t.flag == 1)
    {
        os<<"error!!!";
    }
    else
    {
        os<<setw(2)<<setfill('0')<<t.m_hour<<":";
        os<<setw(2)<<setfill('0')<<t.m_minute<<":";
        os<<setw(2)<<setfill('0')<<t.m_second;
    }
    return os;
}
int main()
{
    Time t;
    int cases;
    cin>>cases;
    cout<<setw(8)<<left<<"++t"<<" ";
    cout<<setw(8)<<left<<"--t"<<" ";
    cout<<setw(8)<<left<<"t"<<" ";
    cout<<setw(8)<<left<<"t--"<<" ";
    cout<<setw(8)<<left<<"t++"<<" ";
    cout<<setw(8)<<left<<"t"<<right<<endl;
    for(int i = 1; i <= cases; ++i)
    {
        cin>>t;
        cout<<(++t)<<" ";
        cout<<(--t)<<" ";
        cout<<t<<" ";
        cout<<t--<<" ";
        cout<<t++<<" ";
        cout<<t<<endl;
    }
}
