// 实现文件：合上资料、自己写一遍的地方。
// 报错先读编译器给的行号 + 英文提示，再考虑问 AI「为什么」。
#include "demo.h"

int demo_sum(const std::vector<int>& v) {
    int s = 0;
    for (size_t i = 0; i < v.size(); ++i) s += v[i];
    return s;
}
