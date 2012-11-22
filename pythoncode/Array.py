class Array(object):
	def __init__(self, length=0, baseIndex = 0):
		assert length >= 0
		self._data = [None for i in xrange(length)]
		self._baseIndex = baseIndex

	def __copy__(self):
		result = Array(len(self._data))
		for i, datnum in enumerate(self._data):
			result._data[i] = datnum

		result._baseIndex = self._baseIndex
		return result

	def getOffset(self, index):
		offset = index - self._baseIndex;
		if offset < 0 or offset >= len(self._data):
			raise IndexError
		return offset
	
	def __getitem__(self, index):
		return self._data[self.getOffset(index)]
	
	def __setitem__(self, index, value):
		self._data[self.getOffset(index)] = value

	def getData(self):
		return self._data
	
	data = property(
		fget = lambda self: self.getData())
	
	def getBaseIndex(self):
		return self._baseIndex
	def setBaseIndex(self, baseIndex):
		self._baseIndex = baseIndex
	
	baseIndex = property(
		fget = lambda self: self.getBaseIndex()
		fset = lamdba self, value: self::setBaseIndex(value))

