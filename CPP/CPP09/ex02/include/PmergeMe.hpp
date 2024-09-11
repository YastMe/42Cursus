#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iterator>
# include <cstdlib>
# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
	public:
		PmergeMe(void);
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &src);
		std::vector<int> vectorSort(std::vector<int> v);
		std::list<int> listSort(std::list<int> l);
		std::vector<int> getVector(void) const;
		std::list<int> getList(void) const;
};

std::ostream & operator << (std::ostream &out, const std::vector<int> &v);
std::ostream & operator << (std::ostream &out, const std::list<int> &l);

#endif