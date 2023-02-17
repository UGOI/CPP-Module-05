#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), m_target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file(m_target + "_shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    file << "          v .   ._, |_  .," << std::endl
         << "   `-._\\/  .  \\ /    |/_" << std::endl
         << "       \\_|O|_    /   \\_/  \\" << std::endl
         << "        /  |     |\\_ /     \\ " << std::endl
         << "        |  |     |\\\\ \\      ||" << std::endl
         << "        \\  |     | \\|\\ \\     //" << std::endl
         << "         \\  \\_   \\_\\_\\_\\_\\_\\/_" << std::endl
         << "         \\(  /\\)  _______     (   /)" << std::endl
         << "           \\  ( /   /\\__/\\   /\\  /)" << std::endl
         << "           \\  \\|___/  \\/  \\|__/ /" << std::endl
         << "             \\           / / |" << std::endl
         << "              \\_________/ /   \\" << std::endl
         << "                \\_|    \\_\\    /" << std::endl
         << "                       \\____/" << std::endl;

    file.close();
}
