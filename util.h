//
// Created by Oliver on 2025/4/2.
//

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <tuple>
#include <utility> // for std::pair

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     explicit ListNode(const int x) : val(x), next(nullptr) {}
};

// 基础版本 - 仅匹配没有begin()/end()的类型
template<typename T>
auto print(const T& value) -> std::void_t<decltype(std::cout << value)> {
    std::cout << value;
}

void print(string s) {
    std::cout << s ;
}

// 字符特化版本
void print(char c) {
    std::cout << "'" << c << "'";
}

// 重载版本，用于打印字符串（避免把字符串当成字符数组处理）
void print(const char* s) {
    std::cout << "\"" << s << "\"";
}

// 打印std::pair
template<typename T1, typename T2>
void print(const std::pair<T1, T2>& pair);

// 打印std::tuple
template<typename... Args>
void print(const std::tuple<Args...>& tuple);

// 打印容器的主模板（适用于大多数STL容器）
template<typename Container>
auto print(const Container& container) -> decltype(container.begin(), container.end(), void()) {
    std::cout << "[";
    bool first = true;
    for (const auto& element : container) {
        if (!first) {
            std::cout << ", ";
        }
        print(element); // 递归调用print处理元素
        first = false;
    }
    std::cout << "]";
}

// 打印std::pair的具体实现
template<typename T1, typename T2>
void print(const std::pair<T1, T2>& pair) {
    std::cout << "(";
    print(pair.first);
    std::cout << ", ";
    print(pair.second);
    std::cout << ")";
}

// 打印std::tuple的具体实现
template<typename... Args, std::size_t... I>
void print_tuple_helper(const std::tuple<Args...>& tuple, std::index_sequence<I...>) {
    std::cout << "(";
    (..., (I == 0 ? void() : void(std::cout << ", "), print(std::get<I>(tuple))));
    std::cout << ")";
}

template<typename... Args>
void print(const std::tuple<Args...>& tuple) {
    print_tuple_helper(tuple, std::index_sequence_for<Args...>{});
}

// 特化版本，用于打印std::map及其类似容器
template<typename Key, typename Value, typename Compare, typename Allocator>
void print(const std::map<Key, Value, Compare, Allocator>& map) {
    std::cout << "{";
    bool first = true;
    for (const auto& pair : map) {
        if (!first) {
            std::cout << ", ";
        }
        print(pair);
        first = false;
    }
    std::cout << "}";
}

// 特化版本，用于打印std::unordered_map
template<typename Key, typename Value, typename Hash, typename KeyEqual, typename Allocator>
void print(const std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>& map) {
    std::cout << "{";
    bool first = true;
    for (const auto& pair : map) {
        if (!first) {
            std::cout << ", ";
        }
        print(pair);
        first = false;
    }
    std::cout << "}";
}

void print(ListNode* node) {
    std::cout << "[";
    while (node) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << ", ";
        }
        node = node->next;
    }
    std::cout << "]";
}

ListNode* buildList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* head = dummy;
    for (int num : nums) {
        head->next = new ListNode(num);
        head = head->next;
    }
    return dummy->next;
}

#endif //UTIL_H
