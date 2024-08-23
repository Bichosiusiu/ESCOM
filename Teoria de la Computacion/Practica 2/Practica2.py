import shutil

class Automata:

    def __init__(self,texto):
        self.texto=texto
    def AnalizadorLexico(self):   
        nums0 = ['1', '2', '3','4','5','6','7','8','9'] 
        octalist = ['0','1','2', '3','4','5','6','7'] 
        hexa = ['A','B','C', 'D','E','F']   
        operadores=['+','-','=','/','<','>','!','*','%']
        especiales = ['+','-','=','<','>','!','%','¡','¿','?','|','°','#','$','&','(',')',',','.',':',';','_','¨',' ','{','}','[',']']

        self.estado='inicio' 
        for i in range(0,len(self.texto)):
            self.transicion=self.texto[i]
            ##print(self.estado,self.transicion)
            
            ##Estado inicial
            if self.estado == "inicio":
                if self.transicion in nums0:
                    self.estado="auxDec"
                elif self.transicion=='+' or self.transicion=='-':
                    self.estado="signo" 
                elif self.transicion=='0':
                    self.estado="Cero"  
                elif self.transicion=='/':
                    self.estado="com"      
                elif self.transicion.isalpha()  or self.transicion=='_' or self.transicion=='$':
                    self.estado="Alpha"    
                elif self.transicion in operadores:
                    self.estado='inicio'            
                else:
                    return False

            ##Estado 'auxDec'    
            elif self.estado =="auxDec": 
                if self.transicion == '.':
                  self.estado='puntoE'    
                elif str.isdigit(self.transicion):
                  self.estado='Decimal' 
                elif self.transicion in operadores:
                    self.estado='inicio'
                else: 
                    return False
                
            ##Estado 'puntoD'    
            elif self.estado =="puntoD": 
                if str.isdigit(self.transicion):
                  self.estado='DecimalsE' 
                else: 
                    return False
        
        
        
            ##Estado 'Decimal'    
            elif self.estado =="Decimal": 
                if self.transicion == '.':
                  self.estado='puntoD'  
                elif str.isdigit(self.transicion):
                  self.estado='Decimal' 
                elif self.transicion in operadores:
                    self.estado='inicio'
                else: 
                    return False
                
            ##Estado 'puntoE'    
            elif self.estado =='puntoE':
                if str.isdigit(self.transicion):
                  self.estado='DecimalsE2'      
                else: 
                    return False

            
            ##Estado 'DecimalsE'    
            elif self.estado =='DecimalsE':
                if self.transicion =='E':
                    self.estado='E'    
                elif str.isdigit(self.transicion):
                  self.estado='DecimalsE' 
                elif self.transicion in operadores:
                    self.estado='inicio'
                else: 
                    return False   
                
            ##Estado 'DecimalsE2'    
            elif self.estado =='DecimalsE2':
                if str.isdigit(self.transicion):
                  self.estado='DecimalsE2' 
                elif self.transicion=='E':
                  self.estado='E' 
                elif self.transicion in operadores:
                    self.estado='inicio'                  
                else: 
                    return False                   
                
            ##Estado 'signo'    
            elif self.estado =='signo':
                if self.transicion in nums0:
                  self.estado='auxDec'
                elif self.transicion == '0':
                  self.estado='Cero'   
                else: 
                    return False    
                
            ##Estado 'aux'    
            elif self.estado =='aux':
                if str.isdigit(self.transicion):
                  self.estado='DecimalsE0'  
                else: 
                    return False   
                
            ##Estado 'DecimalsE0'    
            elif self.estado =='DecimalsE0':
                if str.isdigit(self.transicion):
                  self.estado='DecimalsE0' 
                elif self.transicion=='E':
                  self.estado='E'    
                elif self.transicion in operadores:
                    self.estado='inicio'                
                else: 
                    return False   

                
                
            ##Estado 'cero'    
            elif self.estado =='Cero':
                if self.transicion =='.':
                  self.estado='aux' 
                elif self.transicion in octalist:
                  self.estado='Octal'  
                elif self.transicion=='X'or self.transicion=='x':
                  self.estado='0X'               
                elif self.transicion in operadores:
                    self.estado='inicio'     
                else: 
                    return False 
                
             ##Estado 'E'
            elif self.estado =='E':
                if self.transicion=='+' or self.transicion=='-':   
                    self.estado='Signo2'
                elif str.isdigit(self.transicion):
                    self.estado='digitE'
                else: 
                    return False  
                
            ##Estado 'Octal'  
            elif  self.estado=='Octal':
                if self.transicion in octalist:
                    self.estado='Octal'
                elif self.transicion in operadores:
                    self.estado='inicio'
                else :
                    return False
                
             ##Estado 'digitE'
            elif self.estado =='digitE':
                if str.isdigit(self.transicion):
                    self.estado='digitE'
                else: 
                    return False
            
            #elif self.estado=="DecimalExp":
                #if self.transicion in operadores:
                   # self.estado='inicio'
                #else: return False
            
              ##Estado 'Signo2'
            elif self.estado =='Signo2':              
                if str.isdigit(self.transicion):
                    self.estado='digitE'
                else: 
                    return False

            ##Estado 'cero-x'    
            elif self.estado =='0X':
                if str.isdigit(self.transicion) or self.transicion in hexa:
                  self.estado='Hexadecimal'                     
                else:
                  return False

            ##Estado 'Hexadecimal'          
            elif self.estado =='Hexadecimal':
                if str.isdigit(self.transicion) or self.transicion in hexa:
                  self.estado='Hexadecimal' 
                elif self.transicion in operadores:
                    self.estado='inicio'
                else:
                 return False
            ##Estado 'com'          
            elif self.estado =='com':
                if self.transicion == '*':
                    self.estado = 'com_mul'
                elif self.transicion == '/':
                    self.estado = 'Comentario'
                elif self.transicion == ' ':
                    pass  # Ignorar espacios en blanco dentro del comentario
                else: 
                    return False
                
            ##Estado '*'          
            elif self.estado =='com_mul':
                if self.transicion == '*':
                    self.estado = 'com2'
                elif self.transicion == '/':
                    self.estado = 'ComentarioAs'
                ##elif self.transicion==' ':
                    ##pass  # Ignorar espacios en blanco dentro del comentario
                elif str.isspace(self.transicion):
                    self.estado ='com_mul'
                elif self.transicion.isalpha() or self.transicion.isnumeric() or self.transicion in especiales:
                    self.transicion = 'com_mul'
                else: 
                    return False
                    ##self.estado = 'com_mul'
                

                
            ##Estado 'com2'          
            elif self.estado =='com2':
                if self.transicion=='/':
                    self.estado='ComentarioAs'
                else: 
                    self.estado='com_mul'

            elif self.estado =='Comentario':  
                return True

            
            ##Estado 'Alpha'          
            elif self.estado =='Alpha':
                if self.transicion.isalnum() or self.transicion=='_' or self.transicion=='$':
                    self.estado='Alpha'
                elif self.transicion in operadores:
                    self.estado='inicio'
                else: 
                   return False

           
            else:
              return False          
        
        if self.estado=="DecimalsE":
            return True
        elif self.estado=="DecimalsE2":
            return True    
        elif self.estado=="DecimalsE0":
            return True        
        elif self.estado=="Decimal":
            return True
        elif self.estado=="Octal":
            return True
        ##elif self.estado=="DecimalExp":
            ##return True
        elif self.estado=="digitE":
            return True
    
        elif self.estado=="Hexadecimal":
            return True 
        elif self.estado=="Comentario":
            return True
        elif self.estado=="ComentarioAs":
            return True 
        elif self.estado=="auxDec":
            return True 
        elif self.estado=="Alpha":
            return True         
        ##elif self.estado=="com_mul":
            ##return False                    
        


    

def main():
    count = 0 
    b = 0
    archivos()
    with open('copy.txt','r') as file:
        for line in file:
            count += 1 
            words = line.split()
            for i in range(len(words)):
                word = words[i]
                if checkpalabrasReservadas(word):
                    if i < len(words) - 1:
                        next_word = words[i+1]
                        if next_word in ['=', '+', '-', '*', '/', '>', '<', '==', '!=', '>=', '<=','++','--']:
                            b = 1
                            print("Error en la linea, palabra reservada utilizada com un simbolo: " + str(count)) 
                else:
                    if check_consecutive_operators(word):
                        b = 1
                        print(f"Error en la linea {count}, operadores consecutivos inválidos en: {word}")
                    else:
                        AFD = Automata(word)
                        if AFD.AnalizadorLexico() == False:
                            b = 1
                            print("Error en la linea " + str(count))
    if b != 1:
        print("No se han encontrado errores gramaticales en el archivo")

def archivos():
    original = r'EjemploPracticaAnalizador.java'
    target = r'copy.txt'

    shutil.copyfile(original, target)   
    
    with open('copy.txt', 'r') as file :
     filedata = file.read()
     
    filedata = filedata.replace(';',' ') 
    filedata = filedata.replace(',',' ')  
    filedata = filedata.replace('(',' ')  
    filedata = filedata.replace(')',' ')
    filedata = filedata.replace('{',' ') 
    filedata = filedata.replace('}',' ') 
    filedata = filedata.replace('[',' ') 
    filedata = filedata.replace(']',' ')  
    filedata = filedata.replace('"',' ')          
    
    with open('copy.txt', 'w') as file:
     file.write(filedata)    

def checkpalabrasReservadas(word):
  with open('palabrasreservadas.txt') as file:
    contents = file.read()
  if word in contents:
    return True
  else:
    return False
def check_consecutive_operators(word):
    operadores = set(['+', '-', '=', '/', '<', '>', '!', '*', '%'])
    i = 0
    while i < len(word) -  1: #2: 
        #if word[i] in operadores and word[i + 1] in operadores and word[i + 2] in operadores:
        if word [i] in operadores and word [i+1] in operadores:
            if not ((word[i] == '+' and word[i + 1] == '+') or (word[i] == '-' and word[i + 1] == '-') or (word[i]=='/' and word [i+1]=='/')
                    or (word[i]=='/' and word[i+1] =='*' ) or (word[i]=='*' and word [i+1]=='/') or (word [i] == '=' and word[i+1]=='=') or 
                    (word[i]=='+' and word[i+1]=='=') or (word[i]=='-' and word[i+1]=='=') or (word[i]=='=' and word[i+1]=='-') or (word[i]=='=' and word[i+1]=='-')):
                return True
        i += 1
    return False



if __name__ == "__main__":
    main()