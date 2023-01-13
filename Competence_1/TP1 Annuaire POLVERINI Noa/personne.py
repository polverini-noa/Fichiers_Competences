# --- import
import json
import datetime, langages as l

###################################
######## class Personnne ########## 
###################################

class Personne:
    # constructor
    def __init__(self, prenom : str, nom : str, langages : l.langages, bio : str) -> None: 
        self.__prenom : str = prenom
        self.__nom : str = nom
        self.__langages : l.langages = langages
        self.__bio = bio
    
    def __repr__(self) -> str:
        res = ""
        if self.__langages == l.langages.C : res += "C "
        elif self.__langages == l.langages.C_Plus_Plus : res += "C++"
        elif self.__langages == l.langages.Java : res += "Java"
        elif self.__langages == l.langages.Python : res += "Python"
        elif self.__langages == l.langages.Elixir : res += "Elixir"
        else : res += "_ "
        
        res += self.__prenom +" "+ self.__nom+",("
        res += ':"'+self.__bio+'".'
        return res

    @property
    def prenom(self) -> str: return self.__prenom
    @prenom.setter
    def prenom(self, prenom :str) -> None: self.__prenom = prenom[0].upper()+prenom[1:].lower()  

    @property
    def nom(self) -> str: return self.__nom
    @nom.setter
    def nom(self, nom :str) -> None: self.__nom = nom[0].upper()+nom[1:].lower() 
    
    @property
    def langages(self) -> l.langages: return self.__langages
    @langages.setter
    def langages(self, langages : l.langages) -> None: self.__langages = langages 

    @property
    def bio(self) -> str : return self.__bio
    @bio.setter
    def bio(self, txt : str) -> None: self.__bio = txt

    @property
    def filtre_langue(self) -> str : return self.__filtre_langue
    @filtre_langue.setter
    def filtre_langue(self, txt : str) -> None: self.__filtre_langue = txt
    
    # toJSON
    def toJSON(self) -> str:
        dictP = {
            'langages'  : str(self.__langages),
            'prenom' : self.__prenom,
            'nom'    : self.__nom,
            'bio'    : self.__bio        }
        return json.dumps(dictP,ensure_ascii=False)

    # buildFromJson
    @staticmethod
    def buildFromJSon(d: dict):
        # genre
        langageSTR : str = d['langages'] 
        if langageSTR == 'C': langue = l.langages.C
        elif langageSTR == 'C_Plus_Plus': langue = l.langages.C_Plus_Plus
        elif langageSTR == 'Python': langue = l.langages.Python
        elif langageSTR == 'Elixir': langue = l.langages.Elixir
        elif langageSTR == 'Java': langue = l.langages.Java
        else : langue = l.langages.Rien
        
        prenom :str =  d['prenom'] 
        nom : str =  d['nom'] 
        bio = d['bio'] 
        return Personne(prenom, nom, langue, bio)

    # new
    @staticmethod
    def new(): return Personne("Prénom", "Nom", l.langages.Rien, "biographie") 
