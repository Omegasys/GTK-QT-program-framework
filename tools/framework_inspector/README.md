# Framework Inspector Tool

The **Framework Inspector** is a real-time debugging and introspection tool for MyFramework.

It is designed to help developers understand, debug, and optimize:

- UI widget hierarchy
- Layout engine behavior
- Event propagation system
- Rendering pipeline performance
- Runtime object properties

---

## 🔍 Features

### 🌳 Widget Tree Inspector
Visualizes the entire live widget hierarchy in real time.

### 🧩 Property Editor
Inspect and modify runtime properties of UI elements.

### ⚡ Event Monitor
Tracks all input and system events as they propagate through the framework.

### 🎯 Render Debug Overlay
Displays performance metrics such as:
- FPS
- Draw calls
- Frame timing

### 📐 Layout Debugger
Shows widget positioning, bounding boxes, and layout calculations.

---

## 🧠 Purpose

This tool is equivalent to:

- Unreal Engine “Widget Reflector”
- Qt Inspector tools
- Chrome DevTools (Elements + Layout tabs)

It allows full runtime introspection of MyFramework.

---

## 🔄 System Overview
Framework Runtime
↓
framework_inspector
├── WidgetTreeView
├── PropertyEditor
├── EventMonitor
├── RenderDebugOverlay
└── LayoutDebugger


---

## 🚀 Building

From the root of the repository:

```bash
mkdir build
cd build
cmake ..
make framework_inspector
