#include <iostream>

#include "adaptive_set.h"

void printSet(const AdaptiveSet& numbers) {
    std::cout << "{ ";

    for (int number : numbers.getItems()) {
        std::cout << number << " ";
    }

    std::cout << "}" << std::endl;
}

int main() {
    AdaptiveSet firstSet;
    firstSet.add(2);
    firstSet.add(4);
    firstSet.add(6);

    AdaptiveSet secondSet;
    secondSet.add(4);
    secondSet.add(6);
    secondSet.add(8);

    AdaptiveSet commonNumbers = firstSet.intersection(secondSet);
    AdaptiveSet allNumbers = firstSet.setUnion(secondSet);

    std::cout << "First set: ";
    printSet(firstSet);

    std::cout << "Second set: ";
    printSet(secondSet);

    std::cout << "Intersection: ";
    printSet(commonNumbers);

    std::cout << "Union: ";
    printSet(allNumbers);

    return 0;
}
