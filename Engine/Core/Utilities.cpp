#include "Utilities.h"
#include <algorithm>
#include <cctype>

namespace neu
{
	std::string ToLower(const std::string& str)
	{
		std::string lower = str;
		// convert string characters to lower case 
		std::transform(str.begin(), str.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });
		return lower;
	}

	std::string ToUpper(const std::string& str)
	{
		std::string upper = str;
		// convert string characters to upper case 
		std::transform(str.begin(), str.end(), upper.begin(), [](unsigned char c) { return std::toupper(c); });
		return upper;
	}

	bool CompareIgnoreCase(const std::string& str1, const std::string& str2)
	{
		// if string lengths don't match return false 
		if (str1.length() != str2.length()) return false;
		// returns false if string characters aren't equal 
		for (int i = 0; i < str1.length(); i++)
		{
			//returns false if it finds any inconsistencies, if not then it skips ahead
			if (tolower(str1[i]) != tolower(str1[i])) return false;
		}
		//returns true if it finds no problems
		return true;
		
		//return std::equal(str1.begin(), str1.end(), str2.begin(), [](char c1, char c2));
	}
}