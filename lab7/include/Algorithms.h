#pragma once

#include <iterator>
#include <map>
#include <vector>
#include <utility>
#include "Deque.h"

class DequeAlgorithms {
    public:
        template <typename Iter, typename Compare>
        static void selectionSort(Iter begin, Iter end, Compare compare) {
            for (Iter pos = begin; pos != end; ++pos) {
                Iter best = pos;
                Iter cursor = pos;
                ++cursor;
                for (; cursor != end; ++cursor) {
                    if (compare(*best, *cursor))
                        best = cursor;
                }
                if (best != pos)
                    std::swap(*pos, *best);
            }
        }

        template <typename Iter, typename Pred>
        static auto collectIf(Iter begin, Iter end, Pred predicate) -> Deque<typename std::iterator_traits<Iter>::value_type> {
            Deque<typename std::iterator_traits<Iter>::value_type> result;
            for (Iter it = begin; it != end; ++it) {
                if (predicate(*it)) {
                    auto copy = *it;
                    result.addLast(copy);
                }
            }
            return result;
        }
};

class MapAlgorithms {
    public:
        template <typename Map, typename Pred>
        static std::vector<typename Map::value_type> collectIf(const Map& m, Pred predicate) {
            std::vector<typename Map::value_type> result;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (predicate(*it))
                    result.push_back(*it);
            }
            return result;
        }

        template <typename Map>
        static bool containsKey(const Map& m, const typename Map::key_type& key) {
            return m.find(key) != m.end();
        }
};
