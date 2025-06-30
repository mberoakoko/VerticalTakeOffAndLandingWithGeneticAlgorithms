//
// Created by mbero on 30/06/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <bits/stdc++.h>

namespace utils {
    template <typename T>
    class Comparable;

    template<typename T>
    class Comparable {
    public:
        // friend auto operator == (const T& lhs, const T& rhs) -> bool {
        //     return static_cast<const T&>(lhs) == static_cast<const T&>(rhs);
        // }


        friend auto operator !=(const T& lhs, const T& rhs) -> bool {
            return !(static_cast<const T&>(lhs) == static_cast<const T&>(rhs));
        }

        friend auto operator <= (const T& lhs, const T& rhs) -> bool {
            auto less_than = static_cast<const T&>(lhs) < static_cast<const T&>(rhs);
            auto equal_to = static_cast<const T&>(lhs) == static_cast<const T&>(rhs);
            return less_than or equal_to;;
        }

        friend auto operator >= (const T& lhs, const T& rhs) -> bool {
            auto greater_than = static_cast<const T&>(lhs) > static_cast<const T&>(rhs);
            auto equal_to = static_cast<const T&>(lhs) == static_cast<const T&>(rhs);
            return greater_than or equal_to;
        }
    };

    struct entity: public Comparable<entity> {
        std::uint8_t index;

        auto operator==(const entity & other) const -> bool {
            return index == other.index;
        }
        auto operator <(const entity & other) const -> bool {
            return index < other.index;
        }
        auto operator >(const entity & other) const -> bool {
            return index > other.index;
        }
    };

    auto test_entity() -> void {
        auto e_1 = entity{.index = 1};
        auto e_2 = entity{.index = 1};
        auto e_3 = entity{.index = 3};
        auto e_4 = entity{.index = 4};

        std::cout << ((e_1 >= e_2 )? "true" : "false") << std::endl;
    };

}
#endif //UTILS_HPP
