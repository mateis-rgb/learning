
Le C++ est un langage de programmation : il sert donc à écrire des applications informatiques. Il s'agit d'ailleurs d'un des langages de programmation les plus utilisés aujourd'hui. Chaque programme en C++ doit être écrit en respectant des règles d'écriture très strictes que nous étudierons petit à petit.


## Table des matières




## Importations de modules

Un module est constitué d'un ou plusieurs fichiers de code source compilés dans un fichier binaire. Le fichier binaire décrit tous les types, fonctions et modèles exportés dans le module. Lorsqu'un fichier source importe un module, le compilateur lit le fichier binaire qui contient le contenu du module.

Pour importer un module il faut faire l'instruction suivante :

```c++
#include <module>
```

Ainsi, à la base de tout les programme il y a l'instruction suivante :

```c++
#include <iostream>
```


## La fonction `main()`

La fonction `main()` est l'endroit où votre code source commence l'exécution. Il est a noté que si aucune instruction est noté dans la fonction `main()` mais a l’exterieur de cette fonction, alors rien ne s’exécuteras.

La fonction `main()` se définit ainsi :

```c++
int main () 
{
	// code

	return 0;
}
```

Il est important de mettre l'instruction `return 0;` car sinon le programme ne s’arrête pas. De plus, le 0 est important car il signifie au compilateur que le programme à terminer sans problème.

ATTENTION ⚠️ : Il est important de mettre le point virgule `;` a la fin de chaque instruction pour signifier la fin de la ligne.


## Les variables

Les variables servent à stocker des informations, de par leurs types et leurs valeurs. On définit une variable de la manière suivante :
``` cpp
int x = 3;
```
*Par exemple : ici on définit la variable "x" qui est un entiers et qui a pour valeur 3.*

Plus généralement, on définit une variable par un type et un nom. Le nom d'une variable à une syntaxe bien particulière qui doit être respectée :
* on ne commence jamais par un chiffre ou caractère spécial
* on peut utiliser des lettres minuscules et majuscules, des chiffres (après le premier caractère) et des tirets du bas (ou underscore)
* par conventions, dans ce cours, nous verrons une façon de nommer les variables : 
	* si le nom de la variable est en un seul mot :
		- on met tout le mot en minuscule
	- sinon :
		- on met toute la phrase attaché en minuscule 
		- sauf les premières lettre de chaque mot (excepté le premier mot (cf. exemples de variables ci-dessous))

ATTENTION ⚠️ : Il faut absolument typer les variables et pour cela il existe plusieurs types, voici les plus utilisés :

```cpp
int // entier
float // nombre a virgule
double // nombre a vrigule (plus grand ou égale en taille que le float)
char // caractère
bool // booléen (vrai ou faux)

// si besoin d'optimisation sur du coût en mémoire du programme il existe :
short // pour un entier court
long // pour un entier long
signed // pour une variable signé (qui contient un signe + ou -)
unsigned // pour une variable non signée (qui ne contient pas de signe + ou -)
```

Une fois les types de variables découvert, la syntaxe... Pour créer une variable il y a une syntaxe à respecter, la voici :

```cpp
// syntaxe
<type de la variable> <nom de la variable> = <valeur>;

// ex
int a;
char toto = "b";
bool ceciEstUnNomLong = false;
```

ATTENTION ⚠️ : Il est a noter qu'il n'est pas obligé de donner une valeur au variable, la seule chose d'obligatoire est de les déclarer pour pouvoir les utiliser.

De plus, il existe certain mots clés que l'ont peut ajouter aux variables tel que :

```cpp
// mots clés
const // pour les variables constantes
void // qui permet de définir une fonction (cf. partie sur les fonctions)
struct // qui permet de définir une structure (on le verra dans un prochain cours)

// ex
// On créer un booléen qui ne pourra pas être modifier par la suite
const bool toto = false; 
void HelloWorld () {} // fonction sans type de retour
struct eleve {
	string nom; // c'est comme si on définissait une variable classique
	int age;
	// ect...
}
```

Il est aussi possible d'utilisé des raccourcis pour l'incrémentation et la décrémentation de variables : 

```cpp
int x = O;

x += 1; // => x = x + 1;
x -= 1; // => x = x - 1;

x++; // x = x + 1;
++x; // x = 1 + x;

x--; // x = x - 1;
--x; // x = 1 - x;
```
*ATTENTION ⚠️ : L'ordre est important*.

## La structure d'un programme

Pour qu'un programme fonctionne, il faut qu'il y ait un minimum d'élément dans le fichier `.cpp` pour ça on va commencer par importer la librairie standard :

```cpp
#include <iostream>
```

Ensuite on va définir le contexte (ou namespace), celui ci va nous servir a identifier et grouper un ensemble logique d'éléments utilisés par le programme :

```cpp
using namespace std;
```
*Pour faire simple, ça évite au développeur d'avoir à écrire `std::` devant les instructions qui le nécessitent.*

Ensuite on écrit notre fonction principale :

```cpp
int main ()
{
	// code
	
	return 0;
}
```

Et maintenant on combine tout ça :

```cpp
#include <iostream>

using namspace std;

int main ()
{
	// code
	
	return 0;
}
```

Il faut au minimum écrire ça pour que le programme soit compilé et exécuté (cf. partie sur la compilation et l'exécution ci-dessous).


## La compilation et l'exécution

Une fois le programme fait, il faut l'enregistrer, soit en faisant `fichier -> enregistrer` soit avec un raccourcis `cmd + s` sous macOs, `ctrl + s` sous Windows et Linux, ou voir selon l'éditeur. Pour l'enregistrer, il vous faudra lui donner un nom suivit de l'extension `.cpp`, si cette extension manque, ça ne fonctionneras pas. 

ATTENTION ⚠️ : sur certains éditeurs un type de fichier est présélectionné, faites donc attention à choisir ou bien l'extension que vous souhaitez ou bien a choisir "tout les fichiers" et a noter a la fin `.cpp`.

Lorsque le fichier est enregistrer et bien nommé, il faut le compiler, pour cela on vas utiliser la commande :

ATTENTION ⚠️ : Pour compiler le programme, il faut dans le terminal être dans le répertoire où se trouve le programme, ou écrire le chemin d'accès complet du fichier.

``` sh
g++ <nom du fichier en entré>.cpp -o <nom du fichier en sortie>.out # sous Linux et macOs

g++ <nom du fichier en entré>.cpp -o <nom du fichier en sortie>.exe # sous Windows
```
*Le paramètre de la commande "-o" permet de définir le fichier de sortie après la compilation.*

Remarque : s'il y a des erreurs le compilateur les signaleras et indiqueras l'erreur ainsi que la ligne dans le code ainsi que le caractère.

Si `g++` n'est pas installer sur votre ordinateur, regardez sur internet ou sur le cours dédier (s'il existe, ou demandez le moi). 

Après tout ça, le programme est compiler, il faut maintenant l'exécuter pour qu'il fonctionne.

Sous macOs et Linux, il faut lancer la commande suivante : 

```sh
./<nom du fichier compilé>.out 
```
*Si on se trouve dans le même répertoire.*

```sh
/<chemin d accès complet du fichier compilé>.out
```
*Si on ne se trouve pas dans même répertoire.*

Remarque : dans le terminal, pour les slash "/" des chemin d’accès aux fichier, sous Windows, ces slash, sont inversées. Cela donne quelque chose comme ça : "\\ C: \\ Windows \\ etc".

Sous Windows, il faut lancer la commande suivante : 

``` cmd
.\<nom du fichier compilé>.exe 
```
*Si on se trouve dans le même répertoire.*

```cmd
\<chemin d accès complet du fichier compilé>.out
```
*Si on ne se trouve pas dans même répertoire.*

Et lorsque la commande est lancer le programme se lance.


## Les entrées et sorties

En C++ comme dans d'autres langages il est possible à l'utilisateur de communiquer avec le programme par ces périphériques d'entrée (clavier, souris, etc) et de sortie (écran).

Ici nous ne verrons que les entrées de l'utilisateur au clavier et en sortie les messages dans le terminal.

Pour commencer, le `cout`, littéralement "character out" en anglais. `cout` est un objet utiliser pour afficher la sortie sur le périphérique de sortie standard, en clair, `cout`est un objet qui permet d'afficher des messages ou des variables ou des expressions interprétées dans le terminal lors de l'exécution du programme.

On l’utilise de la manière suivante :

```cpp
cout << "une chaine de caractère";

// sortie : une chaine de caractère
```
*On utilise les chevrons vers la gauche pour signifier que ce qu'on met avant les chevrons vont dans la sortie et non l'inverse.*

De plus, il est possible de combiner plusieurs expressions dans le `cout`:

```cpp
int toto = 3;

cout << "Ceci est une variable " << toto << endl;

// sortie : Ceci est une variable 3
```
*On peut également utiliser `endl` pour dit fait un saut de ligne*.


Ensuite, le `cin` littéralement "character input" en anglais. `cin` est un objet est utilisé pour accepter l'entrée du périphérique d'entrée standard, c'est-à-dire clavier, en clair, `cin`est un objet qui permet a l'utilisateur d'entrer une chaine de caractère via son clavier dans le terminal lors de l'exécution du programme.

On l’utilise de la manière suivante :

```cpp
int uneVariableARemplir;

cin >> uneVariableARemplir;
```
*On utilise les chevrons vers la droite pour signifier que ce qu'on met en entré via le `cin` va dans la variable*.

De plus, il est possible de combiner plusieurs expressions dans le `cin` et de les afficher avec le`cout`:

```cpp
int toto;
int deuxiemeVar;

cout << "Entrez deux valeurs entières : " << endl;
cin >> toto >> deuxiemeVar;

cout << "Ce sont deux variables qui ont été remplies " << toto << " et " << deuxiemeVar << endl;
```


## Les opérateurs & opérateurs logiques

En informatique, l'ordinateur ne comprend que des 0 et des 1, comme l’électricité qui n'a que deux états ouvert (0) ou fermé (1). Le C++ comme dans d'autres langages contient des opérateurs (ou comparateurs) et des opérateurs logiques :

Tout d'abord commençons par les opérateurs, ceux ci servent à faire des comparaisons entre des valeurs ou des variables : 

```cpp
< // strictement inferieur
<= // inferieur ou égale
> // strictement supérieur
>= // supérieur ou égale
== // comparateur d'égalité, à ne pas confondre avec l’afectation qui est un égale simple
!= // n'est pas égal
```

Et dans des exemples concrets :

```cpp
cout << 2 < 3 << endl;
cout << 4 == 3 << endl;

// Sortie : vrai \n faux
```
*Ici le `\n` signifie un saut de ligne*.

Il est important de noter que une comparaison entre deux valeurs ou variables retourne un booléen, ce qui signifie que l'on peut affecter une variable avec une condition :

``` cpp
bool condition = 5 == 3;
```
*Ici implicitement, on définit la variable `condition` de type booléenne `true` (vrai) si 5 est égale à 3, sinon définit la variable `condition` comme `false` (fausse)*.

Et maintenant, les opérateurs logique, quand a eux, ils servent à faire des opérations logiques comme l'addition de deux comparaisons, ou même faire la négation d'un élément, on peut de référer aux tables logique de chaque opérateur pour savoir lequel utiliser.

Il a plusieurs façons d'écrire les opérateurs logique, dans ce cours nous allons en voir une, non pas la plus simple, mais celle qui est la plus rigoureuse et celle qui sera appliquer dans beaucoup d'autres langages de programmation : 

``` cpp
&& // le ET logique
|| // le OU logique
! // la négation
```

Concrètement, la syntaxe est assez simple, les deux opérateurs `&&` et `||` se mettent entre deux conditions. L'opérateur `!` quand a lui se met devant une valeur ou une variable pour dire son contraire.

``` cpp
// ici, si 4 est inférieur à 3 (faux) ou si 5 est égale à 5 (vrai)
cout << 4 < 3 || 5 == 5 << endl;

// Sortie : true

// ici, on demande la négation de true (vrai), et donc sa négation est false (faux)
cout << !true << endl;

// Sortie : false
```


## Les instructions conditionnels

Les instructions conditionnels sont des conditions et si la condition est vrai alors on effectue des instructions sinon on en effectuera d'autres.

Voici la syntaxe :

```cpp
// si la condition est vraie
if (condition) {
	// code
}
// sinon si la confition est vrai
else if (condition) {
	// code
}
// sinon
else {
	// code
}
```

Et voici un exemple :

```cpp

if (3 < 2) {
	cout << "3 est inférieur à 2" << endl;
}
else if (5 != 5) {
	cout << "5 n'est pas égal à 5" << endl;
}
else {
	cout << "Le reste" << endl;
}

// Sortie : Le reste
```

Il faut savoir que le `if-else` n'est pas la seule instruction conditionnelle, il existe aussi le `switch-case` qui lui est utile pour séparer le code en section et qui en fonction d'une variable va changer, par exemple, si on demande à un utilisateur de donner un chiffre entre 1 et 5 et que pour chaque chiffre on affiche quelque chose de différent on peut faire ainsi :

```cpp
int x;

cout << "Entrez un chiffre entre 1 et 5 : ";
cin >> x;

switch (x) {
	case 1:
		cout << "Bravo tu as choisis 1, tu n'as rien gagné" << endl;
		break;

	case 2:
		cout << "Pas de chance tu as choisi 2 maintenant tu peux retenter ta chance." << endl;
		break;
		
	case 3:
		cout << "Pas de chance tu as choisi 3 maintenant tu peux retenter ta chance." << endl;
		break;

	case 4:
		cout << "Toujours rien" << endl;
		break;

	case 5:
		cout << "Flemme de trouver d'autres expressions" << endl;
		break;

	default:
		cout << "le chiffre doit être compris entre 1 et 5." << endl;
		break;
}

```
*Un bloc de case se compose par la condition a côté du mot clé case, a savoir que ce que l'on va mettre a coté est une égalité stricte. Et à la fin de nos case il faut mettre break, sinon le programme va continuer de passer dans les cases. De plus on peut mettre un default, qui veut dire que si aucune valeur n'est entré dans les cases alors on passe dans le default*.
## Les fonctions

Les fonctions ont aussi des types, ils sont liés a valeur de retour de la fonction, si les valeurs de retour ont différent ont utilise le mot clé `void`. Les fonctions peuvent aussi avoir des paramètres, ce sont des comme des variables, ainsi il faut leurs mettre un type et potentiellement une valeur par défaut, par convention il faut mettre les paramètre de la fonction sans valeurs par défaut sont avant celle qui en ont. Voici la syntaxe d'une fonction :

```cpp
int addition (int a, int b = 3)
{
	return a + b;
}

void toto ()
{
	if (1 == 2) {
		return true;
	}
	
	return 1;
}

void proc ()
{
	
}
```
*On appel les fonctions qui ne retourne rien des procédures.*




## Les boucles

## Les tableaux

## Les chaînes de caractères