#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
public:
   MyClass(const string& str)
      :Name(str)
   {
      cout << "Creating" << Name<< endl;

   }

   ~MyClass()
   {
       cout << "Deleting" << endl;
   }

   void MakePoint(shared_ptr<MyClass> ptr)
   {
      Data = ptr;
   }

   void Display()
   {
      if(!Data.expired())
      {
         cout << Data.lock()->Name << endl;
      }
      //cout << Data->Name << endl;
   }

private:
   string Name;
   //shared_ptr<MyClass> Data;
   weak_ptr<MyClass> Data;
};

int main()
{
   shared_ptr<MyClass> ptr = make_shared<MyClass>("Sam");
   shared_ptr<MyClass> ptr1 = make_shared<MyClass>("Tom");

   ptr->MakePoint(ptr1);
   ptr1->MakePoint(ptr);

   ptr->Display();
   ptr1->Display();

}
