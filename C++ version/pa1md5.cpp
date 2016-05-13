// Programming Assignment #1 for CSCI3320 - Advanced Programming
// Written by Justin Shapiro

#define _CRT_SECURE_NO_WARNINGS // Visual Studio disables sprintf and printf by default, so this must be defined http://bit.ly/1TrXvCR
#define MAX_MD5_SIZE (2048)

#include "md5.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

MD5_CTX mdctx;
const unsigned int TEST_STRING_MAX_LENGTH = 20; // Program allows up to 1 quadrillion tests
const unsigned int MD5_STRING_MAX_LENGTH = 16; // An MD5 hash is 16-bytes

__int8 getNumChar(unsigned int val) {
	// Get number of characters to concatenate to hash_str, ref: http://bit.ly/1Sgsbbb
	__int8 concat_str_size = 0;

	while (val != 0) {
		val /= 10;
		concat_str_size++;
	}

	return concat_str_size;
}

void genString(unsigned int test_number, char* test_str_ptr) {
	__int8 concat_size = getNumChar(test_number);
	char* concat_str = new char[concat_size + 1];
	sprintf(concat_str, "%d", test_number); // ref: http://bit.ly/1PYQX9v

	for (int i = 0; i < concat_size; i++)
		test_str_ptr[i + 4] = concat_str[i];
	
	delete [] concat_str;
}

void md5(int num_string) {
	for (unsigned int i = 0; i < num_string; i++) {
		char no_md5_string[TEST_STRING_MAX_LENGTH] = "TEST";
		genString(i + 1, no_md5_string);

		unsigned char hash_str[MAX_MD5_SIZE];
		MD5_Init(&mdctx);
		MD5_Update(&mdctx, no_md5_string, strlen(no_md5_string));
		MD5_Final(hash_str, &mdctx); // ref: Senser, Robert - PA1_MD5_CodeSnippets.txt

		stringstream md5_string_buff; 
		for (int k = 0; k < MD5_STRING_MAX_LENGTH; k++)
			md5_string_buff << setfill('0') << setw(2) << hex << (int)hash_str[k]; // ref: http://bit.ly/1SgPx0n
		
		string md5_string = md5_string_buff.str();

		if (i == 0 || i == num_string - 1)
			cout << "TEST" << i + 1 << " " << md5_string << endl; 
			//  stringstream buff; buff << "TEST" << i + 1 == no_md5_string
	}
}

int main(unsigned int num_args, char* arg1[]) {
	if (num_args != 0 && arg1[1] != nullptr) // needed to program to run in VS w/o any arguments
		md5(atoi((arg1[1])));
	else 
		md5(1);

	return 0;
}