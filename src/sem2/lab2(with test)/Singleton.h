#pragma once

#include <stdexcept>

class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable& other) = delete;
    virtual ~NonCopyable() = default;
    NonCopyable& operator =(const NonCopyable& other) = delete;
};

class NonMoveable {
public:
    NonMoveable() = default;
    NonMoveable(NonMoveable&& other) = delete;
    virtual ~NonMoveable() = default;
    NonMoveable& operator =(NonMoveable&& other) = delete;
};

template <typename T>
class Singleton : public NonCopyable, public NonMoveable {
public:
    template <typename... Args>
    static T* Create(const Args&... args) {
        if (s_Instance) {
            throw std::runtime_error("Already created!");
        }

        return s_Instance = new T(args...);
    }
    static void Destroy() {
        delete s_Instance;
        s_Instance = nullptr;
    }
    static inline T& Get() {
        if (!s_Instance) {
            throw std::runtime_error("Didn't created yet!");
        }
        return *s_Instance;
    }
protected:
    Singleton() = default;
    static inline T* s_Instance = nullptr;
};
