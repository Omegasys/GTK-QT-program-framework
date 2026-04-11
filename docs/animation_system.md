# Animation System

The MyFramework Animation System provides a **timeline-based, property-driven animation engine**.

It is designed for UI responsiveness, smooth transitions, and theme blending.

---

## ✨ Core Features

- Timeline-based animation control
- Easing function support
- Property binding system
- Multi-animation sequencing
- Frame-accurate updates

---

## 🧱 Architecture
Animation
↓
Timeline
↓
Easing Function
↓
Property Update
↓
UI / Render System


---

## ⏱ Timeline Model

Animations are driven by time:


0ms → start
500ms → mid-state
1000ms → end


---

## 🎯 Easing Functions

Supported easing types:

- Linear
- EaseIn
- EaseOut
- EaseInOut

Example:

```cpp
anim.setEasing(Easing::EaseInOut);
🧩 Property Animation

Animations can bind directly to UI properties:

opacity
position
scale
color
blur radius
🎨 Theme Integration

Animations are used heavily in:

theme transitions
gradient blending
window effects
UI feedback (hover, click, focus)
🔄 Update Loop
Engine Tick
   ↓
Animation System Update
   ↓
Timeline Evaluation
   ↓
Property Interpolation
   ↓
UI Render Update
⚠️ Constraints
Must be deterministic per frame
No blocking operations allowed
Must support frame skipping gracefully

---

# 🎨 `docs/rendering_pipeline.md`

```md id="sysdoc4"
# Rendering Pipeline

The MyFramework Rendering Pipeline is a **multi-stage, backend-agnostic rendering system** designed to support modern GPU APIs.

Supported backends:

- Vulkan
- OpenGL
- Metal (planned / macOS)

---

## 🧠 Pipeline Overview


UI Widgets
↓
Layout Engine
↓
Draw Command Generation
↓
Renderer Core
↓
Backend Abstraction Layer
↓
GPU API (Vulkan / OpenGL / Metal)


---

## 🧱 Core Components

### 1. Widgets
UI elements that define structure and behavior.

---

### 2. Layout Engine
Computes:
- position
- size
- alignment
- constraints

---

### 3. Draw Commands
Intermediate representation of rendering operations:

- draw rect
- draw text
- draw texture
- draw gradient

---

### 4. Renderer Core
Processes draw commands and batches them efficiently.

---

### 5. Backend Layer
Translates generic commands into GPU-specific calls.

---

## 🖥 Backend Architecture


Renderer
↓
Backend Interface
├── Vulkan Backend
├── OpenGL Backend
└── Metal Backend


---

## ⚡ Optimization Strategy

- batching draw calls
- minimizing state changes
- caching textures
- reusing command buffers

---

## 🎨 UI Rendering Flow


Widget Tree
↓
Layout Pass
↓
Render Pass
↓
Command Buffer
↓
GPU Execution
