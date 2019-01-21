#include <iostream>
#include <string>

struct Baffer
{
    void* data;
    size_t size;
}

struct BaseStream
{
    Buffer buffer;
};

struct IStream : BaseStream
{
    auto peekg() {return pos;}
    auto seekg(size_t val) { pos = val;}
private:
    size_t pos = 0;
};

struct OStream : BaseStream
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

int main() {
    IOStream* stream = new IOStream{};
    IStream * istream = stream;
    OStream * ostream = stream;
    BaseStream * bstream = stream;
}


/*

[stream] :
0>[ Buffer ]  :            _____          <--------istream
            0>[void*] {8}       |
            8>[size_t] {8}      |
                                |- IStream
16>[ size_t ] {8}          _____|
24>[ Buffer ]  :            ____          <--------ostream
            24>[void*] {8}      |
            32>[size_t] {8}     |
                                |- Ostream
40>[ size_t ] {8}           ____|
48>[int] {4}                     -flag_t // enum construction does not add to space occupied by object
52>[-------] // laocoon(?)
// if there is an object of IOStream after stream 4 bites will be added
56>



    [BS]
    |   \
    [I] [O]  // "ромбовидная проблема", solution is virtual inheritance :: goto v ::
    |  /
    [IO]

    ::v::
    0> 0 / 28                |-vcptr
    8>[ size_t ] {8}         |-IStream  <------istream
    16>[ size_t ] {8}        |-OStream  <------ostream
    24> [int] {4}
    28>[Buffer] :            <------bstream
                >[void*] {8}
                >[size_t] {8}
    44>
*/

// with virtual:
#include <iostream>
#include <string>

struct Baffer
{
    void* data;
    size_t size;
}

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

int main() {
    IOStream* stream = new IOStream{};
    IStream * istream = stream;
    OStream * ostream = stream;
    BaseStream * bstream = stream;
}
