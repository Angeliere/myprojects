#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);

        int getRawBits( void ) const;
        void setRawBits (int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int                 _value;
        static const int    _fractbits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif