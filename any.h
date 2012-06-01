#ifndef __ANY_H_
#define __ANY_H_

#include <cstring>

class any 
{
public:
	any()
	: content(0)
	{
	}
	
	template <typename ValueType>
	any(const ValueType& value)
	: content(new holder<ValueType>(value))
	{
	}

	any(const any& other)
	: content(other.content?other.content->clone():0)
	{
	}
	~any()
	{ 
		delete content;
	}
	
public:	// modifiers
	any& swap(any& rhs)
	{
		std::swap(content, rhs.content);
		return *this;
	}
	
	template <typename ValueType>
	any& operator=(const ValueType& rhs)
	{
		any(rhs).swap(*this);
		return *this;
	}

	any& operator=(any rhs)
	{
		rhs.swap(*this);
		return *this;
	}
	
public:
	bool empty() const
	{
		return !content;
	}
	
	const std::type_info& type() const
	{
		return content? content->type(): typeid(void);
	}
	
private:
	class placeholder
	{
	public:
		virtual ~placeholder()
		{
		}
	public:
		virtual const std::type_info& type() const = 0;
		virtual placeholder* clone() const = 0;
	};
	
	template <typename ValueType>
	class holder : public placeholder
	{
	public:
		holder(const ValueType& value)
		: held(value)
		{
		}
	public:
		virtual const std::type_info& type() const
		{
			return typeid(ValueType);
		}
		virtual placeholder* clone() const
		{
			return new holder(held);
		}
	public:
		ValueType held;
	private:
		holder& operator=(const holder&);
	};
	
private:
	template <typename ValueType>
	friend ValueType* any_cast(any*);
	template <typename ValueType>
	friend ValueType* unsafe_any_cast(any*);
		
	placeholder* content;
};

class bad_any_cast : public std::bad_cast
{
public:
	virtual const char* what() const throw()
	{
		return "boost:bad_any_cast: "
				"failed conversion using boost::any_cast";
	}
};

template <typename ValueType>
ValueType* any_cast(any* operand)
{
	return operand&&
			std::strcmp(operand->type().name(), typeid(ValueType).name())==0
			? &static_cast<any::holder<ValueType>* >(operand->content)->held
			: 0;
}

template <typename ValueType>
ValueType any_cast(any& operand)
{
	typedef remove_reference<ValueType>::type nonref;
	nonref* result = any_cast<nonref>(&operand);
	if (!result) 
		boost:throw_exception(bad_any_cast());
	return *result;
}


#endif	
