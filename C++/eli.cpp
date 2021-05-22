#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::string;

class AbstractEmployee
{
     virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private:
     string Company;
     int Age;

protected:
     string Name;

public:
     void setName(string name)
     {
          Name = name;
     }
     string getName()
     {
          return Name;
     }

     void setCompany(string company)
     {
          Company = company;
     }
     string getCompany()
     {
          return Company;
     }

     void setAge(int age)
     {
          if (age >= 18)
          {
               Age = age;
          }
     }
     int getAge()
     {
          return Age;
     }

     void printInfo()
     {
          cout << "Name -" << Name << std::endl;
          cout << "Company -" << Company << std::endl;
          cout << "Age -" << Age << std::endl;
     }

     Employee(string name, string company, int age)
     {
          Name = name;
          Company = company;
          Age = age;
     }

     void AskForPromotion()
     {
          if (Age > 30)
          {
               cout << Name << " got promoted!" << std::endl;
          }
          else
          {
               cout << Name << ", sorry NO promotion for you!" << std::endl;
          }
     }
     virtual void work()
     {
          cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
     }
};

class Developer : public Employee
{
private:
     string FavProgrammingLanguage;

public:
     void setFav(string lang)
     {
          lang = FavProgrammingLanguage;
     }
     string getFav()
     {
          return FavProgrammingLanguage;
     }
     Developer(string name, string company, int age, string lang)
         : Employee(name, company, age)
     {
          FavProgrammingLanguage = lang;
     }

     void FixBug()
     {
          cout << Name << " fixed buges using " << getFav() << std::endl;
     }

     void work()
     {
          cout << Name << " writing " << FavProgrammingLanguage << " code." << std::endl;
     }
};

class Teacher : public Employee
{
public:
     string Subject;
     void PrepareLesson()
     {
          cout << Name << " is preparing " << Subject << " lessons" << std::endl;
     }
     Teacher(string name, string company, int age, string sub)
         : Employee(name, company, age)
     {
          Subject = sub;
     }

     void work()
     {
          cout << Name << " is teaching " << Subject << std::endl;
     }
};

int main()
{
     // The most common use of polymorphism is when a parent
     //class reference is used to refer to a child class object.
     Developer d1 = Developer("Eli", "Student", 19, "C++");
     d1.FixBug();
     d1.AskForPromotion();
     Teacher t = Teacher("Jack", "Cool-School", 35, "History");
     t.PrepareLesson();
     t.AskForPromotion();

     Employee *e = &d1;
     Employee *e2 = &t;

     e->work();
     e2->work();
}