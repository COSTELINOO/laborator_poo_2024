#include <iostream>

constexpr float operator"" _Kelvin(long double temp) {
    return static_cast<float>(temp - 273.15); 
}

constexpr float operator"" _Fahrenheit(long double temp) {
    return static_cast<float>((temp - 32) * 5 / 9);
}
