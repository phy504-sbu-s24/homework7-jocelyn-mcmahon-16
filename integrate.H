#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <iomanip>

double e = std::pow(10,-12); //epsilon as defined in the question

double trap_int(std::function<double(double)> f, double xleft, double xright, int N);
double mc_int(std::function<double(double)> f, double xleft, double xright, int N);
double gauss(double x);
double sin2(double x);

//Function to integrate via trapezoid
double trap_int(std::function<double(double)> f, double xleft, double xright, int N) {
    double dx = std::abs((xright - xleft))/N; // I feel like I remember N needing to be a double for this division...
    double sum = 0.0;  // to add each iteration of the integration to
    for (double x = xleft; x <= xright; x += dx ) {
        sum += (f(x) + f(x + dx));
    }
    return 0.5 * dx * sum;
}

//Function to integrate via monte carlo
double mc_int(std::function<double(double)> f, double xleft, double xright, int N) {
    //same as before, but now N is the number of random points
    std::mt19937 generator(501); //Choose a seed for reproducible results
    double sum = 0.0;
    double x;
    std::uniform_real_distribution<double> uniform(xleft, xright); // Random distribution to evulate our fucntion at
    for (int i = 0; i < N; i++) {
        x = uniform(generator);
        sum += f(x);
    }
    return sum * ((xright - xleft) / N);
}

double gauss(double x) {
    return std::exp(-x*x);
}

double sin2(double x) {
    return std::pow(std::sin(1 / (x * (2-x) + e)), 2);
}

#endif