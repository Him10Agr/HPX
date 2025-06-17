#ifndef CONFIG_HPP
#define CONFIG_HPP

#include<math.h>
#include<string>

namespace HPX {

	size_t get_size_t(const char* varname, size_t defval);

	std::string get_string(const char* varname, std::string defval);

	std::string valid_string(std::string s);

	extern const double pi;
	extern const size_t max_iter;
	extern const size_t size_x;
	extern const size_t size_y;
	extern const size_t max_color;
	extern const std::string type;

}
#endif