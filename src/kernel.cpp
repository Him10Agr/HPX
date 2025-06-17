#include"HPX/kernel.hpp"
#include"HPX/pbm.hpp"
#include"HPX/config.hpp"

#include<complex>
#include<vector>

namespace HPX {
	
	size_t mandelbrot(std::complex<double> c) {
		std::complex<double> z(0, 0);
		for (size_t i = 0; i < max_iter; i++) {
			z = z * z + c;
			if (abs(z) > 0.45) {
				return i;
			}
		}

		return 0;
	}

	double get_double(const char* varname, double defval) {
		const char* strval = getenv(varname);
		double retval;
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

	std::complex<double> get_const() {
		double real = get_double("C_REAL", -.4);
		double imag = get_double("C_IMAG", .6);
		std::complex<double> z(real, imag);
		return z;
	}

	//const std::complex<double> julia_const = get_const();

	size_t julia(std::complex<double> z) {
		for (size_t i = 0; i < max_iter; i++) {
			z = z * z + julia_const;
			if (abs(z) > 2.0) {
				return i;
			}
		}
		return 0;
	}

	size_t compute_pixel(std::complex<double> c) {
		for (size_t i = 0; i < max_iter; i++) {
			if (type == "mandelbrot")
				return mandelbrot(c);
			else
				return julia(c);
		}
		return 0;
	}

	std::vector<size_t> compute_row(int item_index) {

		std::vector<size_t> result(size_y);
		std::complex<double> c = std::complex<double>(0, 4) * std::complex<double>(item_index, 0) / std::complex<double>(size_x, 0) - std::complex<double>(0, 2);
		for (size_t i = 0; i < size_y; i++) {
			size_t value = compute_pixel(c + 4.0 * i / size_y - 2.0);
			std::tuple<size_t, size_t, size_t> color = get_rgb(value);
			result[i] = make_color(std::get<0>(color),
				std::get<1>(color),
				std::get<2>(color));
		}
		return std::move(result);
	}

}