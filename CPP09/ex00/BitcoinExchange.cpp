#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){

    std::ifstream   file("data.csv");
    std::string     line;
    std::string     date;
    std::string     rate;
    std::size_t     found;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        //extract line to get date, exchange rate
        found = line.find(',');
        date = line.substr(0, found);
        rate = line.substr(found + 1);

        this->_exchangeData[date] = rate;
    }
    file.close();
    // std::map<std::string, std::string>::iterator it = _exchangeData.begin();
    // std::map<std::string, std::string>::iterator ite = _exchangeData.end();
    // while (it != ite)
    // {
    //     std::cout << it->first << ", ";
    //     std::cout << it->second << '\n';
    //     it++;
    // }
}

void    BitcoinExchange::trade(std::string const& file_txt){

    std::ifstream   file(file_txt);
    std::string     line;
    std::size_t     found;
    std::string     date;
    std::string     value;

    if (file.is_open() == false){
        //if file cannot open.
        std::cout << RED << "Error: The file can't open." << '\n' << DEFAULT;
        exit (EXIT_FAILURE);
    }
    else if (file.peek() == EOF){
        //if file is empty.
        std::cout << RED << "Error: Empty file." << '\n' << DEFAULT;
        exit (EXIT_FAILURE);
    }
    
    std::getline(file, line);
    if (line != "date | value"){
        //if header input.txt is invalid
        std::cout << RED << "Error: Invalid format." << '\n' << DEFAULT;
        exit (EXIT_FAILURE);
    }
    while (std::getline(file, line)){
        
        found = line.find('|');
        if (found == std::string::npos){

            std::cout << RED << "Error: bad input => " << line << '\n' << DEFAULT;
            continue ;
        }
        date = trim_space(line.substr(0, found));
        value = trim_space(line.substr(found + 1));

        try
        {
            is_date_valid(date);
            if (value.empty() == true)
                throw std::invalid_argument("Error: value is empty.");
            is_value_valid(value);

            

            std::cout << date << " => " << value << " = " << '\n';
        }catch (std::exception &e){
            std::cout << RED << e.what() << " => " << line << '\n' << DEFAULT;
        }
    }
    file.close();
}

std::string    BitcoinExchange::trim_space(std::string const& str){

    std::size_t head = str.find_first_not_of(' ');
    std::size_t tail;

    if (head == std::string::npos)
        return str;
    tail = str.find_last_not_of(' ');
    return (str.substr(head, (tail - head + 1)));
}

void BitcoinExchange::find_year_range(std::map<std::string, int> &inst){

    std::string    year;
    std::size_t    nYear;
    std::size_t    min = UINT_MAX;
    std::size_t    max = 0;
    std::map<std::string, std::string>::iterator it = this->_exchangeData.begin();
    std::map<std::string, std::string>::iterator ite = this->_exchangeData.end();
    while(it != ite){

        year = (it->first).substr(0, 4);
        nYear = stoi(year);
        if (min > nYear)
            min = nYear;
        if (max < nYear)
            max = nYear;
        it++;
    }
    inst["max"] = max;
    inst["min"] = min;
}

void    BitcoinExchange::is_date_valid(std::string const& date){

    float Year, Month, Day;
    std::string sYear, sMonth, sDay;
    std::map<std::string, int> year_range;

    if (date.length() != 10)
        throw std::invalid_argument("Error: invalid date.");
    if (date.find_first_of('-') != 4 || date.find_last_of('-') != 7)
        throw std::invalid_argument("Error: invalid date.");
    for (std::size_t i = 0; i< date.length(); i++)
    {
        if (std::isdigit(date[i]) == 0 && date[i] != '-')
            throw std::invalid_argument("Error: invalid date.");
    }
    sYear = date.substr(0 ,4);
    sMonth = date.substr(5 ,2);
    sDay = date.substr(8 ,2);

    std::stringstream nYear(sYear);
    std::stringstream nMonth(sMonth);
    std::stringstream nDay(sDay);

    nYear >> Year;
    nMonth >> Month;
    nDay >> Day;

    find_year_range(year_range);
    
    if (Year < year_range["min"] || Year > year_range["max"] || Month < 1 || Month > 12 || Day < 1 || Day > 31)
        throw std::invalid_argument("Error: invalid date (Date doesn't existed).");
    
}

void    BitcoinExchange::is_value_valid(std::string const& value){

    std::size_t dot = 0;
    bool sign;
    float val;

    if (std::find(value.begin(), value.end(), '.') != value.end()){

        dot = value.find('.');
        if (dot == 0)
            throw std::invalid_argument("Error: Dot notation at the begining.");
        else if (dot == value.length() - 1)
            throw std::invalid_argument("Error: Dot notation at the end.");
        else if (std::find(value.begin() + dot + 1, value.end(), '.') != value.end())
            throw std::invalid_argument("Error: Multilple-dot notation.");
    }
    sign = (value[0] == '+' || value[0] == '-');
    for (std::size_t i = sign ? 1:0; i < value.length(); i++)
    {
        if ((std::isdigit(value[i]) == 0) && (value[i] != '.'))
            throw std::invalid_argument("Error: not a number.");
    }
    try{
        val = std::stof(value);
    }catch(std::exception &e){
        throw std::out_of_range("Error: The numbers is out of range.");
    }
    if (val < 0)
        throw std::out_of_range("Error: not a positive number.");
    else if (val > 1000)
        throw std::out_of_range("Error: too large a number.");
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& inst){

    *this = inst;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const& inst){

    if (this != &inst)
        this->_exchangeData = inst._exchangeData;
    return *this;
}

const char* BitcoinExchange::InvalidFile::what() const throw(){ return "Error: could not open file.";}
const char* BitcoinExchange::InvalidArgument::what() const throw(){ return "Error: invalid argument.";}
const char* BitcoinExchange::InvalidValue::what() const throw(){ return "invalid value.";}
