import csv
def is_content(fin):
    with open(fin) as file:
        r=file.read()
        if len(r)==0:
            return False
        else:
            return True

def add_acc(fin,name,id,ps,anum,bal):
    with open (fin,"a",newline="") as file:
        fields=["full_name","login","pswd","acc_number","balance"]
        cur=csv.DictWriter(file,fieldnames=fields)
        if is_content(fin) is False:
            cur.writeheader()
            cur.writerow({"full_name":name,"login":id,"pswd":ps,"acc_number":anum,"balance":bal})
            print ("Account Details Added")
        else:
            cur.writerow({"full_name":name,"login":id,"pswd":ps,"acc_number":anum,"balance":bal})
            print ("Account Details Added")

# add_acc("bank.txt","varad","varad@22","bunnybunny",1234567890,20000)
# add_acc("bank.txt","mann","hello@2217","bunny",1234543560,550000)

def acc_read(fin,anum):
    with open(fin) as file:
        cur=csv.DictReader(file)
        for row in cur:
            if (row["acc_number"] == str(anum)):
                return (row)  #row will be dictionary
            
            
#acc_read("bank.txt",1234567890)

def edit_data(fin,field,anum,replace):
    heading=["full_name","login","pswd","acc_number","balance"]
    lstr = []
    with open (fin) as file:
        data = file.readlines() #list of strings
        # print(data)
        if field in heading:
            for i in data:
                lst=i.split(",") #i is a list
                # print(lst)
                if (lst[3] == str(anum)):
                    lst[heading.index(field)] = str(replace) + "\n"
                    s=",".join(lst)
                    lstr.append(s)
                else:
                    lstr.append(",".join(lst))

        else:
            print("Error")
            return

        # print(lstr)

    with open (fin,"w",newline="") as file:
        file.writelines(lstr)

# edit_data("bank.txt","balance",1234567890,70000)

def withdraw(fin,anum,amt):  #can be used for deposit as well
    data_dict = acc_read(fin,anum)
    n_amt=int(data_dict["balance"]) - amt
    edit_data(fin,"balance",anum,n_amt)


def transfer(fin,acc_from,acc_to,amt):
    with open(fin) as file:
        lst_from = acc_read(fin,acc_from)
        lst_to = acc_read(fin,acc_to)

        new_from = int(lst_from["balance"]) - amt
        new_to = int(lst_to["balance"]) + amt
        
        edit_data(fin,"balance",acc_from,new_from)
        edit_data(fin,"balance",acc_to,new_to)

# transfer("bank.txt",1234543560,1234567890,500)

def check_balance(fin,anum):
    with open(fin) as file:
        data = acc_read(fin,anum)
        print("Your Current Balance is: ",data["balance"])
        
# check_balance("bank.txt",1234567890)

res=True
while (res == True):
    try:
        print("###### Welcome to the Great Bank of World ######")
        already = int(input("Enter '1' to add an Account. Enter '2' to login into your Account: "))
        if already == 1:
            name = input("Enter your name: ")
            vname=0
            # invname=0
            try:
                for i in name:
                    if (ord(i)>=65 and ord(i)<=90)  or  (ord(i)>=97 and ord(i)<=122)  or  (ord(i) == 32) :
                        vname+=1
                    elif (len(name)==1) and ord(i)==32:
                        vname-=1
                    else:
                        print ("Invalid Name")
                        vname-=1
                if (vname==len(name)):
                    print("Valid Name")
                else:
                    print("Invalid name")
                    print()
                    continue
                
            except:
                print ("Incalid Name")

            
            acc_num = int(input("Enter your account number: "))
            try:
                if acc_read("bank.txt",acc_num) != {}:
                    if (len(str(acc_num)) == 16):
                        print("Valid Account number: ")
                    else:
                        print("Invalid Account number")
                        print()
                        continue
                else:
                    print("Invalid Account number")
                    print()
                    continue
            except:
                print ("Invalid Account Number")

            login = input("Enter your Login id: ")
            pswd = input("Enter your Password: ")

            bal = int(input("Enter the amount you've added into your account: "))
            try:
                if bal>2000:
                    print("Valid")
                else:
                    print("Amount less than the limit")
                    print()
                    continue
            except:
                print("Invalid input")

            add_acc("bank.txt",name,login,pswd,acc_num,bal)
        elif(already==2):
            anum=int(input("Enter your account number: "))
            data_lst = acc_read("Bank.txt",anum)
            if data_lst["acc_number"] == str(anum):
                lin = input("Enter your login id: ")
                ps = input("Enter your password: ")
                if data_lst["login"] == lin  and data_lst["pswd"] == ps:
                    print("Hello User")
                    ch = int(input("Enter what you  wanna do:\n Press 1 to withdraw money\n Press 2 to deposit money\n Press 3 to transfer money\n Press 4 to check current balance: \n"))
                    if ch==1:
                        amt = int(input("Enter how much money you wanna withdraw: "))
                        withdraw("bank.txt",anum,amt)
                        print("Done!")
                    elif ch==2:
                        amt = int(input("Enter how much money you wanna deposit: "))
                        withdraw("bank.txt",anum,0-amt)
                        print("done!")
                    elif ch==3:
                        anum_to = int(input("Enter account number of person whom  you wanna transfer money: "))
                        amt = int(input("Enter amount to be transferred: "))
                        transfer("bank.txt",anum,anum_to,amt)
                        print("done!")
                    elif ch==4:
                        check_balance("bank.txt",anum)
                else:
                    print("User not found")
            else:
                print("Account number not found")
        else:
            print("Invalid Choice")
        
        res=input("Wanna continue? yes/no: ")
        if res=="no":
            print("Thank you")
            res = False
        elif res=="yes":
            print()
            res = True
        else:
            print("I'll take it as a no")
            res = False
    except:
        print("Invalid Entry")
        res=input("Wanna continue? yes/no: ")
        if res=="no":
            print("Thank you")
            res = False
        elif res=="yes":
            print()
            res = True
        else:
            print("I'll take it as a no")
            res = False