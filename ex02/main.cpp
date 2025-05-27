/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:07:34 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/27 22:07:35 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main ()
{
    Bureaucrat highGradeBureaucrat("HighGradeEmployee", 1);
    Bureaucrat midGradeBureaucrat("MidGradeEmployee", 70);
    Bureaucrat lowGradeBureaucrat("LowGradeEmployee", 150);

    std::cout << highGradeBureaucrat << std::endl;
    std::cout << midGradeBureaucrat << std::endl;
    std::cout << lowGradeBureaucrat << std::endl;

    std::cout << "\\n--- Testing ShrubberyCreationForm ---" << std::endl;
    ShrubberyCreationForm shrubForm("Garden");
    std::cout << shrubForm << std::endl;

    std::cout << "\\n* Low grade bureaucrat tries to sign and execute Shrubbery *" << std::endl;
    try {
        // Should fail: no enough grade to sign or execute
        lowGradeBureaucrat.signForm(shrubForm); 
        lowGradeBureaucrat.executeForm(shrubForm);
    } catch (const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n* Mid grade bureaucrat signs Shrubbery, Low grade tries to execute *" << std::endl;
    try {
        //mid grade can sign
        midGradeBureaucrat.signForm(shrubForm);
        std::cout << shrubForm << std::endl;
        //low grade cannot execute
        lowGradeBureaucrat.executeForm(shrubForm);
    }  catch (const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n* Mid grade bureaucrat signs and executes Shrubbery *" << std::endl;
    ShrubberyCreationForm shrubForm2("Home");
    try {
        midGradeBureaucrat.signForm(shrubForm2);
        midGradeBureaucrat.executeForm(shrubForm2); 
        std::cout << shrubForm2 << std::endl;
    } catch (const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n\\n--- Testing RobotomyRequestForm ---" << std::endl;
    RobotomyRequestForm roboForm("Bender");
    std::cout << roboForm << std::endl;

    std::cout << "\\n* Low grade bureaucrat tries to sign and execute Robotomy *" << std::endl;
    try {
        lowGradeBureaucrat.signForm(roboForm);
        lowGradeBureaucrat.executeForm(roboForm);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\\n* Mid grade bureaucrat signs Robotomy, Low grade tries to execute *" << std::endl;
    try {
        midGradeBureaucrat.signForm(roboForm); 
        std::cout << roboForm << std::endl;
        lowGradeBureaucrat.executeForm(roboForm);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n* High grade bureaucrat signs and executes Robotomy *" << std::endl;
    RobotomyRequestForm roboForm2("R2D2");
    try {
        highGradeBureaucrat.signForm(roboForm2); 
        highGradeBureaucrat.executeForm(roboForm2); 
        std::cout << roboForm2 << std::endl;
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\\n* Mid grade bureaucrat tries to execute unsigned Robotomy *" << std::endl;
    RobotomyRequestForm roboFormUnsigned("UnsignedBot");
    try {
        // Form not signed
        midGradeBureaucrat.executeForm(roboFormUnsigned);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }



    std::cout << "\\n\\n--- Testing PresidentialPardonForm ---" << std::endl;
    PresidentialPardonForm pardonForm("Arthur Dent");
    std::cout << pardonForm << std::endl;

    std::cout << "\\n* Mid grade bureaucrat tries to sign and execute Pardon *" << std::endl;
    try {
        midGradeBureaucrat.signForm(pardonForm); // Sign: 25, Exec: 5. Mid (70) cannot sign.
        midGradeBureaucrat.executeForm(pardonForm);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n* High grade bureaucrat signs Pardon, Mid grade tries to execute *" << std::endl;
    try {
        highGradeBureaucrat.signForm(pardonForm); // High (1) can sign.
        std::cout << pardonForm << std::endl;
        midGradeBureaucrat.executeForm(pardonForm); // Mid (70) cannot execute (needs 5).
    }  catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n* High grade bureaucrat signs and executes Pardon *" << std::endl;
    PresidentialPardonForm pardonForm2("Ford Prefect");
    try {
        highGradeBureaucrat.signForm(pardonForm2);
        highGradeBureaucrat.executeForm(pardonForm2);
        std::cout << pardonForm2 << std::endl;
    }  catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\\n--- Testing Bureaucrat executeForm method directly ---" << std::endl;
    Bureaucrat executor("Executor", 5);
    ShrubberyCreationForm scf("DirectExec");
    RobotomyRequestForm rrf("DirectExecBot");
    PresidentialPardonForm ppf("DirectExecPres");

    std::cout << " =============================================" << std::endl;

    std::cout << "\\n* Executor signs and executes Shrubbery *" << std::endl;
    try {
        executor.signForm(scf);
        executor.executeForm(scf);
    }catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    std::cout << " =============================================" << std::endl;

    std::cout << "\\n* Executor signs and executes Robotomy *" << std::endl;
    try {
        executor.signForm(rrf);
        executor.executeForm(rrf);
        executor.executeForm(rrf);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\\n* Executor signs and executes Pardon *" << std::endl;
    try {
        executor.signForm(ppf);
        executor.executeForm(ppf);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << " =============================================" << std::endl;

    std::cout << "\\n* Executor tries to execute an unsigned Robotomy form *" << std::endl;
    RobotomyRequestForm rrfUnsigned("UnsignedDirect");
    try {
        // fails : Form not signed
        executor.executeForm(rrfUnsigned);
    } catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << " =============================================" << std::endl;

    std::cout << "* Bureaucrat with too low grade for execution *" << std::endl;
    Bureaucrat lowExec("LowExecGuy", 100);
    PresidentialPardonForm ppfHighReq("HighReqPres"); // Needs grade 5 to execute
    try {
        highGradeBureaucrat.signForm(ppfHighReq); // Signed by high grade
        lowExec.executeForm(ppfHighReq); // lowExec (100) tries to execute, should fail
    }  catch(const AForm::FormNotSignedException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch(const AForm::FormLowExecutionGradeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << " =============================================" << std::endl;
    return 0;
}
