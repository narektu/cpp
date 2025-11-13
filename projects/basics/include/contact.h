#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
public:
   Contact(std::string first_name,
           std::string last_name,
           std::string phone_number,
           std::string email);

   [[nodiscard]] std::string get_first_name() const;
   [[nodiscard]] std::string get_last_name() const;
   [[nodiscard]] std::string get_phone_number() const;
   [[nodiscard]] std::string get_email() const;

   void set_phone_number(std::string new_phone);
   void set_email(std::string new_email);

   bool operator==(const Contact &other) const;

   friend std::ostream &operator<<(std::ostream &os, const Contact &contact);

private:
   std::string first_name_;
   std::string last_name_;
   std::string phone_number_;
   std::string email_;
};

#endif