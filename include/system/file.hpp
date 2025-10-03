#pragma once

#include <string>
#include <vector>

/**
 * @file file.hpp
 * @brief Small file utilities used to read/write telemetry and logs.
 */

#define INPUT_PATTERN_CHARACTER             (696969)
#define INPUT_PATTERN_ESC                   (696942)
#define INPUT_PATTERN_CTRL                  (696924)
#define INPUT_PATTERN_AVPAG                 (696930)
#define INPUT_PATTERN_AVPAG_UP              (696931)
#define INPUT_PATTERN_AVPAG_DOWN            (696932)

namespace File {
    /**
     * @brief Read an entire file into a string.
     * @param filePath Path to the file to read.
     * @return std::string File contents.
     */
    std::string ReadFile(const std::string &filePath);

    /**
     * @brief Write data to a local file (overwrites existing file).
     * @param dataToWrite Data to write.
     * @param filePath Destination file path.
     */
    void WriteFile(const std::string &dataToWrite, const std::string &filePath);

    /**
     * @brief Delete a local file if present.
     * @param filePath Path to the file to delete.
     */
    void DeleteLocalFile(const std::string &filePath);

    /**
     * @brief Append a message to the log file. Optionally prefix with a date.
     * @param message Log message.
     * @param date If true, prefix the entry with a timestamp.
     */
    void LogFile(std::string message, bool date);

    /**
     * @brief Parse a telemetry CSV into a vector of maps; each map is a vector
     *        of (x,y) coordinate pairs representing identities per map.
     * @param filePath CSV telemetry file path.
     * @return Parsed coordinate structure.
     */
    std::vector<std::vector<std::pair<int, int> > > ReadFileAndBuildMap(const std::string &filePath);
};
