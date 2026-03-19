# CUB3D

**CUB3D** is a first-person shooter inspired by early 3D games, implementing from scratch a **2.5D raycasting engine** similar to Wolfenstein 3D, set in a universe inspired by Doom.
The project is fully written in C and focuses on low-level graphics, mathematics, and real-time rendering.

<img width="1913" height="1001" alt="Screenshot from 2026-03-19 15-25-47" src="https://github.com/user-attachments/assets/a11b4af3-7e10-4a1c-bbab-f9161ae53c64" />

---

## Installation

<details>
<summary>Linux only (Windows support coming soon)</summary>

1. Install dependencies

```bash
sudo apt update
sudo apt install -y make gcc xorg libxext-dev zlib1g-dev libbsd-dev
```


2. Clone the repository

```bash
git clone https://github.com/BenjaminRap/CUB3D.git
cd CUB3D
```

3. Build the project

```bash
make bonus
```

4. Run the game

```bash
./cub3D_bonus
```

---

⚠️ **Performance Warning**<br>
If the game is too demanding on your system, you can run a lighter version:

```bash
make all
./cub3D ./assets/mandatory/maps/map.cub
```

* You can replace `map.cub` with any other `.cub` map file
* This version includes fewer features and is easier to run.
</details>
