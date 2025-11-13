#include "../include/manager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

void ContactManager::add_contact(Contact contact)
{
   contacts_.push_back(std::move(contact));
}

bool ContactManager::remove_contact(const std::string &phone_number)
{
   auto it = std::remove_if(contacts_.begin(), contacts_.end(),
                            [&phone_number](const Contact &contact)
                            {
                               return contact.get_phone_number() == phone_number;
                            });

   if (it != contacts_.end())
   {
      contacts_.erase(it, contacts_.end());
      return true;
   }
   return false;
}

ContactManager::ContactList ContactManager::find_contacts(const std::string &query) const
{
   ContactList results;

   for (const auto &contact : contacts_)
   {
      if (contact.get_first_name().find(query) != std::string::npos ||
          contact.get_last_name().find(query) != std::string::npos ||
          contact.get_phone_number().find(query) != std::string::npos)
      {
         results.push_back(contact);
      }
   }
   return results;
}

const ContactManager::ContactList &ContactManager::get_all_contacts() const
{
   return contacts_;
}

void ContactManager::save_to_file(const std::filesystem::path &filepath) const
{
   std::ofstream file(filepath);
   if (!file.is_open())
   {
      throw std::runtime_error("Failed to open file for writing: " + filepath.string());
   }

   for (const auto &contact : contacts_)
   {
      file << contact.get_first_name() << ","
           << contact.get_last_name() << ","
           << contact.get_phone_number() << ","
           << contact.get_email() << "\n";
   }
}

void ContactManager::load_from_file(const std::filesystem::path &filepath)
{
   if (!std::filesystem::exists(filepath))
   {
      return;
   }

   std::ifstream file(filepath);
   if (!file.is_open())
   {
      throw std::runtime_error("Failed to open file for reading: " + filepath.string());
   }

   contacts_.clear();
   std::string line;

   while (std::getline(file, line))
   {
      if (line.empty())
         continue;

      std::stringstream ss(line);
      std::string first, last, phone, email;

      if (std::getline(ss, first, ',') &&
          std::getline(ss, last, ',') &&
          std::getline(ss, phone, ',') &&
          std::getline(ss, email))
      {
         contacts_.emplace_back(first, last, phone, email);
      }
   }
}