#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& exec) const
{
	AForm::execute(exec);

	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "Error: Failed to create output file." << std::endl;
		return ;
	}

	ofs <<
	"               &&& &&  & &&\n"
	"           && &\\/&\\|& ()|/ @, &&\n"
	"           &\\/(/&/&||/& /_/)_&/_&\n"
	"        &() &\\/&|()|/&\\/ '%\" & ()\n"
	"       &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	"     &&   && & &| &| /& & % ()& /&&\n"
	"     ()&_---()&\\&\\|&&-&&--%---()~\n"
	"         &&     \\|||\n"
	"                 |||\n"
	"                 |||\n"
	"                 |||\n"
	"           , -=-~  .-^- _\n"
	"        ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"
	"         .     .  .      +     .      .          .\n"
	"     .       .      .     #       .           .\n"
	"        .      .         ###            .      .      .\n"
	"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
	"          .      . \"####\"###\"####\"  .\n"
	"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
	"  .             \"#########\"#########\"        .        .\n"
	"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
	"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
	"                .\"##\"#####\"#####\"##\"           .      .\n"
	"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
	"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
	"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
	"            .     \"      000      \"    .     .\n"
	"       .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ...... ...\n";

	ofs.close();
}
