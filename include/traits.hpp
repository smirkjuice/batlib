#pragma once

namespace bat
{

    /**
     * @brief    A template struct that wraps a static constant of a given type.
     * @tparam  `Type` The type of the integral.
     * @tparam  `Value` The value of the static constant.
     * @example `auto variable = bat::integral_const<short, 7000>();`
     */
    template<typename Type, Type Value>
    struct integral_const
    {
        static constexpr Type value = Value;
        using value_type            = Type;
        using type                  = integral_const;

        constexpr operator value_type() const noexcept
        {
            return value;
        }

        constexpr value_type operator()() const noexcept
        {
            return value;
        }
    };

    /**
     * @brief  A alias template of `bat::integral_const`, using `bool` as the type.
     * @tparam `B` The boolean value to assign, i.e. `true` or `false`.
     */
    template<bool B>
    using boolean_t = integral_const<bool, B>;

    /// @brief The result of `bat::boolean_t<true>;`
    using true_t = boolean_t<true>;

    /// @brief The result of `bat::boolean_t<false>;`
    using false_t = boolean_t<false>;


    // clang-format off

    // This shit is unreadable, and clang-format just worsens it, so I turned it off just for this struct. 
    // I'm too lazy to change the settings in .clang-format.
    // Good luck.

    /** 
     * @brief A template struct that shows if a given type is an integral type.
     * @tparam T The type to check for integral-ness
     * @example if (bat::is_integral<short>()) { auto sos = sizeof(short); }
     */
    template<typename T>
      struct is_integral : boolean_t 
      <requires (T type, T* ptr, void (*foo)(T))   // START OF REQUIRES
      {
        reinterpret_cast<T>(type);
        foo(0);
        ptr + type;
      } >                                         // END OF REQUIRES
    { 
        /*  START OF STRUCT BODY  */

        static constexpr bool value = boolean_t 
        <requires (T type, T* ptr, void (*foo)(T)) // START OF REQUIRES
        { 
          reinterpret_cast<T>(type); 
          foo(0); 
          ptr + type;
        }>::value;                                // END OF REQUIRES


        // I'll do anything but make a typedef for this lmfao
        constexpr bool operator()() const noexcept {
            return value;
        }

        /*  END OF STRUCT BODY  */
    };


    // clang-format on

} // namespace bat