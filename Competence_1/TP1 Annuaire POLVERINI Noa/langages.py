from enum import Enum

###################################
########## class Genre ############ 
###################################
class langages(Enum):
    C = 1
    C_Plus_Plus = 2
    Elixir = 3
    Python = 4
    Java = 5
    Rien = 6

    def __str__(self): return self.name
    def __repr__(self): return self.name
    
if __name__ == "__main__":
    l = langages.C
    print(l)