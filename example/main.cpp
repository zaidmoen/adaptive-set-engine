#include <iostream>

#include "adaptive_set.h"

void printSet(const adaptive::AdaptiveSet& numbers) {
    std::cout << "{ ";

    for (int number : numbers.values()) {
        std::cout << number << " ";
    }

    std::cout << "}" << std::endl;
}

int main() {
    adaptive::AdaptiveSet firstSet;
    firstSet.add(6);
    firstSet.add(2);
    firstSet.add(4);
    firstSet.add(4);

    adaptive::AdaptiveSet secondSet;
    secondSet.add(4);
    secondSet.add(6);
    secondSet.add(8);

    adaptive::AdaptiveSet commonNumbers = firstSet.intersection(secondSet);
    adaptive::AdaptiveSet allNumbers = firstSet.setUnion(secondSet);
    adaptive::AdaptiveSet onlyFirstSet = firstSet.difference(secondSet);

    std::cout << "First set: ";
    printSet(firstSet);

    std::cout << "Second set: ";
    printSet(secondSet);

    std::cout << "Intersection: ";
    printSet(commonNumbers);

    std::cout << "Union: ";
    printSet(allNumbers);

    std::cout << "Only in first set: ";
    printSet(onlyFirstSet);

    return 0;
}
