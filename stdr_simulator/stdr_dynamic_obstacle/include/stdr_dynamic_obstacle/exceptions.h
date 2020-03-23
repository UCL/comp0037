#include <stdexcept>

#ifndef STDR_DYNAMIC_OBSTACLE_EXCEPTIONS_H
#define STDR_DYNAMIC_OBSTACLE_EXCEPTIONS_H

namespace stdr_dynamic_obstacle {

/**
@class ConnectionException
@brief Provides a connection exception. Publicly inherits from std::runtime_error. Used in robot handler.
**/ 
class ConnectionException : public std::runtime_error
{
  public:
    /**
    @brief Throws an std::runtime_error with a messsage
    @param errorDescription [const std::string] The error message
    **/ 
    ConnectionException(const std::string errorDescription) : 
      std::runtime_error(errorDescription) 
    {
    }

};
/**
@class DoubleFrameIdException
@brief Provides a double frame id exception. Publicly inherits from std::runtime_error. Used in robot handler.
**/ 
class DoubleFrameIdException : public std::runtime_error
{
  public:
    /**
    @brief Throws an std::runtime_error with a messsage
    @param errorDescription [const std::string] The error message
    **/ 
    DoubleFrameIdException(const std::string errorDescription) : 
      std::runtime_error(errorDescription) 
    {
    }

};
} // end of namespace stdr_robot

#endif
