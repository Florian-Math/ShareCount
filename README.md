# ShareCount

ShareCount est une application permettant de gérer des budgets de groupe, soit pour faire une cagnotte, soit pour
partager des dépenses.

Le projet a été testé sur :

- Windows 10
- Arch linux [KDE Plasma]

### Membres du groupe

- DURAND Felix
- MATHIEU Florian
- PETIT Fabien

### Génération de la documentation

Le projet est documenté étape par étape.
Pour générer la documentation allez dans une étape et lancez la commande :
```sh
$ doxygen DoxyFile
```
La documentation de l'étape sera ensuite générée dans le dossier _doc_ de l'étape.

### Base de données de test

Afin de pouvoir tester le projet facilement un base de données de test est donnée, pour l'utiliser :

- Compiler le projet
- Mettre le fichier de base de données nommé "app.db" dans le dossier du build

##### Données de connexion :

|                 Email | Mot de passe |
| --------------------- | -------------|
| fabien@sharecount.fr  |         1234 |
| felix@sharecount.fr   |         1234 |
| florian@sharecount.fr |         1234 |

### Fonctionnalités

La liste des fonctionnalités avec les auteurs est la suivantes (Cette liste se trouve aussi en plus détaillé dans la documentation de la dernière étape)


| Etape |           Fonctionnalité          | Auteur |
| ----- | --------------------------------- | ------ |
|     1 |           Connexion & Inscription | Florian
|     2 |              Création d'un compte | Fabien
|     3 |           Création d'une cagnotte | Florian
|     4 | Ajout des dépenses dans un compte | Florian
|     5 |                 Interface étape 1 | Florian
|     6 |             Interface étape 2 - 3 | Florian
|     7 |                 Interface étape 4 | Florian
|     8 |                    Inviter groupe | Fabien & Florian
|     9 |                   Régler dépenses | Florian
|    10 |                   Créer Transfert | Fabien & Florian
|    11 |                 Valider Transfert | Fabien & Florian
|    12 |                       Déconnexion | Florian
|    13 |                      Clore groupe | Florian

### Screenshots

![AppScreenshot1](https://github.com/Florian-Math/ShareCount/blob/master/screenshots/Capture1.PNG)

![AppScreenshot2](https://github.com/Florian-Math/ShareCount/blob/master/screenshots/Capture2.PNG)

![AppScreenshot3](https://github.com/Florian-Math/ShareCount/blob/master/screenshots/Capture3.PNG)

## Infos
Ce projet a été développé dans le cadre d'un projet de [la Faculté des Sciences et Technologies de Nancy](https://fst.univ-lorraine.fr)
