# Config Editor Tool

The **Config Editor** is a live visual editor for MyFramework configuration files.

It allows real-time editing, previewing, and validation of:

- Theme configurations
- Timeframe-based theme scheduling
- Window layout settings
- Live reload of `.config` files
- Visual color editing

---

## ✨ Features

### 🧠 Live Config System
Changes to config files are detected instantly using the built-in file watcher and applied without restarting the tool.

### 🎨 Theme Editing
Supports:
- Multi-theme slots per application
- Time-based theme switching
- Smooth blending between overlapping themes

### ⏱ Timeframe Editor
Visual editor for defining:
8:00 - 12:00 → Morning Theme
12:00 - 18:00 → Day Theme
18:00 - 24:00 → Night Theme


### 🌈 Color Picker
Allows editing of:
- Hex colors
- RGBA values
- Shadow and blur properties

---

## 🧱 UI Layout

The default layout includes:

- Config tree view (left)
- Timeframe editor (bottom-left)
- Live preview panel (top-right)
- Theme slot editor + color picker (bottom-right)

Layout is defined in:

resources/default_layout.json


---

## 🚀 Building

From the root of the repository:

```bash
mkdir build
cd build
cmake ..
make config_editor
▶ Running
./config_editor
📁 Dependencies
MyFramework (core UI + rendering system)
C++17 or higher
Cross-platform window backend (X11 / Wayland / Win32 / Cocoa)
🔮 Future Improvements

Planned features:

Drag & drop UI layout editor
Dockable panels system
Multi-project config workspaces
Live shader/theme preview inspector

---

# 🧠 What This Adds to Your Project

Now your ecosystem includes:

✔ Core framework  
✔ Full test suite  
✔ Integration tests  
✔ Example apps  
✔ AND a real GUI tool built on top  

---

# 🔥 Big Picture
