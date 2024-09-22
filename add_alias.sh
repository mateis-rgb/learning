#!/bin/bash

# Définir les alias à ajouter
ALIAS_A_AJOUTER="alias la=\"ls -la\"\nalias py=\"python3\"\nalias pip=\"python3 -m pip\"\nalias gcc=\"gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin\"\nalias g++=\"g++ -Wall\""

# Fonction pour ajouter les alias au fichier spécifié
ajouter_alias() {
    local fichier=$1
    if [ -f "$fichier" ]; then
        # Vérifie si les alias existent déjà
        if ! grep -Fxq "alias la=" "$fichier" || ! grep -Fxq "alias py=" "$fichier" || ! grep -Fxq "alias pip=" "$fichier" || ! grep -Fxq "alias gcc=" "$fichier" || ! grep -Fxq "alias g++=" "$fichier"; then
            # Ajoute les alias au fichier
            cp $fichier $fichier.bak
            echo -e "$ALIAS_A_AJOUTER" > "$fichier"
            echo "Alias ajoutés à $fichier"
			source $fichier
        else
            echo "Les alias sont déjà présents dans $fichier"
        fi
    else
        echo "Le fichier $fichier n'existe pas."
    fi
}

# Détermine le shell utilisé
if [ -n "$BASH_VERSION" ]; then
    # Utilisation de Bash
    fichier_rc="$HOME/.bashrc"
    ajouter_alias "$fichier_rc"
elif [ -n "$ZSH_VERSION" ]; then
    # Utilisation de Zsh
    fichier_rc="$HOME/.zshrc"
    ajouter_alias "$fichier_rc"
else
    echo "Ce script ne peut être utilisé que dans un environnement Bash ou Zsh."
fi
