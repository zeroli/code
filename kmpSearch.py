#!/usr/bin/env python

def kmpSearch(text, pattern, next):
	m = 0
	i = 0
	indexrange=[]
	while m+i < len(text):
		if pattern[i] == text[m+i]:
			if i == len(pattern) - 1:
				indexrange.append((m, m+i))
				m = m + i + 1
				i = 0
				continue
			i = i + 1
		else:
			m = m + i - next[i]
			if next[i] > -1:
				i = next[i]
			else:
				i = 0
	return indexrange
	
def getkmpNext(pattern):
	pos = 2
	cnd = 0
	next=[]
	for i in range(len(pattern)):
		next.append(-1)
	next[1] = 0
	while pos < len(pattern):
		if pattern[pos-1] == pattern[cnd]:
			cnd = cnd+1
			next[pos] = cnd
			pos = pos+1
		elif cnd > 0:
			cnd = next[cnd]
		else:
			next[pos] = 0
			pos = pos + 1 
	return next

pattern='abcdabd'
text='abcefgabcdabdefeeeeeabcdabdddddd'

print("pattern is "+pattern)
print("text is "+text)
next = getkmpNext(pattern)
print(next)
print kmpSearch(text, pattern, next)



