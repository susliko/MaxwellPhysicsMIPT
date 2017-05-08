#include <vector>
#include <cmath>
#include "../gnuplot-iostream/gnuplot-iostream.h"
#include "../include/PlotDrawer.h"


int main() {

    std::vector<double> velocities = {1, 2, 3, 4, 5, 6, 5, 6, 5, 6, 7, 8, 9, 20, 15, 10, 12, 13, 15, 16, 18, 20};
    PlotDrawer drawer(900, 1200, "Maxwell", 15, velocities.size(), 20);

    drawer.draw(velocities);
}



