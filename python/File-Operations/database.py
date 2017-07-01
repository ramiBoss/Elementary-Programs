import pickle
import sys
import os

class file_op:
    filename = "";
    
    def __init__(self):
        self.filename = "student.txt"          
            
        
    def insert(self):
        self.f = open(self.filename,'a+')
        if(self.f == False):
            print "Cannot open file"
            return
        else:
            self.name = raw_input("Student Name: ")
            self.age = raw_input("Student's Age: ")
            self.enroll = raw_input("Studemt's Enrollment: ")
            s = Student(self.name, self.age, self.enroll)
            pickle.dump(s, self.f)
            self.f.close()
            return 

    '''def RecordExists(self, file f, del_en):
        self.f = f
        self.del_en = del_en
        while True:
            try:
                s = pickle.load(self.f)
                if(s.enroll == self.del_en.upper()):
                    return 1
            except EOFError:
                return 0'''
            
    def delete(self):
        self.del_en = raw_input("Enter the enrollment number" + "\n")
        self.f = open(self.filename, 'r')
        if(self.f == False):
            print "Some Error Occurred"
            return
        else:
            flag = 0
            while True:
                try:
                    s = pickle.load(self.f)
                    if(s.enroll == self.del_en.upper()):
                        flag = 1
                        break
                except EOFError:
                    break
                
            if(flag == 1):
                print "Record of " + self.del_en.upper()  + " Found"
                self.temp = open("temp.txt", 'w+')
                self.f.seek(0,0)
                while True: 
                    try:
                        s = pickle.load(self.f)
                        if(s.enroll != self.del_en.upper()):
                            pickle.dump(s,self.temp)
                    except EOFError:
                        break
                print "The Record of " + self.del_en.upper() + " deleted successfully"
                self.temp.close()
                os.remove(self.filename)
                os.rename("temp.txt", self.filename)
            if(flag == 0):
                print "Record not found"
            self.f.close()
            return 
        
    def modify(self):
        self.show()
        self.mod_en = raw_input("Enter the Enrollment, you want to change ")
        self.f = open(self.filename, 'r')
        if(self.f == False):
            print "Some Error Occurred"
            return
        else:
            self.f.seek(0, 0)
            flag = 0
            while True:
                try:
                    s = pickle.load(self.f)
                    if(s.enroll == self.mod_en.upper()):
                        flag = 1
                        break
                except EOFError:
                    break
                
            if(flag == 1):
                print "Record of " + self.mod_en.upper()  + " Found"
                self.temp = open("temp.txt", 'w+')
                self.f.seek(0,0)
                while True: 
                    try:
                        s = pickle.load(self.f)
                        if(s.enroll == self.mod_en.upper()):
                            self.name = raw_input("Student Name: ")
                            self.age = raw_input("Student's Age: ")
                            self.enroll = raw_input("Studemt's Enrollment: ")
                            std = Student(self.name, self.age, self.enroll)
                            pickle.dump(std,self.temp)
                        else:
                            pickle.dump(s,self.temp)
                    except EOFError:
                        break
                print "The Record of " + self.mod_en.upper() + " modified successfully"
                self.temp.close()
                self.f.close()
                os.remove(self.filename)
                os.rename("temp.txt", self.filename)
                
            if(flag == 0):
                print "Record not found"
            self.f.close()
            return
        
        
    def show(self):
        self.f = open(self.filename,'r')
        if(self.f == False):
            print "Cannot open file"
            return
        else:
            print "******************************************"
            print "Name" + " \t" + "Age" + "\t "+ "Enrollment"
            while True:
                try:
                    s = pickle.load(self.f)
                    print s.name + " \t" + s.age + "\t "+ s.enroll
                except EOFError:
                    break
        self.f.close()
        return
            

    def ext(self):
        sys.exit()
                    
            
class Student:
    
    def __init__(self, name, age, enroll):
        self.name = name.upper()
        self.age = age.upper()
        self.enroll = enroll.upper()
        
    
def main():
    
    print "**** Student Database Managememt System In Python! ****"
    fop = file_op()
    options = {0 : fop.ext,
               1 : fop.insert,
               2 : fop.delete,
               3 : fop.modify,
               4 : fop.show
               
    }
    while True:
        print "*************"
        option = raw_input("0 : Exit" + " \n" + "1 : Insert" + "\n" + "2: Delete" + " \n" + "3 : Modify" + "\n" + "4 : Show" + "\n")
        if int(option) == 0 or int(option) == 1 or int(option) == 2 or int(option) == 3 or int(option) == 4:
            options[int(option)]()
        else:
            print "Invalid Error"
            

if __name__ == '__main__':
    main()
