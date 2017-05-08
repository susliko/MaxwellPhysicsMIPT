#pragma once

#include <vector>
#include "../gnuplot-iostream/gnuplot-iostream.h"



class PlotDrawer
{
public:
    PlotDrawer(unsigned height, unsigned width, std::string const name,
               unsigned velocity, unsigned N, unsigned numOfIntervals)
            : _height(height)
            , _width(width)
            , _name(name)
            , _maxVelocity(velocity * 2)
            , _N(N)
            , _numOfIntervals(numOfIntervals)
            , _dV(_maxVelocity / double(numOfIntervals))
            , _distribution(_numOfIntervals, 0)
    {
        // Установка имени окна
        gp << "set term wxt title '" + name + "'\n";
        // Установка размеров окна
        gp << "set terminal wxt size "
              + std::to_string(width) + ","
              + std::to_string(height) + "\n";
        // Установка отображаемых диапазонов по обеим осям
        gp << "set xrange [0:"
              + std::to_string(_maxVelocity)
              + "]\nset yrange [0:1]\n";
    }

    // Выводит гистограмму распределения по заданному массиву скоростей частиц
    void draw(std::vector<double> & velocities);


private:
    // Вычисляет распределение частиц по интервалам скоростей
    void countDistribution(std::vector<double> & velocities);

    // Отображает распределение на графике
    void drawPlot();

private:
    Gnuplot gp;                  // Объект-построитель графиков
    unsigned _height;            // Высота окна в пикселях
    unsigned _width;             // Ширина окна в пикселях
    std::string _name;           // Название окна
    unsigned const _maxVelocity; // Диапазон скоростей по оси Х
    unsigned const _N;           // Общее число частиц
    unsigned _numOfIntervals;    // Число интервалов скоростей для гистограммы
    double _dV;                  // Ширина одного интервала
    std::vector<unsigned> _distribution; // Массив распределений частиц по интервалам
};

