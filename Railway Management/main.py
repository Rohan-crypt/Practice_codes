import time
print("Is this Your First time using our application")
time.sleep(2)
acc=input("Enter Y or N:")
if acc =='Y':
    print("For accessing our app please create an account")
    import Createacc
print("Enter the date you want your train to be booked")
time.sleep(2)
print("Note: Enter date in dd/mm format")
date=input()
import PrintFile
print("1 for NEW DELHI JANSHTABDI")
time.sleep(1)
print("2 for DEHRADUN JANSHTB EXPRESS")
time.sleep(1)
print("3 for Dehradun - Banaras Janta Express")
time.sleep(1)
print("4 for DEHRADUN AMRITSAR JN EXPRESS")
time.sleep(1)
print("5 for DEHRADUN SUBEDARGANJ EXPRESS")
time.sleep(1)
print("6 for DEHRADUN KOTA JN AC EXPRESS")
time.sleep(1)
train=int(input("Please a select a train:"))
import reading
list=[1100,900,760,1500,1400,1700]
seats=int(input("Enter the number of seats you want to book"))
price=list[train-1]*seats
print("Your final price is", price)
print("Movincg to payment")
time.sleep(3)
print("Complete your payment here:")
time.sleep(5)
print("Processing...")
time.sleep(4)
print("Thank you")
print("\n\n\n\n")
import printtic
printtic.details(date,price,train)