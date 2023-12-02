#include<iostream>
#include<vector>
#include<string>


using namespace std;

class FamilyTree {
private:
	FamilyTree* _Child1;
	FamilyTree* _Child2;
	string _Name;
	int _BithYear;

public:
	FamilyTree(string Name, int BithYear): _Name(Name), _BithYear(BithYear) {};
	
	void Add(string ChildName, int BithYear) {
		if (_Child1 == nullptr)
		{
			_Child1 = new FamilyTree(ChildName, BithYear);
			
		}
		else if (_Child2 == nullptr) {
			_Child2 = new FamilyTree(ChildName, BithYear);
		}

		else {
			if (_Child1->_BithYear < _Child2 ->_BithYear )
			{
				_Child1->Add(ChildName, BithYear);
			}
			else {
				_Child2->Add(ChildName, BithYear);
			}
		}


	}
	~FamilyTree()
	{
		delete _Child1;
		delete _Child2;
	}
	void Out() {
		cout << this->_Name<< " " << this->_BithYear<< ":\n      ";
		if (_Child1 != nullptr)
		{
			_Child1->Out();
		}
		else { cout << endl; }
		if(_Child2 != nullptr) {
			_Child2->Out();
		}
		else {

		}
	}

};



void main() {
	FamilyTree Family("Mark", 1978);
	Family.Add("MarkJr", 2000);
	Family.Add("Jane", 1999);
	Family.Add("Max", 2023);
	Family.Out();

}

