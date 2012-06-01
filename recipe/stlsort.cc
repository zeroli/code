template <class RandomeAccessIterator>
void __insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	if (first == last) return;
	for (RandomAccessIterator i = first+1; i != last; ++i) 
		__linear_insert(first, i, value_type(first));
}

template <class RandomAccessIterator, class T>
inline void __linear_insert(RandomAccessIterator first, RandomAccessIterator last, T*)
{
	T value = *last;
	if (value < *first) {
		copy_backward(first, last, last+1);
		*first = value;
	} else 
		__unguarded_linear_insert(last, value);
}

template <class RandomAccessItarot, class T>
inline void __unguarded_linear_insert(RandomAccessIterator last, T value)
{
	RandomAccessIterator next = last;
	--next;
	while (value < *next) {	// find first which is <= value
		*last = *next;
		last = next;
		--next;
	}
	*last = value;
}

template <class T>
inline const T& __median(const T& a, const T& b, const T& c)
{
	if (a < b)
		if (b < c)
			return b;
		else if (a < c)
			return c;
		else
			return a;
	else if (a < c)
		return a;
	else if (b < c)
		return c;
	else
		return b;
}

template <class RandomAccessIterator, class T>
RandomAccessIterator __unguarded_partition(RandomAccessIterator first,
											RandomAccessIterator last, T pivot)
{
	while (true) {
		while (*first < pivot) ++first;
		--last;
		while (*last > pivot) --last;
		if (!(first < last)) return first;
		iter_swap(first, last);	// swap their values
		++first;
	}
}

template <class RandomAccessIterator>
inline void sort(RandomAccessIterator first, RandomAccessIterator last)
{
	if (first != last) {
		__introsort_loop(first, last, value_type(first), __lg(last-first)*2);
		__final_insertion_sort(first, last);
	}
}

template <class Size>
inline Size __lg(Size n)
{
	Size k;
	// get maximum k which meet requirement "2^k <= n"
	for (k = 0; n > 1; n >>= 1) 
		++k;
	return k;
}

template <class RandomAccessIterator, class T, class Size>
void __introsort_loop(RandomAccessIterator first, RandomAccessIterator last, T*, 
					Size depth_limit)
{
	while (last - first > __stl_threshold) {
		if (depth_limit == 0) {
			partial_sort(first, last, last);	// go to heap sort
			return;
		}
		--depth_limit;
		RandomAccessIterator cut = __unguarded_partition(first, last, 
						T(__median(*first, *(first+(last-first)/2), *(last-1))));
		__introsort_loop(cut, last, value_type(first), depth_limit);
		last = cut;
	}
}

template <class RandomAccessIterator>
void __final_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	if (last-first > __stl_threshold) {
		__insertion_sort(first, first+__stl_threshold);
		__unguarded_insertion_sort(first+__stl_threshold, last);
	}
	else 
		__insertion_sort(first, last);
}

template <class RandomAccessIterator>
inline void __unguarded_insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	__unguarded_insertion_sort_aux(first, last, value_type(first));
}

template <class RandomAccessIterator>
void __unguarded_insertion_sort_aux(RandomAccessIterator first, RandomAccessIterator last, T*)
{
	for (RandomAccessIterator i = first; i != last; ++i)
		__unguarded_linear_insert(i, T(*i));
}


	
					

		
		 
		

		

