#include "Span.hpp"

/*** parameterized constructor ***/
Span::Span( unsigned int N ) : _maxSize(N)
{
	/* reserver N numbers on the container */
	_numbers.reserve(N);
}

/*** copy constructor ***/
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

/*** assignment operator ***/
Span& Span::operator=(const Span& other )
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

/*** destructor ***/
Span::~Span() {}

/*** public methods ***/

/* add a single number to the Span (vector container) */
void	Span::addNumber( int num )
{
	if (_numbers.size() >= _maxSize) {
		throw std::overflow_error("Span is full, cannot add more numbers");
	}
	_numbers.push_back(num);
}

/* Template method to add a range of numbers using iterators */
template <typename InputIterator>
void	Span::addNumber(InputIterator begin, InputIterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize) {
		throw std::overflow_error("Adding these numbers will exceed the maximum size");
	}
	_numbers.insert(_numbers.end(), begin, end);
}

// Method to calculate the shortest span
int		Span::shortestSpan() const
{
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to calculate a span");
	}
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

/* Method to calculate the longest span */
int		Span::longestSpan() const
{
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate a span");
    }
    
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());

    return maxElement - minElement;
}
