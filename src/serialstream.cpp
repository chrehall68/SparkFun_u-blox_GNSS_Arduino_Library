#include "ublox/serialstream.h"

SerialStream::SerialStream(const std::string &port, unsigned int baud_rate)
    : io(), serial(io, port)
{
    serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
}

size_t SerialStream::write(const uint8_t *buffer, size_t size)
{
    return boost::asio::write(serial, boost::asio::buffer(buffer, size));
}

size_t SerialStream::write(const uint8_t byte)
{
    return boost::asio::write(serial, boost::asio::buffer(&byte, 1));
}
int SerialStream::read()
{
    uint8_t buf;
    boost::asio::read(serial, boost::asio::buffer(&buf, 1));
    return buf;
}

size_t SerialStream::readBytes(uint8_t *buffer, size_t length)
{
    return boost::asio::read(serial, boost::asio::buffer(buffer, length));
}

int SerialStream::available()
{
    boost::asio::serial_port::native_handle_type native_handle = serial.native_handle();
    int bytes_available;
    ioctl(native_handle, FIONREAD, &bytes_available);
    return bytes_available;
}