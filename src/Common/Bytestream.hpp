#include <vector>

#ifndef ___BYTESTREAM___
#define ___BYTESTREAM___

class Bytestream{
	std::vector<char> _buffer;
public:
	Bytestream();
	
	template<typename T>
	void write(T item){
	char *tmp = (char*) &item;
	int i = 0;
	while(i < sizeof(T)){
		_buffer.push_back(*tmp);
		++tmp;
		++i;
	}
}
	long size();
	void appendBytestream(Bytestream *stream);
	std::vector<char>& getBuffer();
};

#endif