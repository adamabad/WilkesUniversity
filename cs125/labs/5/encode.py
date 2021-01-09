# File: encode.py
# Date: Septemeber 26, 2017
# Author: Adam Abad
# Purpose: To encode messages using the Caesar Cipher

def main():

    print()
    print("This program will encode a message using")
    print("a Caesar cipher.")
    print("You will enter a key (number between 1 and 25).")
    print("Written by Adam Abad")
    print()
    
    key = int(input("Enter a key (number between 1 and 25): "))
    print() # for turnin
    print()

    #checks for good key
    if key >= -25:
        if key <= 25:
            
            plaintext = input("Enter a sentence: ")
            print() # for turnin
            print()

            small = plaintext.lower()

            print("With a key of", key)
            print()



            print("Original line:", small)
            print()

            ciphertext = ""

            for ch in small:
                outChar = ch

                if ch >= "a":
                    if ch <= "z":
                        num = ord(ch) + key
                        outChar = chr(num)

                        if outChar > "z":
                            outChar = chr(num - 26)
                        if outChar < "a":
                            outChar = chr(num + 26)

                ciphertext = ciphertext + outChar
            print("Encoded line: ", ciphertext)
        else:
            print("The key must be between -25 and 25, not", key)
    else:
        print("The key must be between -25 and 25, not", key)
        
    print()
    
main()
    
