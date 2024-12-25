import reading
def details(date, price, train):
    print("Your ticket details are")
    with open('Accounts.txt', 'r') as file:
        for line in file:
            print(line)
    for i in range(((train-1)*4)+1,((train-1)*4)+4):
        reading.line(i)
    print("Price is \t", price,"\t on Date: \t",date)