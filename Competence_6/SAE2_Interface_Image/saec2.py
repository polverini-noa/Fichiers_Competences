# SAE2 Traitement images
# GROUPE Noa, Pierre, Marina

# Ce code utilise les modules PyQt6, astropy et numpy pour créer une interface utilisateur 
# qui permet à un utilisateur d'ouvrir un dossier contenant des images FITS, puis d'appliquer 
# un traitement sur ces images (calcul de la moyenne ou de la médiane) et d'afficher le résultat dans l'interface utilisateur.

from PyQt6.QtWidgets import QFileDialog, QApplication, QWidget, QComboBox, QVBoxLayout, QHBoxLayout, QLabel, QPushButton
from astropy.utils.data import get_pkg_data_filename
from PyQt6.QtGui import QPixmap
from astropy.io import fits
from os import walk

import matplotlib.pyplot as plt
import numpy as np
import sys


class fenetre(QWidget) :
    def __init__(self) :
        super().__init__()

        # Liste des fichiers
        self.listeFichiers = []
        
        # change le titre de la fenetre
        self.setWindowTitle("Traitement d'image")

        # change les dimensions de la fenetre
        self.setMinimumWidth(650)
        self.setMinimumHeight(550)

        # crée une layout
        self.VBox = QVBoxLayout()
        self.setLayout(self.VBox)

        # créer la layout pour le bouton ouvrir un dossier contenant toutes les images
        self.HboxLayout = QHBoxLayout()
        self.setLayout(self.HboxLayout)
        self.button : QPushButton = QPushButton("Ouvrir un dossier")
        self.button.clicked.connect(self.openFileDialog)
        
        # ajout des boutons Moyenne et Mediane dans la combobox
        self.ListeDeroulante : QComboBox = QComboBox()
        self.ListeDeroulante.addItems(["Moyenne" , "Médiane"])

        # ajout des boutons au layout
        self.HboxLayout.addWidget(self.button)  
        self.HboxLayout.addWidget(self.ListeDeroulante)  
        
        self.VBox.addLayout(self.HboxLayout)
        
        self.VBox2 = QVBoxLayout()
        self.setLayout(self.VBox2)
        
        self.lbl = QLabel(self)
        self.VBox2.addWidget(self.lbl)  
        
        self.VBox.addLayout(self.VBox2)
        
        self.ListeDeroulante.currentTextChanged.connect(self.changementAffichage)
        
        self.show()
    
        
    def changementAffichage(self):
        " Cette fonction permet d'afficher la moyenne ou la mediane si l'user à sélectionner l'un ou l'autre"
        data = self.listeFichiers
        valeur = self.ListeDeroulante.currentText()
        
        # calcule la moyenne ou la médiane de data en fonction de la valeur sélectionnée dans la liste déroulante
        if valeur=="Moyenne":
            Liste = np.mean(data, axis=0)
        else :
            Liste = np.median(data, axis=0)

        # reformatage de la liste (enlève une liste, passe la liste de ça : [ [ [] ] ] à ça par exemple [ [] ])
        for new_liste in Liste:  
            Liste = new_liste 
            break
        
        # affiche l'image résultant
        plt.imshow(Liste, cmap="gray")
        plt.savefig('my_plot.png')
        pixmap = QPixmap('my_plot.png')
        
        self.lbl.setPixmap(pixmap)
        
    def openFileDialog(self):
        " Cette fonction renvoie les datas des fichiers dans une liste ex : pour 3 image [[data],[data],[data]] "
        
        # Ouvre une fenetre pour choisir le dossier des images 
        fname = QFileDialog.getExistingDirectory(None, 'Open working directory', "Selectionner le dossier")
        
        # Ajoute dans une liste les chemin de chaque fichier
        listeFichiers = []
        for (repertoire, sousRepertoires, fichiers) in walk(fname):
            listeFichiers.extend(fichiers)
        listeFichiersData = []

        # Ajoute dans une liste les datas de chaque fichier
        for index in range(len(listeFichiers)):
            listeFichiersData.append(np.array_split(fits.getdata(get_pkg_data_filename(fname+"/"+listeFichiers[index]), ext=0),1))
        
        
        # cette partie permet supprimer les données incohérentes
        threshold = 3
        
        #Parcours la liste des datas images
        for i in range(len(listeFichiersData)):
            #Parcours la liste des pixels images
            for j in range(len(listeFichiersData[i])):
                # calcule le z-score
                z = (listeFichiersData[i][j]-np.mean(listeFichiersData[i]))/np.std(listeFichiersData[i])
                # si thresold est inférieur au z-score alors supprime le pixel incohérents
                if (z > threshold).any():
                    listeFichiersData[i].remove(listeFichiersData[i][j])
                    
        self.listeFichiers = listeFichiersData
        self.changementAffichage()


if __name__ == '__main__' :
    # permet de lancer la fenetre et de la fermer aussi quand l'user le désire
    app = QApplication(sys.argv)
    firstWindow = fenetre()
    sys.exit(app.exec())