# Raylib Bullet Hell Engine  

A fully functional **bullet hell engine** built with **Raylib**, featuring an integrated **ImGui editor** for real-time customization of bullet patterns, enemy behaviors, and game parameters.  

![bullethell](https://github.com/user-attachments/assets/f85407b5-d61b-43fd-b165-421f19048ed6)

## 🛠️ Features  

- **ImGui-powered editor** – Adjust/Create bullet data and bullet patterns.  
- **Customizable bullet patterns** – Modify in real-time without recompilation.  
- **Player and enemy systems** – Includes movement, hitboxes, and attack behaviors.  

## 📂 Project Structure  

- **`Bullet.cpp`** – Manages bullet movement and behavior.
- **`BulletSpawner.cpp`** – Spawns bullet and manages all the patterns.  
- **`Player.cpp`** – Implements player movement, hitboxes, and interactions.  
- **`GameManager.cpp`** – Core game loop, including rendering, updates and optimization.  
- **`ToolInterface.cpp`** – Handles the ImGui interface (Bullet, Pattern, Editor).

## 💡 Inspiration  

This project was inspired by the work of **Erik Bolumburu** and his [Touhou Clone Engine](https://github.com/erikbolumburu11/Touhou-Clone-Engine). While his work influenced some ideas (especially the look of the engine itself), the code in this project was **entirely rewritten from scratch** in my own way.  

## 📌 Status  

This project is more of a **fun experiment** than anything serious. It's designed to explore the possibilities of bullet hell mechanics with Raylib and **ImGui**, so feel free to play around with it however you like!
