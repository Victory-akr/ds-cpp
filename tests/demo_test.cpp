// 测试文件：先写测试（想清楚边界），再写实现。
// make test 会把 tests/ 下每个文件编译成一个可执行文件并全部运行。
#include <cassert>
#include <vector>
#include <iostream>
#include "demo.h"

int main() {
    assert(demo_sum({}) == 0);          // 边界：空
    assert(demo_sum({5}) == 5);         // 边界：单个
    assert(demo_sum({1, 2, 3, 4}) == 10);
    std::cout << "demo_test: all asserts passed" << std::endl;
    return 0;
}
