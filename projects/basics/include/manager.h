#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <filesystem>
#include "contact.h"

class ContactManager
{
public:
   using ContactList = std::vector<Contact>;

   void add_contact(Contact contact);

   bool remove_contact(const std::string &phone_nunbe);

   [[nodiscard]] ContactList find_contacts(const std::string &query) const;

   [[nodiscard]] const ContactList &get_all_contacts() const;

   void save_to_file(const std::filesystem::path &filepath) const;

   void load_from_file(const std::filesystem::path &filepath);

private:
   ContactList contacts_;
};

#endif