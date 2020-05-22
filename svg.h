#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>

using namespace std;
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left,double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke , string fill);
void svg_text1(double left, double baseline, string text);
string make_info_text();
void show_histogram_svg(const vector<size_t>& bins);
void show_histogram_text(const vector<size_t>& bins);
#endif // SVG_H_INCLUDED
