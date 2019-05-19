#include "genetic_algorithms.hpp"

int main() {
    std::pair<double , double > x (-2., 2.);
    std::pair<double , double > y (-2., 2.);
    genetic_algorithm(x, y);
    return 0;
}
