#include<cassert>
#include<fstream>
#include<tuple>
#include<vector>

#include"HPX/config.hpp"
#include"HPX/pbm.hpp"

namespace HPX {

	//function to smoothen the coloring
	std::tuple<size_t, size_t, size_t> get_rgb(size_t value) {
		size_t t = size_t(value) / size_t(max_iter);
		size_t r = (size_t)(9 * (1 - t) * t * t * t * 255);
		size_t g = (size_t)(15 * (1 - t) * (1 - t) * t * t * 255);
		size_t b = (size_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

		return std::make_tuple(r, g, b);
	}

	//convert rgb tuple into int(size_t)
	size_t make_color(size_t r, size_t g, size_t b) {
		assert(0 <= r && r < max_color);
		assert(0 <= g && g < max_color);
		assert(0 <= b && b < max_color);

		return (b * max_color + g) * max_color + r;
	}

}
