// Move Constructor

#include <iostream>
using namespace std;

class A
{
	int Len;
	int *Data;

public:
	explicit A(int size) : Len(size), Data(new int[Len])
	{
	}

	~A()
	{
		delete[] Data;
	}

	// Copy Constr
	A(const A& obj) : Len(obj.Len), Data(new int[this->Len])
	{
		for(int index = 0; index < Len; ++index)
		{
			this->Data[index] = obj.Data[index];
		}
	}

        //move constr
	A(A&& obj) : Len(obj.Len)
	{
		Data = obj.Data;
		obj.Data = nullptr;
		obj.Len = 0;
	}
};


A createInstance()
{
	A ob(5);
	return ob;
}

void PerformOperation(A ob)
{
	//....
}

int main()
{
	PerformOperation(move(createInstance()));  
	return 0;
}

