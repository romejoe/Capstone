#include "Bytestream.hpp"

Bytestream::Bytestream(){

}
/*
template<typename T>
void Bytestream::write(T item){
	char *tmp = (char*) item;
	int i = 0;
	while(i < sizeof(T)){
		_buffer.push_back(*tmp);
		++tmp;
		++i;
	}
}
*/

long Bytestream::size(){
	return (long) _buffer.size();
}


void Bytestream::appendBytestream(Bytestream *stream){
	std::vector<char> other = stream->_buffer;	
	_buffer.insert(_buffer.end(), other.begin(), other.end());
}

std::vector<char>& Bytestream::getBuffer(){
	return _buffer;
}
