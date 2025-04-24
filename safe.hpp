#ifndef SAFE_HPP
#define SAFE_HPP

#include <vector>

bool isSafeState(const std::vector<std::vector<int>>& allocation,
                 const std::vector<std::vector<int>>& max,
                 const std::vector<int>& available,
                 std::vector<int>& safeSequence);

#endif
