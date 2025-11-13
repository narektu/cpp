#include "../include/contact.h"
#include <utility>
#include <stdexcept>

Contact::Contact(std::string first_name,
                 std::string last_name,
                 std::string phone_number,
                 std::string email)
    : first_name_(std::move(first_name)),
      last_name_(std::move(last_name)),
      phone_number_(std::move(phone_number)),
      email_(std::move(email))
{
   if (first_name_.empty())
   {
      throw std::invalid_argument("Contact must have a first name.");
   }
   if (phone_number_.empty())
   {
      throw std::invalid_argument("Contact must have a phone number.");
   }
}

std::string Contact::get_first_name() const
{
   return first_name_;
}

std::string Contact::get_last_name() const
{
   return last_name_;
}

std::string Contact::get_phone_number() const
{
   return phone_number_;
}

std::string Contact::get_email() const
{
   return email_;
}

void Contact::set_phone_number(std::string new_phone)
{
   if (new_phone.empty())
   {
      throw std::invalid_argument("Phone number cannot be empty.");
   }
   phone_number_ = std::move(new_phone);
}

void Contact::set_email(std::string new_email)
{
   email_ = std::move(new_email);
}

bool Contact::operator==(const Contact &other) const
{
   return std::tie(first_name_, last_name_, phone_number_, email_) ==
          std::tie(other.first_name_, other.last_name_, other.phone_number_, other.email_);
}

std::ostream &operator<<(std::ostream &os, const Contact &contact)
{
   os << "Name: " << contact.first_name_ << " " << contact.last_name_ << "\n"
      << "Phone: " << contact.phone_number_ << "\n"
      << "Email: " << contact.email_;
   return os;
}