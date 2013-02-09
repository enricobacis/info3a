#include "utilities.h"
#include <algorithm>
#include <cctype>

bool strfindi(std::string src, std::string str)
{
	std::transform(src.begin(), src.end(), src.begin(), ::toupper);
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return (src.find(str) == std::string::npos) ? false : true;
}
