// main.cpp：只负责「调用 + 打印」，不放具体算法实现。
// 之后你练的每个数据结构，建议都：demo.h 声明 → demo.cpp 实现 → 这里调用 → tests/ 里断言。
#include <iostream>
#include <vector>
#include "demo.h"

int main() {
    std::vector<int> v{1, 2, 3, 4};
    std::cout << "demo_sum = " << demo_sum(v) << std::endl;
    std::cout << "环境可用：改 src/demo.cpp 后 make run 重新编译" << std::endl;
    return 0;
}
