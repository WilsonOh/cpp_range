# cpp_range
A Range Iterator Implementation in C++

## Usage
`Range([start], stop_exclusive, [step])` (arguments in brackets are optional)<br>
This implementation aims to achieve the same functionailty as Python's `range`
```cpp
#include "Range.hpp"
#include <iostream>
#include <numeric>
#include <functional>

Range nums(101);
int sum = std::accumulate(nums.begin(), nums.end(), 0);
int prod = std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
std::cout << sum << std::endl;
/* Output: 5050 */
std::cout << prod << std::endl;
/* Output: 3628800 */

for (const auto &i : Range(5)) {
  std::cout << i << '\n';
}
/*
Output:
0
1
2
3
4
*/
for (const auto &i : Range(5, 1)) {
  std::cout << i << '\n';
}
/*
Output:
5
4
3
2
1
*/
for (const auto &i : Range(0, 11, 2)) {
  std::cout << i << '\n';
}
/*
Output:
0
2
4
6
8
10
*/
```
