//
// Created by mbero on 30/06/2025.
//

#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP
#include <bits/stdc++.h>
#include "../utils/utils.hpp"

namespace chroma {

    template<typename T>
    class Chromosome: public utils::Comparable<Chromosome<T>>{
    public:
        virtual auto fitness() -> double = 0;
        virtual auto crossover(const T& other) -> std::vector<T> = 0;
        virtual auto mutate () -> void = 0;
        virtual auto copy () -> void = 0;
        virtual ~Chromosome() = default;

        auto operator==(const Chromosome& other) -> bool {
            return fitness() == other.fitness();
        }
        auto operator > (const Chromosome& other) -> bool {
            return fitness() > other.fitness();
        }

        auto operator < (const Chromosome& other) -> bool {
            return fitness() < other.fitness();
        }

    };
}

#endif //CHROMOSOME_HPP
