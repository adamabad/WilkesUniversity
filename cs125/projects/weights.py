# File: weights.py
# Date: October 26, 2017
# Author: Adam Abad
# Purpose: To evaluate pumpkin weights and average their total

def info():
    
    print()
    print("Program to calculate the average of a")
    print("group of pumpkin weights.")
    print("You will be asked to enter the number of")
    print("pumpkins, followed by each pumpkin weight.")
    print("Written by Adam Abad.")
    print()

def weight(pumpkin):
    
    text = "Enter the weight for pumpkin " + str(pumpkin) + ": "
    weight = float(input(text))
    print() #forturnin
    
    if weight < 50:
        print("{0:0.3f} is light".format(weight))
    elif weight < 70:
        print("{0:0.3f} is normal".format(weight))
    else:
        print("{0:0.3f} is heavy".format(weight))
    
    return weight

def calcAverage(totalWeight,numPumpkins):
    
    average = totalWeight/numPumpkins
    print("The average weight of the",numPumpkins,end='')
    print(" pumpkins is {0:0.3f}".format(average))
    
def main():
    
    info()
    numPumpkins = int(input("Enter the number of pumpkins: "))
    print() #forturnin
    print()
    totalWeight = 0
    for pumpkin in range(numPumpkins):
        totalWeight = totalWeight + weight(pumpkin+1)
    calcAverage(totalWeight,numPumpkins)
    print()
    
main()
        
