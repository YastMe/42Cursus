#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <stdlib.h>

# define INT_MAX std::numeric_limits<int>::max()
# define INT_MIN std::numeric_limits<int>::min()
# define FLOAT_MAX std::numeric_limits<float>::max()
# define FLOAT_MIN std::numeric_limits<float>::min()
# define DOUBLE_MAX std::numeric_limits<double>::max()
# define DOUBLE_MIN std::numeric_limits<double>::min()

# define RED "\033[1;31m"
# define DEFAULT "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		ScalarConverter & operator = (const ScalarConverter &scalarconverter);
	public:
		virtual ~ScalarConverter() = 0;
		static void	convert(const std::string &str);
};

#endif