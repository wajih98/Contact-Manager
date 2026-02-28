#include "ContactManager.hpp"
#include <algorithm>
#include <iostream>

std::string ContactManager::addContact(const std::string &name,
                                       const std::string &phoneNumber) {
  if (name.empty() || phoneNumber.empty()) {
    throw std::invalid_argument("Name and phone number cannot be empty");
  }
  // Check if phone number already exists
  for (const auto &pair : m_contacts) {
    if (pair.second.getPhoneNumber() == phoneNumber) {
      throw std::invalid_argument("Phone number already exists!");
    }
  }
  // Check if name already exists
  for (const auto &pair : m_contacts) {
    if (pair.second.getName() == name) {
      throw std::invalid_argument("Name already exists!");
    }
  }
  Contact newContact(name, phoneNumber);
  std::string id = newContact.getId();
  m_contacts.emplace(id, std::move(newContact));
  return id;
}

void ContactManager::removeContact(const std::string &name) {
  auto it = std::find_if(
      m_contacts.begin(), m_contacts.end(),
      [&name](const auto &pair) { return pair.second.getName() == name; });

  if (it != m_contacts.end()) {
    m_contacts.erase(it);
    std::cout << "Contact removed successfully!" << std::endl;
  } else {
    throw std::invalid_argument("Contact not found!");
  }
}

void ContactManager::updateContact(
    const std::string &name, const std::optional<std::string> &newName,
    const std::optional<std::string> &newPhoneNumber) {
  auto it = std::find_if(
      m_contacts.begin(), m_contacts.end(),
      [&name](const auto &pair) { return pair.second.getName() == name; });

  if (it != m_contacts.end()) {
    if (newName) {
      it->second.updateName(*newName);
    }
    if (newPhoneNumber) {
      // Check if new phone number already exists
      for (const auto &pair : m_contacts) {
        if (pair.second.getPhoneNumber() == *newPhoneNumber) {
          throw std::invalid_argument("Phone number already exists!");
        }
      }
      it->second.updatePhoneNumber(*newPhoneNumber);
    }
    std::cout << "Contact updated successfully!" << std::endl;
  } else {
    throw std::invalid_argument("Contact not found!");
  }
}

void ContactManager::viewContact(const std::string &name) const {
  for (const auto &pair : m_contacts) {
    if (pair.second.getName() == name) {
      std::cout << "ID: " << pair.second.getId() << std::endl;
      std::cout << "Name: " << pair.second.getName() << std::endl;
      std::cout << "Phone Number: " << pair.second.getPhoneNumber()
                << std::endl;
      std::cout << "Created At: " << pair.second.getCreationTime() << std::endl;
      std::cout << "Updated At: " << pair.second.getUpdateTime() << std::endl;
      std::cout << "------------------------" << std::endl;
    }
  }
}

void ContactManager::displayAllContacts() const {
  for (const auto &pair : m_contacts) {
    viewContact(pair.second.getName());
  }
}
