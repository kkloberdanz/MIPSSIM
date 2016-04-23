#ifndef SEARCH_H
#define SEARCH_H

namespace kgk {

template <typename Vector_T, typename Target_T>
int binary_search(std::vector<Vector_T> v, Target_T target) { 
    int lo = 0;
    int hi = v.size();
    int mid;
    Vector_T mid_element;

    while (true) {
        if (lo > hi) {
            return -1;
        }
        mid = ((hi + lo) / 2);
        mid_element = v[mid];

        if (mid_element == target) {
            return mid;
        } else if (target < mid_element) {
            hi = mid - 1;
        } else if (target > mid_element) {
            lo = mid + 1;
        } 
    }
}

} // namespace kgk
#endif
