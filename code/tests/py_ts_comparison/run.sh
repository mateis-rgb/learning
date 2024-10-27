#!/bin/bash

# Vérification de l'existence des fichiers
if [[ ! -f "main.py" || ! -f "main.ts" ]]; then
    echo "Les fichiers main.py ou main.ts n'existent pas."
    exit 1
fi

# Compilation du fichier TypeScript
tsc main.ts

# Mesurer le temps d'exécution du fichier Python
echo "Exécution de main.py..."
START_TIME=$(date +%s%N)
python3 main.py > output_python.txt
END_TIME=$(date +%s%N)
PYTHON_TIME=$((END_TIME - START_TIME))
echo "Temps d'exécution de main.py: $((PYTHON_TIME / 1000000)) ms"

# Mesurer le temps d'exécution du fichier TypeScript
echo "Exécution de main.js..."
START_TIME=$(date +%s%N)
ts-node main.ts > output_typescript.txt
END_TIME=$(date +%s%N)
TYPESCRIPT_TIME=$((END_TIME - START_TIME))
echo "Temps d'exécution de main.js: $((TYPESCRIPT_TIME / 1000000)) ms"

# Comparer les sorties
echo "Comparaison des résultats..."
if diff output_python.txt output_typescript.txt > /dev/null; then
    echo "Les sorties des deux programmes sont identiques."
else
    echo "Les sorties des deux programmes diffèrent."
fi

# Afficher les temps d'exécution
echo "Temps total Python: $((PYTHON_TIME / 1000000)) ms"
echo "Temps total TypeScript: $((TYPESCRIPT_TIME / 1000000)) ms"

# Nettoyer les fichiers temporaires
rm output_python.txt output_typescript.txt main.js

exit 0
