#pragma once
#include <iostream>
#include "mylibrary.h"
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
namespace mystring
{
	void print_first_letter_of_each_word(string str)
	{
		bool is_first_letter = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && is_first_letter)
			{
				cout << str[i] << endl;

			}
			is_first_letter = (str[i] == ' ') ? true : false;
		}
	}
	void upper_first_letter_of_each_word(string& str)
	{
		bool is_first_letter = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && is_first_letter)
			{
				str[i] = toupper(str[i]);

			}
			is_first_letter = (str[i] == ' ') ? true : false;
		}
	}
	void lower_each_first_letter_word(string& str)
	{
		bool first_letter = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && first_letter)
			{
				str[i] = tolower(str[i]);
			}
			first_letter = (str[i] == ' ') ? true : false;
		}
	}
	string upper_all_string(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}
	string lower_all_string(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}
	char invert_char(char& c)
	{
		return (isupper(c) ? tolower(c) : toupper(c));
	}
	void invert_string(string& str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = invert_char(str[i]);
		}
	}
	short count_capital_letters(string str)
	{
		short count = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
				count++;
		}
		return (count);
	}
	short count_small_letters(string str)
	{
		short count = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (islower(str[i]))
				count++;
		}
		return (count);
	}
	short letter_count(char c, string str)
	{
		short count = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] == c)
				count++;
		}
		return (count);
	}
	short count_match_case_orNOt(char c, string str, bool matchcase = true)
	{
		short count = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (matchcase)
			{
				if (str[i] == c)
					count++;
			}
			else
			{
				if (tolower(str[i]) == tolower(c))
					count++;
			}
		}
		return (count);
	}
	bool check_vowel(char c)
	{
		c = tolower(c);
		switch (c)
		{
		case 'a':
			return 1;
			break;
		case 'e':
			return 1;
			break;
		case 'i':
			return (1);
			break;
		case 'o':
			return 1;
			break;
		case 'u':
			return 1;
			break;
		default:
			return 0;
		}
		/*
		or instead of the switch statement :
		return(c == 'a' || c == 'o' || c== 'i' || c == 'e'|| c == 'u');
		*/
	}
	short count_vowel_in_string(string str)
	{
		short count = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (check_vowel(str[i]))
				count++;
		}
		return (count);
	}
	void print_all_vowels(string str)
	{
		cout << "\nvolwels in string are :" << endl;
		for (short i = 0; i < str.length(); i++)
		{
			if (check_vowel(str[i]))
				cout << str[i] << "  ";
		}
		cout << endl;
	}
	void print_each_word(string str)
	{
		string delim = " ";
		string sword = "";
		short pos = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			sword = str.substr(0, pos);
			if (sword != "")
			{
				cout << sword << endl;
			}
			str.erase(0, pos + delim.length());
		}
		if (str != "")
			cout << str << endl;
	}
	short count_words_in_string(string str)
	{
		string delim = " ";
		string sword = "";
		short pos = 0, count = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			sword = str.substr(0, pos);
			if (sword != "")
				count++;

			str.erase(0, pos + delim.length());
		}
		if (str != "")
			count++;

		return count;
	}
	void split_string(string str, vector <string>& vstring, string delim)
	{
		string  sword = "";
		short pos = 0;
		while ((pos = str.find(delim)) != std::string::npos)
		{
			sword = str.substr(0, pos);
			if (sword != "")
			{
				vstring.push_back(sword);
			}
			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			vstring.push_back(str);
		}
	}
	void trim_left(string& str)
	{
		short i = 0;
		while (str[i] == ' ')
		{
			str.erase(0, 1);
		}
	}
	/**void trim_right(string& str)
	{
		short index = 0, length = str.length() - 1;

		for (short i = length; i > 0; i--)
		{
			if (str[i] != ' ')
			{
				index = i + 1;
				break;
			}
		}
		str.erase(index, length);
	}*/
	void trim(string& str)
	{
		trim_right(str);
		trim_left(str);
	}
	string join_string(vector <string>& vstring, string delim)
	{
		string str = "";
		for (string& st : vstring)
		{
			str += st;
			if (st != vstring.back())
			{
				str += delim;
			}
		}
		return str;
	}
	string join_string(string arr[3], short length, string delim)
	{
		string str = "";
		for (short i = 0; i < length; i++)
		{
			str += arr[i];
			if (i != (length - 1))
				str += delim;
		}
		return str;
	}
	void reverse_string_words(string& str)
	{
		vector <string> vstring1;
		split_string(str, vstring1, " ");
		str.erase();
		while (!vstring1.empty())
		{
			str += vstring1.back();
			if (vstring1.size() > 1)
			{
				str += " ";
			}
			vstring1.pop_back();
		}
	}
	void reverse_string_words(string& str, string delim)
	{
		vector <string> vstring;
		split_string(str, vstring, delim);
		str.erase();
		vector <string>::iterator iter;
		iter = vstring.end();
		while (iter != vstring.begin())
		{
			iter--;
			str += *iter + delim;

		}
		str.erase(str.length() - 1);
	}
	void replace_word(string word, string to, string& str, bool matchcase = 1)
	{
		vector <string>vstring;
		split_string(str, vstring, " ");
		str.erase();
		short size = vstring.size();
		for (string& st : vstring)
		{
			if (matchcase)
			{
				if (st == word)
					str += to;
				else
					str += st;
			}
			else
			{
				if (lower_all_string(st) == lower_all_string(word))
					str += to;
				else
					str += st;
			}
			if (st != vstring.at(size - 1))
				str += " ";
		}
	}
	void replace_word_in_string(string toreplace, string replaceto, string& str)
	{
		short pos;
		pos = str.find(toreplace);
		while (pos != std::string::npos)
		{
			str.replace(pos, toreplace.length(), replaceto);
			pos = str.find(toreplace);
		}
	}
	string remove_punctuations(string str)
	{
		string s = "";
		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
				s += str[i];
		}
		return s;
	}
}
