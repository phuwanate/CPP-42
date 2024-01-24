#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {

    __read_input();
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& inst){

    *this = inst;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const& inst){

    if (this != &inst){
        this->_exchangeData = inst._exchangeData;
        this->_wallet = inst._wallet;
        this->_it = inst._it;
        this->_line = inst._line;
        this->_date = inst._date;
        this->_value = inst._value;
        this->_prevDate = inst._prevDate;
        this->_currDate = inst._currDate;
        this->_Year = inst._Year;
        this->_Month = inst._Month;
        this->_Day = inst._Day;
        this->_year_range = inst._year_range;
    }
    return *this;
}

//////////////////////////////////////////////Setters/////////////////////////////////////////////////////

void            BitcoinExchange::setCurrdate(std::size_t currDate){ _currDate = currDate; }
void            BitcoinExchange::setPrevdate(std::size_t prevDate){ _prevDate = prevDate; }
void            BitcoinExchange::setDate(std::string const& date){ _date = date; }
void            BitcoinExchange::setValue(std::string const& value){ _value = value; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Private zone////////////////////////////////////////////////

void            BitcoinExchange::__read_input(void){

    std::ifstream   file("data.csv");
    std::string     line;

    std::getline(file, line);
    while (std::getline(file, line)){
        
        _exchangeData[__clean_date(line.substr(0, line.find(',')))] = __clean_value(line.substr(line.find(',') + 1));
    }
    __init_var();
    file.close();
}

void  BitcoinExchange::__init_var(void){

    _year_range["min"] =  UINT_MAX;
    _year_range["max"] = 0;
}

std::size_t		BitcoinExchange::__clean_date(std::string const& date){
    std::size_t         new_date;
    std::stringstream   _stream(date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2));

    _stream >> new_date;
    return (new_date);
}

float		BitcoinExchange::__clean_value(std::string const& value){
    float               new_value;
    std::stringstream	_stream(value);

    _stream >> new_value;
    return (new_value);
}

void BitcoinExchange::__check_file(std::ifstream & file){

    //if file cannot open & if file is empty
    if (file.is_open() == false){
        std::cout << RED << "Error: The file can't open." << '\n' << DEFAULT;
        exit (EXIT_FAILURE);
    }
    else if (file.peek() == EOF){
        std::cout << RED << "Error: Empty file." << '\n' << DEFAULT;
        exit (EXIT_FAILURE);
    }
}

void BitcoinExchange::__check_date_value(void){
    __is_date_valid();
    if (_value.empty() == true)
        throw std::invalid_argument("Error: value is empty.");
    __is_value_valid(_value);
}

bool BitcoinExchange::__is_leapYear(int const Year){

    if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
        return true;
    return false;
}

void    BitcoinExchange::__is_date_valid(void){
            
    if (_date.length() != 10)
        throw std::invalid_argument("Error: invalid date.");
    if (_date.find_first_of('-') != 4 || _date.find_last_of('-') != 7)
        throw std::invalid_argument("Error: invalid date.");
    for (std::size_t i = 0; i< _date.length(); i++)
    {
        if (std::isdigit(_date[i]) == 0 && _date[i] != '-')
            throw std::invalid_argument("Error: invalid date.");
    }
    
    _Year = _it->first / 10000;
    _Month = (_it->first % 10000) / 100;
    _Day = (_it->first % 10000) % 100;

    if (_Month < 1 || _Month > 12 || _Day < 1 || _Day > 31)
        throw std::invalid_argument("Error: invalid date (Date doesn't existed).");

    if ((_Month == 4 || _Month == 6 || _Month == 9 || _Month == 11) && _Day > 30)
        throw std::invalid_argument("Error: invalid date. (Have more than 31 days)");
    
    if (_Month == 2)
    {
        bool leapYear = __is_leapYear(_Year);
        if (_Day > (leapYear ? 29 : 28))
            throw std::invalid_argument("Error: invalid date.");
    }
}

void    BitcoinExchange::__is_value_valid(std::string const& value){

    if (std::find(value.begin(), value.end(), '.') != value.end()){

        if (value.find('.') == 0)
            throw std::invalid_argument("Error: Dot notation at the begining.");
        else if (value.find('.') == value.length() - 1)
            throw std::invalid_argument("Error: Dot notation at the end.");
        else if (std::find(value.begin() + value.find('.') + 1, value.end(), '.') != value.end())
            throw std::invalid_argument("Error: Multilple-dot notation.");
    }
    for (std::size_t i = (value[0] == '+' || value[0] == '-') ? 1:0; i < value.length(); i++)
    {
        if ((std::isdigit(value[i]) == 0) && (value[i] != '.'))
            throw std::invalid_argument("Error: not a number.");
    }
    if (_it->second < 0)
        throw std::out_of_range("Error: not a positive number.");
    else if (_it->second > 1000)
        throw std::out_of_range("Error: too large a number.");
}

std::string    BitcoinExchange::__trim_space(std::string const& str){

    std::size_t head = str.find_first_not_of(' ');
    std::size_t tail;

    if (head == std::string::npos)
        return str;
    tail = str.find_last_not_of(' ');
    return (str.substr(head, (tail - head + 1)));
}

std::size_t BitcoinExchange::__goback_date(void){

    _Year = _currDate / 10000;
    _Month = (_currDate % 10000) / 100;
    _Day = (_currDate % 10000) % 100;  
    int  day_month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (__is_leapYear(_Year) == true)
        day_month[2] = 29;
    _Day--;
    if (_Day == 0){
        _Month--;
        if (_Month == 0){
            _Month = 12;
            _Year--;
            if (_Year < _year_range["min"])
                throw std::out_of_range("Error: bad input out of database range.");
        }
        _Day = day_month[_Month];
    }

    return ( (_Year * 10000) + (_Month * 100) + _Day );
}

void BitcoinExchange::__find_year_range(std::map<std::string, int> &inst){

    int    nYear;
    for (iterator it = _exchangeData.begin(); it != _exchangeData.end(); it++){

        nYear = it->first / 10000;
        if (inst["min"] > nYear)
            inst["min"] = nYear;
        if (inst["max"] < nYear)
            inst["max"] = nYear;   
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////Public zone/////////////////////////////////////////////////


void    BitcoinExchange::trade(std::string const& file_txt){
   
   std::ifstream   file(file_txt);    

    __check_file(file);
    std::getline(file, _line);
    while (std::getline(file, _line)){

        _wallet.clear();
        if (_line.find('|') == std::string::npos){
            if (_line.find(',') == std::string::npos){

            std::cout << RED << "Error: bad input => " << _line << '\n' << DEFAULT;
            continue ;
            }else{
                setDate(_line.substr(0, _line.find(',')));
                setValue(__trim_space(_line.substr(_line.find(',') + 1))); 
                _wallet[__clean_date(_date)] = __clean_value(_value);
            }
        }else{
                setDate(__trim_space(_line.substr(0,_line.find('|'))));
                setValue(__trim_space(_line.substr(_line.find('|') + 1)));
                _wallet[__clean_date(_date)] = __clean_value(_value);
        }
            _it = _wallet.begin();

        try{
            __find_year_range(_year_range);
            __check_date_value();
            setPrevdate(_it->first);
            iterator it_data = _exchangeData.find(_it->first);
            for (; it_data == _exchangeData.end(); it_data = _exchangeData.find(_prevDate)){
                
                setCurrdate(_prevDate);
                setPrevdate(__goback_date());
            }
            std::cout << _date << " => " << _value << " = " << _it->second * it_data->second << '\n';
        }catch (std::exception &e){

            std::cout << RED << e.what() << " => " << _line << '\n' << DEFAULT;
        }
    }
    file.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
