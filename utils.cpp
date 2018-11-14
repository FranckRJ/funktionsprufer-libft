#include <string>
#include <fstream>

#include "utils.hpp"

namespace utils
{
	std::string tmpfileToString()
	{
		std::ifstream ifs(tmpfileName);
		return std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
	}
}
