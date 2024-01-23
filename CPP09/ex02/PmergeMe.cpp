#include "PmergeMe.hpp"

/////////////////////////////////////////Orthodox Carnonical/////////////////////////////////////
template <typename Container>
PmergeMe<Container>::PmergeMe(void): _storage(), _remaining_numb(-1), _end_time(0), _key("before") {}

template <typename Container>
PmergeMe<Container>::~PmergeMe(void) {}

template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe const& inst){ *this = inst; }

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(PmergeMe const& inst){

    if (this != &inst){

        _storage = inst._storage;
        _remaining_numb = inst._remaining_numb;
        _end_time = inst._end_time;
    }
    return *this;
}
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Public zone/////////////////////////////////////////
template <typename Container>
PmergeMe<Container>::PmergeMe(char **arg): _storage(), _remaining_numb(-1), _end_time(0), _key("before"){

    try{
        std::stringstream   stream;
        std::string         number;

        for(std::size_t i = 0; arg[i] != nullptr; i++){
            stream.clear();
            stream << arg[i];
            while (stream >> number) //split
            {    
                __is_integer(number);
                _storage.push_back(__ft_to_number(number));
            }
        }
        if (_storage.size() == 0)
            throw std::invalid_argument("Error: empty arguments.");
        __is_sort();
    }catch (std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
        exit(1);
    }
}

template <typename Container>
void    PmergeMe<Container>::merge_insertion_sort(void){

        _key = "after";
        std::clock_t    begin = std::clock();

        //Build a vector of pairs.
        vector_of_pair  vector_pairs = __build_pairs();
        __sort_pairs(vector_pairs);

        //Build main chain (first of pairs[0] and all second of each pair)
        _storage.clear();
        _storage.push_back(vector_pairs[0].first);
        for (size_type i = 0; i < vector_pairs.size(); i++){

            _storage.push_back(vector_pairs[i].second);
        }

        //Insert all remaining first of each pair to main chain
        for (size_t i = 1; i < vector_pairs.size(); i++){
        
            int index_to_insert = __binary_search(vector_pairs[i].first);
            _storage.insert(_storage.begin() + index_to_insert, vector_pairs[i].first);
        }

        //Insert remaining number
        if (_remaining_numb != -1){

            int index_to_insert = __binary_search(_remaining_numb);
            _storage.insert(_storage.begin() + index_to_insert, _remaining_numb);
        }
        _end_time = static_cast<double>(std::clock() - begin) / CLOCKS_PER_SEC * 1000000;
}

//Getters
template <typename Container>
Container	PmergeMe<Container>::getStorage(void) const{ return _storage; }

template <typename Container>
std::string	PmergeMe<Container>::getKey(void) const{ return _key; }

template <typename Container>
double  PmergeMe<Container>::getTime(void) const{ return _end_time; }

template <typename Container>
std::string getContainerType(void){}

template <>
std::string getContainerType<std::vector<int> >(void){ return "std::vector<int>"; }

template <>
std::string getContainerType<std::deque<int> >(void){ return "std::deque<int>"; }

template <typename Container>
void    PmergeMe<Container>::time_report(void){

		std::cout << "Time to process a range of " << getStorage().size(); 
        std::cout << " elements with " << getContainerType<Container>() << " : ";
		std::cout << std::fixed << std::setprecision(5) << getTime() << " us";
		std::cout << '\n';
}
//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////Private Zone/////////////////////////////////////////
template <typename Container>
typename  PmergeMe<Container>::vector_of_pair	PmergeMe<Container>::__build_pairs(void){

    vector_of_pair  pairs;

    if (_storage.size() % 2 != 0){

        _remaining_numb = _storage.back();
        _storage.pop_back();
    }

    for (size_type i = 0; i < _storage.size(); i+=2){

        if (_storage[i] > _storage[i + 1])
            std::swap(_storage[i], _storage[i + 1]);
        pairs.push_back(std::make_pair(_storage[i], _storage[i + 1]));
    }

    return pairs;
}

template <typename Container>
void    PmergeMe<Container>::__sort_pairs(vector_of_pair & pairs){

    if (pairs.size() <= 1)
        return ;

    size_type half = pairs.size() / 2;
    vector_of_pair left_half(pairs.begin(), pairs.begin() + half);
    vector_of_pair right_half(pairs.begin() + half, pairs.end());

    __sort_pairs(left_half);
    __sort_pairs(right_half);
    
    size_type left_index = 0, right_index = 0, index = 0;

    //sort with merge-style compare left and right
    while (left_index < left_half.size() && right_index < right_half.size())
        pairs[index++] = left_half[left_index].second < right_half[right_index].second ? left_half[left_index++] : right_half[right_index++];
    //push all remaining left half
    while (left_index < left_half.size())
        pairs[index++] = left_half[left_index++];
    //push all remaining right half
    while (right_index < right_half.size())
        pairs[index++] = right_half[right_index++];
}

template <typename Container>
int    PmergeMe<Container>::__binary_search(int needle){

    int left = 0, middle = 0;
    int right = _storage.size() - 1;

    while (left <= right){

        middle = (left + right) / 2;

        if (_storage[middle] == needle)
            return middle;
        else if (_storage[middle] < needle)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return left;
}

template <typename Container>
void    PmergeMe<Container>::__is_integer(std::string const& arg){

    if (arg.empty())
        throw std::invalid_argument("Error: Empty argument.");
    else if (arg[0] == '-')
        throw std::invalid_argument("Error: Negative number.");
    if (arg[0] == '+' && arg.length() == 1)
        throw std::invalid_argument("Error: Bad input");

    std::size_t i = (arg[0] == '+' && arg.length() != 0) ? 1 : 0;
    for(; i < arg.length(); i++){

        if (std::isdigit(arg[i]) == 0)
            throw std::invalid_argument("Error: Not a number.");
    }
}

template <typename Container>
void    PmergeMe<Container>::__is_sort(void){

        std::size_t i = 0;

        for(; i < _storage.size() - 1; i++){
            if (_storage[i] > _storage[i + 1])
                break ;
        }
        if (i == _storage.size() - 1)
            throw std::invalid_argument("All numbers is sorted.");
}

template <typename Container>
int PmergeMe<Container>::__ft_to_number(std::string const& str){

    std::stringstream   stream(str);
    int tmp;

    stream >> tmp;
    return (tmp);
}

//////////////////////////////////////////////////////////////////////////////////////////////

//Only initiate instance of vector and deque of int
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;