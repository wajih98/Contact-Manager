#include "../include/Contact.hpp"

void Contact::updatePhoneNumber(std::string newPhoneNumber) {
  m_phoneNumber = std::move(newPhoneNumber);
  m_updatedAt = std::chrono::system_clock::now();
}

void Contact::updateName(std::string newName) {
  m_name = std::move(newName);
  m_updatedAt = std::chrono::system_clock::now();
}

std::string Contact::generateUniqueID() {
  static uint32_t counter = 0;
  auto now = std::chrono::high_resolution_clock::now();
  auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
                now.time_since_epoch())
                .count();
  return "CID-" + std::to_string(ns) + "-" + std::to_string(counter++);
}

std::string Contact::formatTimePoint(
    const std::chrono::system_clock::time_point &tp) const {
  // Convert to time_t (seconds since epoch)
  std::time_t t = std::chrono::system_clock::to_time_t(tp);

  // Convert to local time
  std::tm local_tm;
#ifdef _WIN32
  localtime_s(&local_tm, &t); // Windows safe version
#else
  localtime_r(&t, &local_tm); // POSIX safe version
#endif

  // Format as string
  std::stringstream ss;
  ss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
  return ss.str();
}

std::string Contact::getCreationTime() const {
  return formatTimePoint(m_createdAt);
}
std::string Contact::getUpdateTime() const {
  return formatTimePoint(m_updatedAt);
}