#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>

auto function_(double x, double y) -> double;
auto get_random(double & a, double & b) -> double;
auto rnd()-> double;
auto combinate(std::vector<std::pair<double , double >>& mas_pop) -> std::vector<std::pair<double, double>>;
auto mutation(std::vector<std::pair<double , double >>& mas_pop)->std::vector<std::pair<double , double >>;
auto selection(std::vector<std::pair<double , double>>& mas_pop) -> std::vector<std::pair<double, double >>;
auto F_max(std::vector<std::pair<double, double>>& mas_pop) -> double;
auto genetic_algorithm(std::pair<double, double> xD, std::pair<double, double > yD) -> void;


auto function_(double x, double y) -> double {
    return (cos(x)*cos(y)*exp(y/2));
}

auto get_random(double & a, double & b) -> double{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(a, b);
    return dis(e);
}

auto rnd()-> double {
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1);
    return dis(e);
}

auto combinate(std::vector<std::pair<double , double >>& mas_pop) -> std::vector<std::pair<double, double>> {
    std::vector<std::pair<double, double>> child;
    std::vector<double > result;

    for (size_t i = 0; i < mas_pop.size(); ++i){
        double f_x = function_(mas_pop.at(i).first , mas_pop.at(i).second);
            result.push_back(f_x);
    }

    auto it = std::max_element(result.begin(), result.end());
    auto curr = (it - result.begin());
    std::pair<double , double > tmp1;
    std::pair<double , double > tmp2;

    for (size_t i = 0; i < mas_pop.size(); ++i){
        if (i != curr){
        tmp1.first = mas_pop[curr].first;
        tmp1.second = mas_pop[i].second;
        child.push_back(tmp1);
        tmp2.first = mas_pop[i].first;
        tmp2.second = mas_pop[curr].second;
        child.push_back(tmp2);
        }
    }
    return child;
}

auto mutation(std::vector<std::pair<double , double >>& mas_pop)->std::vector<std::pair<double , double >> {
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < mas_pop.size(); ++i) {
        double dX = rnd();
        double dY = rnd();

        if (mas_pop[i].first > 0) {
            mas_pop[i].first -= dX;
            mas_pop[i].second -= dY;

        } else {
            mas_pop[i].first += dX;
            mas_pop[i].second += dY;
        }
    }
    return mas_pop;
}

auto selection(std::vector<std::pair<double , double>>& mas_pop) -> std::vector<std::pair<double, double >> {
    std::vector<double > result;
    for (size_t i = 0; i < mas_pop.size(); ++i) {
        double f_x = function_(mas_pop.at(i).first , mas_pop.at(i).second);
        result.push_back(f_x);
    }
    auto it = std::min_element(result.begin(), result.end());
    auto curr = mas_pop.begin() + (it - result.begin());
    result.erase(it);
    mas_pop.erase(curr);
    return mas_pop;
}

auto F_max(std::vector<std::pair<double, double>>& mas_pop) -> double {
    std::vector<double > result;

    for (size_t i = 0; i < mas_pop.size(); ++i) {
        double f_x;
        f_x = function_(mas_pop.at(i).first , mas_pop.at(i).second);

        result.push_back(f_x);
    }
    return result.at(std::max_element(result.begin(), result.end()) - result.begin());
}

auto genetic_algorithm(std::pair<double, double> xD, std::pair<double, double > yD) -> void{
    int iteration = 10;
    int N = 10;
    for (int j = 0; j < iteration; ++j) {
        std::cout << "N = " << N << std::endl<<std::endl;
        std::vector<std::pair<double, double>> mas_pop;
        std::vector<double> result;
        std::pair<double, double> tmp;
        for (int i = 0; i < 4; ++i) {
            std::srand(std::time(nullptr));
            tmp.first = get_random(xD.first, xD.second);
            tmp.second = get_random(yD.first, yD.second);
            double f_x =function_(tmp.first , tmp.second);
            mas_pop.push_back(tmp);
            result.push_back(f_x);
        }
        auto it = std::min_element(result.begin(), result.end());
        auto curr = mas_pop.begin() + (it - result.begin());
        result.erase(it);
        mas_pop.erase(curr);
        for (int i = 0; i < N; ++i) {
            mas_pop = combinate(mas_pop);
            mas_pop = mutation(mas_pop);
            if((i < 10) or ((i+1) % 10 == 0)) {
                if (i > 10) {
                    std::cout << "Generation : " << i+1 <<std::endl;
                }
                std::cout << "| ";
                for (size_t j = 0; j < mas_pop.size(); ++j) {
                    std::cout << "x" << j+1 << ": " << mas_pop[j].first << " | ";
                }
                //std::cout << std::endl <<"|---|---|---|---|";
                std::cout << std::endl << "| ";
                for (size_t j = 0; j < mas_pop.size(); ++j) {
                    std::cout << "y" << j+1 << ": " << mas_pop[j].second << " | ";
                }
                std::cout<<std::endl << "| ";
                for (size_t j = 0; j < mas_pop.size(); ++j) {
                    double f = function_(mas_pop.at(j).first , mas_pop.at(j).second);
                    std::cout << "F(x,y): " << f << " | ";
                }
                mas_pop = selection(mas_pop);
                std::cout << std::endl << "Max: " << F_max(mas_pop) << std::endl;
                
            }
            else mas_pop = selection(mas_pop);
        }
        N += 10;
    }
}
