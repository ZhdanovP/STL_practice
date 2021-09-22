#include "impl.h"
#include <map>

std::map<unsigned int, unsigned int> createConvertor()
{
    std::map<unsigned int, unsigned int> convertor;
    for (unsigned int i = 0; i < 30; ++i) {
        convertor[i] = 1;
    }
    for (unsigned int i = 30; i < 50; ++i) {
        convertor[i] = 2;
    }
    for (unsigned int i = 50; i < 70; ++i) {
        convertor[i] = 3;
    }
    for (unsigned int i = 70; i < 90; ++i) {
        convertor[i] = 4;
    }
    for (unsigned int i = 90; i < 101; ++i) {
        convertor[i] = 5;
    }
    return convertor;
}

const std::map<unsigned int, unsigned int> convertor = createConvertor();

std::pair<bool, unsigned int> convert(const unsigned int &mark)
{
    auto it = convertor.find(mark);
    if (it == convertor.end()) {
        return std::make_pair(false, 0);
    }

    return std::make_pair(true, it->second);
}
