#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

class String {
	char* text = nullptr;
	size_t  size = 0;

public:
	String(const char* str);
	String()
	{
		cout << "Constructor - " << this << '\n';
	}

	String(String& other)
	{
		cout << "Copy - " << this << '\n';
		this->size = other.size;
		this->text = new char[other.size + 1];
		strcpy_s(text, size + 1, other.text);
	}

	~String();

	void operator= (const String& other)
	{
		// if(this->text)
		// 	delete[] text;
		this->size = other.size;
		this->text = new char[other.size + 1];
		strcpy_s(text, size + 1, other.text);
	}

	String operator+(String& other)
	{
		String temp;
		temp.size = this->size + other.size;
		temp.text = new char[temp.size + 1];
		strcpy_s(temp.text, this->size + 1, this->text);
		strcpy_s(temp.text + this->size, other.size + 1, other.text);
		cout << "Operator+ : " << temp << '\n';
		return temp;
	}

	friend ostream& operator<< (ostream& os, const String& string);

	char& operator[] (size_t number)
	{
		if (number >= 0 && number < size)
		{
			return text[number];
		}
		cerr << "Index out of range";
		exit(1);
	}

};

ostream& operator<< (ostream& os, const String& string)
{
	os << string.text;
	return os;
}


String::String(const char* str)
{
	cout << "Constructor with parametr\n";
	size = strlen(str);
	text = new char[size + 1];
	if (text)
		strcpy_s(text, size + 1, str);
}

String::~String() {

	cout << "Destructor - " << this << '\n';
	delete[] text;
}

void f(String a)
{
	cout << "Function: " << a << '\n';

}

void main()
{


	String a("Hello");
	String b(" World");
	String c = b;

	printf("get - %c\n", a[4]);

	c = a + b;
	cout << a << '\n';

	system("pause");
}