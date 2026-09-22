#ifndef ADAPTIVE_SET_H
#define ADAPTIVE_SET_H

#include <vector>

class AdaptiveSet {
private:
    std::vector<int> items;

public:
    void add(int value);
    void remove(int value);
    bool contains(int value) const;
    int size() const;

    AdaptiveSet intersection(const AdaptiveSet& other) const;
    AdaptiveSet setUnion(const AdaptiveSet& other) const;

    const std::vector<int>& getItems() const;
};

#endif
