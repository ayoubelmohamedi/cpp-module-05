/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:07 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:07:08 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();

        const std::string &getTarget() const;
        virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif
