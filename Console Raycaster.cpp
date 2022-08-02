// Alessandro Pegoraro, 2022

#include <iostream>
#include <cassert>
#include "Scalar.h"

using namespace APRaycaster;

int main()
{
    Scalar a = 0.f;
    Scalar b = 1.f;

    assert(Equal(a, 0.f));
    assert(Equal(b, 1.f));
    assert(!Equal(49.86f, b));
    assert(!Equal(a, b));

    std::cout << "Win!" << std::endl;
}

