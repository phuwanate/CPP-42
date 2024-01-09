/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:06 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/09 13:37:50 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

//Check literals floating-point
bool isLiterals(std::string const &arg){

    if (arg == "nan" || arg == "nanf" || arg == "+inf" || arg == "+inff"\
        || arg == "-inf" || arg == "-inff")
        return true;
    return false;
}

bool isImpossible(std::string const &arg, arg_type &_type, bool &_impossible){
    
    try{ 
        if (_type == INT)
            std::stoi(arg);
        else if (_type == FLOAT)
            std::stof(arg);
        else if (_type == DOUBLE)
            std::stod(arg);
    }catch (std::exception &e) {
        _impossible = true;
        return true;
    }
    return false;
}

//Print Output
void printChar(char _c, std::string const &arg){

    if ((std::isprint(_c) == 0  && (_c >= 127)) || isLiterals(arg) == true)
        std::cout << RED << "char: Impossible" << '\n' << DEFAULT;
    else if (std::isprint(_c) == 0)
        std::cout << RED << "char: Non displayable" << '\n' << DEFAULT;
    else
        std::cout << "char: '" << _c << "'" << '\n';
}

void printInt(int _n, std::string const &arg, arg_type _type, bool &_impossible){
    if (_type == CHAR)
        std::cout << "int: " << static_cast<int> (arg[0]);
    else
    {
        _type = INT;
        if (isImpossible(arg, _type, _impossible) == true)
            std::cout << RED << "int: impossible" << DEFAULT;
        else
        {   
            _n = std::stoi( arg );
            std::cout << "int: " << _n;
        }
    }
    std::cout << '\n';
}

void printFloat(float _f, std::string const &arg, arg_type _type, bool &_impossible){
    
    if (_type == CHAR)
        std::cout << "float: " << static_cast<float> (arg[0]) << ".0f";
    else
    {
        _type = FLOAT;
        if (isImpossible(arg, _type, _impossible) == true){
            std::cout << RED << "float: impossible" << '\n' << DEFAULT;
	    return ;
	}
	_f = std::stof( arg );
        std::cout << "float: ";
        if (arg == "nan" || arg == "nanf")
            std::cout << "nanf";
        else if (arg == "+inf" || arg == "+inff")
            std::cout << "+inff";
        else if (arg == "-inf" || arg == "-inff")
            std::cout << "-inff";
        else if (_f - static_cast<int>( _f ) == 0)
            std::cout << _f << ".0f";
        else
            std::cout << _f;
    }
    std::cout << '\n';
}

void printDouble(double _d, std::string const &arg, arg_type _type, bool &_impossible){
    
    if (_type == CHAR)
        std::cout << "double: " << static_cast<double> (arg[0]) << ".0";
    else{
            _type = DOUBLE;
            if (isImpossible(arg, _type, _impossible) == true){
                std::cout << RED << "double: impossible" << '\n' << DEFAULT;
	    	return ;
	    }
	    _d = std::stod( arg );
            std::cout << "double: ";
            if (arg == "nan" || arg == "nanf")
                std::cout << "nan";
            else if (arg == "+inf" || arg == "+inff")
                std::cout << "+inf";
            else if (arg == "-inf" || arg == "-inff")
                std::cout << "-inf";
            else if (_d - static_cast<int>( _d ) == 0)
                std::cout << _d << ".0";
            else
                std::cout << _d;
    }
    std::cout << '\n';
}

//Check arguments type
bool isChar(std::string const &arg){
    if ((arg.length() == 1) && (std::isalpha(arg[0]) != 0)&& (std::isprint(arg[0]) != 0))
        return true;
    return false;
}

bool isInt(std::string const &arg){

    std::size_t j = 0;
    if (arg[j] == '+' || arg[j] == '-')
        j++;
    for (std::size_t i = j; i < arg.length(); i++)
    {
        if (std::isdigit(arg[i]) == 0)
            return false;
    }
    return true;
}

bool isFloat(std::string const &arg){

    std::size_t j = 0;
    std::size_t dot_found = 0;
    
    //The fractional part must be at least 2 digit (numeric + f).
    if (arg.find ('.') == std::string::npos || arg.find ('.') == 0 \
        || arg.find ('.') == arg.length() - 2 || arg.back() != 'f')
        return false;
    if (arg[j] == '+' || arg[j] == '-')
        j++;
    for (std::size_t i = j; i < arg.length() - 1; i++)
    {
        if (arg[i] == '.')
            dot_found += 1;
        if ((std::isdigit(arg[i]) == 0 && arg[i] != '.') || dot_found > 1)
            return false;
    }
    return true;
}

bool isDouble(std::string const &arg){
    
    std::size_t j = 0;
    std::size_t dot_found = 0;
    
    //The fractional part must be at least 1 digit.
    if (arg.find ('.') == std::string::npos || arg.find ('.') == 0 \
        || arg.find ('.') == arg.length() - 1)
        return false;
    if (arg[j] == '+' || arg[j] == '-')
        j++;
    for (std::size_t i = j; i < arg.length(); i++)
    {
        if (arg[i] == '.')
            dot_found += 1;
        if ((std::isdigit(arg[i]) == 0 && arg[i] != '.') || dot_found > 1)
            return false;
    }
    return true;
}


void showOutput(char _c, int const _n, float const _f, double const _d, std::string const &arg,\
 arg_type _type, bool &_impossible){

    if (_n > 255)
        std::cout << RED << "char: Impossible" << '\n' << DEFAULT;
    else
        printChar(_c, arg);
    printInt(_n, arg, _type, _impossible);
    printFloat(_f, arg, _type, _impossible);
    printDouble(_d, arg, _type, _impossible);
}

void literalsOutput(std::string const &arg, arg_type _type, bool &_impossible, float _f, double _d){

    std::cout << RED << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n' << DEFAULT;
    printFloat(_f, arg, _type, _impossible);
    printDouble(_d, arg, _type, _impossible);
}

void    checkType(std::string const &arg, arg_type &_type){
    
    if ( isChar( arg ) == true ){
        
        _type = CHAR;
    } 
    else if ( isInt( arg ) == true ){
        
        _type = INT;
    }
    else if ( isFloat( arg ) == true ){

        _type = FLOAT;
    }
    else if ( isDouble( arg ) == true){

        _type = DOUBLE;
    }
    else if ( isLiterals( arg ) == true){
        
        _type = LITERALS;
    }
    else
        _type = NONE;
}

void typeCast(std::string &arg, arg_type &_type){

    char        _c = 0; 
    int         _n = 0; 
    float       _f = 0.0f; 
    double      _d = 0.0; 
    bool        _impossible = false;
    
    switch ( _type ){

        case CHAR:
                _c = arg[0];
                showOutput(_c, static_cast<int>( _c ), static_cast<float>( _c ), static_cast<double>( _c ), arg, _type, _impossible);
                break ;
        case INT:
                if (isImpossible(arg, _type, _impossible) == false)
                {
                    _n = std::stoi( arg );
                    showOutput(static_cast<char>( _n ), _n, static_cast<float>( _n ), static_cast<double>( _n ), arg, _type, _impossible);
                }else{
                    std::cout << RED << "char: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "int: Impossible" << '\n' << DEFAULT;
                    printFloat(_f, arg, _type, _impossible);
                    printDouble(_d, arg, _type, _impossible);
                }
                break ;
        case FLOAT:
                if (isImpossible(arg, _type, _impossible) == false)
                {
                    _f = std::stof( arg );
                    showOutput(static_cast<char>( _f ), static_cast<int>( _f ), _f, static_cast<double>( _f ),arg, _type, _impossible);
                }else{
                    std::cout << RED << "char: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "int: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "float: Impossible" << '\n' << DEFAULT;
                    printDouble(_d, arg, _type, _impossible);
                }    
                break ;
        case DOUBLE:
                if (isImpossible(arg, _type, _impossible) == false)
                {
                    _d = std::stod( arg );
                    showOutput(static_cast<char>( _d ), static_cast<int>( _d ), static_cast<float>( _d ), _d, arg, _type, _impossible);
                }else{
                    std::cout << RED << "char: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "int: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "float: Impossible" << '\n' << DEFAULT;
                    std::cout << RED << "double: Impossible" << '\n' << DEFAULT;
                }   
                break ;
        case LITERALS:
                literalsOutput( arg , _type, _impossible, _f, _d);
                break ;
        default:
                break ;
    }
}
