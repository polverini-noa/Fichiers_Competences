# --- import
import json, copy, os
import personne

###################################
######## class Annuaire ########### 
###################################

class Annuaire:
    # constructor
    def __init__(self, jsonFile : (str|None) = None) -> None:
        # attributs
        self.__listPersonne : list[personne.Personne] = []
        self.__current : (int|None) = None
        
        # si un fichier est fourni : on charge 
        if jsonFile: self.open(jsonFile)

    @property
    def current(self) -> int | None : return self.__current
    @current.setter
    def current(self, index :int|None) -> None : self.__current = index

    def update(self,p: personne.Personne) -> None:
        pp = self.getPersonne()
        if pp:
            pp.langages = p.langages
            pp.prenom = copy.deepcopy(p.prenom)
            pp.nom = copy.deepcopy(p.nom)
            pp.bio = copy.deepcopy(p.bio)

    def open(self, jsonFile : str) -> None:
        with open(jsonFile, encoding='utf-8') as file:
            print(f'loading file: {jsonFile}', end='... ')
            js = json.load(file) 
            if  'annuaire' in js.keys():
                listPersonne = js['annuaire']
                for p in listPersonne:  
                    pp = personne.Personne.buildFromJSon(p) 
                    self.__listPersonne.append(pp)
                print(f'{len(self.__listPersonne)} personnes trouvées')
                self.__current = 0 if self.__listPersonne else None

    def save(self,jsonFile : str) -> None:
        print(f'saving file: {jsonFile}', end='... ')

        if not  os.path.exists(jsonFile): 
            f = open(jsonFile, "x"); f.close()

        with open(jsonFile, "w", encoding='utf-8') as file: 
            d : dict= {} 
            listPersonne : list= []
            for p in self.__listPersonne :listPersonne.append(json.loads(p.toJSON()))
            d['annuaire'] = listPersonne
            json.dump(d,file,ensure_ascii=False)
        print(f'done!')



    def getPersonneByName(self, name: str) -> (personne.Personne|None):
        searchList : list[str] = list(map(lambda x: x.nom.lower(), self.__listPersonne))
        return self.__listPersonne[searchList.index(name.lower())]

    def addPersonne(self, p : personne.Personne, index : int|None = None) -> None :
        if not isinstance(index, int) or not isinstance(self.__current, int):
            self.__listPersonne.append(p)
            self.current = len(self.__listPersonne) -1 if len(self.__listPersonne) != 0 else None
        else:
            self.__listPersonne.insert(self.__current,p)

    def next(self) -> None :
        if self.__current != None :
            self.__current = (self.__current +1)% len(self.__listPersonne) 
    
    def previous(self) -> None :
        if self.__current != None :
            self.__current = (self.__current - 1)% len(self.__listPersonne)

    def getPersonne(self) -> personne.Personne| None : 
        if self.__current != None: return self.__listPersonne[self.__current]  
        else: return None

# --- main: kind of unit test
if __name__ == "__main__" :
    print("\tTest à partir d'un fichier json:", end= ' ')
    annuaireJS : Annuaire = Annuaire('test.json')