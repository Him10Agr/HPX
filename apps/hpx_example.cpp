#include"HPX/pbm.hpp"
#include"HPX/kernel.hpp"
#include"HPX/config.hpp"

#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>

int main(int argc, char* argv[]) {

	const size_t partition_size = 25;
	const size_t num_partitions = 4;
	std::vector<double> parts(partition_size * num_partitions);
	std::iota(parts.brgin(), parts.end(), 1);
	std::vector<hpx::future<double>> futures;
	double x = 0.1;
	for (size_t i = 0; i < num_partitions; i++) {
		size_t begin = i * partition_size;
		size_t end = (i + 1) * partition_size;
		hpx::future<double> f = hpx::async([begin, end]() -> double {
			std::for_each(parts.begin() + begin, parts.begin() + end, [](double& e) {
				e = std::pow(-1.0, e + 1) * std::pow(x, e) / (e);
				});
			return std::accumulate(parts.begin() + begin, parts.begin() + end, 0);
			});
		futures.push_back(std::move(f))
	};
	double result = 0;
	for (size_t i = 0; i < futures.size(); i++) result += futures[i].get();
	std::cout << result << std::endl;
	return 0;
}