#include<cassert>
#include<fstream>
#include<tuple>
#include<vector>

#include"HPX/config.hpp"
#include"HPX/pbm.hpp"

namespace HPX {

	//function to smoothen the coloring
	std::tuple<size_t, size_t, size_t> get_rgb(int value) {
		double t = double(value) / double(max_iter);
		int r = (int)(9 * (1 - t) * t * t * t * 255);
		int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

		return std::make_tuple(r, g, b);
	}

	//convert rgb tuple into int
	static int make_color(int r, int g, int b) {
		assert(0 <= r && r < max_color);
		assert(0 <= g && g < max_color);
		assert(0 <= b && b < max_color);

		return (b * max_color + g) * max_color + r;
	}
}
