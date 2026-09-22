#include "adaptive_set.h"

void AdaptiveSet::add(int value) {
    if (!contains(value)) {
        items.push_back(value);
    }
}

void AdaptiveSet::remove(int value) {
    for (int index = 0; index < size(); index++) {
        if (items[index] == value) {
            items.erase(items.begin() + index);
            return;
        }
    }
}

bool AdaptiveSet::contains(int value) const {
    for (int item : items) {
        if (item == value) {
            return true;
        }
    }

    return false;
}

int AdaptiveSet::size() const {
    return static_cast<int>(items.size());
}

AdaptiveSet AdaptiveSet::intersection(const AdaptiveSet& other) const {
    AdaptiveSet result;

    for (int item : items) {
        if (other.contains(item)) {
            result.add(item);
        }
    }

    return result;
}

AdaptiveSet AdaptiveSet::setUnion(const AdaptiveSet& other) const {
    AdaptiveSet result = *this;

    for (int item : other.items) {
        result.add(item);
    }

    return result;
}

const std::vector<int>& AdaptiveSet::getItems() const {
    return items;
}
