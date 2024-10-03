#pragma once
#include <traits.hpp>

namespace bat
{
    /*=========================================*/
    /* FUNDAMENTAL TYPES                       */
    /*=========================================*/
            using int8_t  = signed char;
            using uint8_t = unsigned char;

            using int16_t  = signed short;
            using uint16_t = unsigned short;

            using int32_t  = signed int;
            using uint32_t = unsigned int;

            using int64_t  = signed long long;
            using uint64_t = unsigned long long;
            /* 
            * I don't have any typedef for `long` since it's 64 bits on unix-like systems, but 32 bits everywhere else.
            *
            * Plus, `int` is 32 bits everywhere but the Win16 API, and that isn't really used,
            * and `long long` is always 64 bits, apart from some rare cases which aren't defined 
            * by the C++ standard.
            */


            /*=========================================*/
            /* BYTE                                    */
            /*=========================================*/
            enum class byte : uint8_t
            {
            };

            template<typename T>
            inline constexpr byte& operator<<=(byte& byte_operand, T shift) noexcept
                requires (is_integral<T>())
            {
                return byte_operand = byte_operand << shift;
            }

            template<typename T>
            inline constexpr byte operator<<(byte byte_operand, T shift) noexcept
                requires (is_integral<T>())
            {
                return static_cast<byte>(static_cast<uint32_t>(byte_operand) << shift);
            }

            template<typename T>
            inline constexpr byte& operator>>=(byte& byte_operand, T shift) noexcept
                requires (is_integral<T>())
            {
                return byte_operand = byte_operand >> shift;
            }

            template<class T>
            inline constexpr byte operator>>(byte byte_operand, T shift) noexcept
                requires (is_integral<T>())
            {
                return static_cast<byte>(static_cast<uint32_t>(byte_operand) >> shift);
            }
} // namespace bat