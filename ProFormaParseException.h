#ifndef PROFORMA_PARSE_EXCEPTION_H
#define PROFORMA_PARSE_EXCEPTION_H

#include <stdexcept> // Include the header for std::exception

namespace TopDownProteomics::ProForma {
    class ProFormaParseException : public std::exception {
    public:
        // Initializes a new instance of ProFormaParseException without a message
        ProFormaParseException() : std::exception() {}

        // Initializes a new instance of ProFormaParseException with a message
        explicit ProFormaParseException(const char* message) : std::exception(message) {}
    };
}

#endif // PROFORMA_PARSE_EXCEPTION_H
