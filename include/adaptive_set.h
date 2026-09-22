#ifndef ADAPTIVE_SET_H
#define ADAPTIVE_SET_H

#include <cstddef>
#include <vector>

namespace adaptive {

class AdaptiveSet {
private:
    std::vector<int> items;

    std::size_t findPosition(int value) const;

public:
    void add(int value);
    bool remove(int value);
    bool contains(int value) const;
    std::size_t size() const;
    bool empty() const;

    AdaptiveSet intersection(const AdaptiveSet& other) const;
    AdaptiveSet setUnion(const AdaptiveSet& other) const;
    AdaptiveSet difference(const AdaptiveSet& other) const;

    const std::vector<int>& values() const;
};

}

#endif
