class AutomatadePila:
   
    def __init__(self,cadena):
        self.cadena=cadena
        self.stack = []
        
    def GIC(self): 
        num=["1","2","3","4","5","6","7","8","9"]
        s = ['+','-', '*','/','%'] 
        mm = ['+','-'] 
        hexa=['A','B','C','D','E','F'] 
        self.estado='inicio' 
        
        for i in range(0,len(self.cadena)):
            self.transicion=self.cadena[i]
            """
            print(self.estado)
            print(self.transicion) 
            print(self.stack)
            """
           
            if self.estado=='inicio': 
               if self.transicion.isalpha() or self.transicion=='_':
                   self.estado='q1'
               else:
                   break
                   
                   
            elif self.estado=='q1': 
                if self.transicion.isalnum() or self.transicion=='_':
                    self.estado='q1'
                elif self.transicion=='=':
                    self.estado='q2'
                else:
                    break
                          
                    
            elif self.estado=='q2':
               if self.transicion=='(':
                    self.stack.append('(')  
                    self.estado='q2'
               elif self.transicion.isalpha() or self.transicion=='_': 
                    self.estado='q3'
               elif self.transicion in num: 
                    self.estado='q4' 
               elif self.transicion =="0":
                   self.estado="q7"
               elif self.transicion in mm:   
                   self.estado='q3'
               else:
                    break
                    
                    
            elif self.estado=='q3':
               if self.transicion.isalnum() or self.transicion=='_':      
                   self.estado='q3'
               elif self.transicion=='(':
                    self.stack.append('(')
                    self.estado='q3' 
               elif self.transicion==';': 
                   self.estado='q6' 
               elif self.transicion==')':  
                    self.stack.pop() 
                    self.estado='q5'                   
               elif self.transicion in s:
                    self.estado='q2';   
               elif self.transicion == "=":
                    self.estado="q3"
               else:
                    break
                  
                    
                  
            elif self.estado=='q4': 
               if self.transicion.isdigit():
                  self.estado='q4'
               elif self.transicion in s: 
                  self.estado='q2'
               elif self.transicion=="(":
                   self.estado="q4"
               elif self.transicion==')': 
                  self.stack.pop() 
                  self.estado='q5' 
               elif self.transicion==';': 
                  self.estado='q6' 
               elif self.transicion==".":
                   self.estado="q8"
               elif self.transicion=="E":
                   self.estado="q12"
               else:
                    break
                    
            elif self.estado=='q5':                   
                if self.transicion in s:
                   self.estado='q2'
                elif self.transicion==')':
                   self.stack.pop()
                   self.estado='q5'
                elif self.transicion==';':
                   self.estado='q6'
                else:
                    break
            elif self.estado=="q7":
                if self.transicion in num:
                    self.estado="q4"
                elif self.transicion==".":
                    self.estado="q8"
                elif self.transicion=="X" or self.transicion=="x":
                    self.estado="q9"
                elif self.transicion in s:
                    self.estado="q2"
                elif self.transicion =="(":
                    self.stack.append("(")
                    self.estado="q7"
                elif self.transicion == ")":
                    self.stack.pop()
                    self.estado="q5"
                elif self.transicion==";":
                    self.estado="q6"
                else:
                    break

            elif self.estado=="q8":
                if self.transicion in num or self.transicion=="0":
                    self.estado="q11"
                else: 
                    break
            
            elif self.estado=="q9":
                if self.transicion in num or self.transicion in hexa or self.transicion=="0":
                    self.estado="q10"
                else: 
                    break
            
            elif self.estado=="q10":
                if self.transicion in num or self.transicion in hexa or self.transicion=="0":
                    self.estado="q10"
                elif self.transicion =="(":
                    self.stack.append("(")
                    self.estado="q10"
                elif self.transicion==";":
                    self.estado="q6"
                elif self.transicion in s:
                    self.estado="q2"
                elif self.transicion == ")":
                    self.stack.pop()
                    self.estado="q5"
                else:
                    break
            
            elif self.estado=="q11":
                if self.transicion in num or self.transicion=="0":
                    self.estado="q11"
                elif self.transicion in s:
                    self.estado="q2"
                elif self.transicion =="(":
                    self.stack.append("(")
                    self.estado="q10"
                elif self.transicion==";":
                    self.estado="q6"
                elif self.transicion == ")":
                    self.stack.pop()
                    self.estado="q5"
                elif self.transicion == "E":
                    self.estado="q12"
                else:
                    break

            elif self.estado=="q12":
                if self.transicion in mm:
                    self.estado="q14"
                elif self.transicion in num:
                    self.estado="q13"
                else:
                    break
            
            elif self.estado=="q13":
                if self.transicion in num or self.transicion=="0":
                    self.estado="q13"
                elif self.transicion in s:
                    self.estado="q2"
                elif self.transicion =="(":
                    self.stack.append("(")
                    self.estado="q13"
                elif self.transicion==";":
                    self.estado="q6"
                elif self.transicion == ")":
                    self.stack.pop()
                    self.estado="q5"
                else: 
                    break

            elif self.estado=="q14":
                if self.transicion in num:
                    self.estado="q13"
                else:
                    break

                
        if not self.stack and self.estado=='q6':
            return True
        
def checkpalabrasReservadas(word):
  with open('palabrasreservadas.txt','r') as file:
    flag=False
    for linea in file:
        palabra=linea.strip()
        if palabra in word:
            flag = True
            break
    return flag
  

def main():
 word = input("Introduzca la palabra: ")
 newWord=word.replace(" ","")
 checkPalabra=AutomatadePila(newWord)  
 if checkpalabrasReservadas(newWord):
     print("Palabra No aceptada, uso de palabra reservada")
 else:
     print(checkPalabra.cadena)
     if checkPalabra.GIC()==True:
      print('Palabra Aceptada!')
     else:
      print('Palabra no Aceptada! ')
     
if __name__ == "__main__":
    main() 