from PyQt6.QtWidgets import QApplication
import sys
import annuaire, vAnnuaire, personne

######## class main ############### 


######################################################### /!\ ATTENTION /!\ #########################################################
#                veuillez charger un fichier json directement après avoir lancé le programme (fichier test.json dispo)              #
######################################################### /!\ ATTENTION /!\ #########################################################

class Main:     
    # constructor     
    def __init__(self) -> None: 
        # attrbut
        self.modele = annuaire.Annuaire()                  
        self.vue    = vAnnuaire.VAnnuaire()  
        self.vue.personneChanged.connect(self.update)       
        p = self.modele.getPersonne()          
        if isinstance(p, personne.Personne): 
            self.vue.updatePersonne(p.prenom,p.nom,p.langages, p.bio)  

        # slots ie callback         
        self.vue.nextClicked.connect(self.next)         
        self.vue.previousClicked.connect(self.previous)         
        self.vue.openFileClicked.connect(self.openFile)         
        self.vue.newClicked.connect(self.new)         
        self.vue.personneChanged.connect(self.update)         
        self.vue.saveAsClicked.connect(self.saveAs) 
 
    def update(self,d) -> None : 
        d = personne.Personne(d.get("prenom"),d.get("nom"),d.get("langages"),d.get("biographie"))
        self.modele.update(d)

    def next(self) -> None: 
        self.modele.next()
        personne = self.modele.getPersonne()
        if personne != None:
            self.vue.updatePersonne(personne.prenom,personne.nom,personne.langages, personne.bio)

    def previous(self) -> None: 
        self.modele.previous()
        personne = self.modele.getPersonne()
        if personne != None:
            self.vue.updatePersonne(personne.prenom,personne.nom,personne.langages, personne.bio)

    def new(self) -> None:
        p = personne.Personne.new()
        self.modele.addPersonne(p,0) 
        if personne != None:
            self.vue.updatePersonne(p.prenom,p.nom,p.langages, p.bio)

    def openFile(self, fname : str) -> None: 
        self.modele = annuaire.Annuaire(fname)
        p = self.modele.getPersonne()
        if isinstance(p, personne.Personne):
            self.vue.updatePersonne(p.prenom,p.nom,p.langages, p.bio)

    def saveAs(self, filename) -> None:
        self.modele.save(str(filename))

    # fonction qui affiche la liste des personnes associées aux langages qu'elles étudient , liste trier alphab par nom des pers
    
if __name__ == "__main__":
    # permet de lancer la fenetre et de la fermer aussi quand l'user le désire
    app = QApplication(sys.argv)
    firstWindow = Main()
    sys.exit(app.exec())