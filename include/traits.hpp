#pragma once

namespace bat
{
    template<typename Type, Type val>
    struct integral_t
    {
        // I should rename everything in this struct.
        static constexpr Type value = val;
        using value_t               = Type;
        using type                  = integral_t;
        constexpr operator value_t() const noexcept
        {
            return value;
        }
        constexpr value_t operator()() const noexcept
        {
            return value;
        }
    };

    template<bool B>
    using boolean = integral_t<bool, B>;
    using true_t  = boolean<true>;
    using false_t = boolean<false>;


    template<typename T>
      struct is_integral :
      boolean < requires(T type, T* ptr, void (*f)(T)) // Invalidates references with T*
    {
        reinterpret_cast<T>(type); // Invalidates classes
        f(0);                      // Invalidates enums
        ptr + type;                // Invalidates everything else
    } > {};

} // namespace bat