#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
void svg_begin(double width, double height);
void svg_end();
void check_size(double& font_size, bool& flag);
void svg_text(double left, double baseline, string text, double font_size);
void svg_rect(double x, double y, double width, double height, string stroke , string fill);
void show_histogram_svg(const vector<size_t>& bins);
#endif // SVG_H_INCLUDED
