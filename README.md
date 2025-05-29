# cpp-module-05
Try/Catch and Exceptions in CPP.  boring as hell.


offices, corridors, forms, and waiting queues.

General rules:
->  From Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitly stated otherwise
* in our case: Please note that exception classes don’t have to be designed in
Orthodox Canonical Form.

->  No func implementation in header file (except for function templates)
-> keep  include guards.  (Maybe #pragma once) ,Also #include <string>  // ✅ self-contained for each header.
->  STL allowed  in the Module 08 and 09 only. (No containers, algos …)
-> No Memory leakage.

Ex00

Bureaucrat

* A constant name.
*  A grade that ranges from 1 (highest possible grade) to 150 (lowest possible
grade)

- A Bureaucrat with invalid grade must throw an exception:
		
 Bureaucrat::GradeTooHighException 
or
Bureaucrat::GradeTooLowException.

getName() and getGrade()

2 member functions to increment or decrement the bureaucrat grade

Note : grade 1 is the highest one and 150 the lowest, so  incrementing  (increment grade in reverse order)

Features: 
implement an overload of the insertion («):
		<name>, bureaucrat grade <grade>.	
-> main.cpp : tests to prove everything works as expected.


Problems: 
The Problem with Using *this in the Constructor, it creates a forward reference problem.


Ex01

Private members

• A constant name.
• A boolean indicating whether it is signed (at construction, it’s not).
• A constant grade required to sign it.
• And a constant grade required to execute it

Form::GradeTooHighException and Form::GradeTooLowException.

overload of the insertion («)
operator that prints all the form’s informations.

+ beSigned(Bureaucrat) : changes the form status to signed if the bureaucrat’s grade is high enough.
(grade 1 is higher than grade 2.)

throw a Form::GradeTooLowException

+ signForm() member function to the Bureaucrat
print :   <bureaucrat> signed <form>
Otherwise:
<bureaucrat> couldn’t sign <form> because <reason>.

 const in void signForm(const Form &form) const; serves two different purposes:

const : is a method qualifier
1- method can’t change object passed to it (param)
2- function promise not to modify any member var of the object it’s called on (its possessor)

++ when form will be executed ??
Circular dependency ?

Ex02:  No, you need form 28B, not 28C.

AForm : Form must be an abstract class

Derived classes:
1- ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.

2- RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.

3- PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebr

All take target string in their constructor.

Per Form :
execute(Bureaucrat const & executor) const  : function to be added to base class.

—>check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. (Better to check in base class, then exec directly in derived classes) 
—> Otherwise, throw an appropriate exception.


Per Bureaucrat:
executeForm(Form const & form) ;

if it’s successful, print something like:
	<bureaucrat> executed <form>
Else, print an explicit error message.

Bureaucrat responsible for reporting the outcome.
If (form.execute()) succeed, nothing is printed by bureaucrat. 

Ex03: At least this beats coffee-making.

Intern.{h, hpp}, Intern.cpp The intern has no name, no grade, no unique characteristics

makeForm(string formName, string targetOfForm) function.
-> return : pointer to a Form object (whose name is the one passed as parameter)
+ target will be initialized to the second parameter

->prints :  Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error message.

PS: avoid  if/elseif/else forest. 
-> use data-driven approach : 
	se an array of structures (or pairs) that map form names (strings) to functions that create the corresponding form objects.

