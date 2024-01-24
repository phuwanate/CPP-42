#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <exception>

template <typename Container, typename T>
class PmergeMe{

	public:
			typedef typename Container::value_type      	val_type;
			typedef typename Container::size_type       	size_type;

	private:
			Container			_storage;
			val_type			_remaining_numb;
			double				_end_time;
			std::string			_key;

			T					__build_pairs(void);
			int					__binary_search(int needle);
			void				__sort_pairs(T & pairs);
			void				__is_integer(std::string const& arg);
			void				__is_sort(void);

			//Convert string to numeric.
			int      			__ft_to_number(std::string const& str);

	
	public:
			PmergeMe(void);
			PmergeMe(char **arg);
			~PmergeMe(void);
			PmergeMe(PmergeMe const& inst);
			PmergeMe &operator=(PmergeMe const& inst);

			Container			getStorage(void) const;
			std::string 		getContainerType(void);
			std::string 		getKey(void) const;
			double				getTime(void) const;

			void				merge_insertion_sort(void);
			void				time_report(void);
};

template <typename Container, typename T >
std::ostream &operator<<(std::ostream &o, PmergeMe<Container, T> const& inst){

	if (inst.getKey() == "before")
		o << "Before: ";
	else if (inst.getKey() == "after")
		o << "After: ";
	for (std::size_t i = 0; i < inst.getStorage().size(); i++)
		o << inst.getStorage()[i] << " ";
	o << '\n';

	return o;
}

#endif