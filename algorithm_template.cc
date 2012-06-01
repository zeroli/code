/* 
 * algorithm simplified version
 */

/* adjacent_find */
template <class ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
{
	ForwardIterator next = first; ++next;
	if (first!=last) {
		while (next!=last) {
			if (*first++ == *next++) 
				return first;
		}
	}
	return last;
}

/* for_each */
template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	for (; first!=last; ++first)
		f(*first);
	return f;
}

/* find */
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& t)
{
	for (; first!=last; ++first) 
		if (*first==t)
			break;
	return first;
}

/* find_if */
template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate f)
{
	for (; first!=last; ++first)
		if (f(*first))
			break;
	return first;
}


/* find_end */
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
						ForwardIterator2 first2, ForwardIterator2 last2)
{
	ForwardIterator1 it1, limit, ret;
	ForwardIterator2 it2;
	limit = first; advance(limit, 1+distance(first1, last1)-distance(first2, last2));
	ret = last1;

	while (first1!=limit) {
		it1 = first1; it2 = first2;
		while (*it1==*it2) {  // or while (pred(*it1, *it2))
			++it1; ++it2;
			if (it2==last2) {
				ret=first1; 
				break;
			}
		}
		++first1;
	}
	return ret;
}

/* find_first_of 
 * Returns an interator to the first occurrence in the range [first1,last1) of any of the elements in [first2,last2).
 */
template <class FowardIterator1, class ForwardIterator2>
ForwardIterator1 find_first_of(FowardIterator1 first1, ForwardIterator2 last1,
								ForwardIterator2 first2, FowardIterator2 last2)
{
	for (; first1!=last1; ++first1) 
		for (FowardIterator2 it=first2; it!=last2; ++it)
			if (*it==*first1)
				return first1;
	return last1;
}

/* count */
template <class InputIterator, class T>
ptrdiff_t count(InputIterator first, InputIterator last, const T& t)
{
	ptrdiff_t cnt = 0;
	for (; first!=last; ++first)
		if (*first==t)
			cnt++;
	return cnt;
}

/* count_if */
template <class InputIterator, class Predicate>
ptrdiff_t count_if(InputIterator first, InputIterator last, Predicate pred)
{
	ptrdiff_t cnt = 0;
	for (; first!=last; ++first)
		if (pred(*first))
			cnt++;
	return cnt;
}

/* mismatch */
template <class InputIterator1, class InputIterator2>
std::pair<InputIterator1, InputIterator2>
mismatch(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
{
	for (; first1!=last1; ++first1)
		if (*first1 != *first2)
			break;
		++first1; ++first2;
	}
	return make_pair(first1, first2);
}

/* equal */
template <class InputIterator1, class InputIterato2>
bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
{
	while (first1!=last1) {
		if (*first1 != *first2)
			return false;
		++first1; ++first2;
	}
	return true;
}

/* search */
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
						ForwardIterator2 first2, ForwardIterator2 last2)
{
	ForwardIterator1 it1, limit;
	ForwardIterator2 it2;
	limit = first1; advance(limit, 1+distance(first1,last1)-distance(first2,last2));
	
	while (first1!=limit) {
		it1 = first1; it2 = first2;
		while (*it1 == *it2) {
			++it1; ++it2; 
			if (it2==last2) {
				return first1;
			}
		}
		++first1;
	}
	return last1;
}

/* search_n */
template <class ForwardIterator1, class Size, class T>
ForwardIterator1 search_n(ForwardIterator1 first, ForwardIterator1 last,
						Size count, const T& t)
{
	ForwardIterator it, limit;
	Size i;
	limit = first; advance(limit, 1+distance(first, last)-count);

	while (first!=limit) {
		it = first; i=0;
		while (*it==value) {
			++it;
			if (++i==count) 
				return first;
		}
		++first;
	}
	return last;
}
	
/* copy */
template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first1, InputIterator last1, OutputIterator result)
{
	while (first1!=last1)
		*result++ = *first1;
	return result;
}

/* copy_backward */
template <class BidirectionalIterator1, class BidirectionalIterator2>
BidirectionalIterator2 copy_backward(BidirectionalIterator1 first,
									BidirectionalIterator1 last,
									BidirectionalIterator2 result)
{
	while (last!=first) 
		*(--result) = *(--last);
	return result;
}

/* swap */
template <class T>
void swap(T& t1, T& t2)
{
	T tmp(t1); t1 = t2; t2 = tmp;
}

/* swap_range */
template <class ForwardIterator1, class FowardIterator2>
FowardIterator2 swap_ranges(FowardIterator1 first1, FowardIterator1 last1,
							FowardIterator2 first2)
{
	while (first1!=last1) 
		swap(*first1++, *first2++);
	return first2;
}

/* iter_swap */
template <class FowardIterator1, class FowardIterator2>
void iter_swap(FowardIterator1 a, ForwardIterator2 b)
{
	swap(*a, *b);
}

/* transform */
template <class InputIterator, class OutputIterator, class UnaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1,
						OutputIterator result, UnaryOperator op)
{
	while (first1!=last1)
		*result1++ = op(*first1++);
	return result;
}

/* replace */
template <class ForwardtIterator, class T>
void replace(FowardIterator first, ForwardIterator last,
			const T& old_value, const T& new_value)
{
	for (; first!=last; ++first) {
		if (*first==old_value)
			*first=new_value;
	}
}

/* replace_if */
template <class ForwardIterator, class Predicate, class T>
void replace_if(ForwardIterator first, ForwardIterator last,
				Predicate pred, const T& new_value)
{
	for (; first!=last; ++first) {
		if (pred(*first)) 
			*first=new_value;
	}
}

/* replace_copy */
template <class InputIterator, class OutputIterator, class T>
OutputIterator replace_copy(InputIterator first, InputIterator last,
							OutputIterator result, const T& old_value, const T& new_value)
{
	for (; first!=last; ++first, ++result)
		*result = (*first==old_value)? new_value : *first;
	return result;
}

/* replace_copy_if */
template <class InputIterator, class OutputIterator, class Predicate, class T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last,
								OutputIterator result, Predicate pred, const T& new_value)
{
	for (; first!=last; ++first, ++result)
		*result = pred(*first) ? new_value: *first;
	return result;
}

/* fill */
template <class ForwardIterator, class T>
void fill(ForwardIterator first, ForwardIterator last, const T& t)
{
	for (; first!=last; ++first)
		*first = t;
}

/* fill_n */
template <class OutputIterator, class Size, class T>
void fill_n(OutputIterator first, Size n, const T& value)
{
	for (; n>0; --n) 
		*first++ = value;
}

/* generate */
template <class ForwardIterator, class Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
	for (; first!=last; ++first) 
		*first= gen();
}

/* generate_n */
template <class OutputIterator, class Size, class Generator>
void generate_n(OutputIterator first, Size n, Generator gen)
{
	for (; n>0; --n)
		*first++ = gen();
}

/* remove */
template <class ForwardIterator, class T>
ForwardIterator remove(ForwardIterator first, FowardIterator last, const T& value)
{
	ForwardIterator result = first;
	for (; first!=last; ++first)
		if (!(*first==value)) 
			result++ = first;
	return result;
}

/* remove_if */
template <class ForwardIterator, class Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred)
{
	ForwardIterator result = first;
	for (; first!=last; ++first)
		if (!pred(*first))
			result++ = first;
	return result;
}

/* remove_copy */
template <class InputIterator, class OutputIterator, class T>
OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result,
							const T& t)
{
	for (; first!=last; ++first) 
		if (!(*first==t))
			*result++ = *first;
	return result;
}

/* remove_copy_if */
template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result,
							Predicate pred)
{
	for (; first!=last; ++first) {
		if (!(pred(*first)))
			*result++ = *first;
	}
	return result;
}

/* unique */
template <class ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last)
{
	ForwardIterator result = first;
	while (++first!=last) {
		if (!(*result==*first))
			*(++result)=*first;
	}
	return ++result;
}

/* unique_copy */
template <class InputIterator, class OutputIterator>
OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result)
{
	*result = *first;
	while (++first!=last) {
		if (!(*first==*result)) 
			*(++result) = *first;
	}
	return ++result;
}

/* reverse */
template <class BidrectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last)
{
	while (first!=last && first!=--last) {
		swap(*first++, *last);
}

/* reverse_copy */
template <class BidirectionalIterator, class OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last,
							OutputIterator result) 
{
	while (first!=last)
		*result++=*--last;
	return result;
}

/* rotate */
template <class ForwardIterator>
void rotate(ForwardIterator first, ForwardIterator middle,
			ForwardIterator last)
{
	ForwardIterator next = middle;
	while (first!=next) {
		swap(*first++, *next++);
		if (next==last) next = middle;
		else if (first==middle) middle = next;
	}
}

/* min_element */
template <class FowardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
{
	ForwardIterator lowest = first
	if (first==last) return last;
	while (++first!=last) {
		if (*first<*last)
			lowest = frist;
	}
	return lowest;
}

/* lexcographical_compare */
template <class InputIterator1 class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, InputIterator2 last2)
{
	while (first!=last1) {
		if (*first2<*first1 || first2==last2)
			return false;
		else if (*first1<*first2)
			return true;
		first1++; first2++;
	}
	return (first2!=last2);
}

/* lower_bound */
template <class FowardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value)
{
	ForwardIterator it;
	iterator_traits<ForwardIterator>::distance_type count, step;
	count = distance(first, last);
	while (count > 0) {
		it = first; step = count/2; advance(it, step);
		if (*it < value) {  // go to right to search (bigger region)
			first = ++it; count -= step+1;
		} else 		// go to left to search (smaller region)
			count = step;
	}
	return first;
}

