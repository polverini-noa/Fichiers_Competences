from PyQt6.QtWidgets import QWidget, QHBoxLayout, QApplication, QPushButton, QVBoxLayout, QFileDialog
from PyQt6.QtCore import pyqtSignal
import langages as l
import sys

import datetime
from vPersonne import VPersonne

###################################
####### class VueAnnuaire ######### 
###################################

class VAnnuaire(QWidget): 
    # signal     
    nextClicked = pyqtSignal()     
    previousClicked = pyqtSignal()     
    openFileClicked = pyqtSignal(str)     
    newClicked = pyqtSignal()     
    personneChanged = pyqtSignal(dict) 
    saveAsClicked = pyqtSignal(str) 

    # constructor     
    def __init__(self) : 
        super().__init__()
        self.setWindowTitle('python')

        # crée une layout
        self.verLayout = QVBoxLayout()
        self.setLayout(self.verLayout)

        # création de widget vuePersonne
        self.vueP : VPersonne = VPersonne()
        self.verLayout.addWidget(self.vueP)
        self.vueP.personneChanged.connect(self.changePersonne)

        # création des 5 boutons 
        self.precedent : QPushButton = QPushButton("<< précédent")
        self.load : QPushButton = QPushButton("load")
        self.new : QPushButton = QPushButton("new")
        self.save_as : QPushButton = QPushButton("save as")
        self.suivant : QPushButton = QPushButton("suivant >>")

        # connection
        self.precedent.clicked.connect(self.preced)         
        self.load.clicked.connect(self.charge)         
        self.new.clicked.connect(self.nouveau)         
        self.save_as.clicked.connect(self.sauvegarder)         
        self.suivant.clicked.connect(self.suiv)         

        # création du layout horizontal pour les 5 boutons
        self.hoz_boutons : QHBoxLayout = QHBoxLayout()

        # ajout des 5 boutons à la boxx horizontal
        self.hoz_boutons.addWidget(self.precedent)
        self.hoz_boutons.addWidget(self.load)
        self.hoz_boutons.addWidget(self.new)
        self.hoz_boutons.addWidget(self.save_as)
        self.hoz_boutons.addWidget(self.suivant)

        # ajout de la box horizontale à la grille
        self.verLayout.addLayout(self.hoz_boutons)

        self.show()
    
    def preced(self):
        self.previousClicked.emit()

    def charge(self):
        fileName = QFileDialog.getOpenFileName(self, "Ouvrir un fichier", "", "Text Files (*.json)")
        self.openFileClicked.emit(fileName[0])

    def nouveau(self):
        self.newClicked.emit()

    def sauvegarder(self):
        fileName = QFileDialog.getSaveFileName(self, "Enregistrez le fichier", "", "Text Files (*.json)")
        self.saveAsClicked.emit(fileName[0])

    def suiv(self):
        self.nextClicked.emit()

    def updatePersonne(self, p: str, n:str, l: l.langages, b: str) -> None : 
        self.vueP.updatePersonne(p,n,l, b)

    def changePersonne(self, d) -> None : 
        self.personneChanged.emit(d)

if __name__ == '__main__' :
    # permet de lancer la fenetre et de la fermer aussi quand l'user le désire
    app = QApplication(sys.argv)
    firstWindow = VAnnuaire()
    sys.exit(app.exec())