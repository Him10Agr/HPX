#ifndef KERNEL_HPP
#define KERNEL_HPP


#include<vector>
#include<iostream>
#include<complex>

namespace HPX {

	//compute mandelbrot set
	size_t mandelbrot(std::complex<double> c);

	double get_double(const char* varname, double defval);

	std::complex<double> get_const();

	const std::complex<double> julia_const = get_const();

	//compute julia set
	size_t julia(std::complex<double> z);

	//compute mandelbrot set fora pixel
	size_t compute_pixel(std::complex<double> c);

	std::vector<size_t> compute_row(int item_index);

}
#endif