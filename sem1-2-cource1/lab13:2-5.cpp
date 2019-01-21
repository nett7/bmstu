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
public:
    size_t pos = 0;
};

struct OStream : virtual BaseStream
{
    auto peekp() {return pos;}
    auto seekp(size_t val) { pos = val;}
public:
    size_t pos = 1;
};

struct IOStream : IStream, OStream
{
    enum flag_t {good, bad, fail};
    flag_t flag;
    
};


struct IStream_ : BaseStream
{
    auto peekg() {return pos;}
    auto seekg(size_t val) { pos = val;}
public:
    size_t pos = 0;
};

struct OStream_ : BaseStream
{
    auto peekp() {return pos;}
    auto seekp(size_t val) { pos = val;}
public:
    size_t pos = 0;
};

struct IOStream_ : IStream_, OStream_
{
    enum flag_t {good, bad, fail};
    flag_t flag;
    
};
int main() {
    IOStream* stream = new IOStream{};
    IStream * istream = stream;
    OStream * ostream = stream;
    BaseStream * bstream = stream;
    IOStream_* stream_ = new IOStream_{};
    IStream_ * istream_ = stream_;
    OStream_ * ostream_ = stream_;
    cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
    cout <<"."<< "_________virtual_________" <<"."<< endl;
    cout <<"|"<<" stream : "<< stream  << " +" << (long int)stream - (long int)stream <<" |" <<endl;
    cout <<"|"<<"istream : "<< istream << " +" << (long int)istream - (long int)stream <<" |"<< endl;
    cout <<"|"<<"istream::pos : "<< &istream->pos << " +" << ((long int)&istream->pos - (long int)istream) <<" |"<< endl;
    cout <<"|"<<"ostream : "<< ostream << " +" << (long int)ostream - (long int)stream <<"|"<< endl;
    cout <<"|"<<"ostream::pos : "<< &ostream->pos << " +" << ((long int)&ostream->pos - (long int)ostream) <<" |"<< endl;
    cout <<"|"<<"bstream : "<< bstream << " +" << (long int)bstream - (long int)stream<<"|" <<endl;
            cout  <<"."<< "-------------------------" <<  "."<<endl;
    cout <<"."<< "_______not virtual_______" <<"."<< endl;
    cout <<"|"<<" stream : "<< stream_  << " +" << (long int)stream_ - (long int)stream_  <<" |"<<endl;
    cout <<"|"<<"istream : "<< istream_ << " +" << (long int)istream_ - (long int)stream_ <<" |"<<endl;
     cout <<"|"<<"istream::pos : "<< &istream_->pos << " +" << ((long int)&istream_->pos - (long int)istream_) <<" |"<< endl;
    cout <<"|"<<"ostream : "<< ostream_ << " +" << (long int)ostream_ - (long int)stream_ <<"|"<<endl;
    cout <<"|"<<"ostream::pos : "<< &ostream_->pos << " +" << ((long int)&ostream_->pos - (long int)ostream_) <<" |"<< endl;
        cout  <<"."<< "-------------------------" <<  "."<<endl;
}



