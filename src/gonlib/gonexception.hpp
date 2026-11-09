#pragma once

namespace gon {
    class exception {
        public:                    
            constexpr exception() noexcept { }
            constexpr exception(const exception&) noexcept { }
            constexpr exception& operator=(const exception&) noexcept {
                return *this;
            }
            constexpr virtual ~exception() = default;
            constexpr virtual const char* what() const noexcept {
                return "gon::exception";
            }

    };
    class out_of_range : public exception {
        private:
            const char* msg = nullptr;
        public:
            constexpr out_of_range(const char* messe) noexcept {
                msg = messe;
            }
            constexpr ~out_of_range() noexcept override = default;
            constexpr const char* what() const noexcept override {
                return msg;
            }
    };
}