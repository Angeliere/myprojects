#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);

        int getRawBits( void ) const;
        void setRawBits (int const raw );

    private:
        int                 _value;
        static const int    _fractbits = 8;
};

#endif