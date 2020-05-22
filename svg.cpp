#include "svg.h"
#include "histogram.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>

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

void svg_text(double left,double baseline , string text)
{
    cout<< "<text x='" << left << "' y='"<< baseline <<"' > "<< text << "</text>";
}

void svg_rect(double x, double y, double width, double height,string stroke = "black",string fill = "black")
{
    cout<< "<rect x='"<<  x << "' y='"<< y << "' width='"<< width << "' height='"<< height << "' stroke='"<< stroke << "' fill='"<< fill <<"'/>";
}

void svg_text1(double left, double baseline, string text)
{
    cout << "<text x='"<< left << "' y='"<< baseline <<"' > "<< text << "</text>";
}

string make_info_text()
{
    stringstream buffer;
    DWORD dwVersion = 0;
    dwVersion = GetVersion();
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    if ((info & 0x80000000) == 0)
        {
             DWORD mask_major = 0b00000000'00000000'00000000'11111111;
             DWORD version_major = version & mask_major;
             DWORD version_minor = version >> 8;
             printf("Win 16-x version is %x\n", version);
             printf("Win decimal-version is %u\n", version);
             printf("Win major version is %x\n", version_major);
             printf("Win minor version is %u\n", version_minor);
             DWORD build = platform;
             buffer << "Windows v" << version_major << "." << version_minor << "(build " << build << ")\n";
        }
        char system_dir[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = sizeof(system_dir);
        GetComputerNameA(system_dir, &size);
        buffer << "Computer name: " << system_dir << "\n";
        return buffer.str();
}

void show_histogram_svg(const vector<size_t>& bins)
{
    string stroke;
    string fill;
    const auto IMAGE_WIDTH = 500;
    const auto IMAGE_HEIGHT = 400;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top=0;
    for(size_t bin:bins)
    {
        const double bin_width =BLOCK_WIDTH*bin;
        svg_text(TEXT_LEFT,top+TEXT_BASELINE,to_string(bin));
        svg_rect(TEXT_WIDTH,top,bin_width,BIN_HEIGHT,stroke="black",fill="black");
        top+=BIN_HEIGHT;
    }
    svg_text1(TEXT_LEFT, top+BIN_HEIGHT, make_info_text());
    svg_end();
}
