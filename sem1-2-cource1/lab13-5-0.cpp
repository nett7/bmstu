#include <iostream>
#include <string>
using namespace std;

struct Buffer
{
    void* data;
    size_t size;
};

struct BaseStream
{
    Buffer buffer;
};

struct IStream : virtual BaseStream
{
    auto peekg() {return pos;}
    auto seekg(size_t val) { pos = val;}
private:
    size_t pos = 0;
};

struct OStream : virtual BaseStream
{
    auto peekp() {return pos;}
    auto seekp(size_t val) { pos = val;}
private:
    size_t pos = 0;
};

struct IOStream : IStream, OStream
{
    enum flag_t {good, bad, fail};
    flag_t flag;
    
};


struct tIStream : BaseStream
{
    auto peekg() {return pos;}
    auto seekg(size_t val) { pos = val;}
private:
    size_t pos = 0;
};

struct tOStream : BaseStream
{
    auto peekp() {return pos;}
    auto seekp(size_t val) { pos = val;}
private:
    size_t pos = 0;
};

struct tIOStream : tIStream, tOStream
{
    enum flag_t {good, bad, fail};
    flag_t flag;
    
};
int main() {
    IOStream* stream = new IOStream{};
    IStream * istream = stream;
    OStream * ostream = stream;
    BaseStream * bstream = stream;
    tIOStream* tstream = new tIOStream{};
    tIStream * tistream = tstream;
    tOStream * tostream = tstream;
    cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
    cout << "----virtual---- " << endl;
    cout <<" stream : "<< stream  << " +" << (long int)stream - (long int)stream << endl;
    cout <<"istream : "<< istream << " +" << (long int)istream - (long int)stream << endl;
    cout <<"ostream : "<< ostream << " +" << (long int)ostream - (long int)stream << endl;
    cout <<"bstream : "<< bstream << " +" << (long int)bstream - (long int)stream <<endl;
    
    cout << "----not virtual---- " << endl;
    cout <<" stream : "<< tstream  << " +" << (long int)tstream - (long int)tstream << endl;
    cout <<"istream : "<< tistream << " +" << (long int)tistream - (long int)tstream << endl;
    cout <<"ostream : "<< tostream << " +" << (long int)tostream - (long int)tstream << endl;
}
