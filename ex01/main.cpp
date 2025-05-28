/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:49:56 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/29 00:56:26 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 140);

        Form formA("TopSecret", 100, 120);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        std::cout << "=======================================" << std::endl;
        std::cout << "\nBob tries to sign the form (should fail):" << std::endl;
        bob.signForm(formA);

        std::cout << "=======================================" << std::endl;

        std::cout << "\nAlice tries to sign the form (should succeed):" << std::endl;
        alice.signForm(formA);

        std::cout << "=======================================" << std::endl;
        
        std::cout << "\nForm status after signing attempts:" << std::endl;
        std::cout << formA << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}