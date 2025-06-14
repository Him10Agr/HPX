#include "HPX/config.hpp"

#include<complex>
#include<string>
#include<cmath>
#include<iostream>
#include<sstream>

typedef std::complex<double> complex;

namespace HPX {

	inline size_t get_size_t(const char* varname, size_t defval) {
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

	inline std::string get_string(const char* varname, std::string defval) {
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

	inline std::string valid_string(std::string s) {

		if (s == "mandelbrot");
		else if (s == "julia");
		else {
			std::cout << "Only 'mandelbrot' and 'julia' are valid values for type.";
			exit(1);
		}

		return s;
	}

}