#include "../include/Physics.h"


int main(){
    // Общее число шариков
    unsigned N = 20;
    // Начальная скорость каждого из шариков в пикселях в секунду
    unsigned maxVelocity = 250;
    // Радиус каждого шарика в пикселях
    float r = 10;

    // Сущность модели
    Physics maxwell(N, maxVelocity, r);

    maxwell.run();
}