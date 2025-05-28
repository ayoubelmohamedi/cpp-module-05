/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:10 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/29 00:20:15 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "Default constructor called for RobotomyRequestForm" << std::endl;
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Constructor called for RobotomyRequestForm with target: " << _target << std::endl;
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
    std::cout << "Copy constructor called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "Copy assignment operator called for RobotomyRequestForm" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor called for RobotomyRequestForm: " << _target << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (!isExecutableBy(executor))
        throw AForm::FormLowExecutionGradeException();

    std::cout << "* Drilling noises *" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << _target << " failed." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
    os << static_cast<const AForm&>(form);
    os << " [RobotomyRequestForm: Target = " << form.getTarget() << "]";
    return os;
}
