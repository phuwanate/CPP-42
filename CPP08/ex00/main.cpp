#include "easyfind.hpp"

int main(void){

    std::vector<int> v;
    std::cout << "-> Vector: [ ";
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(42);
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)   
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
    easyfind< std::vector<int> >(v, 42);
    std::cout << std::endl;

    std::list<int>  l;
    std::cout << "-> List: [ ";
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(42);
    for(std::list<int>::iterator it = l.begin(); it != l.end(); it++)   
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
    easyfind(l, 42);
    std::cout << std::endl;

    l.pop_back();
    std::cout << "-> List: [ ";
    for(std::list<int>::iterator it = l.begin(); it != l.end(); it++)   
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
    easyfind(l, 42);
    std::cout << std::endl;

    std::cout << "-> Deque: [ ";
    std::deque<int> d;
    d.push_front(2);
    d.push_back(3);
    d.push_front(1);
    d.push_back(42);
    for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++)   
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
    easyfind(d, 4242);
    std::cout << std::endl;
}