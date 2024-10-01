#pragma once

namespace bat
{
    template<typename Type, Type value_param>
    struct integral
    {
        static constexpr Type value = value_param;
        using value_type            = Type;
        using type                  = integral;

        constexpr operator value_type() const noexcept
        {
            return value;
        }

        constexpr value_type operator()() const noexcept
        {
            return value;
        }
    };

    template<bool B>
    using boolean_t = integral<bool, B>;
    using true_t    = boolean_t<true>;
    using false_t   = boolean_t<false>;


    // clang-format off
    // Holy FUCK this shit is unreadable, and clang-format just worsens it.
    // Good luck.

    /** 
     * @brief A template struct that shows if a given type is an integral type.
     * @tparam T The type to check for integral-ness
     * @example if (bat::is_integral<short>())) { auto sos = sizeof(short); }
     */
    template<typename T>
      struct is_integral : boolean_t <requires
      (T type, T* ptr, void (*foo)(T))
      {
        reinterpret_cast<T>(type);
        foo(0);
        ptr + type;
      } > /*  END OF REQUIRES  */
    { 
        /*  STRUCT BODY  */

        static constexpr bool value = boolean_t <requires 
        (T type, T* ptr, void (*foo)(T)) 
        { 
          reinterpret_cast<T>(type); 
          foo(0); 
          ptr + type;
        }>::value;
        // I'll do anything but make a typedef for this lmfao
        constexpr bool operator()() const noexcept {
            return value;
        }
    };
    // clang-format on

} // namespace bat