#include "Contact.hpp"
#include <string>
#include <unordered_map >

class ContactManager {
public:
  ContactManager() = default;
  ~ContactManager() = default;

  std::string addContact(const std::string &name,
                         const std::string &phoneNumber);
  void removeContact(const std::string &name);
  void viewContact(const std::string &name) const;
  void updateContact(const std::string &name,
                     const std::optional<std::string> &newName,
                     const std::optional<std::string> &newPhoneNumber);
  void displayAllContacts() const;

private:
  std::unordered_map<std::string, Contact> m_contacts;
};