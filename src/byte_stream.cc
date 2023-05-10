#include <stdexcept>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  // Your code here.
  const size_t size = min( data.length(), capacity_ - buffer.size() );
  data = data.substr( 0, size );
  for ( const char& c : data ) {
    buffer.push_back( c );
  }
  total_pushed_bytes += size;
}

void Writer::close()
{
  // Your code here.
  is_closed_ = true;
}

void Writer::set_error()
{
  // Your code here.
  is_error_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return is_closed_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return total_pushed_bytes;
}

string_view Reader::peek() const
{
  // Your code here.

  // char front_ = buffer.front();
  // return std::string_view(&front_, 1); // convert `char` to `string_view`
  // not pass, why

  return string_view( &buffer.front(), 1 );
}

bool Reader::is_finished() const
{
  return buffer.empty() && is_closed_;
}

bool Reader::has_error() const
{
  return is_error_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  const size_t size = min( len, buffer.size() );
  // buffer.erase(buffer.begin(), buffer.begin() + size);
  for ( size_t i = 0; i < size; i++ ) {
    buffer.pop_front();
  }
  total_popped_bytes += size;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return buffer.size();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return total_popped_bytes;
}
