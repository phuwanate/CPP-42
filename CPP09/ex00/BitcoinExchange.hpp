#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <limits>
#include <stddef.h>


class BitcoinExchange{

    public:
	    typedef std::map<std::size_t, float>::iterator iterator;
 
	    BitcoinExchange(void);
	    ~BitcoinExchange(void);
	    BitcoinExchange(BitcoinExchange const& inst);
	    BitcoinExchange &operator=(BitcoinExchange const& inst);

	    void            trade(std::string const& file_txt);
	    
	    //Setters
	    void            setCurrdate(std::size_t currDate);
	    void            setPrevdate(std::size_t prevDate);
	    void            setDate(std::string const& date);
	    void            setValue(std::string const& value);

    private:
	    std::map<std::size_t, float>	_exchangeData;
	    std::map<std::size_t, float>	_wallet;
	    std::map<std::string, int>     	_year_range;
	    iterator				_it;	
	    std::string                         _line, _date, _value;
	    std::size_t                         _prevDate, _currDate;
	    int 				_Year, _Month, _Day;

	    void		__read_input(void);
	    void		__init_var(void);
	    void            	__find_year_range(std::map<std::string, int> &inst);
	    float		__clean_value(std::string const& value);
	    std::size_t		__clean_date(std::string const& date);
	    std::size_t     	__goback_date(void);
	    std::string     	__trim_space(std::string const& str);
    
	   //Valid data checker.
	    void            	__check_file(std::ifstream & file);
	    void            	__is_value_valid(std::string const& value);
	    void            	__is_date_valid(void);
	    void            	__check_date_value(void);
	    bool            	__is_leapYear(int const Year);

};

#endif