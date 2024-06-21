// Stream.h
#ifndef STREAM_H
#define STREAM_H

#include <cstdint>
using std::uint8_t, std::size_t;

class Stream
{
public:
    virtual ~Stream() = default;

    virtual size_t write(const uint8_t *buffer, size_t size) = 0;
    virtual size_t write(const uint8_t value) = 0;
    virtual int read() = 0;
    virtual size_t readBytes(uint8_t *buffer, size_t length) = 0;
    virtual int available() = 0;
};

#endif // STREAM_H
