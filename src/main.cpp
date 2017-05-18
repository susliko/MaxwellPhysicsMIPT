#include "../include/Physics.h"


int main(){
    // Общее число шариков
    unsigned N = 500;
    // Начальная скорость каждого из шариков в пикселях в секунду
    unsigned velocity = 250;
    // Радиус каждого шарика в пикселях
    float r = 3;


    // Сущность модели
    Physics maxwell(N, velocity, r);

    maxwell.run();
}