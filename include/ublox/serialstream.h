// SerialStream.h
#ifndef SERIALSTREAM_H
#define SERIALSTREAM_H

#include "ublox/stream.h"
#include <boost/asio.hpp>

class SerialStream : public Stream
{
public:
    SerialStream(const std::string &port, unsigned int baud_rate);

    size_t write(const uint8_t *buffer, size_t size) override;
    size_t write(const uint8_t byte) override;

    int read() override;

    size_t readBytes(uint8_t *buffer, size_t length) override;

    int available() override;

private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
};

#endif // SERIALSTREAM_H
