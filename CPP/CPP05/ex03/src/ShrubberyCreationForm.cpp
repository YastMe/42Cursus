#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExecute)
{
	_target = "default_file";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::_gradeToSign, ShrubberyCreationForm::_gradeToExecute)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform) : AForm(shrubberycreationform)
{
	*this = shrubberycreationform;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &shrubberycreationform)
{
	if (this != &shrubberycreationform)
		_target = shrubberycreationform.getTarget();
	return (*this);
}

std::string const ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}


void	ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::ofstream	file;
		std::string		filename = _target;
		int				nbr = 0;

		filename.append("_shrubbery");
		file.open(filename.c_str());
		nbr = std::rand() % 10 + 1;
		for (int i = 0; i < nbr + 1; i++)
		{
			file << "       _-_" << std::endl;
			file << "    /~~   ~~\\" << std::endl;
			file << " /~~         ~~\\" << std::endl;
			file << "{               }" << std::endl;
			file << " \\  _-     -_  /" << std::endl;
			file << "   ~  \\\\ //  ~" << std::endl;
			file << "_- -   | | _- _" << std::endl;
			file << "  _ -  | |   -_" << std::endl;
			file << "      // \\\\" << std::endl;
		}
		file.close();
		std::cout << "Planted " << nbr + 1 << " trees in " << filename << ". Team Trees has nothing on us. Step up your game, Mr. Beast." << std::endl;
	}
}
