# File: age.py
# Date: September 12, 2017
# Author: Adam Abad
# Purpose: To calculates the age of a user based on a users' input

def main():
    
    print()
    print("Program to calculate your age.")
    print("Written by Adam Abad.")
    print()

    birth_month = int(input("Enter the month of your birth (1-12): "))
    print() #turnin enter
    birth_day = int(input("Enter the day of the month of your birth (1-31): "))
    print() #turnin enter
    birth_year = int(input("Enter the year of your birth: "))
    print() #turnin enter
    print()

    today_month = 9
    today_day = 12
    today_year = 2017
    
    age = today_year - birth_year

    if birth_month > today_month:
        age = age - 1
        
    if birth_month == today_month:
        if birth_day > today_day:
            age = age - 1

    print("Today's date is", today_month, "/", today_day, "/", today_year)
    print("Your birthday is on", birth_month, "/", birth_day, "/", birth_year)
    print("Your age is", age, "years old.")
    print()
    
main()
