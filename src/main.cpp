// Demo of sending data via temporary files.  The default is to send data to gnuplot directly
// through stdin.
//
// Compile it with:
//   g++ -o example-tmpfile example-tmpfile.cc -lboost_iostreams -lboost_system -lboost_filesystem

#include <map>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "../gnuplot-iostream/gnuplot-iostream.h"

int main() {
    Gnuplot gp;

    const double dv = 1.0;
    std::vector<int> numOnV = { 1, 2, 3, 3, 4, 5, 5, 4, 3, 2, 1};

    double N = 0;
    for (int i: numOnV) { N += i; };


    gp << "set term wxt title 'Maxwell'\n";
    gp << "set terminal wxt size 1000, 900\n";
    gp << "set xrange [0:15]\nset yrange [0:1]\n";


    for (int i = 0; i < numOnV.size(); ++i) {
        std::string toPlot = "set object " + std::to_string(i+1) + " rect from "
                             + std::to_string(i * dv) + ",0 to " + std::to_string(i * dv + dv) + ","
                             + std::to_string(numOnV[i] / N) + "fc lt 2 back\n plot -x\n";
        gp << toPlot;
    }
    gp << "plot (2/3.14)**0.5*x**2/8*exp(-x**2/8)\n";
}