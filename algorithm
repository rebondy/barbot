Margarita = ["Tequila", "Cointreau", "Lime Juice"]
MintJulep = ["Wiskey", "Angostura Bitters", "Sugar Syrup"]
PlantersPunch = ["White Rum", "Lime Juice", "Sugar Syrup", "Angostura Bitters"]
Cosmopolitan = ["Vodka", "Cointreau", "Lime Juice", "Cranberry Juice"]
Vodkatini = ["Vodka", "Vermouth"]
Fitzgerald = ["Lemon Juice", "Sugar Syrup", "Angostura Bitters", "Gin"]
DryMartini = ["Gin", "Vermouth"]
VodkaSour = ["Vodka", "Lemon Juice", "Sugar Syrup"]
Gimlet = ["Gin", "Lime Juice"]
LemonDaiquiri = ["Cointreau", "White Rum", "Lemon Juice"]
CranberryVodka = ["Cranberry Juice", "Vodka"]
Manhattan = ["Angostura Bitters", "Vermouth", "Wiskey"]
Daiquiri = ["White Rum", "Sugar Syrup", "Lime Juice"]
WiskeySour = ["Wiskey", "Lemon Juice", "Sugar Syrup"]
CapeCodder = ["Vodka", "Cranberry Juice"]
OldFashioned = ["Wiskey", "Angostura Bitters", "Sugar Syrup"]
Mojito = ["Sugar Syrup", "White Rum"]
#print("the length is", len(masterSet))
#print(masterSet)

def sort ():
    # This function uses the randomly ordered set (masterSet) to place an ingredient at a servo

    # initialize variables
    masterList = Margarita + MintJulep + PlantersPunch + Cosmopolitan + Vodkatini + Fitzgerald + DryMartini + VodkaSour + Gimlet + LemonDaiquiri + CranberryVodka + Manhattan + Daiquiri + WiskeySour + CapeCodder + OldFashioned + Mojito
    masterSet = set(masterList)
    servo1 = ['first', 'second', 'third']
    servo2 = ['first', 'second', 'third']
    servo3 = ['first', 'second', 'third']
    servo4 = ['first', 'second', 'third']
    n = 0
    overlapCounter = 0

    # place ingredient at each servo 
    for i in masterSet:
        if n < 3:
            servo1[n] = i
            n = n +1
        elif n < 6:
            servo2[n-3] = i
            n = n + 1
        elif n < 9:
            servo3[n-6] = i
            n = n + 1
        elif n < 12:
            servo4[n-9] = i
            n = n + 1

    # write what ingredient is randomly placed in which servo's position
#    print("Servo 1 is : ", servo1,"Servo 2 is : ", servo2,"Servo 3 is : ", servo3,"Servo 4 is : ", servo4)

    # check each drink recipe to see if there is overlap at each servo
    overlapCounter = overlap(servo1, servo2, servo3, servo4, Margarita)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, MintJulep)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, PlantersPunch)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Cosmopolitan)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Vodkatini)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Fitzgerald)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, DryMartini)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, VodkaSour)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Gimlet)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, LemonDaiquiri)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, CranberryVodka)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Manhattan)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Daiquiri)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, WiskeySour)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, CapeCodder)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, OldFashioned)
    overlapCounter = overlapCounter + overlap(servo1, servo2, servo3, servo4, Mojito)
#   print("Overlap on this one was: ", overlapCounter)
#    while overlapCounter > 5:
#        main()
#    if overlapCounter <= 5:
#        print("Overlap on this one was: ", overlapCounter)
#        print("Servo 1 is : ", servo1,"Servo 2 is : ", servo2,"Servo 3 is : ", servo3,"Servo 4 is : ", servo4)   
    print("Overlap on this one was: ", overlapCounter)
    print("Servo 1 is : ", servo1,"Servo 2 is : ", servo2,"Servo 3 is : ", servo3,"Servo 4 is : ", servo4)   



def overlap (servo1 : list, servo2 : list, servo3 : list, servo4 : list, drinkRecipe : list):
    overlap = 0
    for i in range(len(drinkRecipe)):
        overlap = overlap + checkServo(i, drinkRecipe, servo1)
        overlap = overlap + checkServo(i, drinkRecipe, servo2)
        overlap = overlap + checkServo(i, drinkRecipe, servo3)
        overlap = overlap + checkServo(i, drinkRecipe, servo4)
    return overlap

def checkServo (i : int, drinkRecipe : list, servoToCheck : list):
    overlap = 0
    if drinkRecipe[i] in servoToCheck:
                if i+1 < len(drinkRecipe):
                    if drinkRecipe[i+1] in servoToCheck:
                        overlap = overlap + 1
                        #print('Overlap occured at: ', servoToCheck)
                if i+2 < len(drinkRecipe):
                    if drinkRecipe[i+2] in servoToCheck:
                        overlap = overlap + 1
                        #print('Overlap occured at: ', servoToCheck)
                if i+3 < len(drinkRecipe):
                    if drinkRecipe[i+3] in servoToCheck:
                        overlap = overlap + 1
                        #print('Overlap occured at: ', servoToCheck)
    return overlap

def main():
    sort()

main()