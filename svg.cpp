#include "svg.h"
#include <vector>
#include <iostream>
using namespace std;

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void check_size(double& font_size, bool& flag)
{
    flag=true;
    if( font_size < 8 || font_size > 32)
    {
        cerr << "Error. Enter subject to conditions";
        flag=false;
    }
}

void svg_text(double left,double baseline,string text,double font_size=12)
{
    cout<< "<text x='" << left << "' y='"<< baseline << "' font-size='" << font_size <<"' > "<< text <<"</text>";
}
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black")
{
    cout<< "<rect x='"<<  x << "' y='"<< y << "' width='"<< width <<"' height='"<< height << "' stroke='"<< stroke << "' fill='"<< fill <<"'/>";
}

void show_histogram_svg(const vector<size_t>& bins)
{
    string stroke;
    string fill;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const size_t MAX_ASTERISK = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    bool flag;
    double font_size;
    cerr << "Enter font size: ";
    cin >> font_size;
    check_size(font_size,flag);
    if(flag=true)
    {
        size_t max_count = 0;
        for (size_t count : bins)
        {
            if (count > max_count)
            {
                max_count = count;
            }
        }
        const bool scaling_needed = max_count * BLOCK_WIDTH > MAX_ASTERISK;
        svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
        double top=0;
        for(size_t bin:bins)
        {
            size_t height = bin;
            if (scaling_needed)
            {
                const double scaling_factor = (double)MAX_ASTERISK / (max_count * BLOCK_WIDTH);
                height = (size_t)(bin * scaling_factor);
            }
            const double bin_width =BLOCK_WIDTH* height;
            svg_text(TEXT_LEFT,top+TEXT_BASELINE,to_string(bin), 12);
            svg_rect(TEXT_WIDTH,top,bin_width,BIN_HEIGHT,"black","black");
            top+=BIN_HEIGHT;
        }
        svg_end();
    }
}
