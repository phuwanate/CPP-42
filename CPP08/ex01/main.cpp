#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void){

  //Mandatoty test
  std::cout << "-> mandatory test: " << '\n';
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp;

  std::cout << sp.shortestSpan() << '\n';
  std::cout << sp.longestSpan() << '\n';
  std::cout << '\n';


  // Duplicated number test
  std::cout << "-> Duplicated number test: " << '\n';
  Span sp2 = Span(2);
  sp2.addNumber(6);
  sp2.addNumber(6);
  std::cout << sp2 << '\n';

  //Full Span
  std::cout << "-> Full span test: " << '\n';
  Span sp3 = Span(2);
  sp3.addNumber(1);
  sp3.addNumber(2);
  sp3.addNumber(3);
  std::cout << sp3 << '\n';

  //Fill Span with range of iterators
  std::cout << "-> Fill over range of Span test: " << '\n';
  Span sp4 = Span(4);
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  sp4.addNumber(v.begin(), v.end());
  std::cout << sp4;
  sp4.addNumber(v.begin(), v.end());
  std::cout << '\n';

  // No span found test
  std::cout << "-> No span test: " << '\n';
  Span  one = Span(1);
  one.addNumber(1);
  one.shortestSpan();
  one.longestSpan();
  std::cout << '\n';

  // 10,000 numbers test
  std::cout << "-> 10,0000 numbers test: " << '\n';
  Span huge_span = Span(10000);
  std::vector<int>  huge_v;
  std::srand(std::time(0));

  for (int i = 0; i < 10000; i++)
      huge_v.push_back(i + 1);
  std::vector<int>::iterator v_it = huge_v.begin();
  std::vector<int>::iterator v_ite = huge_v.end();
  std::cout << "vector[0]: [" << *huge_v.begin() << "]" << '\n';
  std::cout << "vector[9999]: [" << *(huge_v.end() - 1) << "]" << '\n';

  huge_span.addNumber(v_it, v_ite);
  std::cout << huge_span.shortestSpan() << '\n';
  std::cout << huge_span.longestSpan() << '\n';
}