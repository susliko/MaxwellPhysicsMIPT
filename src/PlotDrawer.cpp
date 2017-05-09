#include "../include/PlotDrawer.h"

void PlotDrawer::draw(std::vector<double> & velocities) {
    for (unsigned & i : _distribution) {
        i = 0;
    }
    countDistribution(velocities);
    drawPlot();
}



void PlotDrawer::countDistribution(std::vector<double> & velocities) {
    for (double v : velocities) {
        unsigned interval = static_cast<unsigned>(v / _dV);
        ++_distribution[interval];
    }
}



void PlotDrawer::drawPlot() {
    for (int i = 0; i < _numOfIntervals; ++i) {
        std::string toPlot = "set object " + std::to_string(i+1) + " rect from "
                             + std::to_string(i * _dV) + ",0 to " + std::to_string(i * _dV + _dV) + ","
                             + std::to_string(_distribution[i] / double(_N)) + "fc lt 2 back\n";
        gp << toPlot;
    }
    gp << "plot (2/3.14)**0.5*x**2/8*exp(-x**2/8)\n";
}
