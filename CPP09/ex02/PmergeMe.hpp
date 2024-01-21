#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <exception>

template <typename Container>
class PmergeMe{

	public:
			typedef typename Container::value_type      	val_type;
			typedef typename Container::size_type       	size_type;
			typedef typename std::pair <val_type, val_type>	pair_type;
			typedef typename std::vector<pair_type>			vector_of_pair;

	private:
			Container	_storage;
			val_type	_remaining_numb;
			double		_end_time;
			std::string	_key;

			vector_of_pair		__build_pairs(void);
			void				__sort_pairs(vector_of_pair & pairs);
			int					__binary_search(int needle);
			void				__is_integer(std::string const& arg);
			void				__is_sort(void);
	
	public:
			PmergeMe(void);
			PmergeMe(char **arg);
			~PmergeMe(void);
			PmergeMe(PmergeMe const& inst);
			PmergeMe &operator=(PmergeMe const& inst);

			Container	getStorage(void) const;
			std::string getKey(void) const;
			double		getTime(void) const;

			void	merge_insertion_sort(void);
			void	time_report(void);
};

template <typename Container>
std::ostream &operator<<(std::ostream &o, PmergeMe<Container> const& inst){

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