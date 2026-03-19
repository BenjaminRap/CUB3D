# CUB3D

**CUB3D** is a first-person shooter inspired by classic 3D games, implementing from scratch a **2.5D raycasting engine** similar to *Wolfenstein 3D*, set in a universe inspired by *Doom*.
The project is fully written in **C** and focuses on low-level graphics, mathematics, and real-time rendering.

<img width="1913" height="1001" alt="Screenshot from CUB3D" src="https://github.com/user-attachments/assets/a11b4af3-7e10-4a1c-bbab-f9161ae53c64" />

---

## 🚀 Installation

<details>
<summary>Linux only (Docker support coming soon)</summary>

### 1️⃣ Install dependencies

```bash
sudo apt update
sudo apt install -y make gcc xorg libxext-dev zlib1g-dev libbsd-dev
```

### 2️⃣ Clone the repository

```bash
git clone https://github.com/BenjaminRap/CUB3D.git
cd CUB3D
```

### 3️⃣ Build the project

```bash
make bonus
```

### 4️⃣ Run the game

```bash
./cub3D_bonus
```

---

> ⚠️ **Performance Warning**
> If the game is too demanding on your system, you can run a lighter version:
>
> ```bash
> make all
> ./cub3D ./assets/mandatory/maps/map.cub
> ```
>
> *You can replace `map.cub` with any other `.cub` map file.*
> *This lighter version includes fewer features and is easier to run.*

</details>

---

## 🎮 Gameplay

<details>
<summary>Controls</summary>

* **Move**: `W` `A` `S` `D`
* **Jump**: `Space`
* **Shoot**: Left mouse button
* **Switch weapons**: Mouse wheel
* **Open doors**: `E`

</details>

<details>
<summary>UI</summary>

* **Mini-map**: shows enemies as red dots
* **Health bar**: displayed in red
* **Ammo count**: displayed in blue for the current weapon

</details>

<details>
<summary>Enemies</summary>

Enemies have **melee** and **ranged attacks**, and they will prioritize one type based on their behavior. Some rush you, others maintain distance and shoot.

| Enemy                             | Description                                                             |
| --------------------------------- | ----------------------------------------------------------------------- |
| **Imp**                           | Weak enemy, melee and ranged attacks.                                   |
| **Demon**                         | Low HP, fast, melee-focused.                                            |
| **Cacodemon**                     | Keeps distance, attacks from range, switches to melee if you get close. |
| **Baron of Hell**                 | Large demon, high HP, strong melee and ranged attacks, prefers melee.   |
| **Lost Soul**                     | Weak enemy, rushes players to explode on contact.                       |
| **Pain Elemental**                | Summons Lost Souls, keeps distance but attacks in melee if approached.  |
| **Cyber Demon**                   | Boss enemy, massive HP, devastating ranged attacks.                     |
| **Revenant**                      | Ranged and melee attacks, prioritizes ranged, launches missiles.        |
| **Mancubus**                      | Strong melee and ranged attacks, prioritizes ranged.                    |
| **Corrupted Sergeant / Commando** | Weak corrupted human, ranged attacks only.                              |

</details>

<details>
<summary>Weapons</summary>

| Weapon                    | Description                                      |
| ------------------------- | ------------------------------------------------ |
| **Hands**                 | Short-range melee attack, low damage.            |
| **Pistol**                | Basic firearm for weak enemies.                  |
| **Chaingun**              | Low damage but fires continuously, many bullets. |
| **Big Fucking Gun (BFG)** | Upgraded chaingun, more powerful.                |
| **Plasma Gun**            | Low speed, no damage, but immobilizes enemies.   |
| **Shotgun**               | High damage, short-range.                        |
| **Rocket Launcher**       | Extremely powerful, very limited ammo.           |
| **Chainsaw**              | Melee attack, low damage, grants ammo on kills.  |

</details>

<details>
<summary>Creating New Maps</summary>

Maps are stored as `.cub` files.

<details>
<summary>Texture paths</summary>

Each map file must begin with the paths of all textures used in the game.
To use default textures, you can copy them from an existing map file.

Format:

```
ANIMATION_NAME ./texture/path.xpm sizeX,sizeY animationDelay
```

* **ANIMATION_NAME** → identifier of the animation
* **./texture/path.xpm** → path to the `.xpm` spritesheet
* **sizeX,sizeY** → size of a single tile in pixels (width,height)
* **animationDelay** → delay between frames in milliseconds

**Example:**

```
IMP_PROJECTILE_DEATH ./assets/textures/doom/effects/imp_projectile/imp_projectile_death.xpm 50,44 100
```

</details>

<details>
<summary>Map composition</summary>

* ` ` → empty space
* `0` → free ground with ceiling
* `1` → wall
* `z` → Demon
* `i` → Imp
* `c` → Cacodemon
* `b` → Baron of Hell
* `k` → Lost Soul
* `p` → Pain Elemental
* `y` → Cyber Demon
* `r` → Revenant
* `m` → Mancubus
* `v` → Commando
* `f` → Sergeant
* `d` → Door
* `l` → Light
* `n` → Player facing North
* `s` → Player facing South
* `e` → Player facing East
* `w` → Player facing West

> By default, all tiles have a ceiling. To use a sky instead, replace `0` with `2` and capitalize the corresponding tile letter.
> The map must be enclosed by walls; the void should not be accessible to the player.

</details>

<details>
<summary>Playing Custom Maps</summary>

* In the lighter version, pass the map as the second argument:

  ```bash
  ./cub3D ./assets/mandatory/maps/map.cub
  ```
* In the bonus version, 5 maps are available in `./assets/bonus/maps/`:

  1. map_island.cub
  2. map_enemies.cub
  3. map_test.cub
  4. map_rooms.cub
  5. map_rooms2.cub

> To play a custom map, replace one of the existing files with yours.

</details>

</details>
