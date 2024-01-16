#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "-> MutantStack test: " << '\n';
    MutantStack<int> mstack;
    mstack.push(5); 
    mstack.push(17);
    std::cout << mstack.top() << std::endl; 
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int> s(mstack);

    std::cout << std::endl;

    std::cout << "-> List test: " << '\n';
    std::list<int>  l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    std::list<int>::iterator l_it = l.begin();
    std::list<int>::iterator l_ite = l.end();
    ++l_it;
    --l_it;
    while (l_it != l_ite) 
    {
        std::cout << *l_it << std::endl;
        ++l_it; 
    }
    return 0;
}