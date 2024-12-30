![Banner](img/cub_banner.png "ps banner") <br>

<h2>🏁 Goals</h2>

Cub3D is a project of graphics programming and game development. Inspired by classic games like Wolfenstein 3D, Cub3D uses a 2D map and raycasting techniques to simulate a 3D environment. The goal is to create a simple game engine with realistic rendering, player controls, and an interactive world.
Project Goals

    Learn Raycasting: Develop a pseudo-3D rendering engine by implementing raycasting to detect walls and simulate depth.
    Understand Graphics Programming: Use the MiniLibX library to handle graphical rendering, event management, and texture mapping.
    Build Game Mechanics: Implement player movement, collision detection, and interaction with the game world.
    Explore Optimization: Create efficient algorithms to maintain real-time rendering performance.

Features

    2D to 3D Rendering:
        Simulate a 3D perspective using raycasting techniques.
        Render walls with textures and manage distance scaling for realistic depth.

    Player Movement:
        Allow movement forward, backward, left, and right (strafing).
        Enable smooth rotation using keyboard or mouse input.

    Map Parsing:
        Parse .cub configuration files to load the game map, player starting position, and settings.
        Validate maps for proper boundaries and layout.

    Textures and Colors:
        Apply textures to walls and optionally to floors and ceilings.
        Support solid colors for floors and ceilings as a fallback.

    Collision Detection:
        Prevent the player from walking through walls or leaving the game area.

    Keyboard Interaction:
        Handle inputs such as movement keys (WASD or arrows) and quitting the game (ESC key).

Requirements

To successfully build and run Cub3D, you will need:

    MiniLibX Library: Provided by 42 for graphical output.
    C Compiler: gcc or equivalent to compile the project.
    Standard Libraries: Functions like malloc, free, read, open, etc., provided by the C standard library.

Why This Project Matters

Cub3D is an excellent introduction to graphics programming and game development. By completing this project, you will gain:

    A solid understanding of how early 3D games were developed.
    Confidence in working with rendering algorithms and mathematics.
    Experience in creating interactive, real-time applications.

