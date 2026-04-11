# Theme Editor Tool

The **Theme Editor** is a visual design tool for MyFramework that allows users to create, edit, and preview themes in real time.

It is built entirely on top of MyFramework and demonstrates:

- Custom UI system usage
- Real-time rendering pipeline
- Live theme preview system
- Gradient editing system
- Timeline-based theme scheduling

---

## ✨ Features

### 🎨 Visual Theme Editing
Edit themes using a live preview canvas that updates instantly.

### 🌈 Gradient Editor
Create smooth multi-stop gradients with draggable color stops.

### ⏱ Theme Timeline System
Assign themes to specific times of day:
08:00 - Morning Theme
12:00 - Day Theme
18:00 - Evening Theme


Supports:
- Overlapping transitions
- Smooth blending
- Fallback themes

---

## 🪟 UI Components

- ThemeWindow (main editor layout)
- ThemeCanvas (live preview)
- GradientEditor (color gradient builder)
- ThemeTimelineView (time-based scheduling)
- ColorStopWidget (draggable gradient stops)

---

## 🧱 Architecture
ThemeEditorApp
├── ThemeWindow
│ ├── ThemeCanvas
│ ├── GradientEditor
│ │ └── ColorStopWidget
│ └── ThemeTimelineView


---

## 🚀 Building

From the root project directory:

```bash
mkdir build
cd build
cmake ..
make theme_editor
▶ Running
./theme_editor
📁 Dependencies
MyFramework core library
UI module (Widget, Window, Layout)
Render system (for live preview)
Animation system (for transitions)
🔮 Future Improvements

Planned upgrades:

GPU-accelerated gradient rendering
Drag-and-drop theme blocks
Shader-based live preview
Multi-project theme workspace
Export to .theme packaged format

---

# 🧠 What This Completes

Now your ecosystem has:

✔ Core framework  
✔ Full test suite  
✔ Config Editor tool  
✔ Theme Editor tool  
✔ Live preview systems  
✔ Build systems for both tools  

---

# 🔥 Big Picture

You now effectively have:

> 🎨 A full visual design suite built on your own UI engine

This is the same pattern used by:

- Qt (Qt Creator + Designer)
- Unreal Engine (Editor + Material Editor)
- Figma (UI system + design tools)
