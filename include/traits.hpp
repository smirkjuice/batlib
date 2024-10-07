#pragma once

namespace bat
{
    /**
     * `bat::integral_const<T, V>`
     *
     * @brief    A template struct that wraps a static constant of a given type.
     * @tparam  `Type` The type of the integral.
     * @tparam  `Value` The value of the static constant.
     * @example `auto variable = bat::integral_const<short, 7000>();`
     *
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
     * `bat::boolean_t<B>`
     * 
     * @brief  A alias template of `bat::integral_const`, using `bool` as the type.
     * @tparam `B` The boolean value to assign, i.e. `true` or `false`.
     *
     */
    template<bool B>
    using boolean_t = integral_const<bool, B>;


    /**
     * `bat::true_t`
     *
     * @brief Alias of `bat::boolean_t<true>`
     *
     */
    using true_t = boolean_t<true>;


    /**
     * `bat::false_t`
     *
     * @brief Alias of `bat::boolean_t<false>`
     *
     */
    using false_t = boolean_t<false>;


    /**
     * @brief A template struct that shows if a given type is an integral type.
     * @tparam T The type to check for integral-ness
     * @example `return bat::is_integral_type<short>::value;`
     */
    template<typename T>
      struct is_integral_type : boolean_t < requires(T type, T* ptr, void (*foo)(T))
    {
        reinterpret_cast<T>(type);
        foo(0);
        ptr + type;
    } > {};

    /**
      * @brief A variable template of `bat::is_integral_type<T>::value;`
      * @tparam T The type to check for integral-ness
      * @example `requires bat::is_integral<T>`
     */
    template<typename T>
    constexpr inline bool is_integral = is_integral_type<T>::value;

} // namespace bat