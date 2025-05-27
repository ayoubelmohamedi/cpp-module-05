/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:16 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:07:17 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("default_target") {
    std::cout << "Default constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    std::cout << "Constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), _target(other._target) {
    std::cout << "Copy constructor called for ShrubberyCreationForm: " << _target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "Copy assignment operator called for ShrubberyCreationForm: " << _target << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor called for ShrubberyCreationForm: " << _target << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (!isExecutableBy(executor))
        throw AForm::GradeTooLowException();
 
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    outfile << "       /\\       " << std::endl;
    outfile << "      /\\*\\      " << std::endl;
    outfile << "     /\\O\\*\\     " << std::endl;
    outfile << "    /*/\\/\\/\\    " << std::endl;
    outfile << "   /\\O\\/\\*\\/\\   " << std::endl;
    outfile << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
    outfile << " /\\O\\/\\/*/\\/O/\\ " << std::endl;
    outfile << "       ||       " << std::endl;
    outfile << "       ||       " << std::endl;
    outfile << "       ||       " << std::endl;
    outfile << std::endl;
    outfile << "       /\\       " << std::endl;
    outfile << "      /  \\      " << std::endl;
    outfile << "     /    \\     " << std::endl;
    outfile << "    /      \\    " << std::endl;
    outfile << "   /        \\   " << std::endl;
    outfile << "  /__________\\  " << std::endl;
    outfile << "       ||       " << std::endl;
    outfile << "       ||       " << std::endl;
    outfile << "       ||       " << std::endl;
    
    outfile.close();

    std::cout << executor.getName() << " executed " << _target << std::endl;
}


std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
    os << "ShrubberyCreationForm: " << form.getName() 
       << ", Target: " << form.getTarget() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getSignGrade() 
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

