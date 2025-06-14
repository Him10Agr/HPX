#ifndef CONFIG_HPP
#define CONFIG_HPP

#include<math.h>
#include<string>

inline size_t get_size_t(const char* varname, size_t defval);

inline std::string get_string(const char* varname, std::string defval);

inline std::string valid_string(std::string s);

const double pi = M_PI;
const size_t max_iter = get_size_t("MAX_ITER", 80);
const size_t size_x = get_size_t("SIZE_X", 3840);
const size_t size_y = get_size_t("SIZE_Y", 2160);
const int max_color = get_size_t("MAX_COLOR", 256);
std::string type = valid_string(get_string("TYPE", "mandelbrot"));

#endif