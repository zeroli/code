template <typename T, std::size_t N>
class array {
public:
	// types
	typedef T										value_type;
	typedef T*										iterator;
	typedef const T*								const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
	typedef T& 										reference;
	typedef const T&								const_reference;
	typedef std::size_t								size_type;
	typedef std::ptrdiff_t							diffrerence_type;

	// static constants
	static const size_type static_size = N;
	// ctr/copy/dtr
	template <typename U> array& operator=(const array<U,N>& rhs)
	{
		std::copy(rhs.begin(), rhs.end(), begin());
		return *this;
	}
	
	// iterator support
	iterator begin() { return elems; }
	const_iterator begin() const { return elems; }
	iterator end() { return elems+N; }
	const_iterator end() const { return elems+N; }
	
	// reverse iterator support
	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	// capacity
	size_type size() { return N; }
	bool empty()	 { return false; }
	size_type max_size() { return N; }
	
	// element access
	reference operator[](size_type) 
	{ 
		return elems[i];
	}
	const_reference operator[](size_type) const
	{ 
		return elems[i]; 
	}
	reference at(size_type)
	{
		rangecheck(i); return elems[i]; 
	}
	const_reference at(size_type) const
	{
		rangecheck(i); return elems[i];
	}
	reference front()
	{
		return elems[0];
	}
	const_reference front() const
	{
		return elems[0];
	}
	reference back()
	{	
		return elems[N-1];
	}
	const_reference back() const
	{
		return elems[N-1];
	}
	T* data() 
	{
		return elems;
	}
	const T* data() const
	{
		return elems;
	}
	T* c_array()
	{
		return elems;
	}
	
	// modifiers
	void swap(array<T, N>&);
	void assign(const T&)
	{
		fill(value);
	}
	void fill(const T& value)
	{
		std::fill_n(begin(), size(), value);
	}
	T elems[N];

	static void rangecheck(size_typ i) 
	{
		if (i >= size()) {
			std::out_of_range e("Array<>: index out of range");
			boost::throw_exception(e);
		}
	}
};

// specified algorithms
template <typename T, std::size_t N> void swap(array<T, N>&, array<T,N>&);

// comparisons
template <typename T, std::size_t N>
	bool operator==(const array<T, N>&, const array<T, N>&);

template <typename T, std::size_t N>
	bool operator!=(const array<T, N>&, const array<T, N>&);
	
template <typename T, std::size_t N>
	bool operator<(cosnt array<T, N>&, const array<T, N>&);
	
template <typename T, std::size_t N>
	bool operator>(const array<T, N>&, const array<T, N>&);
	
template <typename T, std::size_t N>
	bool operator<=(const array<T, N>&, const array<T, N>&);
	
template <typename T, std::size_t N>
	bool operator>=(const array<T, N>&, const array<T, N>&);

