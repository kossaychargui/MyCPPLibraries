#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:

	static string NumberToText(long long int Num)
	{
		if (Num == 0)
		{
			return "";
		}
		if (Num > 0 && Num < 20)
		{
			string arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
			"eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
			return (arr[Num]);
		}
		if (Num > 19 && Num < 100)
		{
			string arr[] = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty" };
			return (arr[Num / 10] + " " + NumberToText(Num % 10));
		}
		if (Num > 99 && Num < 1000)
		{
			string arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
			return (arr[Num / 100] + " hundred " + NumberToText(Num % 100) + " ");
		}
		if (Num > 999 && Num < 1000000)
		{
			return (NumberToText(Num / 1000) + " thousand " + NumberToText(Num % 1000));
		}
		if (Num > 999999 && Num < 1000000000)
		{
			return (NumberToText(Num / 1000000) + " million " + NumberToText(Num % 1000000));
		}
		if (Num > 999999999 && Num < 1000000000000)
		{
			return (NumberToText(Num / 1000000000) + " billion " + NumberToText(Num % 1000000000));
		}
	}

	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int from, int to) {
		return (rand() % (from - to + 1) + from);
	}

	static char GetRandomCharacter(enCharType CharType) {
		if (CharType == MixChars) {
			CharType = (enCharType)RandomNumber(1, 3);
		}
		switch (CharType)
		{
		case clsUtil::SmallLetter:
			return (char(RandomNumber(97, 122)));
			break;
		case clsUtil::CapitalLetter:
			return (char(RandomNumber(65, 90)));
			break;
		case clsUtil::Digit:
			return (char(RandomNumber(48, 57)));
			break;
		default:
			return (char(RandomNumber(33, 47)));
		}
	}

	static string GenerateWord(enCharType CharType, short Length) {
		string Word = "";
		for (short i = 0; i < Length; i++)
			Word += GetRandomCharacter(CharType);

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter) {
		string Key = "";
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4) + '-';
		Key += GenerateWord(CharType, 4);
	}

	static void FillArrayWithRandomNumbers(int arr[100], short arrLength, int from, int to) {
		for (short i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(from, to);
	}

	static void FillArrayWithRandomWords(string arr[100], short arrLength, enCharType CharType, short wordLength) {
		for (short i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, wordLength);
	}

	static void FillArrayWithRandomKeys(string arr[100], short arrLength, enCharType CharType) {
		for (short i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void Swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	static void Swap(bool& a, bool& b) {
		bool temp = a;
		a = b;
		b = temp;
	}

	static void Swap(char& a, char& b) {
		char temp = a;
		a = b;
		b = temp;
	}

	static void Swap(string& a, string& b) {
		string temp = a;
		a = b;
		b = temp;
	}

	static void Swap(clsDate& a, clsDate& b) {
		clsDate temp = a;
		a = b;
		b = temp;

	}

	static void ShuffleArray(int arr[100], short arrLength) {
		for (short i = 0; i < arrLength; i++) {
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}
	}

	static void ShuffleArray(string arr[100], short arrLength) {
		for (short i = 0; i < arrLength; i++) {
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}
	}

	static string Tabs(int NumberOfTabs) {
		string tab = "\t";
		for (short i = 0; i < NumberOfTabs; i++)
			tab += tab;

		return  tab;
	}

	static string EncryptText(string Text, short EncryptionKey = 2) {
		for (short i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] + EncryptionKey);

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2) {
		for (short i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] - EncryptionKey);

		return Text;
	}

};
