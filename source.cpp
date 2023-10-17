#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;


bool ValidateInput(string input_num, int in_sourceBase) {
	bool valid = true;
	// checks if the number is legally binary
	if (in_sourceBase == 2) {
		for (int i = 0; i < input_num.length(); i++) {
			if (input_num[i] != '0' && input_num[i] != '1') {
				valid = false;
			}
		}
	}
	// checks if the number is  legally octal
	else if (in_sourceBase == 8) {
		for (int i = 0; i < input_num.length(); i++) {
			if (input_num[i] != '0' && input_num[i] != '1' && input_num[i] != '2' && input_num[i] != '3' && input_num[i] != '4' && input_num[i] != '5' && input_num[i] != '6' && input_num[i] != '7') {
				valid = false;
			}
		}
	}
	// checks if the number is  legally decimal
	else if (in_sourceBase == 10) {
		for (int i = 0; i < input_num.length(); i++) {
			if (input_num[i] != '0' && input_num[i] != '1' && input_num[i] != '2' && input_num[i] != '3' && input_num[i] != '4' && input_num[i] != '5' && input_num[i] != '6' && input_num[i] != '7' && input_num[i] != '8' && input_num[i] != '9') {
				valid = false;
			}
		}
	}
	// checks if the number is  legally hexadecimal
	else {
		for (int i = 0; i < input_num.length(); i++) {
			if (input_num[i] != '0' && input_num[i] != '1' && input_num[i] != '2' && input_num[i] != '3' && input_num[i] != '4' && input_num[i] != '5' && input_num[i] != '6' && input_num[i] != '7' && input_num[i] != '8' && input_num[i] != '9' && input_num[i] != 'A' && input_num[i] != 'B' && input_num[i] != 'C' && input_num[i] != 'D' && input_num[i] != 'E' && input_num[i] != 'F') {
				valid = false;
			}
		}
	}
	return valid;
}


//binary to decimal
int BintoDec(string input_number) {
	int num = stoi(input_number), newnum = 0, counter = 0, rem;
	while (num != 0) {
		rem = num % 10;
		num /= 10;
		newnum += rem * pow(2, counter);
		++counter;
	}
	return newnum;
}
//octal to decimal
int OcttoDec(string input_number) {
	int num = stoi(input_number), newnum = 0, counter = 0, rem;
	while (num != 0) {
		rem = num % 10;
		num /= 10;
		newnum += rem * pow(8, counter);
		++counter;
	}
	return newnum;
}
//hexadecimal to decimal
unsigned long HextoDec(string input_number) {
	unsigned long num = 0;
	for (int i = 0; i < input_number.length(); i++) {
		if (input_number[i] >= 48 && input_number[i] <= 57)
		{
			num += (input_number[i] - 48) * pow(16, input_number.length() - i - 1);
		}
		else if (input_number[i] >= 65 && input_number[i] <= 70) {
			num += (input_number[i] - 55) * pow(16, input_number.length() - i - 1);
		}
		else if (input_number[i] >= 97 && input_number[i] <= 102) {
			num += (input_number[i] - 87) * pow(16, input_number.length() - i - 1);
		}
	}
	return num;
}

//decimal to binary code
int DectoBin(string input_number) {
	int newnum = stoi(input_number);
	int  rem, prod = 1, bin = 0;

	while (newnum != 0) {
		rem = newnum % 2;
		bin += (rem * prod);
		newnum /= 2;
		prod *= 10;
	}

	return bin;
}
// decimal to octal code
int DectoOct(string input_number) {
	int newnum = stoi(input_number);
	int  rem, prod = 1, bin = 0;

	while (newnum != 0) {
		rem = newnum % 8;
		bin += (rem * prod);
		newnum /= 8;
		prod *= 10;
	}

	return bin;
}

// decimal to hex code
string DectoHex(int input_number) {
	char temp[100];
	string output = "";
	int remainder;
	int count = 0;

	while (input_number != 0) {
		remainder = input_number % 16;

		if (remainder < 10) {
			remainder += 48;
		}
		else {
			remainder += 55;
		}

		temp[count] = remainder;
		count++;

		input_number /= 16;
	}

	for (int i = count - 1; i >= 0; i--) {
		output = output + temp[i];
	}

	return output;
}
	

	
//This function converts any number from one base to another base
int convert_number(string input_number, int source_base, int target_base) {
	int number = 0;
	string output;

	if (source_base == 2) {
		number = BintoDec(input_number);
	}
	else if (source_base == 8) {
		number = OcttoDec(input_number);
	}
	else if (source_base == 10) {
		number = stoi(input_number);
	}
	else if (source_base == 16) {
		number = HextoDec(input_number);
	}


	if (target_base == 2) {
		stringstream ss;
		ss << number;
		string str = ss.str();
		cout << "your number is: " << DectoBin(str) << endl;
	}
	else if (target_base == 8) {
		stringstream ss;
		ss << number;
		string str = ss.str();
		cout << "your number is: " << DectoOct(str) << endl;
	}
	else if (target_base == 10) {
		cout << "your number is: " << number << endl;
	}
	else if (target_base == 16) {
		cout << "your number is: " << DectoHex(number) << endl;
	}
	return 0;
}

int main() {

	string num;
	int sourceBase;
	int targetBase;
	char repeat;
	do {
		cout << "Please indicate the number you wish to convert (please use caps for letters in Hexadecimals):" << endl;
		cin >> num;

		cout << "Please indicate the source base you wish to convert from:" << endl;
		cin >> sourceBase;

		cout << "Please indicate the target base you wish to convert to:" << endl;
		cin >> targetBase;

		if (ValidateInput(num, sourceBase) == true) {
			int calculated = convert_number(num, sourceBase, targetBase);
		}
		else {
			cout << "error!" << endl;
		}

		cout << "would you like to make another calculation? (Y for yes and N for no)" << endl;
		cin >> repeat;
		if (repeat == 'N' || repeat == 'n') {
			return 0;
		}
	} while (repeat == 'Y' || repeat == 'y');

}

