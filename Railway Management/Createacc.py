with open("Accounts.txt", "a") as file:
    name=input("Enter Your Name")
    file.write(name + "\t")
    mobno = input("Please enter your mobile number: ")
    file.write(mobno + "\t")
    emailid = input("Please enter your Email id: ")
    file.write(emailid + "\t")