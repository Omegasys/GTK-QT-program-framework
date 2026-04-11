# API Reference

This document outlines the core APIs of MyFramework.

---

## Core

### Application
Manages lifecycle.

```cpp
Application app;
app.initialize();
app.run();
app.shutdown();
Widget

Base UI element.

class Widget {
public:
    virtual void update();
};
Events
Event e;
window->pollEvent(e);
Rendering
Renderer::draw(command);
Config
Config cfg = ConfigParser::parseFile("app.config");

---

# ⚙️ `docs/config_system.md`

```md id="doc4"
# Config System

MyFramework uses a **live reload configuration system**.

---

## Features

- Hot-reload `.config` files
- File watcher integration
- Per-application settings
- Theme scheduling support

---

## Format

Example:


window.width=1280
window.height=720
theme=dark


---

## Advanced Theme Timeframes

Your extended format:


#123456-123456-123456-255-255-255-255-123456-123456-123456


---

## Meaning

1. Left gradient color  
2. Center gradient color  
3. Right gradient color  
4. Opacity (0–255)  
5. Blur radius  
6. Corner radius  
7. Shadow distance  
8. Shadow left color  
9. Shadow center color  
10. Shadow right color  

---

## Live Reload

When file changes:
