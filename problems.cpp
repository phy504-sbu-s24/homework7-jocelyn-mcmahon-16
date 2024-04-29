#include <cmath>
#include <iostream>
#include <random>
#include <iomanip>

#include "integrate.H"

int main() {
    // so I just wrote out the numbers that we want to use as N, but I also have commented out a while loop
    // that will actually double the value of N so to get those same values.


    const std::vector<int> N = {8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    // int N = 8;
    // int N_max = 4096;
    

    // don't comment these two lines
    std::cout << "First Integral: e^-(x^2)" << std::endl;
    std::cout << std::setw(15) << "N" << std::setw(15) <<  "Trap" << std::setw(15) << "MC" << std::endl;
    
    for (int i = 0; i < N.size(); i++) {
        std::cout << std::setw(15) << N[i] << std::setw(15) << trap_int(gauss, -5, 5, N[i]) << std::setw(15) << mc_int(gauss, -5, 5, N[i]) << std::endl;
    }
    // while (N <= N_max) {
    //     std::cout << std::setw(15) << N << std::setw(15) << trap_int(gauss, -5, 5, N) << std::setw(15) << mc_int(gauss, -5, 5, N) << std::endl;
    //     N *= 2;
    // }
    
    // don't comment these two lines
    std::cout << "Second Integral: sin^2(1/(x(2-x) + e))" << std::endl;
    std::cout << std::setw(15) << "N" << std::setw(15) <<  "Trap" << std::setw(15) << "MC" << std::endl;
    
    for (int i = 0; i < N.size(); i++) {
        std::cout << std::setw(15) << N[i] << std::setw(15) << trap_int(sin2, 0, 2, N[i]) << std::setw(15) << mc_int(sin2, 0, 2, N[i]) << std::endl;
    }
    
    // N = 8;
    // while (N <= N_max) {
    //     std::cout << std::setw(15) << N << std::setw(15) << trap_int(sin2, 0, 2, N) << std::setw(15) << mc_int(sin2, 0, 2, N) << std::endl;
    //     N *= 2;
    // }
}