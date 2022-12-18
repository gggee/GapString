#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#define SIZE 1000

//Function to remove the next (left) space in a string
char* LTrim(char* str) {
	int i = 0; int j = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			break;
		}
	}
	for (j = 0; str[i] != '\0'; j++, i++) {
		str[j] = str[i];
	}
	str[j] = '\0';
	return str;
}

//Function to remove trailing (right) spaces in a string
char* RTrim(char* str)
{
	int size = strlen(str);
	for (int i = size - 1; i >= 0; i--) {
		if (str[i] != ' ') {
			str[i + 1] = '\0';
			return str;
		}
	}
	str[0] = '\0';
	return str;
}

//Function of extracting and trailing strings in a string
char* Trim(char* str) {
	//return RTrim(LTrim(str));
	return LTrim(RTrim(str));
}


//Function to remove all extra spaces in a string
char* TrimAll(char* str) {
	Trim(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			LTrim(str + 1 + i); //remove 1 and all spaces disappear
			//LTrim(&str[i + 1]);
		}
	}
	return str;
}

int main() {
	system("chcp 1251 > nul");
	cout << "Enter string: ";
	char str[SIZE];
	cin.getline(str, SIZE);
	cout << "String: " << "\'" << str << "\'" << endl;
	//cout << "Removing spaces from the right: " << "\'" << RTrim(str) << "\'" << endl;
	//cout << "Removing spaces from the left: " << "\'" << LTrim(str) << "\'" << endl;
	cout << "Removing trailing spaces: " << "\'" << Trim(str) << "\'" << endl;
	cout << "Removing extra spaces: " << "\'" << TrimAll(str) << "\'" << endl;
	cin.get(); cin.get();
}