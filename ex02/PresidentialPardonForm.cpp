/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:39 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/29 00:19:49 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "Default constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Constructor called for PresidentialPardonForm with target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
    std::cout << "Copy constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "Copy assignment operator called for PresidentialPardonForm" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor called for PresidentialPardonForm: " << _target << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (!isExecutableBy(executor))
        throw AForm::FormLowExecutionGradeException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
    os << static_cast<const AForm&>(form);
    os << " [PresidentialPardonForm: Target = " << form.getTarget() << "]";
    return os;
}
