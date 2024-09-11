#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	while (*argv)
	{
		_vector.push_back(atoi(*argv));
		_list.push_back(atoi(*argv));
		argv++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme) { *this = pmergeme; }

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator = (const PmergeMe &pmergeme)
{
	if (this != &pmergeme)
	{
		_vector = pmergeme.getVector();
		_list = pmergeme.getList();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &v)
{
	std::vector<int>::const_iterator iterator = v.begin();
	std::vector<int>::const_iterator end = v.end();

	while (iterator != end)
	{
		out << *iterator;
		++iterator;
		if (iterator != end)
			out << " ";
	}
	return (out);
}

std::ostream &operator<<(std::ostream &out, const std::list<int> &l)
{
	std::list<int>::const_iterator iterator = l.begin();
	std::list<int>::const_iterator end = l.end();

	while (iterator != end)
	{
		out << *iterator;
		++iterator;
		if (iterator != end)
			out << " ";
	}
	return (out);
}

std::vector<int> PmergeMe::getVector() const { return (_vector); }
std::list<int> PmergeMe::getList() const { return (_list); }

static std::vector<int>	vector_merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int>	result;

	while (!left.empty() && !right.empty())
	{
		if (left[0] < right[0])
		{
			result.push_back(left[0]);
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}

	while (!left.empty())
	{
		result.push_back(left[0]);
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right[0]);
		right.erase(right.begin());
	}
	return (result);	
}

std::vector<int> PmergeMe::vectorSort(std::vector<int> v)
{
	if (v.size() <= 1)
		return (v);
	
	std::vector<int>	left;
	std::vector<int>	right;
	unsigned long int	middle = v.size() / 2;

	for (unsigned long int i = 0; i < v.size(); i++)
	{
		if (i < middle)
			left.push_back(v[i]);
		else
			right.push_back(v[i]);
	}

	left = vectorSort(left);
	right = vectorSort(right);

	return (vector_merge(left, right));
}

static std::list<int> list_merge(std::list<int> left, std::list<int> right)
{
	std::list<int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}

	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}
	return (result);
}


std::list<int>	PmergeMe::listSort(std::list<int> l)
{
	if (l.size() <= 1)
		return (l);
	
	std::list<int> left;
	std::list<int> right;
	int middle = l.size() / 2;

	std::list<int>::iterator iterator = l.begin();
	std::list<int>::iterator end = l.end();

	for (int i = 0; iterator != end; i++)
	{
		if (i < middle)
			left.push_back(*iterator);
		else
			right.push_back(*iterator);
		iterator++;
	}

	left = listSort(left);
	right = listSort(right);

	return (list_merge(left, right));
}
