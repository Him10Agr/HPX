#include "HPX/config.hpp"

#include<complex>
#include<string>
#include<cmath>
#include<iostream>
#include<sstream>

namespace HPX {

	size_t get_size_t(const char* varname, size_t defval) {
		const char* strval = getenv(varname);
		size_t retval;
		if (strval == nullptr) {
			retval = defval;
		}
		else {
			std::stringstream ss(strval);
			ss >> retval;
		}
		std::cout << "Using " << varname << " = " << retval << std::endl;

		return retval;
	}

	std::string get_string(const char* varname, std::string defval) {
		const char* strval = getenv(varname);
		std::string retval;
		if (strval == nullptr) {
			retval = defval;
		}
		else {
			retval = strval;
		}
		std::cout << "Using " << varname << " = " << retval << std::endl;

		return retval;
	}

	std::string valid_string(std::string s) {

		if (s == "mandelbrot");
		else if (s == "julia");
		else {
			std::cout << "Only 'mandelbrot' and 'julia' are valid values for type.";
			exit(1);
		}

		return s;
	}

	const double pi = M_PI;
	const size_t max_iter = get_size_t("MAX_ITER", 300);
	const size_t size_x = get_size_t("SIZE_X", 3840);
	const size_t size_y = get_size_t("SIZE_Y", 2160);
	const size_t max_color = get_size_t("MAX_COLOR", 256);
	const std::string type = valid_string(get_string("TYPE", "julia"));


}