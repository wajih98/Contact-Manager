#include <chrono>
#include <iomanip>
#include <string>

class Contact {
public:
  Contact(std::string name, std::string phoneNumber)
      : m_name(std::move(name)), m_phoneNumber(std::move(phoneNumber)),
        m_createdAt(std::chrono::system_clock::now()),
        m_updatedAt(std::chrono::system_clock::now()),
        m_id(generateUniqueID()){};
  std::string getId() const { return m_id; };
  std::string getName() const { return m_name; };
  std::string getPhoneNumber() const { return m_phoneNumber; };
  std::string getCreationTime() const;
  std::string getUpdateTime() const;
  // Update contact info
  void updatePhoneNumber(std::string newPhoneNumber);
  void updateName(std::string newName);

private:
  // Generate unique ID from system clock + static counter
  static std::string generateUniqueID();

  std::string
  formatTimePoint(const std::chrono::system_clock::time_point &tp) const;

  std::string m_id;
  std::string m_name;
  std::string m_phoneNumber;
  std::chrono::system_clock::time_point m_createdAt;
  std::chrono::system_clock::time_point m_updatedAt;
};