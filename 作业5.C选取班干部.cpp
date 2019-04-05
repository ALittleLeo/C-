#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Student
{
public:

    Student(string name, bool sex, int grade)//��ʼ��һ������ע�⣺���е�next��ʼ��ΪNULL��
    {
        m_name = name;
        m_sex = sex;
        m_grade = grade;
        next = NULL;
        cout<<"A student named by "<<m_name<<" is created!"<<endl;
    }
    ~Student()
    {
        cout<<"A student named by "<<m_name<<" is erased."<<endl;
    }
    void showInfo()//���һ��ѧ������Ϣ��next���⡣
    {
        cout<<"name = "<<m_name<<", sex = "<<m_sex<<", grade = "<<m_grade<<";";
    }
    Student* getNext()//���nextָ�롣
    {
        return next;
    }
    void setNext(Student *a)//����nextָ��ָ�����
    {
        next = a;
    }

protected:
    string m_name;
    bool m_sex;
    int m_grade;
    Student *next;//ָ����һ��ѧ��ָ�롣
};
class StudentCadre : public Student
{
public:
    StudentCadre(string name, bool sex, int grade, string pos):Student(name, sex, grade), position(pos)
    {
        cout<<"A student cadre with position "<<position<<" is created."<<endl;
    }
    ~StudentCadre()
    {

    }
    void showInfo()
    {
        cout<<"name = "<<m_name<<", sex = "<<m_sex<<", grade = "<<m_grade<<"; position = "<<position<<".";
    }
private:
    string position;
};


int main()
{
    int num;
    string name, position;
    bool sex;
    int grade;
    Student *header, *student, *curStudent;

    cin>>name>>sex>>grade>>position;
    header = new StudentCadre(name, sex, grade,position);
    curStudent = header;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cin>>name>>sex>>grade;
        student = new Student(name, sex, grade);
        curStudent -> setNext(student);
        curStudent = curStudent -> getNext();
    }
    ((StudentCadre*)header) -> showInfo();
    cout<<endl;
    curStudent = header;
    while (curStudent -> getNext() != NULL)
    {
        curStudent = curStudent -> getNext();
        curStudent->showInfo();
        cout<<endl;
    }

    curStudent = header;
    while (curStudent != NULL)
    {
        student = curStudent;
        curStudent = curStudent -> getNext();
        delete student;
    }
    return 0;
}







//#include<iostream>
//#include<string>
//using namespace std;
//classStudent
//{
//public:
//    string name;
//    bool sex;
//    int grade;
//    Student *next;
//    Student(string _name, bool_sex,int_grade):name(_name),grade(_grade),sex(_sex),next(NULL)
//    {
//        cout<<"A student named by "<<name<<" is created!"<<endl;
//    }
//
//    ~Student()
//    {
//        cout<<"A student named by "<<name<<" is erased."<<endl;
//    }
//    void showInfo()
//    {
//        cout<<"name = "<<name<<", sex = "<<sex<<", grade ="<<grade<<";"
//
//    }
//    Student* getNext()
//    {
//        return next;
//    }
//    voidsetNext(Student*a)
//    {
//        next =a;
//    }
//};
//class StudentCadre :
//    public Student
//{
//    string position;
//public:
//    StudentCadre(string _name, bool_sex, int_grade, string pos):Student( _name,_sex, _grade),position(pos)
//    {
//        cout<<"A student cadre with position "<<position<<" is created."<<endl;
//    }
//    ~StudentCadre() {}
//    void showInfo()
//    {
//        cout<<"name = "<<name<<", sex = "<<sex<<", grade ="<<grade<<"; position = "<<position<<".";
//    }
//};
//int main()
//
//
//
//{
//
//
//
//
//
//
//
//
//
//
//
//    intnum;
//
//
//
//
//
//
//
//
//
//
//
//    string name, position;
//
//
//
//
//
//
//
//
//
//
//
//    boolsex;
//
//
//
//
//
//
//
//
//
//
//
//    intgrade;
//
//
//
//
//
//
//
//
//
//
//
//    Student *header, *student, *curStudent;
//
//
//
//
//
