#include<algorithm>
#include<future>
#include<iostream>
#include<complex>
#include"HPX/pbm.hpp"
#include"HPX/config.hpp"
#include"HPX/kernel.hpp"
#include<hpx/hpx.hpp>
//#include<hpx/hpx_main.hpp>
#include<hpx/hpx_init.hpp>

using namespace HPX;

void launch(size_t begin, size_t end, PBM* pbm) {
	for (size_t i = begin; i < end; i++) {
		std::complex<double> c = std::complex<double>(0, 4) * std::complex<double>((double)i, 0) /
			std::complex<double>((double)size_x, 0) - std::complex<double>(0, 2);
		for (size_t j = 0; j < size_y; j++) {
			int value = compute_pixel(c + 4.0 * (double)j / (double)size_y - 2.0);
			std::tuple<size_t, size_t, size_t> color = get_rgb(value);
			(*pbm)(i, j) = make_color(std::get<0>(color),
				std::get<1>(color),
				std::get<2>(color));
		}
	}
}

int hpx_main(hpx::program_options::variables_map& vm) {
	size_t parts = get_size_t("NUM_THREADS", 3);
	size_t output = get_size_t("OUTPUT", 1);
	PBM pbm = PBM(size_x, size_y);

	size_t size = std::round(size_x / parts);
	std::vector<hpx::future<void>> futures;
	auto start = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < parts; i++) {
		size_t start = i * size;
		size_t end = (i + 1) * size;
		if (i == parts - 1) end = size_x;
		auto f = hpx::async(launch, start, end, &pbm);
		futures.push_back(std::move(f));
	}
	for (auto&& f : futures) f.wait();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << duration.count() << std::endl;
	if (output == 1) pbm.save("test" + type + ".pbm");
	return hpx::finalize();
}

int main(int argc, char* argv[]) {

	return hpx::init(argc, argv);
}