from PyQt6.QtWidgets import QWidget, QComboBox, QLineEdit, QTextEdit, QApplication, QGridLayout
from PyQt6.QtCore import pyqtSignal
import langages as l
import sys

###################################
####### class VuePersonne ######### 
###################################

class VPersonne(QWidget): 
    # signal     
    personneChanged : pyqtSignal = pyqtSignal(dict) 

    # constructor     
    def __init__(self): 
        super().__init__()
        self.setWindowTitle('python')
        
        # # crée une layout
        self.verLayout = QGridLayout()
        self.setLayout(self.verLayout)

        # définition des widgets
        self.langue : QComboBox = QComboBox()
        self.langue.addItems(["C", "C++", "Elixir", "Python", "Java", "Rien"])
        self.prenom : QLineEdit = QLineEdit("Prénom")
        self.nom : QLineEdit = QLineEdit("Nom")         
        self.bio : QTextEdit = QTextEdit('"biographie"')
        self.lang_filtre : QTextEdit = QTextEdit("Séléctionner un filtre de code pour voir afficher les personnes maitrisant ce langage.    (je n'ai pas réussi à faire fonctionner cette fonctionnalité, il y quelques traces de recherches je pense que je n'étais pas loin de la solution)         PS : n'oubliez pas de charger le fichier test.json grâce au bouton load pour tester le programme")
        
        # connection
        self.langue.currentIndexChanged.connect(self.changeLangue)         
        self.prenom.editingFinished.connect(self.changePrenom)         
        self.nom.editingFinished.connect(self.changeNom)         
        self.bio.textChanged.connect(self.changeBiographie) 
        self.lang_filtre.textChanged.connect(self.changeBiographie)
           
        # ajoute les 3 premiers widgets sur la 1ère ligne dans la QgridLayout avec ses coordonnées associés
        self.verLayout.addWidget(self.langue,0,0)
        self.verLayout.addWidget(self.prenom,0,1)
        self.verLayout.addWidget(self.nom,0,2)

        # ajout du widget bio dans la grille
        self.verLayout.addWidget(self.bio,2,1,2,3)   
        self.verLayout.addWidget(self.lang_filtre,2,0,2,1)

        self.show()
    
    # callback     
    
    def changeLangue(self) -> None : 
        self.personneChanged.emit(self.getAllInfo())
    def changePrenom(self) -> None : 
        self.personneChanged.emit(self.getAllInfo())                            
    def changeNom(self) -> None : 
        self.personneChanged.emit(self.getAllInfo())
    def changeBiographie(self) -> None : 
        self.personneChanged.emit(self.getAllInfo())
    def changeFiltre(self) -> None : 
        self.personneChanged.emit(self.getAllInfo())
        
    def getAllInfo(self): 
        langue = self.langue.currentIndex()
        if langue == 1:
            langue = "C"
        elif langue == 2:
            langue = "C++"
        elif langue == 3:
            langue = "Elixir"
        elif langue == 4:
            langue = "Python"
        elif langue == 5:
            langue = "Java"
        else :
            langue = "Rien"
        
        # filtre = ""  
        # if self.langue.currentText() in self.bio.toPlainText() :
        #     filtre = ""+self.prenom.text()+" "+self.nom.text()
        #     print(filtre)
            
        return {
        "langue":langue,
        "prenom":self.prenom.text(),
        "nom":self.nom.text(),
        "biographie":self.bio.toPlainText()
        }
 
    # update : mise à jour de la vue     
    def updatePersonne(self, p: str, n:str, langue: l.langages, b: str) -> None : 
        self.prenom.setText(p)  
        self.nom.setText(n)

        if str(langue) == 'C' :
            self.langue.setCurrentIndex(0)
        elif str(langue) == 'C_Plus_Plus' :
            self.langue.setCurrentIndex(1)
        elif str(langue) == 'Elixir' :
            self.langue.setCurrentIndex(2)
        elif str(langue) == 'Python' :
            self.langue.setCurrentIndex(3)
        elif str(langue) == 'Java' :
            self.langue.setCurrentIndex(4)
        else : 
            self.langue.setCurrentIndex(5)
        self.bio.setText(b)

if __name__ == '__main__' :
    # permet de lancer la fenetre et de la fermer aussi quand l'user le désire
    app = QApplication(sys.argv)
    firstWindow = VPersonne()
    sys.exit(app.exec())