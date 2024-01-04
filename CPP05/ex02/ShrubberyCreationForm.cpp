/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:12:21 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:33:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("Default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target){

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &instance): AForm(instance), _target(instance._target){
    
}
ShrubberyCreationForm::~ShrubberyCreationForm(void){

    std::cout << "ShrubberyCreationForm destroyed." << '\n';
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &instance){

    if (this != &instance)
        this->_target = instance._target;
    return (*this);
}

void		    ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

    if (this->getFormStatus() == false)
        throw AForm::NotbeSigned();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooHighExcecution();
    
    std::ofstream	wFile(this->_target + "_shrubbery");
    wFile << '\n';
    wFile << "                       _{/{/\\}\\" << '\n';
    wFile << "                    `_{/\\}{/\\}/}/}" << '\n';
    wFile << "                  _{/\\} _{/\\}{//\\}/}" << '\n';              
    wFile << "                {/{/\\}{/{/\\}(\\}{/\\} _" << '\n';         
    wFile << "               `{/\\}{/{/\\}(_)\\}{/{/\\}  _" << '\n'; 
    wFile << "             _\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\}}" << '\n'; 
    wFile << "            {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}/" << '\n'; 
    wFile << "           _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}`" << '\n'; 
    wFile << "         {/{/{\\{\\{\\(/}`{\\{\\/}/}{\\}(_){\\/}\\}" << '\n'; 
    wFile << "         _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}}" << '\n'; 
    wFile << "        {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}}`" << '\n'; 
    wFile << "        {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/}`)/}/}" << '\n'; 
    wFile << "        `{/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)}/}}" << '\n'; 
    wFile << "         {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\\}" << '\n'; 
    wFile << "          {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}/}" << '\n'; 
    wFile << "           {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}/}" << '\n'; 
    wFile << "            `(_|{/{\\/}{\\{\\/}/}{\\{\\|/}/}(_)`" << '\n'; 
    wFile << "              (_)/{/{\\{\\/}{/{\\{\\{\\(_)/}" << '\n'; 
    wFile << "                {/{\\{\\{\\/}/}{\\{\\}/}/}" << '\n'; 
    wFile << "                  {){/ {\\/}{\\/} \\}\\}" << '\n'; 
    wFile << "                       \\.-'.-/" << '\n'; 
    wFile << "              __...    |'-.-'| --...__" << '\n'; 
    wFile << "    _...--   ..----'   |'...'|  ' ..   ...." << '\n'; 
    wFile << "    -     .  . .    |. |-._  |   . .  '" << '\n';    
    wFile << "    .  '-  '    .--'   | '-.'|    .  '  . '" << '\n';
    wFile << "            ' ..       |'-_.-|" << '\n';
    wFile << "    .  '  .         _.-|-._ -|-._  .  '  ." << '\n';
    wFile << "                  .'   |'- .-|   '." << '\n';
    wFile << "    ..-'   ' .    '.   '-._.-'   .'  '  - ." << '\n';
    wFile << "    .-' '           '-._______.-'     '  ." << '\n';
    wFile << "            .      ~," << '\n';
    wFile << "        .       .   .   .    ' '-." << '\n';
    std::cout << ORANGE << this->_target + "_shrubbery" << " created." << '\n' << DEFAULT;
}