#include "main.h"

int add(int num1, int num2) { return num1 + num2; }
int subtract(int num1, int num2) { return num1 - num2; }
int mult(int num1, int num2) { return num1 * num2; }
double divide(double num1, double num2) { return num1 / num2; }

int TryConvertToInt(string num)
{
	transform(num.begin(), num.end(), num.begin(),
		[](unsigned char c) { return std::tolower(c); });
	
	if (strNums.count(num))
	{
		return strNums.find(num)->second;
	}

	int temp;
	try {
		temp = stoi(num);
		return temp;
	}
	catch (exception)
	{
		cout << "Invalid Input. Please input a single digit number";
		exit(0);
	}
}

int CheckIfSingleDigit(string num)
{
	int temp = TryConvertToInt(num);

	if (temp < 10 && temp > -10)
		return temp;
	else
	{
		cout << "Input must be a single digit";
		exit(0);
	}
}

int main()
{
	char operation;
	string input1, input2;
	int num1 = 0, num2 = 0;
	double result = 0;

	cout << "Please enter your first number\n";
	cin >> input1;
	num1 = CheckIfSingleDigit(input1);
	cout << "Please enter your second number\n";
	cin >> input2;
	num2 = CheckIfSingleDigit(input2);
	cout << "Please the type of operation (+,-,*,/)\n";
	cin >> operation;

	if (operation == '+')
		result = add(num1, num2);
	else if (operation == '-')
		result = subtract(num1, num2);
	else if (operation == '*')
		result = mult(num1, num2);
	else if (operation == '/')
		result = divide(num1, num2);
	else
	{
		cout << "Invalid Operand. Please enter in the following format: \"operator number number\"";
		exit(0);
	}

	cout << result;
}