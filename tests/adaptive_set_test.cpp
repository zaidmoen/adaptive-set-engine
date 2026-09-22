#include <cassert>

#include "adaptive_set.h"

void testInsertAndSearch() {
    adaptive::AdaptiveSet numbers;

    numbers.add(8);
    numbers.add(2);
    numbers.add(8);

    assert(numbers.size() == 2);
    assert(numbers.contains(2));
    assert(numbers.contains(8));
    assert(!numbers.contains(5));
    assert(numbers.values()[0] == 2);
    assert(numbers.values()[1] == 8);
}

void testRemove() {
    adaptive::AdaptiveSet numbers;
    numbers.add(1);
    numbers.add(3);

    assert(numbers.remove(1));
    assert(!numbers.remove(10));
    assert(!numbers.contains(1));
    assert(numbers.contains(3));
}

void testSetOperations() {
    adaptive::AdaptiveSet first;
    first.add(1);
    first.add(2);
    first.add(4);

    adaptive::AdaptiveSet second;
    second.add(2);
    second.add(3);
    second.add(4);

    adaptive::AdaptiveSet common = first.intersection(second);
    adaptive::AdaptiveSet all = first.setUnion(second);
    adaptive::AdaptiveSet onlyFirst = first.difference(second);

    assert(common.size() == 2);
    assert(common.contains(2));
    assert(common.contains(4));

    assert(all.size() == 4);
    assert(all.contains(1));
    assert(all.contains(2));
    assert(all.contains(3));
    assert(all.contains(4));

    assert(onlyFirst.size() == 1);
    assert(onlyFirst.contains(1));
}

int main() {
    testInsertAndSearch();
    testRemove();
    testSetOperations();
    return 0;
}
