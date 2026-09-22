#include "adaptive_set.h"

namespace adaptive {

// Keeping the values sorted makes searching and set operations easier.
std::size_t AdaptiveSet::findPosition(int value) const {
    std::size_t left = 0;
    std::size_t right = items.size();

    while (left < right) {
        std::size_t middle = left + (right - left) / 2;

        if (items[middle] < value) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}

void AdaptiveSet::add(int value) {
    std::size_t position = findPosition(value);

    if (position == items.size() || items[position] != value) {
        items.insert(items.begin() + position, value);
    }
}

bool AdaptiveSet::remove(int value) {
    std::size_t position = findPosition(value);

    if (position == items.size() || items[position] != value) {
        return false;
    }

    items.erase(items.begin() + position);
    return true;
}

bool AdaptiveSet::contains(int value) const {
    std::size_t position = findPosition(value);
    return position < items.size() && items[position] == value;
}

std::size_t AdaptiveSet::size() const {
    return items.size();
}

bool AdaptiveSet::empty() const {
    return items.empty();
}

AdaptiveSet AdaptiveSet::intersection(const AdaptiveSet& other) const {
    AdaptiveSet result;
    std::size_t left = 0;
    std::size_t right = 0;

    while (left < items.size() && right < other.items.size()) {
        if (items[left] == other.items[right]) {
            result.items.push_back(items[left]);
            left++;
            right++;
        } else if (items[left] < other.items[right]) {
            left++;
        } else {
            right++;
        }
    }

    return result;
}

AdaptiveSet AdaptiveSet::setUnion(const AdaptiveSet& other) const {
    AdaptiveSet result;
    std::size_t left = 0;
    std::size_t right = 0;

    while (left < items.size() || right < other.items.size()) {
        if (right == other.items.size() ||
            (left < items.size() && items[left] < other.items[right])) {
            result.items.push_back(items[left]);
            left++;
        } else if (left == items.size() || other.items[right] < items[left]) {
            result.items.push_back(other.items[right]);
            right++;
        } else {
            result.items.push_back(items[left]);
            left++;
            right++;
        }
    }

    return result;
}

AdaptiveSet AdaptiveSet::difference(const AdaptiveSet& other) const {
    AdaptiveSet result;
    std::size_t left = 0;
    std::size_t right = 0;

    while (left < items.size()) {
        if (right == other.items.size() || items[left] < other.items[right]) {
            result.items.push_back(items[left]);
            left++;
        } else if (items[left] == other.items[right]) {
            left++;
            right++;
        } else {
            right++;
        }
    }

    return result;
}

const std::vector<int>& AdaptiveSet::values() const {
    return items;
}

}
