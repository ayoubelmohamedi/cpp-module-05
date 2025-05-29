# cpp-module-05

## Overview

This module covers exception handling in C++ through a bureaucratic simulation involving offices, forms, and bureaucrats.

---

## General Rules

- Classes must follow the Orthodox Canonical Form (except exception classes).
- No function implementation in header files (except templates).
- Use include guards or `#pragma once`. Each header must be self-contained.
- STL is only allowed in Modules 08 and 09.
- No memory leaks.

---

## Ex00: Bureaucrat

- **Attributes:**  
  - Constant name  
  - Grade (1 = highest, 150 = lowest)
- **Exceptions:**  
  - `Bureaucrat::GradeTooHighException`  
  - `Bureaucrat::GradeTooLowException`
- **Methods:**  
  - `getName()`, `getGrade()`
  - Increment/decrement grade (note: incrementing means a lower number)
- **Operator:**  
  - Overload `<<` to print: `<name>, bureaucrat grade <grade>`
- **Test:**  
  - Provide tests in `main.cpp`

---

## Ex01: Form

- **Attributes:**  
  - Constant name  
  - Boolean signed status (default: false)  
  - Constant grades required to sign and execute
- **Exceptions:**  
  - `Form::GradeTooHighException`  
  - `Form::GradeTooLowException`
- **Methods:**  
  - `beSigned(Bureaucrat)` (throws if grade too low)
  - Overload `<<` to print form info
  - `Bureaucrat::signForm(Form&)` prints success/failure message

---

## Ex02: AForm (Abstract Base) & Derived Forms

- **Derived Forms:**  
  - `ShrubberyCreationForm` (sign: 145, exec: 137) — creates ASCII trees in a file  
  - `RobotomyRequestForm` (sign: 72, exec: 45) — 50% chance of success  
  - `PresidentialPardonForm` (sign: 25, exec: 5) — prints pardon message
- **All forms take a target string in their constructor.**
- **Methods:**  
  - `execute(Bureaucrat const&) const` (checks signed status and grade)
  - `Bureaucrat::executeForm(Form const&)` prints outcome

---

## Ex03: Intern

- **Class:**  
  - `Intern` (no attributes)
- **Method:**  
  - `makeForm(string formName, string target)`  
    - Returns pointer to a new Form object  
    - Prints creation message or error if form name is invalid
    - Use a data-driven approach (map form names to creation functions)

---

## Notes

- Grade 1 is the highest, 150 is the lowest.
- Exception classes do not need to follow the Orthodox Canonical Form.
- Avoid circular dependencies.
- Keep code clean and modular.

