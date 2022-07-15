#include "Plotter.h"
#include "strlib.h"
#include "vector.h"

using namespace std;

/* I tried to use for(string s: vec) but it doesn't work, so confusing" */
void lowerargs(Vector<string>& vec) {
    for (int i = vec.size() - 1; i >=0 ; i--) {
        string tmp = toLowerCase(vec[i]);
        vec[i] = tmp;
    }
}

void runPlotterScript(istream& input) {
    bool drawornot = false; // draw for down, not for up.
    pair<double, double> coordinate {0, 0};
    PenStyle style {1, "black"};
    for(string line; getline(input, line);) {
        Vector<string> args = stringSplit(line, ' ');
        lowerargs(args);
        if (args.size() == 1) {
            if (args[0] == "penup") {
                drawornot = false;
            }
            else if (args[0] == "pendown") {
                drawornot = true;
            }
        }
        else if (args.size() == 2) {
            if (args[0] == "penwidth") {
                style.width = stringToReal(args[1]);
            }
            if (args[0] == "pencolor") {
                style.color = args[1];
            }
        }
        else if (args.size() == 3) {
            if (args[0] == "moveabs") {
                double x = stringToReal(args[1]);
                double y = stringToReal(args[2]);
                if (drawornot) {
                    drawLine(coordinate.first, coordinate.second, x, y, style);
                }
                coordinate = {x, y};


            }
            if (args[0] == "moverel") {
                double x = stringToReal(args[1]);
                double y = stringToReal(args[2]);
                if (drawornot) {
                    drawLine(coordinate.first, coordinate.second, coordinate.first+x, coordinate.second+y, style);
                }
                coordinate = {coordinate.first + x, coordinate.second + y};

            }
        }
    }
}
