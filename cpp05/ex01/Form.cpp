#include "Form.hpp"

Form::Form(): _name("default"), sign_grade(150), execute_grade(150)
{
    isSigned = false;
}

Form::Form(const std::string name, const int sg, const int eg): _name(name) , sign_grade(sg), execute_grade(eg)
{
    if (sg > 150 || eg > 150)
        throw (Form::GradeTooLowException());
    else if (sg < 1 || eg < 1)
        throw (Form::GradeTooHighException());
    isSigned = false;
}

Form::Form(const Form &src): _name(src.getName()), sign_grade(src.getSGrade()), execute_grade(src.getEGrade())
{
    *this = src;
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this -> isSigned = src.getSigned();
    }
    return (*this);
}

Form::~Form()
{
    
}

const std::string &Form::getName() const
{
    return (this->_name);
}

int Form::getSGrade() const
{
    return (this->sign_grade);
}

int Form::getEGrade() const
{
    return (this->execute_grade);
}

bool Form::getSigned() const
{
    return (this->isSigned);
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->sign_grade)
        throw (Form::GradeTooLowException());
    this->isSigned = true;
    std::cout << this->_name << " has been signed by " << obj.getName() << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &out, const Form& src)
{
    out << "Form " << src.getName() << " is ";
    if (src.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << src.getSGrade() << " to sign and grade " << src.getEGrade() << " to execute" << std::endl;
    return (out);
}

