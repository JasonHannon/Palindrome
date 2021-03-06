// Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/// <summary>
/// A recursive function that checks if a string is a palindrome.
/// </summary>
/// <param name="str"> a constant string of the word you are checking </param>
/// <param name="start"> an integer with the starting value of the string (0) </param>
/// <param name="end"> an integer with the last value of the string (string.length() - 1) </param>
bool IsPalindrome(string & str, int start, int end)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	if (start >= end)
		return true;
	if (str[start] != str[end])
		return false;
	return IsPalindrome(str, ++start, --end);
}

/// <summary>
/// A non-recursive function that checks if a string is a palindrome.
/// </summary>
/// <param name="str"> a constant string of the word you are checking </param>
bool IsPalindrome(string & str)
{
	int start = 0;
	int end = str.length() - 1;

	transform(str.begin(), str.end(), str.begin(), ::tolower);

	while (start < end)
	{
		if (str[start++] != str[end--])
			return false;
	}

	return true;
}


int main()
{
	string word;

	cout << "Please enter a word: "; 
	cin >> word;

	if (IsPalindrome(word, 0, word.length() - 1))
		cout << "Yes. That word is a palindrome." << endl;
	else
		cout << "No. That word is not a palindrome." << endl;

	system("PAUSE");

    return 0;
}

