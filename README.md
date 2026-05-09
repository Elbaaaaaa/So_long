## so_long (C / MiniLibX)

`so_long` est un mini-jeu 2D en C basé sur **MiniLibX** (projet 42). Le programme charge une carte au format `.ber`, affiche un niveau en tuiles, puis permet au joueur de collecter tous les items et de rejoindre la sortie.

### Fonctionnalités

- **Parsing de map `.ber`** avec validations :
  - map **rectangulaire**
  - map **fermée par des murs**
  - caractères autorisés
  - exactement **1 joueur (`P`)**, **1 sortie (`E`)**, au moins **1 collectible (`C`)**
- **Pathfinding** : vérifie que les collectibles et la sortie sont atteignables.
- **Rendu graphique** via MiniLibX (textures, fenêtre, affichage des tuiles).
- **Compteur de mouvements** affiché dans le terminal.

### Bonus (cible `make bonus`)

- **Ennemi(s)** sur la carte (`D`).
- **Animations / boucle de rendu** (hook MLX).

### Contrôles

- **W/A/S/D** : déplacer le joueur
- **ESC** : quitter le jeu

### Format de map

Le jeu lit un fichier `*.ber` composé de caractères :

- **`1`** : mur
- **`0`** : sol
- **`P`** : position de départ du joueur (unique)
- **`C`** : collectible(s)
- **`E`** : sortie (unique)
- **Bonus** : **`D`** : ennemi

Des exemples sont fournis dans `maps/`.

### Compilation

Depuis la racine du projet :

```bash
make
```

Bonus :

```bash
make bonus
```

Nettoyage :

```bash
make clean
make fclean
make re
```

### Exécution

```bash
./so_long maps/map.ber
```

Bonus :

```bash
make bonus && ./so_long maps/map_bonus_little.ber
```

### Dépendances (Linux / X11)

Ce projet compile la MiniLibX avec des liens X11 (voir `Makefile`) :

- `X11`
- `Xext`

Sur Debian/Ubuntu, par exemple :

```bash
sudo apt-get update
sudo apt-get install -y xorg libxext-dev libx11-dev
```

### Structure du projet

- `includes/` : headers (structures, prototypes)
- `src/` : version “mandatory”
- `src_bonus/` : version bonus (ennemis, hooks/animations)
- `lib/` : `libft/` + `mlx/`
- `maps/` : maps de démonstration (`.ber`)

### Auteur

- **ebella** — Étudiant(e) 42

