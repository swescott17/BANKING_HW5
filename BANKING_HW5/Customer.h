#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
using namespace std;
/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation!
{

private:
	string name; //customer's name
	string address; //customer's address
	int age; //customer's age
	string telephone_number; //customer's telephone number
	int customer_number; //generated customer number
public:
	Customer() {}
	Customer(string name_n, string address_n, int age_n, string tele)
	{
		name = name_n;
		address = address_n;
		age = age_n;
		telephone_number = tele;
		set_customer_number();
		//Special code for setting customer number
	}
	virtual double get_sInterest() = 0;
	virtual double get_cInterest() = 0;
	string get_name()
	{
		return name;
	}
	void set_name(string newname)
	{
		name = newname;
	}
	string get_address()
	{
		return address;
	}
	void set_address(string newadd)
	{
		address = newadd;
	}
	int get_age()
	{
		return age;
	}
	void set_age(int newage)
	{
		age = newage;
	}
	string get_telephone_number()
	{
		return telephone_number;
	}
	void set_telephone_number(int num)
	{
		telephone_number = num;
	}
	int get_customerNUM()
	{
		return customer_number;
	}
	void set_customer_number()
	{

		string customer_f = name.substr(0, 3); //first three letters of first name
		int len = name.find(" ", 0); //finding the space between first and last name
		string customer_l = name.substr(len + 1, 3); //first three letters of last name
		string temp; //empty string
		temp.append(customer_f); //adds to a string first letters of the first name
		temp.append(customer_l);  //adds first 3 letters of last name

		char letter = '\0'; //empty char
		for (int i = 0; i < temp.size(); ++i) //turns letters into ints
		{
			letter += temp[i];
		}

		customer_number = (int)letter; //turns char to int
		customer_number *= age; //multiplies by age
		customer_number = customer_number % 1000; //relays a 3 digit customer number

	}
};

class Senior : public Customer
{
private:
	friend Customer;
	const double SAVINGS_INTEREST = 0.04;
	const double CHECK_INTEREST = 0.02;
	const double CHECK_CHARGE = 3.5;
	const double OVERDRAFT_PENALTY = 22.5;
public:
	Senior() {}
	Senior(string name, string address, int age, string telephone, int customer_id) {}
	double get_cInterest()
	{
		return CHECK_INTEREST;
	}
	double get_sInterest()
	{
		return SAVINGS_INTEREST;
	}
};

class Adult : public Customer
{
private:
	friend Customer;
	const double SAVINGS_INTEREST = 0.04;
	const double CHECK_INTEREST = 0.02;
	const double CHECK_CHARGE = 5;
	const double OVERDRAFT_PENALTY = 30;
public:
	Adult() {}
	Adult(string name, string address, int age, string telephone, int customer_id) {}
	double get_cInterest()
	{
		return CHECK_INTEREST;
	}
	double get_sInterest()
	{
		return SAVINGS_INTEREST;
	}
};

class Student : public Customer
{
private:
	friend Customer;
	const double SAVINGS_INTEREST = 0.03;
	const double CHECK_INTEREST = 0.01;
	const double CHECK_CHARGE = 0.50;
	const double OVERDRAFT_PENALTY = 25;
public:
	Student() {}
	Student(string name, string address, int age, string telephone, int customer_id) {}
	double get_cInterest()
	{
		return CHECK_INTEREST;
	}
	double get_sInterest()
	{
		return SAVINGS_INTEREST;
	}
};
#endif
