#include <vector>

// Macro short for macro instruction that then determine what is triggered for the smaller ones
#if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

extern "C" {
    EXPORT int AddNumbers(int a, int b) {
        return a + b;
    }
}