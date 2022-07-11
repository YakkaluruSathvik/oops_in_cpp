#include <iostream>
#include <string>
using namespace std;

//   Abstraction
class AbstractEmployee{
    virtual void AskPromotion()=0;
};

class Employee:AbstractEmployee{
//   Default - Private
//   Encapsulation
private:
    string Company;
    int Age;
protected:
    string Name;
public:
//  getters and setters
    void setName(string name){
        Name = name;
    }
    
    string getName(){
        return Name;
    }
    
    void setCompany(string company){
        Company = company;
    }
    
    string getCompany(){
        return Company;
    }
    
    void setAge(int age){
        if (age>=18)
        Age = age;
    }
    
    int getAge(){
        return Age;
    }
    
    void fun(){
        cout<< "Name - " << Name << endl;
        cout<< "Company - " << Company << endl;
        cout<< "Age - " << Age << endl;
    }
    
    // Constructor Parametrized ('Default Constructor is initialised' even if we don't make any other Constructor inside class )
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    };
    
    void AskPromotion(){
        if (Age>=30)
        cout << Name  << " Promoted!!" << endl;
        else
        cout << Name  << " Not Promoted!!" << endl;
    }
    
    // Polymorphism
    virtual void work(){
        cout << Name << " is checking emails and fixing bugs " << endl;
    }
};

class Developer:public Employee{
// public in class inheritence is used to access to it's parent class(es) methods
    public:
    string FavProgramminglang;
    Developer(string name, string company, int age, string favProgramminglang)
    :Employee(name , company, age)
    {
        FavProgramminglang = favProgramminglang;
    }
    
    void FixBug(){
        cout<< getName() << " fixed the bug using " << FavProgramminglang << endl;
        // private variable of class Employee can be accessed by changung it into protected to avoid error
        cout<< Name << " fixed the bug using " << FavProgramminglang << endl;
    }
    
    void work(){
        cout << Name << " is developing software and fixing bugs " << endl;
    }
};

class Teacher:public Employee{
// public in class inheritence is used to access to it's parent class(es) methods
    public:
    string Subject;
    Teacher(string name, string company, int age, string subject)
    :Employee(name, company, age)
    {
        Subject = subject;
    }
    
    void prepareLesson(){
        cout<< getName() << " is preparing " << Subject << endl;
        // private variable of class Employee can be accessed by changung it into protected to avoid error
        cout<< Name << " is preparing " << Subject << endl;
    }
    
    void work(){
        cout << Name << " is checking backlogs and making lesson plans " << endl;
    }
};

int main()
{
    Employee O1 = Employee("Sathvik", "Microsoft", 35);
    O1.fun();
    Employee O2 = Employee("Gwen stacy", "Marvel", 23);
    O2.fun();
    
    O2.setAge(23);
    cout << O2.getAge() << endl;
    
    O1.AskPromotion();
    O2.AskPromotion();
    
    Developer d = Developer("Sathvik", "Microsoft", 35, "C++");
    d.FixBug();
    d.AskPromotion();
    Teacher t = Teacher("John", "Stanford", 65, "Genetics");
    t.prepareLesson();
    t.AskPromotion();
    
    // Polymorphism
    d.work();
    t.work();
    
    // Polymorphism using pointers to derived class from base class & use of Virtual function
    Employee *e1 = &d;
    Employee *e2 = &t;
    
    e1->work();
    e2->work();
    
    return 0;
}