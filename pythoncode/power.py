def power(x, n):
	if n==0:
		return 1
	elif n%2==0:
		return power(x*x, n / 2)
	else:
		return x * power(x*x, n / 2)

if __name__ == '__main__':
	print(power(2, 10))
	
