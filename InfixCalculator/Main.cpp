#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string infixExp;

	cout << "Echo an infix expression: ";
	cin >> infixExp;

	for (int i = 0; i < infixExp.length(); i++)
	{
		cout << infixExp[i];
	}

	cout << endl;

	system("pause");
	return 0;
}