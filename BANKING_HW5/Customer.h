#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation!
{
	friend Adult;
	friend Senior;
	friend Student;
private:
	string name; //customer's name
	string address; //customer's address
	int age; //customer's age
	int telephone_number; //customer's telephone number
	int customer_number; //generated customer number
public:
	Customer() {}
	Customer(string name_n, string address_n, int age_n, int tele)
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
	int get_telephone_number()
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
		string temp;
		temp.append(customer_f);
		temp.append(customer_l);
		cout << temp << endl;
		char letter = '\0';
		for (int i = 0; i < temp.size(); ++i)
		{
			letter += temp[i];
		}

		customer_number = (int)letter;
		customer_number *= age;
		customer_number = customer_number % 1000;


		// Special
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
	double get_cInterest()
	{
		return CHECK_INTEREST;
	}
	void set_cInterest(double m)
	{
		static_cast<double>(CHECK_INTEREST) = m;
	}
	double get_sInterest()
	{
		return SAVINGS_INTEREST;
	}
	void set_sInterest(double n)
	{
		static_cast<double>(SAVINGS_INTEREST) = n;
	}
};
#endif
