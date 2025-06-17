#ifndef PBM_HPP
#define PBM_HPP

#include<tuple>
#include<vector>
#include<string>
#include<fstream>

#include"config.hpp"

namespace HPX {
	std::tuple<size_t, size_t, size_t> get_rgb(size_t value);

	size_t make_color(size_t r, size_t g, size_t b);

	template<typename vector_type>
	class PBM_ {
		typename vector_type::allocator_type a;
		int w, h;
		vector_type values;

		void _init() {
			for (int j = 0; j < h; j++) {
				std::vector<int> row;
				for (int i = 0; i < w; i++) {
					row.push_back(0);
				}
				values[j] = std::move(row);
			}
		}
	public:
		int get_width() { return w; }
		int get_height() { return h; }

		PBM_() {};
		PBM_(int w_, int h_) : w(w_), h(h_), a(), values(h_, a) { _init(); }
		PBM_(int w_, int h_, vector_type::allocator_type a_) : w(w_), h(h_), a(a_), values(h_, a) { _init(); }
		~PBM_() {};

		//get or set a pixel
		int& operator()(int i, int j) {
			return values.at(j).at(i);
		}

		//get or set a row
		std::vector<int>& row(int j) { return values.at(j); }

		//save file
		void save(const std::string& fname) {
			std::ofstream f(fname);
			f << "P3\n";
			f << w << " " << h << "\n";
			f << max_color - 1 << "\n";
			for (int j = 0; j < h; j++) {
				auto& row = values.at(j);
				for (int i = 0; i < w; i++) {
					int color = row.at(i);
					for (int c = 0; c < 3; c++) {
						f << (color % max_color) << " ";
						color /= max_color;
					}
					f << "\n";
				}
			}
			f.close();
		};
	};

}
using PBM = HPX::PBM_<std::vector<std::vector<int>>>;
#endif

