#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

namespace naibench
{
    class NaiBench
    {
        public:
            NaiBench(const std::string& func_name)
            : m_func_name(func_name),
              m_start(std::chrono::high_resolution_clock::now())
            {}

            ~NaiBench()
            {
                m_end = std::chrono::high_resolution_clock::now();
                auto elapsed = m_end - m_start;

                std::cout << m_func_name << ": " << std::fixed << std::setprecision(16) << elapsed.count() << " time elapsed.\n";
            }

        private:
            using time_point_t = std::chrono::time_point
            <
                std::chrono::high_resolution_clock,
                std::chrono::duration<double>
            >;

        private:
            std::string m_func_name;
            time_point_t m_start;
            time_point_t m_end;
    }; // class NaiBench
} // namespace naibench

#define NAIBENCH_START() naibench::NaiBench start(__func__)
#define NAIBENCH_STOP() start.~NaiBench()
