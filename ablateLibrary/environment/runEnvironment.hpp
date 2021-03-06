#ifndef ABLATELIBRARY_RUNENVIRONMENT_HPP
#define ABLATELIBRARY_RUNENVIRONMENT_HPP
#include <filesystem>
#include "parameters/parameters.hpp"

namespace ablate::environment {
class RunEnvironment {
   private:
    std::filesystem::path outputDirectory;
    const std::string title;

   public:
    explicit RunEnvironment(const parameters::Parameters&, std::filesystem::path inputPath = {});

    // force RunEnvironment to be a singleton
    RunEnvironment(RunEnvironment& other) = delete;
    void operator=(const RunEnvironment&) = delete;

    // static access methods
    static void Setup(const parameters::Parameters&, std::filesystem::path inputPath = {});
    inline static const RunEnvironment& Get() { return *runEnvironment; }

    inline const std::filesystem::path& GetOutputDirectory() const { return outputDirectory; }

   private:
    inline static std::unique_ptr<RunEnvironment> runEnvironment = nullptr;
};
}  // namespace ablate::environment

#endif  // ABLATELIBRARY_RUNENVIRONMENT_H
